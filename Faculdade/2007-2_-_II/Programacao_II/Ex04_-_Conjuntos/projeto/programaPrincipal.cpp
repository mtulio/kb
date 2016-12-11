#include<iostream>
#include<string>
#include<cstdlib> //biblioteca para o uso do comando system
#include"classeConjunto.h"
#include"classeInterface.h"
using namespace std;
int main (void)
{//inicio do programa principal
          unsigned int tam;
          system("cls");
          cout<<"\t\t**_Sistema_de_Conjuntos_**"<<endl;
          cout<<"Digrite o tamanho do vetor A: ";
          cin>>tam;
          Conjunto VetA(tam); 
          Interface::lerVetor(VetA);
          cout<<"Digite o tamanho do vetor B: ";
          cin>>tam;
          Conjunto VetB(tam);
          Interface::lerVetor(VetB);
          int opcao=12;
          while(opcao){//1 repita
                       system("cls");
                       cout<<"\t\t**_Sistema_de_Conjuntos_**";
                       cout<<endl<<" 1 - Uniao";
                       cout<<endl<<" 2 - Interseccao";
                       cout<<endl<<" 3 - Diferenca A-B";
                       cout<<endl<<" 4 - Diferenca B-A";
                       cout<<endl<<" 5 - Sub-Conjunto A-B";
                       cout<<endl<<" 6 - Sub-Conjunto B-A";
                       cout<<endl<<" 7 - Identicos";
                       cout<<endl<<" 8 - Disjuntos";
                       cout<<endl<<" 9 - Amplitude";
                       cout<<endl<<"10 - Produto Escalar (A e B)";
                       cout<<endl<<"11 - Vazio";
                       //cout<<endl<<"12 - Calcular Todos";
                       cout<<endl<<" 0 - Sair";// flag de saida
                       cout<<endl<<endl;
                       cout<<"\tDigite a opcao: ";
                       cin>>opcao;
                       system("cls");
                       cout<<"\t\t**_Sistema_de_Conjuntos_**";                       
                       switch(opcao){
                                     case 1:{//Uniao (todos os elementos)
                                          cout<<endl<<"Opcao: Uniao"<<endl;
                                          unsigned int tam = VetA.obterIndiceUso() + VetB.obterIndiceUso();
                                          Conjunto VetC(tam);
                                          VetC.uniao(VetA,VetB);
                                          //escrevendo o resultado
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          cout<<endl<<"  Vetor Uniao: ";
                                          Interface::escreverVetor(VetC);
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();cin.get();
                                          break;                                          
                                     case 2:{//Interseccao (Elementos em comum entre os 2 vetores)
                                          cout<<endl<<"Opcao: Interseccao"<<endl;                                          
                                          unsigned int tam;
                                          if (VetA.obterIndiceUso()>VetB.obterIndiceUso()) tam=VetB.obterIndiceUso();
                                          else tam=VetA.obterIndiceUso();
                                          Conjunto VetC(tam);
                                          VetC.interseccao(VetA,VetB);
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          cout<<endl<<"  Vetor Interseccao: ";
                                          Interface::escreverVetor(VetC);
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();cin.get();
                                          break;                                         
                                     case 3:{//Diferenca de A-B (Os que tiverem em A e não tiver em B)
                                          cout<<endl<<"Opcao: Diferenca A-B"<<endl;  
                                          unsigned int tam = VetA.obterIndiceUso();
                                          Conjunto VetC(tam);
                                          VetC.diferenca(VetA,VetB);
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);                                          
                                          cout<<endl<<"  Vetor Diferenca (A-B): ";
                                          Interface::escreverVetor(VetC);
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;                                          
                                     case 4:{//Diferença de B-A (Os que tiverem em B e não tiver em A)
                                          cout<<endl<<"Opcao: Diferenca B-A"<<endl; 
                                          unsigned int tam = VetB.obterIndiceUso();
                                          Conjunto VetC(tam);
                                          VetC.diferenca(VetB,VetA);
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);   
                                          cout<<endl<<"  Vetor Diferenca (B-A): ";
                                          Interface::escreverVetor(VetC);
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;  
                                     case 5:{//sub-conjunto A-B (Elementos que tiver em A, TEM q ter em B)
                                     	  cout<<endl<<"Opcao: Sub-Conjunto A-B"<<endl; 
                                          unsigned int tam=VetB.obterIndiceUso();
                                     	  Conjunto VetC(tam);
                                     	  cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          if(VetC.subConjunto(VetA,VetB)) cout<<endl<<"  A eh Sub-Conjnuto de B "<<endl;
                                     	  else cout<<endl<<"  A nao eh Sub-Conjunto de B"<<endl;
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;  
                                     case 6:{//sub-conjunto B-A (Elementos que tiver em B, TEM q ter em A)
                                          cout<<endl<<"Opcao: Sub-Conjunto B-A"<<endl; 
                                     	  unsigned int tam=VetA.obterIndiceUso();
                                     	  Conjunto VetC(tam);
                                     	  cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          if(VetC.subConjunto(VetB,VetA)) cout<<endl<<"  B eh Sub-Conjunto de A!!!"<<endl;
                                     	  else cout<<endl<<"  B nao eh Sub-Conjunto de A!!!"<<endl;
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;                                 
                                     case 7:{//conjuntos identicos (Elementos identicos, nao importa a ordem)
                                          cout<<endl<<"Opcao: Identicos"<<endl;
                                          unsigned int tam=VetA.obterTamanho();
                                          Conjunto VetC(tam);
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          if(VetC.identicos(VetA,VetB)) cout<<endl<<"  Os conjuntos sao identicos!!!"<<endl;
                                          else {cout<<endl<<"  Os Conjuntos nao sao identicos"<<endl;}
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;  
                                     case 8:{//Disjunto (Intersecção tem de ser = a zero!
                                          cout<<endl<<"Opcao: Disjuntos"<<endl;
                                          if(VetA.obterTamanho()>VetB.obterTamanho()) unsigned int tam=VetA.obterTamanho();
                                          else unsigned int tam=VetB.obterTamanho();
                                          Conjunto VetC(tam);
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          if(VetC.disjuntos(VetA,VetB)) cout<<endl<<"  Os vetores(A e B) sao Disjuntos"<<endl;
                                          else {cout<<endl<<"  Os conjuntos(A e B) nao sao Disjuntos"<<endl;}
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar...!!!"<<endl;
                                          cin.get();cin.get();
                                          break;                                         
                                     case 9:{//amplitude (diferença do maior pelo menor)
                                          cout<<endl<<"Opcao: Amplitude"<<endl;
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          cout<<endl<<"  A amplitude do Conjunto A eh: "<<VetA.amplitude();
                                          cout<<endl<<"  A amplitude do Conjunto B eh: "<<VetB.amplitude();
                                          }
                                          cout<<endl<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();cin.get();
                                          break;
                                     case 10:{//produto escalar (soma do produto da posição I do vetor A com a posição I do vetor B)
                                          cout<<endl<<"Opcao: Produto Escalar"<<endl;
                                          int resultado=0;
                                          cout<<endl<<"  VetA: ";
                                          Interface::escreverVetor(VetA);
                                          cout<<endl<<"  VetB: ";
                                          Interface::escreverVetor(VetB);
                                          if(VetA.produtoEscalar(VetB,resultado)) cout<<endl<<"  O produto escalar entre A e B eh: "<<resultado<<endl;
                                          else {cout<<endl<<"  Nao eh possivel fazer o produto escalar entre os dois conjuntos"<<endl;}
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();cin.get();
                                          break;  
                                     case 11:
                                          if(VetA.vazio()) cout<<endl<<" O conjunto A eh vazio";
                                          else cout<<endl<<" O conjunto A nao eh vazio";
                                          if(VetB.vazio()) cout<<endl<<" O conjunto B eh vazio";
                                          else cout<<endl<<" O conjunto B nao eh vazio";
                                          cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();cin.get();
                                          break;                                     
                                     /*case 12:{//calcular todos
                                          Interface::escreverTodos(VetA,VetB);                                          
                                          }
                                          cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                          cin.get();
                                          break;*/
                                     case 0:
                                          cout<<endl<<endl<<"Finalizando Programa..Tecle Enter..."<<endl;
                                          cin.get();cin.get();
                                          //exit(0); //retorna ao SO
                                          break;
                                     default:
                                             cout<<endl<<endl<<"\tOPCAO INVALIDA - TENTE NOVAMENTE!!!";
                                             cout<<endl<<"Pressione Enter pra continuar..."<<endl;
                                             cin.get();cin.get();
                                             /* Comando que faz uma pausa no programa
                                             e retorna imediatamente apos uma 
                                             tecla ser pressionada.*/
                                     break;
                       }//fim do switch
          }//fim do 1 repita
}//fim do programa principal
