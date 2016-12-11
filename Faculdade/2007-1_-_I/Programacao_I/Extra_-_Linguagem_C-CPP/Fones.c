#include <stdio.h>
#include <string.h>
#include <math.h>
int main (void){
  char E[2];
  printf("\n\nO que deseja executar?\n\n (A)Agenda;\n (C)Calcular Médias;\n\n Informe: ");
  scanf("%s", &E);
  if(strcmp(E,"A")==0){
    char N[10];
    printf("\n\tDigite o nome a ser localizado: ");
    scanf("%s", &N);
    if((strcmp(N,"Fernando")==0)||(strcmp(N,"Joao")==0)||(strcmp(N,"Tulio")==0)){
      if(strcmp(N,"Fernando")==0){
        char D[2];
        printf("\n\tResidencia (R), ou celular (C)? ");
        scanf("%s", &D);
        if(strcmp(D,"R")==0){
          printf("\n\t\tO numero desejado é (62)33571378\n\n");}
        if(strcmp(D,"C")==0){
          printf("\n\t\tO numero desejado é (62)81184098\n\n");}
      }
      if(strcmp(N,"Joao")==0){
        char J[2];
        printf("\n\tResidencia (R), ou Celular (C)? ");
        scanf("%s", &J);
        if(strcmp(J,"R")==0){
          printf("\n\t\tO número Residencial é (62)33572274\n\n");}
        if(strcmp(J,"C")==0){
          printf("\n\t\tO número do celular é (62)81548965\n\n");}
      }
      if(strcmp(N,"Tulio")==0){
        char M[2];
        printf("\n\tVivo (V), ou TIM, vivier sem fronteiras, (T)? ");
        scanf("%s", &M);
        if(strcmp(M,"V")==0){
          printf("\n\t\tO número desejado é (62)99247727\n\n");}
        if(strcmp(M,"T")==0){
          printf("\n\t\tO número desejado(Você tem bom gosto), é (62)81156292\n\n");}
      }
    }
    else{printf("\n\t\tO nome %s não consta na lista.\n\n", N);}
  }
    if(strcmp(E,"C")==0){
      float a, b, c, d, M, V, K, P;
      int MD;
      char W[15], SN[20], G[15], T[35], CUR[35];
      printf("\n\tQual o curso?\n\n\t\t(1)Eng. Computação;\t\t(2)Direito;\n\t\t(3)Eng. Civil;\t\t\t(4)Medicina;\n\t\t(5)Propaganda e Pubicidade;\t(6)Farmacia;\n\t\t(7)Eng. Alimentos;\t\t(8)Relações Internacionais;\n\n\tInforme sendo o numéro ou o nome do curso: ");
      scanf("%s", &T);
      printf("\n\tDigite o 1º nome do Aluno: ");
      scanf("%s", &W);
      printf("\tDigite o SobreNome: ");
      scanf("%s", &SN);
      strcat(W," ");
      strcat(W,SN);
      printf("\n\tQuantidade de Crédito Matriculado? ");
      scanf("%f", &P);
      printf("\n\tDigite a nota da P1: ");
      scanf("%f", &a);
      printf("\tDigite a nota da P2: ");
      scanf("%f", &b);
      printf("\tDigite a nota da P3: ");
      scanf("%f", &c);
      printf("\tDigite a nota da P4: ");
      scanf("%f", &d);
      printf("\n\t\tQual a Média a ser calculada?\n\t\t(1)Aritmética;\n\t\t(2)Harmônica;\n\t\t(3)Geométrica;\n\t\t(4)Quadrática;\n\n\t\tInforme: ");
      scanf("%i", &MD);
      if(MD==1){
	M=(a+b+c+d)/4.0;
	strcpy(G,"Aritmética");
      }
      if(MD==2){
	M=4.0/((1.0/a)+(1.0/b)+(1.0/c)+(1.0/d));
	strcpy(G,"Harmônica");
      }
      if(MD==3){
	M=pow((a*b*c*d),(1.0/4.0));
	strcpy(G,"Geométrica");
      }
      if(MD==4){
	M=sqrt(((pow(a,2.0))+(pow(b,2.0))+(pow(c,2.0))+(pow(d,2.0)))/4.0);
	strcpy(G,"Quadrática");
      }
      printf("\n\t\t\tA Média %s é %.1f\n\n", G, M);
      if((MD<1)||(MD>4)){
	printf("\n\t\t\t\tOpção Invalida\n\n");}
      if((strcmp(T,"1"))==0||(strcmp(T,"Eng.Computação"))==0){
	K=P*30.0;
	strcpy(CUR,"Eng. Computação");
      }
      if((strcmp(T,"2"))==0||(strcmp(T,"Direito"))==0){
	K=P*23.1;
	strcpy(CUR,"Direito");
      }
      if((strcmp(T,"3"))==0||(strcmp(T,"Eng.Civil"))==0){
	K=P*28.8;
	strcpy(CUR,"Eng. Civil");
      }
      if((strcmp(T,"4"))==0||(strcmp(T,"Medicina"))==0){
	K=P*115.4;
	strcpy(CUR,"Medicina");
      }
      if((strcmp(T,"5"))==0||(strcmp(T,"Propaganda e Pubicidade"))==0){
	K=P*22.7;
	strcpy(CUR,"Propaganda e Publicidade");
      }
      if(M>=8.0){
	printf("O Aluno %s foi aprovado com um ótima média, Parabens!\n", W);
	V=K*0.5;
	printf("Sendo a mensalidade do curso de %s, de %.2fR$\n\n", CUR, V);
      }
      if((M>=6.5)&&(M<8.0)){
	printf("O Aluno %s foi aprovado. Você tem capacidade para melhorar, ESTUDE!!!\n\n", W);
	V=K*0.7;
	printf("Sendo a mensalidade do curso de %s, de %.2fR$\n\n", CUR, V);
      }
      if((M>=5.0)&&(M<6.5)){
	printf("O aluno %s foi aprovado, porem séra um péssimo proffisional. ESTUDE MAIS... BEM MAIS!\n\n", W);
	V=K*0.9;
	printf("Sendo a mensalidade do curso de %s, de %.2fR$\n\n", CUR, V);
      }
      if(M<5.0){
	printf("%s, você REPROVOU! Um péssimo exemplo! Matricule-se novamente... ESTUDA VAGABUNDO!!!\n\n", W);
	V=K;
	printf("Sendo a mensalidade do curso de %s, de %.2fR$\n\n", CUR, V);
      }
    }
    getchar();
    getchar();
}
