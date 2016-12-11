/* Necessary includes for drivers */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/fcntl.h>
#include <linux/ioport.h>
#include <asm/system.h>
#include <asm/uaccess.h>
#include <asm/io.h>

MODULE_AUTHOR("Marco Tulio, Helio, Luan e Andre");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Sistemas Operacionais - Device Driver");
MODULE_LICENSE("GPL - SO ELEVADOR =D");

/* Driver global variables */
int base = 0x378;

/* Major number */
int numero_maior = 146;

/* Reservation of the parallel port*/
int porta;

/* Function declaration */
int portaparalela_open(struct inode *inode, struct file *filp);
int portaparalela_release(struct inode *inode, struct file *filp);
ssize_t portaparalela_write(struct file *filp, char *buf, size_t count, loff_t *f_pos);

/* Structure that declares the common file access funtions */
struct file_operations portaparalela_operacoes = {
	write:   portaparalela_write,
	open:    portaparalela_open,
	release: portaparalela_release
};

int __init portaparalela_init(void)
{
	/* Registering device */
	int resultado;
	resultado = register_chrdev(numero_maior, "elevador", &portaparalela_operacoes);
	if (resultado < 0)
	{
		printk(KERN_ALERT " > elevador: não foi possivel obter o major number %d\n", numero_maior);
		return resultado;
	}

	/*Registering port*/
	porta = check_region(base, 1);
	if (porta) 
	{
		printk(" > elevador: não foi possivel reservar a porta 0x378\n");
		resultado = porta;
	}
	request_region(base, 1, "elevador");

	printk(KERN_INFO " > elevador: Modulo da porta paralela/Elevador carregado\n");
	return 0;
}

void __exit portaparalela_exit(void) 
{
	/* Make major number free */
	unregister_chrdev(numero_maior, "elevador");
	/* Make port free! */
	if (!porta)
		release_region(base, 1);
	printk(KERN_INFO " > elevador: Removendo modulo da porta paralela\n");
}

module_init(portaparalela_init);
module_exit(portaparalela_exit);

int portaparalela_open(struct inode *inode, struct file *filp) 
{
	try_module_get(THIS_MODULE);
	printk(KERN_ALERT " > elevador: A porta paralela foi aberta com sucesso\n");
	return 0;
}

int portaparalela_release(struct inode *inode, struct file *filp) 
{
	module_put(THIS_MODULE);
	printk(KERN_ALERT " > elevador: A porta paralela foi fechada com sucesso\n");
	return 0;
}

ssize_t portaparalela_write(struct file *filp, char *buff,size_t count, loff_t *f_pos) 
{
	int passo;
	char portaparalela_buffer;
	/* Buffer writing to the device */
	copy_from_user(&portaparalela_buffer, buff, 1);
	/* Writing to the port */
	passo = (portaparalela_buffer - 48);
	outb(passo, base);
	//printk(KERN_EMERG "VALOR: %s\n", portaparalela_buffer);
	return 1;
}
