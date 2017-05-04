/* cmp1160: exemplo do uso da chamada clone
            para compilar: gcc -static clone2.c */
             
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>

// 64kB para a pilha de execução
#define FIBER_STACK 1024*64

// função (programa) executado pela thread filho
int threadFunction( void* argument )
{
printf( "thread filho executada !\n" );
return 0;
}

int main()
{
void* stack;
pid_t pid;

// Aloca a pilha de execucao
stack = malloc( FIBER_STACK );
if ( stack == 0 )
{
perror( "malloc: erro ao alocar a pilha de execucao" );
exit( 1 );
}

printf( "Criando a thread filho...\n" );

// A chamada clone() é usada para criar a thread filho
pid = clone( &threadFunction, (char*) stack + FIBER_STACK,
SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0 );
if ( pid == -1 )
{
perror( "problemas com o clone" );
exit( 2 );
}

// Agurada o termino da execucao do filho
pid = waitpid( pid, 0, 0 );
if ( pid == -1 )
{
perror( "problemas com waitpid" );
exit( 3 );
}

// libera a pilh (stack) de execucao
free( stack );

printf( "thread filho finalizada e memória liberada.\n" );

return 0;

}

