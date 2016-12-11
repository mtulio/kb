/* cmp1160: exemplo cria dois clones. 
            Quando veifica-se com o comando ps pode-se ver que o Pai e o primeiro 
            clone tem o mesmo PID, isto porque a flag CLONE_PID foi utilizada na crição 
            do clone. 
            No outro clone criado é feito o compartilhamento de sistema de arquivo 
            (CLONE_FS) e de arquivos (CLONE_FILES). 
            
            Para compilar: gcc -static clone1.c
            
            */
            
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>

int main()
{
void **newstack, *t ;
int *teste, pid, CLONE_PID;
  printf("Veja o ps -all em outra secao!\nDepois precione CTRL+C\n");
__clone(teste, newstack,CLONE_FILES|CLONE_FS,t) ;
__clone(teste,newstack, CLONE_PID,t) ;
for(;;) ;
return 0;
}
