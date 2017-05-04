//exemplo demonstrando o uso de variaveis de condicao e monitores
 
#include <pthread.h>
#include <stdio.h>

typedef struct {
    pthread_mutex_t     mutex;  //protege o valor de value
    pthread_cond_t      cond;   //variavel de condicao
    int                 value;  //secao critica gerenciada por mutex */
} cond_struct_t;

cond_struct_t data = {
    PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0};

//inicializacao:
//status de cond
void * wait_thread (int *hibernation)
{
    int status;

    sleep (*hibernation);

    /****** ENTRADA NO MONITOR *******/
    status = pthread_mutex_lock (&data.mutex);
    if (status != 0) {fprintf(stderr,"Erro em P() da S.C.\n"); exit(-1);}
    printf("int status:%d\n",status); 
    data.value = 1; //inicializa contador
    status = pthread_cond_signal (&data.cond);
    printf("int status:%d\n",status); 
    if (status != 0) {fprintf(stderr,"Erro em wait cond\n"); exit(-1);}
    printf("int status:%d\n",status); 
    status = pthread_mutex_unlock (&data.mutex);
    printf("int status:%d\n",status); 
    if (status != 0) {fprintf(stderr,"Erro em V() da S.C.\n"); exit(-1);}
    /******* SAIDA DO MONITOR ************/

    return NULL;
}

int main (int argc, char *argv[])
{
    int status;
    pthread_t wait_thread_id;
    struct timespec timeout;
    int hibernation = 10;//n de seg que wait_thread sleep antes
			 //de sinalizar a variavel de condicao

    
    if (argc > 1) hibernation = atoi (argv[1]);

    // Cria wait_thread.
     
    status = pthread_create (&wait_thread_id, NULL, (void *) wait_thread, &hibernation);
    if (status != 0) {fprintf(stderr,"ERRO na criacao de wait_thread\n"); exit(-1);}
    printf("int status main:%d\n",status); 
    
    //espera que a variavel de condicao seja sinalizada por the wait_thread
    
    /***** ENTRADA NO MONITOR **********/
    status = pthread_mutex_lock (&data.mutex);
    if (status != 0) {fprintf(stderr,"ERRO em P() no mutex thread_main\n"); exit(-1);}
    printf("int status main:%d\n",status); 
    while (data.value == 0) {
        status = pthread_cond_wait(&data.cond, &data.mutex);
        printf("int status main:%d\n",status); 
    	}
    if (status != 0) {fprintf(stderr,"Erro no Wait thread_main\n"); exit(-1);}
    printf("int status main:%d\n",status); 
    status = pthread_mutex_unlock (&data.mutex);
    if (status != 0) {fprintf(stderr,"Erro V() no mutex thread_main\n"); exit(-1);}
    printf("int status main:%d\n",status); 
    /******* SAIDA DO MONITOR **************/

    printf("VARIAVEL DE condicao foi sinalizada, data.value=%d\n",data.value);
    return 0;
}
