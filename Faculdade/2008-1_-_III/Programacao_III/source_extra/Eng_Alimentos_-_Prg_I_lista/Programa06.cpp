#include<iostream>
#include<string>

int main (void){
    
    //DECLARANDO AS VARIAVEIS
    std::string nomeCliente, tipoPavimentacao;
    float valorPorMetro, area, totalAPagar;
    
    
    do{
       //LENDO AS INFORMACOES NECESSARIAS
       std::cout<<" Digite o nome do cliente: ";
       std::cin>>nomeCliente;
       std::cout<<" Digite o codigo do tipo de Pavimentacao(R1/R2/R3/R4): ";
       std::cin>>tipoPavimentacao;
       std::cout<<" Digite a area para ser pavimentada: ";
       std::cin>>area;
    
       //DESCOBRINDO O VALOR POR METRO COMPARANDO AO TIPO DE PAVIMENTACAO 
       // DADO NO EXERCICIO
       if(tipoPavimentacao=="R1") valorPorMetro = 120.00;
       else if(tipoPavimentacao=="R2") valorPorMetro = 150.00;
            else if(tipoPavimentacao=="R3") valorPorMetro = 250.00;
                 else if(tipoPavimentacao=="R4") valorPorMetro = 160.00;
                      else std::cout<<" Codigo de pavimentacao invalido! Digite novamente!"<<std::endl;
                   
    //enquanto nao digitar o codigo de pavimentacao certo o laco ira se repetir
    }while(tipoPavimentacao!="R1" && tipoPavimentacao!="R2" && tipoPavimentacao!="R2" && tipoPavimentacao!="R4");
    
    
    //CONDICAO PARA CALCULO DO DESCONTO DE 3% - DADO NO ENUNCIADO DO EXERCICIO
    if(area>250) valorPorMetro = valorPorMetro*0.97;    
    
    //CALCULANDO O VALOR A PAGAR
    totalAPagar = area*valorPorMetro;

    //IMPRIMINDO O RESULTADO
    std::cout<<" Nome do Cliente: "<<nomeCliente<<" \n";
    std::cout<<" Total a pagar: R$ "<<totalAPagar<<" \n";    
}//fim do main
