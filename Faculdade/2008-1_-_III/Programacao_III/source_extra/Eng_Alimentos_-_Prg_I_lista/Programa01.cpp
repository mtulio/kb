#include<iostream>

int main(void)
{
    //DECLARANDO AS VARIAVEIS
    float N1, N2, N3, N4, soma;
    

    // INICIALIZANDO AS VARIAVEIS - APENAS AS QUE PRECISAM SER INICIALIZADAS
    soma = 0;
    // LENDO OS NUMEROS PARA A VERIFICACAO
    std::cout<<" Digite o 1o numeto: ";
    std::cin>>N1;
    
    std::cout<<" Digite o 2o numeto: ";
    std::cin>>N2;
    
    std::cout<<" Digite o 3o numeto: ";
    std::cin>>N3;
    
    std::cout<<" Digite o 4o numeto: ";
    std::cin>>N4;
    
    // VERIFICANDO OS TRES MAIORES E SOMANDO:
    // CASO N1 SEJA O MENOR NUMERO
    if((N1<N2) && (N1<N3) && (N1<N4)) soma = N2 + N3 + N4;
    
    // CASO N2 SEJA O MENOR NUMERO
    if((N2<N1) && (N2<N3) && (N2<N4)) soma = N1 + N3 + N4;
    
    // CASO N3 SEJA O MENOR NUMERO
    if((N3<N1) && (N3<N2) && (N3<N4)) soma = N1 + N2 + N4;
    
    // CASO N4 SEJA O MENOR NUMERO
    if((N4<N1) && (N4<N2) && (N4<N3)) soma = N1 + N2 + N3;
    
    // IMPRIMINDO A SOMA
    std::cout<<" Resultado da soma dos 3 maiores eh: "<<soma<<"\n";
}// FIM DO MAIN
