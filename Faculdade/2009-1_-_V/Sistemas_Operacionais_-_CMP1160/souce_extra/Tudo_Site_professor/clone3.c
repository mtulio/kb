/* CMP1160: exemplo de uso de clone ()
            para compilar: cc -static clone3c */

#include <stdio.h>
#include <signal.h>
#include <sched.h>
#include <stdlib.h>

int x; // variavel a ser compartilhada

int processofilho()
{
	printf("\n[Filho] O valor de x=%d. Vou alterar para 10.", x);
	x = 10;
	return(1);
}

int  main()
{
	int pid, v, i;
	void *pilha;
	
	x=10;
	pilha = (void *) malloc(100);
	
	pid = getpid();
	v = clone(processofilho, pilha, CLONE_VM, NULL);
	if (v<0)
	{
		printf("\nErro na criacao do processo filho");
		exit(1);
	}
	else 
	{
		wait();
		printf ("\n[Pai  ] O valor de x=%d.", x);
	} 
	printf ("\n[Pai  ] Fim.\n");
	return (1);
}
