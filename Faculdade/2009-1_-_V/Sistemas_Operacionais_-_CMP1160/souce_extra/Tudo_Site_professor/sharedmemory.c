//Sistemas Operacionais - cmp1160
//Exemplo para verificacao do funcionamento da memoria compartilhada
//leitura: Advanced Linux Programming 2001 (cap 5)
//Exercicio da aula: contruir uma aplicação concorrente (com dois processo:pai-filho) 
//com objetivo de compartilhar um mesmo segmento de memoria. 
//Obs. Utilizar fork() e vfork() e verificar desafio da seção crítica.

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main ()
{
    int segment_id;
    char* shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x6400;

/* Alocacao do segmento de memoria */
segment_id = shmget (IPC_PRIVATE, shared_segment_size,
IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

/* Anexacao do segmento */
shared_memory = (char*) shmat (segment_id, 0, 0);
printf ("Memoria anexada no endereco %p\n", shared_memory);

/* Obtendo tamanho do segmento */
shmctl (segment_id, IPC_STAT, &shmbuffer);
segment_size = shmbuffer.shm_segsz;
printf ("tamanho do segmento: %d\n", segment_size);

/* Escreve uma string para memoria compartilhada*/
sprintf (shared_memory, "CMP1160 - SO");

/* Desanexa segmento compartilhado*/
shmdt (shared_memory);

/* Reanexa o segmento de memoria compartilhada em novo endereco */
shared_memory = (char*) shmat (segment_id, (void*) 0x5000000, 0);
printf ("Memoria anexada em %p\n", shared_memory);

/* Escreve a string armazenada na memoria compartilhada */
printf ("%s\n", shared_memory);

/* Desanexa o segmento compartilhado */
shmdt (shared_memory);
/* Desaloca o segmento compartilhado */
shmctl (segment_id, IPC_RMID, 0);
return 0;
}
