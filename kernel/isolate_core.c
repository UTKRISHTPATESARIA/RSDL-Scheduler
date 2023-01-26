#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/cpu.h>
#include <linux/sched/isolation.h>
#include <linux/fs.h>
#include <linux/fsnotify.h>
#include <../fs/internal.h>
/*
	++ The system call defined below : isolate_core will isolate the core 0 by mimicking what cpuset does.
	++ We have used specific system calls from within the kernel code-base to mimic the following commands 
	which will offer isolation to CPU0.

		$ mkdir /dev/cpuset

		$ mount -t cpuset none /dev/cpuset

		$ cd /dev/cpuset

		$ mkdir isolated

		$ mkdir housekeeping

		$ echo 1-3 > housekeeping/cpus

		$ echo 0 > housekeeping/mems

		$ echo 0 > isolated/cpus

		$ echo 0 > isolated/mems

		$ echo 0 > sched_load_balance

		$ echo 0 > isolated/sched_load_balance

		$ while read P
			do
			echo $P > housekeeping/cgroup.procs
			done < cgroup.procs

*/
SYSCALL_DEFINE3(isolate_core, char *, buf, char *, buf1, char *, buf2)
{
	struct file *f, *f1, *f2, *f3, *f4, *f5, *housekeeping, *to_migrate;
	char buff[10];
	long long src_off = 0;
	long long dst_off = 0;
	int fl = 1, idx = 0;
	char lt;
	printk("Creating Dir : CPUSETS\n");
	do_mkdirat(-100, getname(buf), 0);

	printk("Mounting Dir : CPUSETS\n");
	do_mount("", buf, "cpuset", 0, NULL);

	printk("Creating Sub-Dir : isolated\n");
	do_mkdirat(-100, getname(buf1), 0);

	printk("Creating Sub-Dir : housekeeping\n");
	do_mkdirat(-100, getname(buf2), 0);

	printk("Writing 0 to isolated set\n");
	f = filp_open("/dev/cpuset/isolated/cpus", 2, 0);
	kernel_write(f, "0\n", 2, 0);
	filp_close(f, NULL);

	printk("Writing 0 mem to isolated set\n");
	f1 = filp_open("/dev/cpuset/isolated/mems", 2, 0);
	kernel_write(f1, "0\n", 2, 0);
	filp_close(f1, NULL);

	printk("Disabling load balance on isolated\n");
	f2 = filp_open("/dev/cpuset/isolated/sched_load_balance", 2, 0);
	kernel_write(f2, "0\n", 4, 0);
	filp_close(f2, NULL);

	printk("Adding remaining cpus\n");
	f3 = filp_open("/dev/cpuset/housekeeping/cpus", 2, 0);
	kernel_write(f3, "1-3\n", 4, 0);
	filp_close(f3, NULL);

	printk("Adding mem\n");
	f4 = filp_open("/dev/cpuset/housekeeping/mems", 2, 0);
	kernel_write(f4, "0\n", 2, 0);
	filp_close(f4, NULL);

	printk("Disabling load balance on top level\n");
	f5 = filp_open("/dev/cpuset/sched_load_balance", 2, 0);
	kernel_write(f5, "0\n", 2, 0);
	filp_close(f5, NULL);

	printk("Migrating processes away from isolated cpu\n");
	housekeeping = filp_open("/dev/cpuset/housekeeping/cgroup.procs", 2, 0);
	to_migrate = filp_open("/dev/cpuset/cgroup.procs", 2, 0);

	while(1){
		fl = 1;

		while(1){
			fl = kernel_read(to_migrate, &lt, 1, &src_off);
			if(!fl) break;
			
			buff[idx++] = lt;
			if(lt == '\n')
				break;
		}

		if(!fl) break;
		kernel_write(housekeeping, buff, idx, &dst_off);
		idx = 0;
	}

	filp_close(housekeeping, NULL);
	filp_close(to_migrate, NULL);

	return 0;

}

/*
	System call to affine any process to the isolated core 0.
	
	Use sprintf() to pass the pid of the process in string format.
*/
SYSCALL_DEFINE1(set_affine, char __user *, buf){

	struct file *f;
	char str[100];
	int len = 0;
	len = sizeof(buf);
	printk("Copy from User\n");

	if(strncpy_from_user(str, buf, len) < 0)
		return -1;

	printk("Adding process to isolated CPU\n");
	f = filp_open("/dev/cpuset/isolated/cgroup.procs", 2, 0);

	printk("Added\n");
	kernel_write(f, str, sizeof(str), 0);
	filp_close(f, NULL);

	return 0;
}