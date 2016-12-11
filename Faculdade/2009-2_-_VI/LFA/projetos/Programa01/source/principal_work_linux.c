#include<stdio.h>
/*
PASSOS
1 - Ler a cadeia inicial
2 - Validar a cadeia
3 - Calcular a cadeia
4 - Imprimir o resultado

Dicas Professor:
- criar laço infinito
- sair do laço infinito pelo return no momento certo
- usar com economia variaveis globais

*/

//*************************************************************
//*********** IINICIO DO PROGRAMA PRINCIPAL
int main (void)
{
//Apresentação
system("clear");
printf("\n* Materia: Linguagens Formais e Automatos");
printf("\n* Professor: Iamar");
printf("\n* Aluno:Marco Tulio");
printf("\n\n\t** Prorgama 01 - Leitura de um AFD Minimizado. Pg 82 livro **\n\n");

//**************************** PASSO 1 *********
// LEITURA E VALIDACAO DA PALAVRA DE ENTRADA
// DIVIDIR CADA RESPONSABILIDADE EM UM METODO PARA FACILITAR A SAIDA DO PROGRAMA
//**********************************************

//OPção para pode ler outra palavra
int opcao=1;

while(opcao==1)
{//inicio laco do menu principal

        printf("------------------------------------------------------------------");
        printf("\nAlfabeto Valido: {a,b}, sendo A==a e B==b...");
        char palavra[100];
        printf("\nInforme a cadeia de em concordancia com o alfabeto: ");
        scanf("%s", &palavra);

        //printf("\nCadeia informada: %s \n",palavra);


//varrendo a palavra pra descobrir a qtd de caracteres
        int contPal=0;
        for(contPal=0; palavra[contPal] != '\0' ; contPal++){
                //printf("\n[%i]=%i",contPal,palavra[contPal]);
        }
  
//teste      
//        printf("\n\tA palavra tem %i procedimentos!\n",contPal);



//********************* PASSO 2 **************
// VALIDANDO A CADEIA INFORMADA
//*********************************************
//validando a palavra de acordo com o alfabeto
        int i;
        for(i=0; i<contPal; i++)
        {
                //Forçando todas palavras serem minusculas
                if(palavra[i] < 97) palavra[i]+=32;

                //validando se a palavra informada condiz com o alfabeto
                if(palavra[i] != 'a'){//if 1
                        if(palavra[i] != 'b' ){//if 2
                                printf("\nA palavra informada não faz parte do alfabeto.");
                                printf("\nA seguinte ambiguidade foi encontrada: %c",palavra[i]);
                                printf("\nO programa está sendo finalizado!\n\n");
                                exit(0);
                        }//fim if 2
                }//fim if 1
        }//fim validacao - for
        //ao final do ultimo laco a palavra foi validada
//Proximo procedimento é varrer os estados de acordo com a palavra informada.

//*******************  PASSO 3 ***********************************
// EXECUTAR A VARREDURA PELOS ESTADOS EQUIVALENTES DO AFD REDUZIDO
//*****************************************************************
//Varrendo o AFD Reduzido
/*
O Proximo laco será executado se varrer toda a palavra ete chegar no seu fim
*/

//chamada do metodo de calculo
        int resultado = calcular1oAFD(palavra, contPal);
        resultado = calcular2oAFD(palavra, contPal);

        printf("\n------------------------------------------------------------------");



// Finalização
        if(resultado==0) printf("\n\nPrograma executado sem erros.");
        else printf("\n\nOcorreram alguns erros inesperados no programa.");


        printf("\n\nDeseja executar o programa novamente informando outra palavra?\n\t(1)-sim\n\t(0)-Nao\n\tInforme:");
        scanf("%i",&opcao);
//        printf("\n\nOpcao: %i",opcao);
        
        if(opcao!=1){
             if(opcao!=0){ printf("\n\nOpção Invalida..."); opcao=0;}
        }
//        printf("\n\nOpcao: %i",opcao);
//imprimir caminho/resultados

}//fim do while
//fim laco do menu principal


//******************* FINALIZANDO O PROGRAMA
//finalizar programa
        printf("\nFinalizando Programa!\n");
}//fim main
//********** FIM DO PROGRAMA PRINCIPAL


//************* CALCULANDO O PRIMEIRO EXERCICIO 

