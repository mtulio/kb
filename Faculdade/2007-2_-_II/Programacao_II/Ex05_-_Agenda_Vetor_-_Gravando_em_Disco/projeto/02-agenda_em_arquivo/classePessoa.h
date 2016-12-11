#ifndef CLASSEPESSOA_H_
#define CLASSEPESSOA_H_
#include<string>

//*****************************************************************
// Classe tem como responsabilidade armazenar os dados(nome,telefone e email)
// de uma pessoa
//A grande sacada do programa e a conversao de um arquivo para os atributos desta classe
//e sao os metodos desta classe q tem essa responsabilidade
//*****************************************************************
class Pessoa
{
	//Atributos
		private:
				std::string nome;
				unsigned long telefone;
				std::string email;
	//Metodos
		public:
				Pessoa(){};
				Pessoa(	const std::string &nome, unsigned long telefone, 
									const std::string &email):
									nome(nome),
                                    telefone(telefone),
                                    email(email)
                                    {};					
				void atribuirNome(const std::string &nome){this->nome=nome;};
				void obterNome(std::string &nome)const {nome=this->nome;};
				void atribuirTelefone(unsigned long telefone){this->telefone=telefone;};
				unsigned long obterTelefone()const{return telefone;};
				void atribuirEmail(const std::string &email){this->email=email;};
				const std::string & obterEmail()const{return email;};
				
				void atribuir(const std::string &string);
				void obter(std::string &string)const;
};

void Pessoa::atribuir(const std::string &str)//recebe como parametro uma string que e a linha do arquivo
//Tem como principal objetivo converter uma string p/ os atributos da classe pessoa
//metodo usado no objeto temporario para receber os nomes do arquivo e atribui-los aos atributos
{
	std::string nome, email;//criara uma string para receber qdo receber os dados q serao separados e serao armazenados dentro dessas variaveis
	unsigned long telefone=0;//a mesma coisa para essa variavel
	unsigned int pos=0;//indice de uso q verificara a string(linha) em cada posicao, 
	for(pos=0;str[pos]!=';';pos++) nome+=str[pos];//"separando" o nome da string"str", ate encontrar o ";" q eh onde indica a separacao do nome, telefone e email
	for(pos++;str[pos]!=';';pos++)telefone = telefone*10+static_cast<int>(str[pos])-48;
    //static_cast >> conversor de tipo de c++
    //"separando" o telefone da string, e transformando o telefone q eta atualmente em string para um inteiro
    //processo de trasformação(string p/ int)= verificando os numeros na tabela ASCII, 
    //Ex: o nro 0 (em string) na tabela eh 48, para encontrar o 0 subtrai 48 e assim transformara p/ num inteiro
	
    
    for(pos++;str[pos]!=';';pos++)email+=str[pos];//"separando" o email da string
	this->nome=nome;//armazenado o nome encontrado no atributo
	this->telefone=telefone;//armazenando o telefone encontrado no atributo
	this->email=email;//armazenando o email encontrado no atributo
	
	//std::cout<<nome<<std::endl;
}

void Pessoa::obter(std::string &str)const
//este metodo tem como objetivo armazenar os valores dentro do arquivo, ou seja, concatena-los em apenas uma string..a linha no caso!!!
{
	std::string linha, telefoneStr;
	linha = nome;//inicialmente a var linha recebera o nome
	//transformando o telefone que eh inteiro em uma string
	for(unsigned int aux=telefone;aux;){//condição, repetir enquanto a var aux for > que 0
		telefoneStr=static_cast<char>(aux%10+48)+telefoneStr;
		aux/=10;
	}	
	linha+=";";//caractere identificador que indica o fim de cada atributo na linha
	linha+=telefoneStr;//armazenando o telefone, em formato de uma string, dentro da var linha
	linha+=";";//identificador de fim do atributo
	linha+=email;//armazenando o email dentro do char linha
	linha+=";";//identificador de fim de atributo
	str=linha;//uma string com todos os dados do objeto..nome, telefone e email
}

#endif /*CLASSEPESSOA_H_*/
