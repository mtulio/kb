/*Marco Tulio*/
/*A conferir, pois o uso de trunc � apenas para arredondar o numero*/

# include <stdio.h>
# include <math.h>
int main(void){
  float n, qd;
  printf("\nDigite um numero inteiro positivo: ");
  scanf("%f", &n);
  qd = sqrt(n);
  if(qd == trunc(qd)){
  printf("\nO quadrado perfeito de %.0f � %.0f.\n",n,qd);
  }
  else{
  printf("\nO n�mero %.0f n�o � quadrado perfeito.\n",n);
  }
  getchar();
  getchar();
} 