//valor de retorno inteiro devido ao tratamento de erros.
int calcular1oAFD(char palavra[],int contPal)
{
//Apresentacao:
printf("------------------------------------------------------------------");
printf("\n\t***Executando o Primeiro Exercicio.\nCaracteristicas:\n\tAlfabeto = a,b \n\tEstados = q0,q1,q2,q3 e q4\n\tEquivalencias:(q0),(q12) e (q34)\n");
        int i;
        int autFinal=0;
        int estadoAtual=0;//defini o estado inicial, neste caso o q0
        for(i=0; i<contPal; i++){

                //Testes                
                //printf("\n[%i]=%c",i,palavra[i]);
                //printf("\nautAtual: %i",estadoAtual);

                switch(palavra[i]){
                        case 'a':
                        {//inicio case a
                                switch(estadoAtual){
                                        case 0:
                                        {
                                                 if(palavra[i+1]== '\0'){
                                                        printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                        printf("\nEstado Terminado = (q0).");
                                                        printf("\n(q0) não são estados finais!\n\n");
                                                        return 0;
                                                        //exit(0);
                                                }//fim if1
                                                else 
                                                        estadoAtual=12;
                                        break;
                                        }//fim case 

                                        //*************INICIO CASE 12
                                        case 12:
                                        {
                                        //verficando se a proxima palavra é nula, se afirmativo este é a ultima leitura, entao:
                                        //entoa terminara no proximo estado
                                          if(palavra[i+1]== '\0'){
                                             estadoAtual=34;
                                             printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                             printf("\nEstado Terminado = (q%i).",estadoAtual);
                                             printf("\n(q%i) são estados finais!.",estadoAtual);//referente a q34
                                             return 0;                                             
                                                //exit(0);
                                          }//fim if1
                                        else 
                                           estadoAtual=34; //estado q12 processando 'a' vai para q34
     
                                        break;
                                        }//fim case 
        
                                        //*************INICIO CASE 34
                                        case 34:
                                        {
                                                if(palavra[i+1]== '\0'){
                                                     estadoAtual=34;
                                                     printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                     printf("\nEstado Terminado = (q%i).",estadoAtual);
                                                     printf("\n(q%i) são estados finais!.",estadoAtual);//referente a q34
                                                     return 0;
                                                     //exit(0);
                                                }//fim if1
                                                else
                                                   estadoAtual=34;//estado q34 processando 'a' vai para ele mesmo
                                        break;
                                        }//fim case 
                                         
                                        default:
                                        {
                                                printf("\n\nErro inesperado dentro da verificao da palavra 'a'.\n\n");
                                                return (-1); //exit(0);
                                        break;}

                                }//fim switch p estadoAtual
                        
                        //********** FIM CASE 'a'
                        break;
                        }//fim case 'a'
                        
                        //INICIO CASE 'b'
                        case 'b':
                        {
                                switch(estadoAtual){
                                        case 0:
                                        {
                                                //tratando a condicao dde que q0 nao lê 'b' 
                                             printf("\nNenhuma Ação. \nO Automato (q0) não pode ler a palavra 'b'!");
                                             printf("\nEstado Terminal = (q0)."); 
                                             printf("\n(q0) não são estados finais!\n\n");
                                             return(0);//exit(0);
                                        break;
                                        }//fim case 

                                        //*************INICIO CASE 12
                                        case 12:
                                        {
                                                if(palavra[i+1]== '\0'){
                                                     estadoAtual=12;
                                                     printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                     printf("\nEstado Terminado = (q%i).",estadoAtual);
                                                     printf("\n(q%i) não são estados finais!.\n",estadoAtual);//referente a q34
                                                     return(0);//exit(0);
                                                }//fim if1
                                        else
                                                estadoAtual=12; //estado q12 processando b fica nele mesmo.
     
                                        break;
                                        }//fim case  12
        
                                        //*************INICIO CASE 34
                                        case 34:
                                        {
                                                if(palavra[i+1]== '\0'){
                                                     estadoAtual=12;
                                                     printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                     printf("\nEstado Terminado = (q%i).",estadoAtual);
                                                     printf("\n(q%i) não são estados finais!.\n",estadoAtual);//referente a q34
                                                     return(0); //exit(0);
                                                }//fim if1
                                                //se nao for a ultima leitura o estado q34 ao ler 'b' vai para o estado q12                                                
                                                else estadoAtual=12;

                                        break;
                                        }//fim case 
                                         
                                        default:
                                        {
                                                printf("\n\nErro inesperado dentro da verificao da palavra 'b'.\n\n"); 
                                                return (-1); //exit(0);
                                        break;}

                                }//fim switch p estadoAtual - PROCESSANDO 'b'
                        break;
                        }//fim case b - switch1
                        default: //default switch principal
                        {
                                printf("\n\tErro inesperado! <Switch-Default>\n");
                                return (-1); //exit(0);
                        }//fim default
                }//fim switch 01
        }//fim for
}//fim do caluclo do 1o AFD
//****** FIM DO METODO PARA LER O 1 AFD MINIMIZADO
//*************************************************************

//*************************************************************
//****** Metodo para ler a Cadaeia do 2º AFD Minimizado.
//*************************************************************

