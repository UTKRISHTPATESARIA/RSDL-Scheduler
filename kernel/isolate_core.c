#include <linux/syscalls.h>
#include <linux/sched/isolation.h>
#include <linux/cpu.h>

SYSCALL_DEFINE0(isolate_core)
{
  /*char *buf = "nohz_buf=0 , isolcpus=nohz,domain,managed_irq,0";
  housekeeping_nohz_full_setup(buf);
  housekeeping_isolcpus_setup(buf);*/
  printk(KERN_INFO "********* Starting CPU0 Isolation process *********\n");
  remove_cpu(0);
  
  return 0;
}