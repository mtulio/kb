#include "classeCPF.h"

bool CPF::validar(unsigned long numeroCPF, unsigned int dV)
{//Iniciando o metodo validar
	unsigned long numeroAux;
	unsigned int soma, dv1, dv2, dvf, coeficiente;
	numeroAux = numeroCPF;
	soma=0;
	for (coeficiente=2;numeroAux; coeficiente++) {//Abrindo o laço da 1 soma
		soma = soma + (numeroAux%10)*coeficiente;
		numeroAux = numeroAux/10;
	}//fechado o laço da 1 soma
	dv1 = 11 - soma%11;
	if (dv1>9) dv1 = 0;
	soma = dv1*2;
	numeroAux = numeroCPF;
	for (coeficiente=3; numeroAux; coeficiente++){//Inicando o for da 2 soma
		soma = soma + (numeroAux%10)*coeficiente;
		numeroAux = numeroAux/10;
	}//Fechando o laço da 2 soma
	dv2 = 11 - soma%11;
	if (dv2>9) dv2=0;
	dvf = dv1*10 + dv2;
	if (dV == dvf) return true;
	return false;

}//FIm do metodo validar

bool CPF::atribuir(unsigned long numeroCPF, unsigned int dV)
{//Inicio da metodo atribuir
	if (validar(numeroCPF, dV)) {//Se o validar for verdadeiro...
		numero = numeroCPF;
		digitoVerificador = dV;
		return true;
	}//Fim do retorno verdadeiro validar 
	else {/*Colocando essas atribuições, evita problemas na hora de imprimir o CPF
			* quando o CPF for validado c/ retorno false
			*/
			numero = numeroCPF;
			digitoVerificador = dV;		
			return false;
	}
}//Fim do metodo atribuir

void CPF::obter(unsigned long &numeroCPF, unsigned int &dV)
{//Inicio do metodo obter
	numeroCPF = numero;
	dV = digitoVerificador;
}//Fim do metodo obter

CPF::CPF(){}//Construtor 
CPF::~CPF(){}//Destrutor
