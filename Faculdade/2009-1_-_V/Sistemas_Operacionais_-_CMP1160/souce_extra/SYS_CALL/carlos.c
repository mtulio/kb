#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage int sys_carlos(){
	printk(KERN_EMERG "CARLOS ANTONIO CONSEGUIU FINALMENTE FAZER ISSO FUNCIONAR");
	return 1;
}

