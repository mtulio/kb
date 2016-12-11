#ifndef AUTOMATO_H_
#define AUTOMATO_H_

#include<string>
#include<iostream>

#include"Persistencia.h"

//definindo o tamanho maximo da tabela de simbolos
#define tamMaxTabSimb 999

/* Identificadores de erros dos metodos
Ex.: Id-Aut<id>+msgErro
* 01 - iniciarAutomato()
* 02 - lerAutomato()
* 03 - regraSemantica1()
* 04 - regraSemantica2()
* 05 - gerarFonteEmC()
* 06 - getMsgErroLexico()
* 07 - getMsgErroSemantico()
* 08 - getElementoTabSimbolos()
* 09 - getTamTabSimbolos()
* 10 - qtdElementosLinha()
* 11 - tamanhoStr()
* 12 - isNumber()
* 13 - getEstadoAtual()
*/

class Automato{

private:
	//Atributos
	unsigned int estadoAtual;
	std::string tabelaSimbolos[999];
	unsigned int tamTabSimb;
	unsigned int posTabSimb;
	std::string nomeArquivoEmPortugol;
	std::string nomeArquivoEmC;
	
	
	//regras semanticas
	//so pode ser chamado apos validar uma variavel, ou seja passar pelo metodo validarVariavel	
/*03*/	std::string regraSemantica1(std::string token);
/*04*/	bool regraSemantica2(std::string token);

/*02*/	std::string lerAutomato(std::string token); //finalidade de percorrer o automato
/*05*/	std::string gerarFonteEmC(unsigned int estado, std::string token);

/*06*/	std::string getMsgErroLexico(int idErro); //finalidade de obter os erros lexicos, do automato
/*07*/	std::string getMsgErroSemantico(int idErro); //finalidade de obter os erros semanticos

/*08*/	std::string getElementoTabSimbolos(unsigned int pos){ return this->tabelaSimbolos[pos]; }	
/*09*/	unsigned int getTamTabSimbolos() { return this->tamTabSimb; }

/*10*/	unsigned int qtdElementosLinha(std::string linha);
/*11*/	unsigned int tamanhoStr(std::string str);
/*12*/	bool isNumber(std::string token);
	
public:
	
/*00*/	Automato(std::string nomeArquivoEmPortugol):
				nomeArquivoEmPortugol(nomeArquivoEmPortugol),
				estadoAtual(0),
				tamTabSimb(0),
				posTabSimb(0)
				{ 
					std::string tmp = nomeArquivoEmPortugol+".c";
					this->nomeArquivoEmC = tmp;
				}
	//~Automato(){ if(tabelaSimbolos[]) delete tabelaSimbolos[]; }
		
/*01*/	std::string iniciarAutomato();
	
/*13*/	unsigned int getEstadoAtual(){ return this->estadoAtual; }//obtem o estado atual
		
};//fim classe
//********************************************************************************************
/* 01 */
/*
* Finalidade de ler do arquivo(chamar o metodo q lê),
* Tratar a string lida e chamar o metodo lerAutomato
*/
std::string Automato::iniciarAutomato()
{
	//std::cout<<" Compilando : "<<nomeArquivoEmPortugol<<std::endl;
	Persistencia persistencia(this->nomeArquivoEmPortugol);

	//var aux para msg re retorno
	std::string msgRetorno;

	//std::cout<<"\n\t Teste de falha de seg..."<<std::endl;

	//testes da persistencia
	//std::cout<<"\t\tawl - Qtd total de linhas: "<<persistencia.getQtdTotalDeLinhas()<<std::endl;
	//std::cout<<"\t\tawl - Ultima Linha Lida: "<<persistencia.getUltimaLinhaLida()<<std::endl;
	
	std::string linhaQuebrada, strTemp, strTemp2;
	char chtemp;

	while(!persistencia.fimDoArquivo()){
		
		
		//std::cout<<"\n\tEstado Atual: "<<getEstadoAtual()<<std::endl;
		//std::cout<<"\n\tUltima linha lida: "<<persistencia.getUltimaLinhaLida();

		//testes da persistencia
		//std::cout<<"\t\tdwl - Qtd total de linhas: "<<persistencia.getQtdTotalDeLinhas()<<std::endl;
		//std::cout<<"\t\tdwl - Ultima Linha Lida: "<<persistencia.getUltimaLinhaLida()<<std::endl;
	
	
		//std::cout<<"\n\t Teste de falha de seg...whileFimFile"<<std::endl;
		std::string linha = persistencia.lerProxLinhaDoArquivo();
		//obtem a qtd de elementos em uma linha
		unsigned int qtdElementos = qtdElementosLinha(linha);
		
		//std::cout<<"\n\t Qtd de elementos linha("<<linha<<").="<<qtdElementos<<std::endl;
		//std::cout<<"\n\t Valor da linha: "<<linha<<"."<<std::endl;
		
		//verificando se a linha contem "(" e ")"
		int posPrimeiroParenteses = 0, 
			posSegundoParenteses = 0;
				
		//std::cout<<"\n\t Posicao primeiro parenteses:"<<posPrimeiroParenteses<<std::endl;
		//std::cout<<"\n\t Posicao segundo parenteses:"<<posSegundoParenteses<<std::endl;
		
		//verificando a existencia de parenteses e a posicao de cada
		for(int i=0; linha[i] != '\0'; i++){
			if(linha[i] == '(') posPrimeiroParenteses = i;
			if(linha[i] == ')') posSegundoParenteses = i;
		}//fim for
				
		//std::cout<<"\n\t Posicao primeiro parenteses:"<<posPrimeiroParenteses<<std::endl;
		//std::cout<<"\n\t Posicao segundo parenteses:"<<posSegundoParenteses<<std::endl;
		
		int caso=0; //1=nao tem (), 2=tem ()
		if((posPrimeiroParenteses ==0) && (posSegundoParenteses==0)) caso=1;
		else caso=2;
		
		unsigned int tamLinha=0;
		//obtendo o tamanho da linha
		for(int x=0; linha[x] != '\0';x++) {tamLinha++;}
		
		std::cout<<"Verificando a linha "<<persistencia.getUltimaLinhaLida()<<": "<<linha<<std::endl;
		
		switch(qtdElementos){
			
			case 0:{//nao existe nenhum elemento para ser lido na linha
				//return ("-1");
				break;
			}//fim case 0
		
			case 1:{//c1
					
				//msgRetorno = lerAutomato(linha);
				//if(msgRetorno!=("-1")) return ("iniA-c1. "+msgRetorno);
				int j,i;
				for(i=0,j=0; linha[i]!='\0'; i++,j++){
					linhaQuebrada = "";//str aux
					
					for(;((linha[j] != ' ') && (linha[j] != '\0')) && (j<=tamLinha);j++){
						//nao copiando espacos em brancos ou tabulados
						if(linha[j]!=' ') 
							if(linha[j]!='\t') linhaQuebrada = linhaQuebrada + linha[j];
						//std::cout<<"\tA-def-case1-f1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-f1-Valor j: "<<j<<std::endl;
						//std::cout<<"\tA-def-case1-f1-f1-linhaQuebrada="<<linhaQuebrada<<" == linha[j]="<<linha[j]<<std::endl;
					}//fim for2
					
					//std::cout<<"\tA-def-case1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-Valor j: "<<j<<std::endl;
					//std::cout<<"\tA-def-case1-f1-linhaQuebrada ="<<linhaQuebrada<<"."<<std::endl;

					if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){
						//std::cout<<"\n\tA-def-case1-f1-if11-Estado Atual:"<<estadoAtual<<std::endl;
						msgRetorno = lerAutomato(linhaQuebrada);
						//std::cout<<"\n\tA-def-case1-f1-if12-Estado Atual:"<<estadoAtual<<std::endl;
						//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
						//strTemp = ((i+1)+48);
						//chtemp = persistencia.getUltimaLinhaLida()+48;
						//strTemp2 = chtemp;
						if(msgRetorno!=("-1")){
							std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
							return ("01-c1."+msgRetorno);
						}
						else {
                             //#if WIN32
                             std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
                        }
					}//fim if
					i=j;
				}//fim for
				
				
				//std::cout<<"\n\t Final do case 1, msg:"<<msgRetorno<<std::endl;
			break;
			}//fim case 1
			
			default:{//01-df
				switch(caso){
				//caso 1 - nao contem ()
					case 1:{//01-df-c1
						//std::cout<<"\n\t Caso tratado:"<<caso<<std::endl;
						
						int j,i;
												
						//std::cout<<"\t\tTamanho da linha: "<<tamLinha<<std::endl;
											
						for(i=0,j=0; linha[i]!='\0'; i++,j++){
							linhaQuebrada = "";//str aux
							//std::cout<<"\tA-def-case1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-Valor j: "<<j<<std::endl;
							//std::cout<<"\t\tA-def-case1-f1-LINHA ="<<linha<<"."<<std::endl;
							
							//repita ate construir a palavra da linha
							for(;((linha[j] != ' ') && (linha[j] != '\0')) && (j<=tamLinha);j++){
								//nao copiando espacos em brancos ou tabulados
								if(linha[j]!=' ') 
									if(linha[j]!='\t') linhaQuebrada = linhaQuebrada + linha[j];
								//std::cout<<"\tA-def-case1-f1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-f1-Valor j: "<<j<<std::endl;
								//std::cout<<"\tA-def-case1-f1-f1-linhaQuebrada="<<linhaQuebrada<<" == linha[j]="<<linha[j]<<std::endl;
							}//fim for2
							
							//std::cout<<"\tA-def-case1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-Valor j: "<<j<<std::endl;
							//std::cout<<"\tA-def-case1-f1-linhaQuebrada ="<<linhaQuebrada<<"."<<std::endl;
							
							if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){
								//std::cout<<"\n\tA-def-case1-f1-if11-Estado Atual:"<<estadoAtual<<std::endl;
								msgRetorno = lerAutomato(linhaQuebrada);
								//std::cout<<"\n\tA-def-case1-f1-if12-Estado Atual:"<<estadoAtual<<std::endl;
								//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
								//strTemp = ((i+1)+48);
								//strTemp2 = (persistencia.getUltimaLinhaLida()+48);
								//chtemp = persistencia.getUltimaLinhaLida()+48;
								//strTemp2 = chtemp;
								//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c1for."+strTemp+". "+msgRetorno);
								if(msgRetorno!=("-1")){
									std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
									return ("01-df-c1."+msgRetorno);
								}
								else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
							}//fim if
							i=j;
						}//fim for
					break;
					}//fim case
				//caso 2 - contem ()
					case 2:{//01-df-c2
						//std::cout<<"\n\tA-def-case2"<<std::endl;
						//std::cout<<"\n\t Caso tratado:"<<caso<<std::endl;
						int j,i;
						for(i=0,j=0; linha[i]!='\0'; i++,j++){
							linhaQuebrada="";
							//std::cout<<"\n\tfor no inicio do case."<<std::endl;
							//std::cout<<"\n\tA-def-case2-for1"<<std::endl;
							
							//TRATANDO ANTES DOS PARENTESES
							if(i<posPrimeiroParenteses){//if1
								//std::cout<<"\n\tEntrou no if antes dos parenteses"<<std::endl;
								//std::cout<<"\n\tValor de i-antes: "<<i<<"\n\tValor de j-antes:"<<j<<std::endl;
								for(;((linha[j] != ' ') && (linha[j] != '\0')) && (j<=tamLinha);j++){
									//nao copiando espacos em brancos ou tabulados
									if(linha[j]!=' ') 
										if(linha[j]!='\t') linhaQuebrada = linhaQuebrada + linha[j];
									//std::cout<<"\tA-def-case1-f1-f1-Valor i: "<<i<<std::endl<<"\tA-def-case1-f1-f1-Valor j: "<<j<<std::endl;
									//std::cout<<"\tA-def-case1-f1-f1-linhaQuebrada="<<linhaQuebrada<<" == linha[j]="<<linha[j]<<std::endl;
								}//fim for2
								//std::cout<<"\n\tValor de i-depois: "<<i<<"\n\tValor de j-depois:"<<j<<std::endl;
								//std::cout<<"\tif antes dos parenteses-linhaQuebrada ="<<linhaQuebrada<<"."<<std::endl;
								
								//msgRetorno = lerAutomato(linhaQuebrada);
								
								if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){//01-df-c2-if1
									//std::cout<<"\n\tA-def-case2-for1-if11-Estado Atual:"<<estadoAtual<<std::endl;
									msgRetorno = lerAutomato(linhaQuebrada);
									//std::cout<<"\n\tA-def-case2-for1-if12-Estado Atual:"<<estadoAtual<<std::endl;
									//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
									//strTemp = ((i+1)+48);
									//strTemp2 = (persistencia.getUltimaLinhaLida()+48);
									//chtemp = persistencia.getUltimaLinhaLida()+48;
									//strTemp2 = chtemp;
									//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c2i1."+strTemp+". "+msgRetorno);
									if(msgRetorno!=("-1")){
										std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
										return ("01-df-c2-if1."+msgRetorno);
									}
									else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
								}//fim if
								//i=j;
								//if(msgRetorno!=("-1")) return ("iniA-c2c2i1"+msgRetorno);
								//std::cout<<"\n\tSaindo do if antes dos parenteses"<<std::endl;
							}//fim if1
							//TRATANDO NA MESMA POSICAO DO PARENTESEs (
							if(i==posPrimeiroParenteses){//01-df-c2-if2
								//std::cout<<"\n\tentrou no if (i==posPrimeiroParenteses)."<<std::endl;
								if(linha[i]=='(') linhaQuebrada = linha[i];
								if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){
									//std::cout<<"\n\tTratando qdo i==( -Estado Atual:"<<estadoAtual<<std::endl;
									msgRetorno = lerAutomato(linhaQuebrada);
									//std::cout<<"\n\tTratando qdo i==( -Estado Atual:"<<estadoAtual<<std::endl;
									//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
									//strTemp = ((i+1)+48);
									//strTemp2 = ((persistencia.getUltimaLinhaLida())+48);
									//chtemp = persistencia.getUltimaLinhaLida()+48;
									//strTemp2 = chtemp;
									//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c2i2"+strTemp+". "+msgRetorno);
									if(msgRetorno!=("-1")){
										std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
										return ("01-df-c2-if2."+msgRetorno);
									}
										else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
								}//fim if
								j++;
							}//fim if
							//TRATANDO DENTRO DOS PARENTESES
							if(i>posPrimeiroParenteses && i<posSegundoParenteses){
								//copiando o "Qualquer texto"
								//std::cout<<"\n\tif DENTRO dos parenteses: teste de entrada"<<std::endl;
								
								//std::cout<<"Conteudo vetor - linha["<<i+1<<"]="<<linha[i+1]<<std::endl;
								//std::cout<<"Conteudo vetor - linha["<<i+2<<"]="<<linha[i+2]<<std::endl;
								int inicioTexto, fimTexto;

/*
								if(linha[posPrimeiroParenteses+1]!= ' ' && linha[posPrimeiroParenteses+1]!= '\0'){ inicioTexto = posPrimeiroParenteses+1;
									fimTexto = posSegundoParenteses-1;
								} 
								else if(linha[posPrimeiroParenteses+2]== ' ' || linha[posPrimeiroParenteses+1]!= '\0'){
									inicioTexto = posPrimeiroParenteses+2;
									fimTexto = posSegundoParenteses-2;
								}//fim else
*/
								inicioTexto = posPrimeiroParenteses+2;
								fimTexto = posSegundoParenteses-2;
								//std::cout<<"\n\tInicioTexto: "<<inicioTexto<<std::endl;
								//std::cout<<"\n\tFim Texto: "<<fimTexto<<std::endl;
								//std::cout<<"Conteudo vetor - linha["<<inicioTexto<<"]="<<linha[inicioTexto]<<std::endl;
								//std::cout<<"Conteudo vetor - linha["<<fimTexto<<"]="<<linha[fimTexto]<<std::endl;
								
								//Copiando todo conteudo do texto para uma var temp
								for(;inicioTexto<=fimTexto;inicioTexto++){
									linhaQuebrada = linhaQuebrada + linha[inicioTexto];
								}//fim for2
								
								//std::cout<<"\n\tif DENTRO dos parenteses: teste depois do for"<<std::endl;
								//std::cout<<" \n\t Linha quebrada: "<<linhaQuebrada<<std::endl;
								//std::cout<<"\n\t - LQ - Valor de j: "<<posSegundoParenteses<<std::endl;
								
								//msgRetorno = lerAutomato(linhaQuebrada);
								
								if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){//01-df-c2-if3
									//std::cout<<"\n\tA-def-case2-for1-if2-if1-Estado Atual:"<<estadoAtual<<std::endl;
									msgRetorno = lerAutomato(linhaQuebrada);
									//std::cout<<"\n\tA-def-case2-for1-if2-if1-Estado Atual:"<<estadoAtual<<std::endl;
									//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
									//strTemp = ((i+1)+48);
									//strTemp2 = (persistencia.getUltimaLinhaLida()+48);
									//chtemp = persistencia.getUltimaLinhaLida()+48;
									//strTemp2 = chtemp;
									//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c2i2"+strTemp+". "+msgRetorno);
									if(msgRetorno!=("-1")){
										std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
										return ("01-df-c2-if3."+msgRetorno);
									}
										else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
								}//fim if
								
								//if(msgRetorno!=("-1")) return ("iniA-c2c2i2"+msgRetorno);
								linhaQuebrada = "";
								
								//REDIRECIONANDO O indice j para a posicao anterior a do parenteses 
								//para nao copiar repetidamente o texto;
								j = posSegundoParenteses-1;

							}//fim if1
							//TRATANDO NA MESMA POSICAO DO PARENTESEs )
							if(i==posSegundoParenteses){ //01-df-c2-if4
								//std::cout<<"\n\tentrou no if (i==posPrimeiroParenteses)."<<std::endl;
								if(linha[i]==')') linhaQuebrada = linha[i];
								if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){
									//std::cout<<"\n\tTratando qdo i==) -Estado Atual:"<<estadoAtual<<std::endl;
									msgRetorno = lerAutomato(linhaQuebrada);
									//std::cout<<"\n\tTratando qdo i==) -Estado Atual:"<<estadoAtual<<std::endl;
									//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
									//strTemp = ((i+1)+48);
									//chtemp = persistencia.getUltimaLinhaLida()+48;
									//strTemp2 = chtemp;
									//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c2i2"+strTemp+". "+msgRetorno);
									if(msgRetorno!=("-1")){
										std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
										return ("01-df-c2-if4."+msgRetorno);
									}
										else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
								}//fim if
								j++;
							}//fim if
							//TRATANDO CONTEUDO DEPOIS DO PARENTESES
							if(i>posSegundoParenteses){
								for(;((linha[j] != ' ') && (linha[j] != '\0')) && (j<=tamLinha);j++){
									//nao copiando espacos em brancos ou tabulados
									if(linha[j]!=' ') 
										if(linha[j]!='\t') linhaQuebrada = linhaQuebrada + linha[j];
								}//fim for2
								
								if(linha[i]!= ' ' && linhaQuebrada[0] != '\0'){//01-df-c2-if5
									//std::cout<<"\n\tA-def-case2-for1-if2-if1-Estado Atual:"<<estadoAtual<<std::endl;
									msgRetorno = lerAutomato(linhaQuebrada);
									//std::cout<<"\n\tA-def-case2-for1-if2-if1-Estado Atual:"<<estadoAtual<<std::endl;
									//std::cout<<"\n\t Linha quebrada:"<<linhaQuebrada<<std::endl;
									//strTemp = ((i+1)+48);
									//strTemp2 = ((persistencia.getUltimaLinhaLida())+48);
									//chtemp = persistencia.getUltimaLinhaLida()+48;
									//strTemp2 = chtemp;
									//if(msgRetorno!=("-1")) return ("linha:"+strTemp2+":iniA-c2c2i3"+strTemp+". "+msgRetorno);
									if(msgRetorno!=("-1")){
										std::cout<<"Erro na linha "<<persistencia.getUltimaLinhaLida()<<": ";
										return ("01-df-c2-if5."+msgRetorno);
									}
										else std::cout<<"Token OK: "<<linhaQuebrada<<std::endl;
								}//fim if
								
								//if(msgRetorno!=("-1")) return ("iniA-c2c2i3"+msgRetorno);
								linhaQuebrada = "";
							}//fim if1
							//i=j;
							//tratando quando se le um texto, e preciso reposicionar o indice para uma
							//posicao antes do parenteses, pois no proximo loop o indice sera incrementado
							//para a posicao do parenteses.
							//quando entrar nesse if eh pq esta dentro do parenteses
							if(i>posPrimeiroParenteses && i<posSegundoParenteses){ i=j; }
							else { i=j; }
						}//fim for
					break;
					}//fim case 2
				}//fim switch
			break;
			}//fim case 2
		}//fim switch
	}//fim while
	//std::cout<<"\n\t Teste de falha de seg... fim metodo"<<std::endl;
	return ("-1");
}//fim metodo iniciar

