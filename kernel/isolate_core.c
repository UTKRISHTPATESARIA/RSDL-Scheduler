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
  /*
  char *buf = "nohz_buf=0 , isolcpus=nohz,domain,managed_irq,0";
  housekeeping_nohz_full_setup(buf);
  housekeeping_isolcpus_setup(buf);*/

  printk(KERN_INFO "********* Starting CPU0 Isolation process *********\n");
  /*Put CPU0 offline*/
  remove_cpu(cpuid);

	return 0;
}