#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

/* the thread runs in this function */
void *runner(void *param); 

int main(int argc, char *argv[])
{
	int i, scope;
	pthread_t tid[NUM_THREADS]; 	/* the thread identifier */
	pthread_attr_t attr; 		/* set of attributes for the thread */

	/* get the default attributes */
	pthread_attr_init(&attr);

	/* first inquire on the current scope */
	if (pthread_attr_getscope(&attr, &scope) != 0)
		fprintf(stderr, "Unable to get scheduling scope\n");
	else {
		if (scope == PTHREAD_SCOPE_PROCESS)
			printf("PTHREAD_SCOPE_PROCESS\n");
		else if (scope == PTHREAD_SCOPE_SYSTEM)
			printf("PTHREAD_SCOPE_SYSTEM\n");
		else 
			fprintf(stderr,"Illegal scope value\n");
	}
	
	/* set the scheduling algorithm PROCESS or SYSTEM */
	/* On Linux and Mac OS X 10.3.4 systems, 
	 * only PTHREAD_SCOPE_SYSTEM is supported. 
	 * Solaris supports both. */
	if (pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM) != 0)
		fprintf(stderr, "Unable to set scheduling scope\n");
	
	/* now create the threads */
	for (i = 0; i < NUM_THREADS; i++) 
		pthread_create(&tid[i],&attr,runner,NULL); 

	/**
	 * Now join on each thread
	 */
	for (i = 0; i < NUM_THREADS; i++) 
		pthread_join(tid[i], NULL);
}

/**
 * The thread will begin control in this function.
 * Each thread will output its own version of "Hello World"
 */
void *runner(void *param) 
{
	/* do some work */

	pthread_exit(0);
}

