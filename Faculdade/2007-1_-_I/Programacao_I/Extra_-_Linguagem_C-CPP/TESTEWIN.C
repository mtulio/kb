/*Marco Tulio*/

//PESQUISAR...Como limpar lixos do teclado que vem no getchar?!!!

#include<stdio.h>
#include<string.h>

main()
{
 char exe[8] = "ex", opcao[3];
 
 while((exe[2]!='0') && (exe[3]!='0'))
  {
   printf ("\nBem Vindo Marco Tulio\n\n");
   printf ("\n\t\tProgramação I - Lista 02\n\n");
   printf ("(01)-Exercicio 01\t(02)-Exercicio 02\t(03)-Exercicio 03\n(04)-Exercicio 04\t(05)-Exercicio 05\t(06)-Exercicio 06\n(07)-Exercicio 07\t(08)-Exercicio 08\t(09)-Exercicio 09\n(10)-Exercicio 10\t(11)-Exercicio 11\t(12)-Exercicio 12\n(13)-Exercicio 13\t(14)-Exercicio 14\t(15)-Exercicio 15\n(16)-Exercicio 16\t(17)-Exercicio 17\t(18)-Exercicio 18\n(19)-Exercicio 19\t(20)-Exercicio 20\t(21)-Exercicio 21\n(22)-Exercicio 22\t(23)-Exercicio 23\t(24)-Exercicio 24\n(25)-Exercicio 25\t(26)-Exercicio 26\t(27)-Exercicio 27\n(28)-Exercicio 28\t(29)-Exercicio 29\t(30)-Exercicio 30\n(31)-Exercicio 31\t(32)-Exercicio 32\t(33)-Exercicio 33\n(34)-Exercicio 34\t(35)-Exercicio 35\t(36)-Exercicio 36\n(37)-Exercicio 37\t(38)-Exercicio 38\t(39)-Exercicio 39\n(40)-Exercicio 40\t(41)-Exercicio 41\t(42)-Exercicio 42\n(43)-Exercicio 43\n(00)-EXIT\n\nQual exercicio vc deseja executar?: ");
   scanf ("%s", &opcao);

//Concatenei o numero digitado na posição 0 [1º numero] do vetor getchar e comparei com a posição 2 do vetor exe //
   exe[2]=opcao[0];

//Concatenei o numero digitado na posição 1 [2º numero] do vetor getchar e comparei com a posição 3 do vetor exe //
   exe[3]=opcao[1];
 
   if((exe[2]==0) && (exe[3]==0)) return; /*O comando return, retorna ao OS*/
   if((exe[2]!=0) && (exe[3]!=0)) system(&exe); /*O comando system executa comandos do terminal*/
   
  }

  fflush(stdin); //limpa buffet do teclado - Windows
  //__fpurge(stdin); //limpa buffet do teclado - Linux
  getchar();  
}