int calcular2oAFD(char palavra[],int contPal)
{
printf("\n------------------------------------------------------------------");
printf("\n\t***Executando o Segundo Exercicio.\nCaracteristicas:\n\tAlfabeto = a,b \n\tEstados = q0,q1,q2,q3,q4 e q5\n\tEquivalencias:(q015) e (q234)\n");
        int i;
        //int autFinal=0;
        int estadoAtual=15;//defini o estado inicial, neste caso o q0
        //Os estados q0,q1,q5 e q2,q3,q4 são equivalentes.
        for(i=0; i<contPal; i++){

                //Testes                
                //printf("\n[%i]=%c",i,palavra[i]);
                //printf("\nautAtual: %i",estadoAtual);

                switch(palavra[i]){
                        case 'a':
                        {//inicio case a
                                switch(estadoAtual){
                                        
                                        //lendo os estados equivalentes q0,q1,q5                                        
                                        case 15:
                                        {
                                                 if(palavra[i+1]== '\0'){
                                                        estadoAtual=15;                                                        
                                                        printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                        printf("\nEstado Terminado = (q0%i).",estadoAtual);
                                                        printf("\n(q0%i) não são estados finais!\n\n",estadoAtual);
                                                        return 0;
                                                        //exit(0);
                                                }//fim if1
                                                else 
                                                        estadoAtual=15;
                                        break;
                                        }//fim case 

                                        //*************INICIO CASE 234
                                        //lendo os estados equivalentes q2,q3,q4
                                        case 234:
                                        {
                                        //verficando se a proxima palavra é nula, se afirmativo este é a ultima leitura, entao:
                                        //entoa terminara no proximo estado
                                          if(palavra[i+1]== '\0'){
                                             estadoAtual=234;
                                             printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                             printf("\nEstado Terminado = (q%i).",estadoAtual);
                                             printf("\n(q%i) são estados Finais!.",estadoAtual);
                                             return 0;                                             
                                                //exit(0);
                                          }//fim if1
                                        else 
                                           estadoAtual=234; //estado q234 processando 'a' fica nele mesmo
     
                                        break;
                                        }//fim case 

                                        default:
                                        {
                                                printf("\n\nErro inesperado dentro da verificao da palavra 'a'.\n\n");
                                                return (-1); //exit(0);
                                        break;}
                                }//fim switch p estadoAtual
                        //********** FIM CASE 'a'
                        break;
                        }//fim case 'a'
                        
                        //INICIO CASE 'b'
                        case 'b':
                        {
                                switch(estadoAtual){

                                        //*************INICIO CASE 12
                                        //lendo os estados equivalentes q0,q1,q5
                                        case 15:
                                        {
                                                //se a proxima leitura for nula será encerrado aki.
                                                if(palavra[i+1]== '\0'){
                                                     estadoAtual=234;
                                                     printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                     printf("\nEstado Terminado = (q%i).",estadoAtual);
                                                     printf("\n(q%i) são estados Finais!.\n",estadoAtual);
                                                     return (0);
                                                        //exit(0);
                                                }//fim if1
                                        else
                                                estadoAtual=234; //estado q015 processando b vai para q234
     
                                        break;
                                        }//fim case  12
        
                                        //*************INICIO CASE 34
                                        //lendo os estados equivalentes q2,q3,q4                                        
                                        case 234:
                                        {
                                                //condicao de que ao ler b no estado q234 ira mudar p o estado q015
                                                //se a proxima leitura for nula será encerrado aki.
                                                if(palavra[i+1]== '\0'){
                                                     estadoAtual=15;
                                                     printf("\nTerminando a leitura por ser a ultima palavra da fita!");
                                                     printf("\nEstado Terminado = (q0%i).",estadoAtual);
                                                     printf("\n(q0%i) não são estados Finais!.\n",estadoAtual);
                                                     return (0); //exit(0);
                                                }//fim if1
                                                //se nao for a ultima leitura o estado q234 ao ler 'b' vai para o estado: q12                                                
                                                else estadoAtual=15;

                                        break;
                                        }//fim case 
                                         
                                        default:
                                        {
                                                printf("\n\nErro inesperado dentro da verificao da palavra 'b'.\n\n"); 
                                                return (-1); //exit(0);
                                        break;}

                                }//fim switch p estadoAtual - PROCESSANDO 'b'
                        break;
                        }//fim case b - switch1
                        default: //default switch principal
                        {
                                printf("\n\tErro inesperado! <Switch-Default>\n");
                                return (-1); //exit(0);
                        }//fim default
                }//fim switch 01
        }//fim for
}//fim calcular2oAFD

//****** FIM DO METODO PARA LER O 2 AFD MINIMIZADO
