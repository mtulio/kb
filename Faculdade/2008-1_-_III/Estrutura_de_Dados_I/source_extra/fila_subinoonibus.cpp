#include<iostream>
#include<string>

using namespace std;

int main (void){

    string palavra="subinoonibus";
    
    cout<<"Digite a palavra: ";
    getline(cin, palavra);
    
    /*cout<<palavra[0]<<endl;
    cout<<palavra[1]<<endl;
    cout<<palavra[2]<<endl;
    cout<<palavra[3]<<endl;
    cout<<palavra[4]<<endl;
    cout<<palavra[5]<<endl;
    cout<<palavra[6]<<endl;
    cout<<palavra[7]<<endl;
    cout<<palavra[8]<<endl;
    cout<<palavra[9]<<endl;
    cout<<palavra[10]<<endl;
    cout<<palavra[11]<<endl;
    cout<<palavra[12]<<endl;*/
    
    //cout<<endl<<"     AKII"<<endl;
    int tamanho=0;
    for(int i=0; palavra[i]!='\0'; i++){
            //cout<<endl<<"     AKII"<<endl;
            tamanho++;            
    }
    //cout<<tamanho<<endl;
    
    //cout<<endl<<"     AKII"<<endl;
    for(int i=0, j=tamanho-1; i<tamanho; i++, j--){
            
            if(palavra[i]!=palavra[j]){ cout<<"A palavra nao eh palindroma"<<endl;
                                       cin.get();
                                       return 0;}
    }
    cout<<endl<<"A palavra eh palindroma"<<endl;
    cin.get();


}
