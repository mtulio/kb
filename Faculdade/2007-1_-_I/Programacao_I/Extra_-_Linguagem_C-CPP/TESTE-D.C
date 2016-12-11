/*Marco Tulio*/
/*A conferir, pois o uso de trunc é apenas para arredondar o numero*/

# include <stdio.h>
# include <math.h>
int main(void){
  float n, qd;
  printf("\nDigite um numero inteiro positivo: ");
  scanf("%f", &n);
  qd = sqrt(n);
  if(qd == trunc(qd)){
  printf("\nO quadrado perfeito de %.0f é %.0f.\n",n,qd);
  }
  else{
  printf("\nO número %.0f não é quadrado perfeito.\n",n);
  }
  getchar();
  getchar();
} 
