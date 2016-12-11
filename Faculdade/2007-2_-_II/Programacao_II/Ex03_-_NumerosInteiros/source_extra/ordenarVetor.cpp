#include<iostream>
#include<string>
using namespace std;

int main (void){
int tamanho;


cout<<"digite o tamanho do vetor";
cin>>tamanho;

string vet[tamanho];

for(int i=0; i<tamanho; i++){
        cout<<i<<" - nome: ";
        cin>>vet[i];
}
string nome1, nome2, nomeAux;
for(int i=0; i<tamanho; i++){
        for(int j=i+1; j<tamanho; j++){
                nome1=vet[i];
                nome2=vet[j];
                if(nome1[0]>96) nome1[0]-=32;
                if(nome2[0]>96) nome2[0]-=32;
                if(nome1[0]>nome2[0]){
                            nomeAux=vet[i];
                            vet[i]=vet[j];
                            vet[j]=nomeAux;
                            cout<<"ENTREI"<<endl;
                }
        }
}          


for(int i =0; i<tamanho; i++){
        cout<<endl<<i<<" - nome: "<<vet[i]<<endl;
}


getchar();
getchar();

}