//********************************************************************************************
/* 02 */
std::string Automato::lerAutomato(std::string token)
{
	std::string msgRetorno;
	switch(estadoAtual){
		case 0: {//ok
			if(token=="programa"){
				estadoAtual = 1;
				
				msgRetorno = gerarFonteEmC(0,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(0);
		break;
		}
		case 1: {//ok
			if(token=="var"){
				estadoAtual = 2;
				
				msgRetorno = gerarFonteEmC(1,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(1);
		break;
		}
		case 2: {//ok
			if(token==";"){
				estadoAtual = 4;
				
				msgRetorno = gerarFonteEmC(2,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else {
				//aplicando a regra 
				std::string tokenAux = regraSemantica1(token);
				//verificando se foi alocado ou não.
				//Se o valor for -1 está ok
				if(tokenAux == "-1") { 
					estadoAtual = 3;
					
					msgRetorno = gerarFonteEmC(2,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1"); 
				} //fim if 
				else return (getMsgErroLexico(2)+tokenAux); //contendo o erro
			}//fim else 1
		break;
		}
		case 3: {//ok
			if(token==";"){
				estadoAtual = 4;
				
				msgRetorno = gerarFonteEmC(3,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else {
				//aplicando a regra 
				std::string tokenAux = regraSemantica1(token);
				//verificando se foi alocado ou não.
				//Se o valor for -1 está ok
				if(tokenAux == "-1") {
					estadoAtual = 3;
					
					msgRetorno = gerarFonteEmC(3,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1"); 
				} //fim if 
				else return (getMsgErroLexico(3)+tokenAux); //contendo o erro
			}//fim else
		break;
		}
		case 4: {//ok
			if(token=="leia"){
				estadoAtual = 5;
				
				msgRetorno = gerarFonteEmC(4,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(4);
		break;
		}
		case 5: {//ok
			if(regraSemantica2(token)){
				estadoAtual = 6;
				
				msgRetorno = gerarFonteEmC(5,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(5);
		break;
		}
		case 6: {//ok
			if(token=="leia"){
				estadoAtual = 5;
				
				msgRetorno = gerarFonteEmC(6,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="escreva"){
					estadoAtual = 7;
					
					msgRetorno = gerarFonteEmC(6,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(6);
		break;
		}
		case 7: {//ok
			if(token=="("){
				estadoAtual = 9;
				
				msgRetorno = gerarFonteEmC(7,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else {
				if(regraSemantica2(token)){
					estadoAtual = 8;
					
					msgRetorno = gerarFonteEmC(7,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(7);
			}//fim else			
		break;
		}
		case 8: {//ok
			if(token=="leia"){
				estadoAtual = 5;
				
				msgRetorno = gerarFonteEmC(8,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="escreva"){
					estadoAtual = 7;
					
					msgRetorno = gerarFonteEmC(8,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else if(token=="at"){
						estadoAtual = 11;
						
						msgRetorno = gerarFonteEmC(8,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
					else return getMsgErroLexico(8);
		break;
		}
		case 9: {
			if(token==")"){
				estadoAtual = 10;
				
				msgRetorno = gerarFonteEmC(9,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim 
			else {
				estadoAtual = 9;
				
				msgRetorno = gerarFonteEmC(9,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else
			
			//return getMsgErroLexico(9); //n precisa..aceita qualquer coisa
			
		break;
		}
		case 10: {//ok
			if(token=="leia"){
				estadoAtual = 5;
				
				msgRetorno = gerarFonteEmC(10,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="escreva"){
					estadoAtual = 7;
					
					msgRetorno = gerarFonteEmC(10,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else if(token=="at"){
						estadoAtual = 11;
						
						msgRetorno = gerarFonteEmC(10,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
					else return getMsgErroLexico(10);
		break;
		}
		case 11: {//ok
			//tratar regra semantica s2
			if(regraSemantica2(token)){
				estadoAtual = 12;
				
				msgRetorno = gerarFonteEmC(11,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(11);
		break;
		}
		case 12: {//ok
			if(token=="="){
				estadoAtual = 13;
				
				msgRetorno = gerarFonteEmC(12,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(12);
		break;
		}
		case 13: {//ok
			//tratar regra semantica 2 ou ler num
			//metodo para validar se eh ou nao um numero
			//para validar eh preciso saber se a variavel e um numero ou n
			
			//se nao for um numero verificara se ele obedece a regra semantica 2
			if(!isNumber(token)){
				if(regraSemantica2(token)){
					estadoAtual = 15;
					
					msgRetorno = gerarFonteEmC(13,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(13);			
			}//fim if is number
			else { //se for um numero fazera a transicao
				estadoAtual = 14;
				
				msgRetorno = gerarFonteEmC(13,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else is number
		break;
		}
		case 14: {//ok
			if(token=="at"){
				estadoAtual = 11;
				
				msgRetorno = gerarFonteEmC(14,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else{ if(token=="se"){
					estadoAtual = 16;
					
					msgRetorno = gerarFonteEmC(14,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(14);
			}//fim else
		break;
		}
		case 15: {//ok
			if(token=="at"){
				estadoAtual = 11;
				
				msgRetorno = gerarFonteEmC(15,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="se"){
					estadoAtual = 16;
					
					msgRetorno = gerarFonteEmC(15,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(15);
		break;
		}
		case 16: {//ok
			//tratar regra semantica s2
			if(regraSemantica2(token)){
				estadoAtual = 17;
				
				msgRetorno = gerarFonteEmC(16,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(16);
		break;
		}
		case 17: {//ok
			if(token==">"){
				estadoAtual = 18;
				
				msgRetorno = gerarFonteEmC(17,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="<"){
					estadoAtual = 18;
					
					msgRetorno = gerarFonteEmC(17,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else if(token==">="){
						estadoAtual = 18;
						
						msgRetorno = gerarFonteEmC(17,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
					else if(token=="<="){
							estadoAtual = 18;
							
							msgRetorno = gerarFonteEmC(17,token);
							if(msgRetorno!=("-1")) return msgRetorno;
							
							return ("-1");
						}//fim if
						else if(token=="!="){
								estadoAtual = 18;
								
								msgRetorno = gerarFonteEmC(17,token);
								if(msgRetorno!=("-1")) return msgRetorno;								
								
								return ("-1");
							}//fim if
							else if(token=="=="){
									estadoAtual = 18;
									
									msgRetorno = gerarFonteEmC(17,token);
									if(msgRetorno!=("-1")) return msgRetorno;
									
									return ("-1");
								}//fim if
								else return getMsgErroLexico(17);
		break;
		}
		case 18: {//ok
			//tratar regra semantica 2 ou ler num
			//se nao for um numero verificara se ele obedece a regra semantica 2
			if(!isNumber(token)){
				if(regraSemantica2(token)){
					estadoAtual = 20;
					
					msgRetorno = gerarFonteEmC(18,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(18);
			}//fim if is number
			else { //se for um numero fazera a transicao
				estadoAtual = 19;
				
				msgRetorno = gerarFonteEmC(18,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else is number
			
		break;
		}
		case 19: {//ok
			if(token=="entao"){
				estadoAtual = 21;
				
				msgRetorno = gerarFonteEmC(19,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(19);
		break;
		}
		case 20: {//ok
			if(token=="entao"){
				estadoAtual = 21;
				
				msgRetorno = gerarFonteEmC(20,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(20);
		break;
		}
		case 21: {//ok
			if(token=="at"){
				estadoAtual = 22;
				
				msgRetorno = gerarFonteEmC(21,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(21);
		break;
		}
		case 22: {//ok
			//tratar regra semantica s2
			if(regraSemantica2(token)){
				estadoAtual = 23;
				
				msgRetorno = gerarFonteEmC(22,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(22);
		break;
		}
		case 23: {//ok
			if(token=="="){
				estadoAtual = 24;
				
				msgRetorno = gerarFonteEmC(23,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(23);
		break;
		}
		case 24: {//ok
			//tratar regra semantica 2 ou ler num
			//se nao for um numero verificara se ele obedece a regra semantica 2
			if(!isNumber(token)){
				if(regraSemantica2(token)){
					estadoAtual = 25;
					
					msgRetorno = gerarFonteEmC(24,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(24);
			}//fim if is number
			else { //se for um numero fazera a transicao
				estadoAtual = 27;
				
				msgRetorno = gerarFonteEmC(24,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else is number
			
		break;
		}
		case 25: {//ok
			if(token==";"){
				estadoAtual = 28;
				
				msgRetorno = gerarFonteEmC(25,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="+"){
					estadoAtual = 26;
					
					msgRetorno = gerarFonteEmC(25,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else if(token=="-"){
						estadoAtual = 26;
						
						msgRetorno = gerarFonteEmC(25,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
				else if(token=="*"){
						estadoAtual = 26;
						
						msgRetorno = gerarFonteEmC(25,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
					else return getMsgErroLexico(25);
		break;
		}
		case 26: {//ok
			//tratar regra semantica 2 ou ler num
			
			//se nao for um numero verificara se ele obedece a regra semantica 2
			if(!isNumber(token)){
				if(regraSemantica2(token)){
					estadoAtual = 25;
					
					msgRetorno = gerarFonteEmC(26,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else return getMsgErroLexico(24);
			}//fim if is number
			else { //se for um numero fazera a transicao
				estadoAtual = 27;
				
				msgRetorno = gerarFonteEmC(26,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else is number
		break;
		}
		case 27: {//ok
			if(token==";"){
				estadoAtual = 28;
				
				msgRetorno = gerarFonteEmC(27,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else if(token=="+"){
					estadoAtual = 26;
					
					msgRetorno = gerarFonteEmC(27,token);
					if(msgRetorno!=("-1")) return msgRetorno;
					
					return ("-1");
				}//fim if
				else if(token=="-"){
						estadoAtual = 26;
						
						msgRetorno = gerarFonteEmC(27,token);
						if(msgRetorno!=("-1")) return msgRetorno;
						
						return ("-1");
					}//fim if
					else if(token=="*"){
							estadoAtual = 26;
							
							msgRetorno = gerarFonteEmC(27,token);
							if(msgRetorno!=("-1")) return msgRetorno;
							
							return ("-1");
						}//fim if
						else return getMsgErroLexico(27);
		break;
		}
		case 28: {//ok
			if(token=="senao"){
				estadoAtual = 29;
				
				msgRetorno = gerarFonteEmC(28,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(28);
		break;
		}
		case 29: {//ok
			if(token=="escreva"){
				estadoAtual = 30;
				
				msgRetorno = gerarFonteEmC(29,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(29);
		break;
		}
		case 30: {//ok
			if(token=="("){
				estadoAtual = 31;
				
				msgRetorno = gerarFonteEmC(30,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(30);
		break;
		}
		case 31: {
			if(token==")"){
				estadoAtual = 32;
				
				msgRetorno = gerarFonteEmC(31,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim 
			else {
				estadoAtual = 31;
				
				msgRetorno = gerarFonteEmC(31,token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim else
				
			//return ("Metodo n implementado."+getMsgErroLexico(31));
		break;
		}
		case 32: {//ok
			if(token=="fim"){
				estadoAtual = 33;
				
				msgRetorno = gerarFonteEmC(32, token);
				if(msgRetorno!=("-1")) return msgRetorno;
				
				return ("-1");
			}//fim if
			else return getMsgErroLexico(32);
		break;
		}
		case 33: {
			//estado final
			return getMsgErroLexico(33);
		break;
		}
	}//fim switch
}//fim lerNoAutomato

//******************************************************************************************************
/* 03 */
/*
 * Finalidade de validar a regra semantica 1. regras sobre a Var(token):
 * - Não pode ultrapassar 255 caracteres;
 * - Deve iniciar com A-Z ou a-z
 * - Deve terminar com $
 * - Verificar se a tabela de simbolos não esta cheia
 * O metodo deve retornar uma mensagem de erro se nao seguir as regras ou
 * -1 inidicando que está ok.
 */
std::string Automato::regraSemantica1(std::string token)
{
	//contando o tamanho da palavra
	int i;
	for(i=0; token[i]!= '\0'; i++);
	if(i>255){
		return (getMsgErroSemantico(3)+"Var= "+token);
	}//fim if
	//verificando se obedece a seguinte regra:
	//inicia com [A-Z] ou [a-z]  - pesquisando na tabela ascii
	if((token[0] < 65) || (token[0] > 122)){
		return (getMsgErroSemantico(1)+"Var(regra:[a-z,A-Z])= "+token);
	}//fim if
	else{
		if(token[i-1] != '$'){
			return (getMsgErroSemantico(1)+"Var(regra:$)= "+token);
		}//fim validar id variavel
		else {
			//verificando o espacovazio na tab de simbolos
			if(tamTabSimb>=tamMaxTabSimb){
				return (getMsgErroSemantico(1)+"\nTabela de Simbolos Cheia");			
			}//fim if ver espaco na tab simb
			else {
				//verificando se existe algum simbolo na tabela
				if(regraSemantica2(token)) return ("\nVariavel ja declarada"); 
				tabelaSimbolos[tamTabSimb+1] = token;
				tamTabSimb+=1;
				if(tabelaSimbolos[tamTabSimb] != token) 
					{ return ("Problemas na alocacao da Var=" + token + " na tabela de Simbolos"); }
					else return ("-1"); //-1 == ok			
			}//fim else
		}//fim else
	}//fim else
}//fim regra2
//******************************************************************************************************
/* 04 */
bool Automato::regraSemantica2(std::string token)
{
	int i;
	for(i=0;i<=tamTabSimb;i++){
		if(tabelaSimbolos[i]==token){
			return true;
		}//fim if
	}//fim for
	return false;
}//fim regra semantica2
//*********************************************************************/
/* 05 */
std::string Automato::gerarFonteEmC(unsigned int estado, std::string token)
{
	std::string msgErro;
	switch(estado){
		case 0: {
			if(token=="programa"){
				//std::cout<<"\n\t Dentro case gerarFonteEmC - antes gravar 1 linha"<<std::endl;
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "#include<stdio.h>\n\n");
				if(msgErro!=("-1")) return msgErro;
				//std::cout<<"\n\t Dentro case gerarFonteEmC - depois gravar 1 linha"<<std::endl;
				//Persistencia::gravarLinha(this->nomeArquivoEmC, "\n");
				//std::cout<<"\n\t Dentro case gerarFonteEmC - antes gravar 2 linha"<<std::endl;
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "int main (void){\n\n");
				if(msgErro!=("-1")) return (msgErro);
				//std::cout<<"\n\t Dentro case gerarFonteEmC - depois gravar 12linha"<<std::endl;
				
				return ("-1");
			}//fim if
		break;
		}//fim case
		case 1: {
			if(token=="var"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "int ");
				if(msgErro!=("-1")) return msgErro;
				//std::cout<<"\n\t Dentro case gerarFonteEmC - CASE 1"<<std::endl;
				return ("-1");
			}//fim if
		break;
		}//fim case
		case 2: {
			if(token==";"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, ";\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				//std::cout<<"\n\t Dentro case gerarFonteEmC - CASE 2 - ELSE 1: TOKEN="<<token<<std::endl;
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				//std::cout<<"\n\t Dentro case gerarFonteEmC - CASE 2 - ELSE 2"<<std::endl;
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, strAux);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case	
		case 3: {
			if(token==";"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, ";\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (", "+strAux));
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		case 4: {
			if(token=="leia"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nscanf(\"%d\",&");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		case 5: {
			std::string strAux="";
			for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
			msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, ((strAux)+(");")));
			if(msgErro!=("-1")) return msgErro;
			return ("-1");
		break;
		}//fim case
		case 6: {
			if(token=="leia"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nscanf(\"%d\",&");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="escreva"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nprintf(");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		case 7: {
			if(token=="("){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\"");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, ("\"%d\","+strAux+");"));
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		case 8: {
			if(token=="escreva"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nprintf(");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="at"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
			else if(token=="leia"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nscanf(\"%d\",&");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		case 9: {
			if(token==")"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\\n\");");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, token);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		case 10: {
			if(token=="escreva"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nprintf(");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="at"){
					msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\n");
					if(msgErro!=("-1")) return msgErro;
					return ("-1");
				}//fim else
				else if(token=="leia"){
						msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nscanf(\"%d\",&");
						if(msgErro!=("-1")) return msgErro;
						return ("-1");
					}//fim if
		break;
		}//fim case
		case 11: {
			std::string strAux="";
			for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
			msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (strAux));
			if(msgErro!=("-1")) return msgErro;
			return ("-1");
		break;
		}//fim case
		case 12: {
			if(token=="="){
				//std::cout<<"\n\t CASE 12 - dentro de ="<<std::endl;
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " = ");
				//std::cout<<"\n\t CASE 12 - dentro de = - depois do call do metodo"<<std::endl;
				if(msgErro!=("-1")) return msgErro;
				//std::cout<<"\n\t CASE 12 - dentro de = - depois do call do metodo"<<std::endl;
				return ("-1");
			}//fim if
		break;
		}//fim case
		case 13: {
			
			if(isNumber(token)){
				//std::cout<<"\n\t CASE 13 - is number "<<std::endl;
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (token+";"));
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				//std::cout<<"\n\t CASE 13 - else is number 1 "<<std::endl;
				std::string strAux="";
				//std::cout<<"\n\t CASE 13 - else is number 2 "<<std::endl;
				for(int i=0;token[i]!='$';i++){ strAux = strAux+token[i]; }
				
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (strAux+";"));
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		
		case 14: {
			if(token=="at"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="se"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\nif( ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 15: {
			if(token=="at"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="se"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nif( ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 16: {
			std::string strAux="";
			for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
			msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (strAux));
			if(msgErro!=("-1")) return msgErro;
			return ("-1");
		break;
		}//fim case

		case 17: {
			if(token==">"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " > ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="<"){
					msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " < ");
					if(msgErro!=("-1")) return msgErro;
					return ("-1");
				}//fim if
				else if(token==">="){
						msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " >= ");
						if(msgErro!=("-1")) return msgErro;
						return ("-1");
					}//fim if
					else if(token=="<="){
							msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " <= ");
							if(msgErro!=("-1")) return msgErro;
							return ("-1");
						}//fim if
		break;
		}//fim case
		
		case 18: {
			if(isNumber(token)){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, token);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, strAux);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		
		case 19: {
			if(token=="entao"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " ){\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 20: {
			if(token=="entao"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " ){\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 21: {
			if(token=="at"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\t");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 22: {
			std::string strAux="";
			for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
			msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, (strAux));
			if(msgErro!=("-1")) return msgErro;
			return ("-1");
		break;
		}//fim case

		case 23: {
			if(token=="="){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " = ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 24: {
			if(isNumber(token)){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, token);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, strAux);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		
		case 25: {
			if(token=="+"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " + ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="-"){
					msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " - ");
					if(msgErro!=("-1")) return msgErro;
					return ("-1");
				}
				else if(token=="*"){
						msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " * ");
						if(msgErro!=("-1")) return msgErro;
						return ("-1");
					}
					else if(token==";"){
							msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " ;\n");
							if(msgErro!=("-1")) return msgErro;
							return ("-1");
						}	
		break;
		}//fim case
		
		case 26: {
			if(isNumber(token)){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, token);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				std::string strAux="";
				for(int i=0;token[i]!='$';i++){ strAux = strAux + token[i]; }
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, strAux);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		
		case 27: {
			if(token=="+"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " + ");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else if(token=="-"){
					msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " - ");
					if(msgErro!=("-1")) return msgErro;
					return ("-1");
				}
				else if(token=="*"){
						msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " * ");
						if(msgErro!=("-1")) return msgErro;
						return ("-1");
					}
					else if(token==";"){
							msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, " ;\n");
							if(msgErro!=("-1")) return msgErro;
							return ("-1");
						}	
		break;
		}//fim case
		
		case 28: {
			if(token=="senao"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n}\nelse");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 29: {
			if(token=="escreva"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\n\tprintf(");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 30: {
			if(token=="("){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\"");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
		
		case 31: {
			if(token==")"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\\n\");\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
			else {
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, token);
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim else
		break;
		}//fim case
		
		case 32: {
			if(token=="fim"){
				msgErro = Persistencia::gravarLinha(this->nomeArquivoEmC, "\nexit(0);\n\n}\n");
				if(msgErro!=("-1")) return msgErro;
				return ("-1");
			}//fim if
		break;
		}//fim case
	}//fim switch
}//fim gerarFonteEmC

//******************************************************************/
/* 06 */
std::string Automato::getMsgErroLexico(int idErro)
{
	switch(idErro){
		case 0: {return "Esperando Id=programa";			break;}
		case 1: {return "Esperando Id=var";				break;}
		case 2: {return "Esperando Id=; ou Uma variavel";		break;}
		case 3: {return "Esperando Id=; ou Uma variavel";		break;}
		case 4: {return "Esperando Id=leia";				break;}
		case 5: {return "Esperando uma variavel";			break;}
		case 6: {return "Esperando Id=leia ou escreva";			break;}
		case 7: {return "Esperando Id=( ou uma variavel";		break;}
		case 8: {return "Esperando Id=at ou leia";			break;}
		case 9: {return "Aceita qualquer texto - sem regras";		break;}
		case 10: {return "Esperando Id=at ou leia";			break;}
		case 11: {return "Esperando  uma variavel";			break;}
		case 12: {return "Esperando Id= =";				break;}
		case 13: {return "Esperando um numero inteiro ou uma variavel";	break;}
		case 14: {return "Esperando Id= se";				break;}
		case 15: {return "Esperando Id= se";				break;}
		case 16: {return "Esperando uma variavel";			break;}
		case 17: {return "Esperando Operadores (<,>,<=,>=,==,!=)";	break;}
		case 18: {return "Esperando um numero inteiro ou uma variavel"; break;}
		case 19: {return "Esperando Id= entao";				break;}
		case 20: {return "Esperando Id= entao";				break;}
		case 21: {return "Esperando Id= at"; 				break;}
		case 22: {return "Esperando  uma variavel";			break;}
		case 23: {return "Esperando Id= =";				break;}
		case 24: {return "Esperando um numero inteiro ou uma variavel"; break;}
		case 25: {return "Esperando Operacoes (+,-,*) ou ;";		break;}
		case 26: {return "Esperando um numero inteiro ou uma variavel"; break;}
		case 27: {return "Esperando Operacoes (+,-,*) ou ;";		break;}
		case 28: {return "Esperando Id= senao";				break;}
		case 29: {return "Esperando Id= escreva";			break;}
		case 30: {return "Esperando Id= (";				break;}
		case 31: {return "Aceita qualquer texto - sem regras";		break;}
		case 32: {return "Esperando Id= fim";				break;}
		case 33: {return "Estado final alcancado - Nada a ser feito ";	break;}
	
	}//fim switch
}//fim metodo

//******************************************************************************************************
/* 07 */
std::string Automato::getMsgErroSemantico(int idErro)
{
	switch(idErro){
		case 1: { return "\nVariavel invalida. "; break; }
		case 2: { return "\nVariavel nao declarada"; break; }
		case 3: { return "\nSemantic Error: Variavel com nome muito grande. "; break; }
		case 4: { 
			//std::string nroEntradas = (int)(this->tamTabSimb+48).c_str();
			//return ("Semantic Error: Tabela de Simbolos cheia. Numero de entradas= " + nroEntradas + " variavel(is)");
			return ("Semantic Error: Tabela de Simbolos cheia. Numero de entradas maximas: 999 variavel(is)");
		break;
		}
	}//fim switch
}//fim metodo get msg erro semantico

//********************************************************************************************
/* 10 */
unsigned int Automato::qtdElementosLinha(std::string linha)
{
	int cont=0;
	for(int x=0; linha[x] != '\0';x++){
		//std::cout<<"\nentrou no for"<<std::endl;
		//if(x==0) cont+=1;//se a primeira linha nao eh vazia entao existe pelo menos uma var
		//std::cout<<"linha["<<x<<"]="<<linha[x]<<std::endl;
		
		//ignorando os espacos vazios
		if(linha[x]!=' ' && linha[x+1]==' '){ cont++; }
		if(linha[x]!=' ' && linha[x+1]=='\0'){ cont++; }
		
	}//fim for
	return cont;	
}//fim qtdElementos Linha

//********************************************************************************************
/* 11 */
/*Obtem o tamanho da string*/
unsigned int Automato::tamanhoStr(std::string str)
{
	int tam=0;
	for(int i=0;str[i] != '\0' ;i++) { tam++; }
	return tam;
}//fim tamanho str

//********************************************************************************************
/* 12 */
/*
* Este metodo tem a finalidade de verificar se uma string passada é um numero ou nao
*/
bool Automato::isNumber(std::string token)
{
	std::string strAux;
	unsigned int tamStr = tamanhoStr(token);
	
	//std::cout<<" STR analisada: "<<token<<std::endl;
	//std::cout<<" Tamanho str: "<<tamStr<<std::endl;
	
	for(int i=0; i<tamStr; i++){
		//std::cout<<"\ttoken["<<i<<"]="<<token[i]<<std::endl;
		char letra = token[i];
		int nroAux = letra - 48;
		//std::cout<<"\tnro aux:"<<nroAux<<std::endl;
		// (45-48) == -3 == - .na tabela ascii
		if(!(nroAux == -3)){ //tratando o negativo
			//std::cout<<"\tIF1 - nro aux:"<<nroAux<<std::endl;
			if(nroAux < 0) {
				//std::cout<<"\tIF2 - nro aux:"<<nroAux<<std::endl;
				return false;
			}//fim if
			else if(nroAux > 9) {
				//std::cout<<"\tIF3 - nro aux:"<<nroAux<<std::endl;
				return false;
			}//fim if
		}//fim if
	}//fim for
	return true;
}//fim is number

#endif /*AUTOMATO_H_*/
