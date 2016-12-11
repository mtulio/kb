#include<stdio.h>
#include<math.h>
main()
{//inicio do metodo capicua
 
	int i, j,n,temp, tmp2, qtd, den=0, pot;
	float den2;
    int vet[100];//valor maximo do vetor (ninguem vai dugitar um num > 100, soh se for doido...rsrs)

 printf ("Digite o valor de n: ");
 scanf ("%i", &n);
	
    //i=indice que vai calcular qtd de digitos
    i=0;
    //temp eh a var tem q vai calcular a qtd de digitos
    temp=n;
    while(temp>=10){
                    tmp2=temp/10;
                    temp=tmp2;
                    i++;
                    printf ("\n\tqtd dig %i\n",i);
    }
    i++;//essa condição eh pq para contar o ultimo digito de unidades
     printf ("\n\tqtd dig %i\n",i);
  
     //concatenando o valor n em um vetor
     j=i;
     pot=i-1;
    //printf("POTENCIA=%f",(pow(10,pot)));
    // vet=0;//iniciando a variavel vet
     while(j>0){
                den2=(pow(10,pot));
                
                den=den2;
                vet[i-j]=n/den;
                n=n%den;
                pot--;
                j--;
                
                //printf ("\nden=%i\nVet[i-j]=%i\nn=%i\npot=%i\nj=%i\n",den,vet[i-j],n,pot,j);
     }
    
     //comparando as diagonais do vetor (capicua)
     qtd=i;
     j=qtd-1;
     
     for(i=0; i!=j ; i++,j--) {
              if(vet[i]!= vet[j]){
                          printf ("\nNão eh capicua");
                          getchar();
                          getchar();
                          return 0;
               }
     }//fechando laço for
     
     printf ("\n\n\tEh capicua!\n");
 
 
 
 getchar();
 getchar();
 
 	//if(numero==n) printf ("O numero %i eh capicua!\n");
	//else ("O numero %i nao eh capicua!\n");;
}//fim do metodo capicua
/*
bool numeroNatural::capicua (unsigned long N)const//não altera os valores do objeto 
{//inicio do metodo capicua 
int i=0, a=0, numero=0, num ,n; 
do{
     N/10;
     i=i+1;
}while(N/10>0);
a=i
do{
     n=N/10 
     num=n%10*(pow(10,a));
     numero=num+numero;
     a=a-1;
}while(N/10>0);
if(numero==N) return(true);
else return (false);
}//fim do metodo capicua
*/
