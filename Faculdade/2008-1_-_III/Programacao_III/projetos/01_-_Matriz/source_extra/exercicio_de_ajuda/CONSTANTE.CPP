/* CONSTANTE.CPP - :Programa que calcula a área de uma circunferência de raio r. */ 

#include <iostream> 

#include <iomanip>

// Função Principal 
using namespace std;
int main(void) 

{

const double PI = 3.141592; 

double raio; 

cout<<"\n Digite o raio da circunferência: ";

cin >> raio; 

double area = PI * raio * raio; 

cout << setiosflags( ios::fixed | ios::right); 

cout << " \n Area da circunferência: " << setprecision(2) << setw(12) << area; 
getchar();
getchar();
}
