#include<iostream>
#include<iomanip>
#include"classeInterface.h"
#include"classeConjunto.h"
using namespace std;

/* Este metodo tem a funcao de ler todos os elementor que o usuario digitar*/
void Interface::lerVetor(Conjunto &Vet)
{//inicio
         int i=0, elemento=0;
         for(int i=0; i<Vet.obterTamanho();){//1° repita
             cout<<"Vetor["<<i<<"]=";
             cin>>elemento;         
             if(!Vet.atribuir(elemento)){//Se atribur retornar 0 ele n poderá impedir o usuario de digitar elementos repetidos
             	cout<<"  Elemento repetido, Digite novamente..."<<std::endl;}
             else i++;
         }//fim 1° repit
}//fim do metodo ler vetor

void Interface::escreverVetor(const Conjunto &Vet)
{//Inicio     
     cout<<"[ ";
     int elemento;
     for(unsigned int pos=0; pos<Vet.obterIndiceUso(); pos ++){
                Vet.obter(pos,elemento);
                cout<<elemento<<" ";  
     }
     cout<<"]";
     
}//Fim do metodo Escrever Vetor

/*
void Interface::escreverTodos(const Conjunto &VetA, const Conjunto &VetB)
{
     unsigned int tam;
     cout<<endl<<" _______________________________________________________________";   
     cout<<endl<<"|"<<setw(25)<< "VetA|";
     escreverVetor(VetA);
     cout<<endl<<"|"<<setw(25)<<"VetB|";
     escreverVetor(VetB);
     cout<<endl<<"|_______________________________________________________________";   
     //Chamada UNIAO Inicio
     cout<<endl<<"|"<<setw(25)<<"Uniao|"<<" \t";
     {
     tam = VetA.obterIndiceUso() + VetB.obterIndiceUso();
     Conjunto VetC(tam);
     VetC.uniao(VetA,VetB);     
     escreverVetor(VetC);
     }//Uniao FIM
     //Chamada Interseccao
     cout<<endl<<"|"<<setw(25)<<"Interseccao|"<<" \t";
     {
       if (VetA.obterIndiceUso()>VetB.obterIndiceUso()) tam=VetB.obterIndiceUso();
       else tam=VetA.obterIndiceUso();
       Conjunto VetC(tam);
       VetC.interseccao(VetA,VetB);
       escreverVetor(VetC);
     }//Interseccao FIM
     //Chamada Diferenca AB     
     cout<<endl<<"|"<<setw(25)<<"Diferenca(A - B)|"<<" \t";
     {
      tam = VetA.obterIndiceUso();
      Conjunto VetC(tam);
      VetC.diferenca(VetA,VetB);
      escreverVetor(VetC);                                 
     }//Diferenca AB FIM
     //Chamada Diferenca BA 
     cout<<endl<<"|"<<setw(25)<<"Diferenca(B - A)|"<<" \t";
     {
      tam = VetB.obterIndiceUso();
      Conjunto VetC(tam);
      VetC.diferenca(VetB,VetA);
      escreverVetor(VetC);                                 
     }//Diferenca BA FIM
     //Chamada Sub Conjunto AB
     cout<<endl<<"|"<<setw(25)<<"Sub-Conjunto A e B|";
     {
        tam=VetB.obterIndiceUso();
        Conjunto VetC(tam);
        if(VetC.subConjunto(VetA,VetB)) cout<<" A eh Sub-Conjnuto de B ";
     	  else cout<<" A nao eh Sub-Conjunto de B";                                                 
     }//SubConjunto AB FIM
     //Chamada Sub Conjunto BA
     cout<<endl<<"|"<<setw(25)<<"Sub-Conjunto B e A|";
     {
        tam=VetA.obterIndiceUso();
        Conjunto VetC(tam);
        if(VetC.subConjunto(VetB,VetA)) cout<<" B eh Sub-Conjnuto de A ";
     	  else cout<<" B nao eh Sub-Conjunto de A";     	                                                  
     }//Diferenca BA FIM
     //Chamada Identicos
     cout<<endl<<"|"<<setw(25)<<"Identicos|";
     {
      tam=VetA.obterTamanho();
      Conjunto VetC(tam);
      if(VetC.identicos(VetA,VetB)) cout<<" Os conjuntos sao identicos!!!";
        else {cout<<" Os Conjuntos nao sao identicos";}                                                
     }//Identicos FIM
     //Chamda Disjuntos
     cout<<endl<<"|"<<setw(25)<<"Disjuntos|";
     {
     if(VetA.obterTamanho()>VetB.obterTamanho()) unsigned int tam=VetA.obterTamanho();
       else unsigned int tam=VetB.obterTamanho();
     Conjunto VetC(tam);
     if(VetC.disjuntos(VetA,VetB)) cout<<" Os vetores(A e B) sao Disjuntos";
       else {cout<<" Os conjuntos(A e B) nao sao Disjuntos";}
     }  //Disjuntos FIM
   //Chamada Amplitude A
     cout<<endl<<"|"<<setw(25)<<"Amplitude A|";
     cout<<"\t"<<VetA.amplitude();//Amplitude A FIM                                                    
   //Chamada Amplitude A     
     cout<<endl<<"|"<<setw(25)<<"Amplitude B|";
     cout<<"\t"<<VetB.amplitude();//Amplitude B FIM
     //Chamada Produto Escalar
     cout<<endl<<"|"<<setw(25)<<"Produto Escalar (A e B)|";
     {
      int resultado=0;
      if(VetA.produtoEscalar(VetB,resultado)) cout<<"\t"<<resultado;
        else {cout<<" Produto Escalar Impossivel";}                                             
     }//Produto Escalar FIM
     //Chamada Vazio
     //{
      if(VetA.vazio()) cout<<endl<<" O conjunto A eh vazio";
        else cout<<endl<<" O conjunto A nao eh vazio";
      if(VetB.vazio()) cout<<endl<<" O conjunto B eh vazio";
        else cout<<endl<<" O conjunto B nao eh vazio";
    // }//Vazio FIM
     cout<<endl<<setw(1)<<"|"<<"________________________________________________________________";   
     cin.get();
}*/
