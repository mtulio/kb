#include<string>
#include<iostream>
#include"Automato.h"

using namespace std;

int main(void)
{
	string str1, str2, str3, str4;

	str1 = "987654";
	str2 = "-1";
	str3 = "marco";
	str4 = "*";

//	if(str2 > str1) cout<<"str2 e maior"<<endl;
//	else cout<<"str2 e menor"<<endl;

//	if(str1 > str3) cout<<"str1 e maior"<<endl;
//	else cout<<"str1 e menor"<<endl;

	cout<<"str1 = "<<str1<<endl;
	cout<<"str2 = "<<str2<<endl;
	cout<<"str3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;


	Automato automato;

	if(automato.isNumber(str1)) cout<<" A string str1 eh um numero!!!"<<endl;
	else cout<<"A string str1 nao eh um numero"<<endl;


	if(automato.isNumber(str2)) cout<<" A string str2 eh um numero!!!"<<endl;
	else cout<<"A string str2 nao eh um numero"<<endl;

	if(automato.isNumber(str3)) cout<<" A string str3 eh um numero!!!"<<endl;
	else cout<<"A string str3 nao eh um numero"<<endl;

	if(automato.isNumber(str4)) cout<<" A string str4 eh um numero!!!"<<endl;
	else cout<<"A string str4 nao eh um numero"<<endl;
}//fim main
