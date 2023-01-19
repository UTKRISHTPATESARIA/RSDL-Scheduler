#include <linux/syscalls.h>
#include <linux/sched/isolation.h>
#include <linux/cpu.h>

SYSCALL_DEFINE1(isolate_core, int, cpuid)
{
  /*
  char *buf = "nohz_buf=0 , isolcpus=nohz,domain,managed_irq,0";
  housekeeping_nohz_full_setup(buf);
  housekeeping_isolcpus_setup(buf);*/

  printk(KERN_INFO "********* Starting CPU0 Isolation process *********\n");
  /*Put any offline*/
  remove_cpu(cpuid);

  return 0;
}