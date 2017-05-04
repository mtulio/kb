#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <asm/io.h>

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *,struct file *);
static int device_release(struct inode *,struct file *);
static ssize_t device_read(struct file *,char *,size_t,loff_t *);
static ssize_t device_write(struct file *,const char *,size_t,loff_t *);

#define SUCCESS 0
#define DEVICE_NAME "chardev"
#define BUF_LEN 80

static int Major;
static int Device_Open = 0;
static char msg[BUF_LEN];
static char *msg_Ptr;
static struct file_operations fops = {
  .read = device_read,
  .write = device_write,
  .open = device_open,
  .release = device_release
};

int init_module(void){
  Major = register_chrdev(0,DEVICE_NAME,&fops);
  if(Major<0){
    printk(KERN_ALERT "O registro do device char falhou com %d\n",Major);
    return Major;
  }
  printk(KERN_INFO "Fui designado com o Major Number %d. Para falar com\n",Major);
  printk(KERN_INFO "o driver, crie um arquivo com dev\n");
  printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n",DEVICE_NAME,Major);
  printk(KERN_INFO "Tente varios Minor Number. Tente utilizando cat e echo para\n");
  printk(KERN_INFO "o arquivo do dispositivo.\n");
  printk(KERN_INFO "Remove o arquivo do Device e o Modulo quando terminado.\n");
  return SUCCESS;
}

void cleanup_module(void){
  int ret=0;
  unregister_chrdev(Major,DEVICE_NAME);
  if(ret<0){
    printk(KERN_ALERT "Erro no unregister_chrdev: %d\n",ret);
  }
}

static int device_open(struct inode *inode,struct file *file){
  static int counter = 0;
  if(Device_Open) return -EBUSY;
  Device_Open++;
  sprintf(msg,"Eu jah te disse %d vezes, Hello world!\n", counter++);
  msg_Ptr=msg;
  try_module_get(THIS_MODULE);
  return SUCCESS;
}

static int device_release(struct inode *inode,struct file *file){
  Device_Open--;
  module_put(THIS_MODULE);
  return 0;
}

static ssize_t device_read(struct file *filp,char *buffer,size_t length,loff_t *offset){
  int bytes_read=0;
  if(*msg_Ptr==0) return 0;
  while(length&&*msg_Ptr){
    put_user(*(msg_Ptr++),buffer++);
    length--;
    bytes_read++;
  }
  return bytes_read;
}

static ssize_t device_write(struct file *filp,const char *buff,size_t len,loff_t *off){
  unsigned int byte=0;
  int i=0;
  char nome;
  printk(KERN_INFO "\nEntramos no MODULO\e");
  copy_from_user(&nome,buff,1);
  byte=buff[0]-48;
  printk(KERN_INFO "Nome = %d\n", nome);
  printk(KERN_INFO "\n***\tPela %d, Byte = %d\n",i,byte);
  outb(byte,0x378);
  //printk(KERN_INFO "Retorno r = %d\n",r);
  printk(KERN_INFO "Buff[0] = %d  Buff[1] = %d  Buff = %s\n************************\e",buff[0],buff[1],buff);
  i++;
  return 1;
}
