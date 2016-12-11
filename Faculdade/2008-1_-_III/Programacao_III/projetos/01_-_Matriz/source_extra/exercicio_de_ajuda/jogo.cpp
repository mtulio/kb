#include <stdio.h>

#define MAX 102 /* Tamanho maximo do jogo + 2 para a moldura */
#define VERD  1
#define FALSO 0

int inicio(int A[][MAX], int i, int j);
/* prototipo da funcao inicio, declarada no fim do arquivo */

int main() {
  int A[MAX][MAX], m, n;
  int i, j, cont;

  printf("Digite dimensoes do jogo: ");
  scanf("%d %d", &m, &n);

  /* Leitura da matriz */
  printf("Digite a matriz linha por linha\n");
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      scanf("%d",&A[i][j]);

  /* Preparacao de uma moldura para facilitar as contas */
  for (j = 0; j <= n+1; j++){
    A[0][j] = -1;
    A[m+1][j]= -1;
  }
  for (i = 1; i <= m; i++){
    A[i][0] = -1;
    A[i][n+1] = -1;
  }

  /* Maos a obra */
  cont=0;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (inicio(A,i,j) == VERD){
	cont++;
        A[i][j] = cont;
      }

  /* Impressao do resultado */
  printf("Matriz resultante:\n");
  for (i = 1; i <= m; i++){
    for (j = 1; j <= n; j++)
      printf("%3d",A[i][j]);
    printf("\n");
  }
getchar();
getchar();
  return 0;
}

int inicio(int A[][MAX], int i, int j) {

  if (A[i][j] != -1 && ((A[i-1][j] == -1 && A[i+1][j] != -1) ||
			(A[i][j-1] == -1 && A[i][j+1] != -1))){
    return VERD;
    getchar();
getchar();
}  
  else {
    return FALSO;
getchar();
getchar();
}
}
