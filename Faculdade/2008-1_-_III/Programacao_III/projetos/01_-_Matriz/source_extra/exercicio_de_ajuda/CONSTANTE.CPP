/* CONSTANTE.CPP - :Programa que calcula a �rea de uma circunfer�ncia de raio r. */ 

#include <iostream> 

#include <iomanip>

// Fun��o Principal 
using namespace std;
int main(void) 

{

const double PI = 3.141592; 

double raio; 

cout<<"\n Digite o raio da circunfer�ncia: ";

cin >> raio; 

double area = PI * raio * raio; 

cout << setiosflags( ios::fixed | ios::right); 

cout << " \n Area da circunfer�ncia: " << setprecision(2) << setw(12) << area; 
getchar();
getchar();
}