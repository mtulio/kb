//PESQUISAR...Como limpar lixos do teclado que vem no getchar?!!!

#include<stdio.h>
#include<string.h>

main()
{
 char exe[8] = "./ex";

 while((exe[4]!='0') && (exe[5]!='0'))
  {
   printf ("\nBem Vindo Marco Tulio\n\n");
   printf ("\n\t\tProgramação I - Lista 02\n\n");
   printf ("(01)-Exercicio 01\t(02)-Exercicio 02\t(03)-Exercicio 03\n(04)-Exercicio 04\t(05)-Exercicio 05\t(06)-Exercicio 06\n(07)-Exercicio 07\t(08)-Exercicio 08\t(09)-Exercicio 09\n(10)-Exercicio 10\t(11)-Exercicio 11\t(12)-Exercicio 12\n(13)-Exercicio 13\t(14)-Exercicio 14\t(15)-Exercicio 15\n(16)-Exercicio 16\t(17)-Exercicio 17\t(18)-Exercicio 18\n(19)-Exercicio 19\t(20)-Exercicio 20\nQual exercicio vc deseja executar?: ");

//Concatenei o numero digitado na posição 0 [1º numero] do vetor getchar e comparei com a posição 4 do vetor exe //
   exe[4]=getchar();

//Concatenei o numero digitado na posição 1 [2º numero] do vetor getchar e comparei com a posição 5 do vetor exe //
   exe[5]=getchar();
   if((exe[4]!='0') && (exe[5]!='0'))system(&exe);
  }

}

