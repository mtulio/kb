
/* UNFINISHED - random number generator*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int element_init = 01;
unsigned int element_end = 60;
unsigned int matrix[6][10];

//#define RAND_MAX  60
unsigned int LAST=0;
unsigned int NI = (6-1);
unsigned int NJ = (10-1);

int get_random(void) {
	//RAND_MAX = 60;
	srand(time(NULL));
	int rand_n = rand() % 60;

	return rand_n;
}

unsigned int get_random_script(void) {
	char str_cmd[128] = "cat /dev/urandom| tr -dc '0-5' | fold -w 2 | head -n 1";
	char str_buf[1024];
	FILE *fd;

	fd = popen(str_cmd, "r");
    while (fgets(str_buf, 1024, fd) != NULL)
    //printf("%d", atoi(str_buf));
    return (atoi(str_buf));

}

int number_exist(unsigned int value) {
	//TODO
	//unsigned int value;
	for (int i=0; i < NI; i++ ) {
		for (int j=0; j< NJ; j++) {
			if (matrix[i][j] == value) {
//				printf("==dup[%d]==", value);
				return 1;
			}
		}
	}
	return 0;
}

unsigned int get_last_number(void)
{
	return LAST++;
}

void set_random_matrix(void) {

	unsigned int value, resp = 1;
	for (int i=0; i < 10 ; i++ ) {
		//printf("\n%d : ", i+1);
		for (int j=0; j<6; j++) {

			do {
				//value = rand() % 60;
				if ( (i==NI) && (j==NJ)) { // solve bug from last number
//					printf("=last=");
					value = get_last_number();
					if (number_exist(value) == 0)
						resp = 0;
					else
						resp = 1;
				}
				else {
//					printf("=x=");
					value = get_random_script();
					if (number_exist(value) == 0)
						resp = 0;
					else
						resp = 1;
				}
			} while (resp != 0);

			matrix[i][j] = value;
			if ( j == 0  )
				printf("\n(%d)", matrix[i][j]);
			else
				printf("(%d)", matrix[i][j]);
		}
	}
}



/*
  0.
0= 1 2 3 4
1= 4 5 6 7

 *
 * */
void show_matrix(void)
{
	// TODO

	for (int i=0; i < 10 ; i++ ) {
		printf("\n%d : ", i);
		for (int j=0; j<6; j++) {
			//printf("[%d][%d]=(%d)", i, j, matrix[i][j]);
			printf("(%d)", matrix[i][j]);
		}
	}
	printf("\n");
}

int main(void) {

	//printf("=%d\n", get_random());
	//printf("=", get_random_script());

	set_random_matrix();
//	show_matrix();

	printf("\n");
	exit(1);
}
