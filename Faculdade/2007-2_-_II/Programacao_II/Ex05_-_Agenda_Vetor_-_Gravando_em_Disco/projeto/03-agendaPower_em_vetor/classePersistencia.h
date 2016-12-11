#ifndef CLASSEPERSISTENCIA_H_
#define CLASSEPERSISTENCIA_H_
#include"classePessoa.h"
#include"classeIterador.h"
#include<string>

//****************************************************
// 
//************************************************

/*****************************************************************
1 - limita o tamanho da agenda
2 - 
A classe persistencia "comanda" a agenda, atribuindo, obtendo e apagando nomes, 
controlando  o tamanho dela, a qtd de posicoes que foram usadas..etc..
//*****************************************************************/
class Persistencia
{
	//Atributos
	private:
		static const unsigned int tamanho=5;//define o tamannho da agenda com 5 posiçoes
		unsigned int indiceUso; // e a quantidade de espaço usado na agenda...
		Pessoa agenda[tamanho];// criei um objeto vetor de tamanho[tamanho]... da classe Pessoa
	//Metodos
		bool busca(const std::string &nome, unsigned int &posicao)const;
        //Metodo bool é privado, pois so vai
        //ser usado nessa classe
	public:
		Persistencia():indiceUso(0){};//construtor sem parametros inline implicito
		//dando valores iniciais ao IndiceUso que por sua vez é um atributo...
		int atribuir(const Pessoa &objeto);
		bool obter(const std::string &nome, Pessoa & objPessoa)const;
		bool apagar(const std::string &nome);
		Iterator *obterTodasAsPessoas();
		Iterator *obterTodasAsPessoasNome(char letra);
		
};

//*****************************************************************************************

int Persistencia::atribuir(const Pessoa &objeto) // objeto istanciado da classe Pessoa...

//Atribuir: "pega" o nome, telefone e email em fim todo o objeto e jogar na posiçao da agenda....

{// inicio metodo
	if(indiceUso<tamanho){ // verificando se a agenda esta cheia... pois so posso atribuir uma coisa em outra se nao estiver cheio....
		std::string nome;//declarando uma variavel do tipo string para receber o parametro do metodo obter nome
		unsigned int pos;//a var pos serve para receber o valor da posição retornado pelo metodo busca
		objeto.obterNome(nome);//a var nome vai reveber o nome do objeto da classe pessoa q eh um parametro do metodo atribuir
		if(!busca(nome,pos)) { //verifica se o nome já existe negando o metodo busca...
			agenda[indiceUso]=objeto; //caso n existe ele "guardara" o objeto dentro da agenda(vetor de objetos da classe Pessoa)
			indiceUso++; // incrementando o contador de posições usadas na agenda (indiceDeUso)
			return 1;  // inclusao feita;
		}else return 2;// Nome ja Existe
	}else return 3;  // agenda cheia
}// fim metodo


//*****************************************************************************************

bool Persistencia::busca(const std::string &nome, unsigned int &posicao)const
// te enviar um nome para ser buscado dentro  da agenda... e retorna a posiçao....

// -Ow esse nome ta ae ?
//  Ta nao
// Entao beleza !

{// inicio do metodo
	unsigned int pos;// declaro uma variavel..
	for(pos=0;pos<indiceUso;pos++){// serve para verificar todas as posiçoes da agenda	
		std::string nomeObj; // criando uma variavel do tipo string		
        agenda[pos].obterNome(nomeObj);// istanciei o objeto agenda[pos] da classe pessoa no atributo.
        //e estou usando o metodo obterNome nesta chamada.. pq so posso usar metodos de classes
        //externas usando istanciaçao de Objetos da classe... 
        //e a resposta esta caindo no parametro nomeObj        
		if(nomeObj==nome){//verificando se o nome informado e o mesmo do atributo
			posicao=pos;//para verificar em que posição está o nome
			return true;//encontrou o nome e retornara verdadeiro
		}//fim do if
	}// fim for
	//Em fim o buscar serve para buscar nome que voce quer retornando a posiçao... se ele achar ele retorna verdadeiro
	return false; // se nao achar o nome retorna falso...
}// fim do metodo


//*******************************************************************************************************



bool Persistencia::obter(const std::string &nome, Pessoa &objPessoa)const
//obter tem como função "procurar" o nome informado na agenda e envia-lo(objeto) para "fora" como parametro
{
	unsigned int pos;//pos indica em que posicao o objeto esta na agenda
	if(busca(nome,pos)){// verificara se existe o nome na agenda, e retornara como paramentro a posicao do nome na agenda
		objPessoa = agenda[pos];//vai na agenda na posicao informada pelo metodo busca e armazenara dentro do parametro objPessoa
		return true; // se existir retorna verdadeiro
	}//fim if
	else return false;// se caso o nome nao exista retornara falso
}

bool Persistencia::apagar(const std::string &nome)
// vai  verificar se o nome existe, e caso ele exista ele informara a posiçao e ele ira la naquela posiçao e substituira pelo ultimo objeto
{
	unsigned int pos; // declarando a variavel pos...
	if(busca(nome,pos)){ // verificando se o nome existe...
		agenda[pos]=agenda[indiceUso-1];//vai na agenda na posicao do nome e será substituira o objeto pelo ultimo objeto da agenda
		indiceUso--;//decremeta uma posicao no indice de uso q indica qtas posicoes da agenda foi usado
		return true;//APAGADO COM SUCESSO
	}
	return false;//FALHA AO APAGAR - nao existe o nome na agenda
}

Iterator *Persistencia::obterTodasAsPessoas()
{//faz uma copia da agenda e envia para o iterador

//alocando dinamicamente no espaco da memoria um vetor(de objetos) da classe pessoa, do tamando da agenda criada no atributo
	Pessoa *copiaAgenda = new Pessoa[tamanho];//Reservando um espaço na memoria de um vetor da classe pesssoa
	for(unsigned int pos=0; pos<indiceUso; pos++){//anda de posiçao por posiçao
		copiaAgenda[pos]=agenda[pos];//FAZENDO UMA COPIA DA AGENDA - copiar para o novo objeto na posicao "pos" a posicao da agenda
	}
	Iterator *it = new Iterator(copiaAgenda,tamanho,indiceUso);
	//o construtor do iterador tem 3 parametros, 
    //o 1 sera a copia da agenda
    //o 2 o tamanho da agenda
    //o 3 sera a qtd de posições usadas na agenda
	
	return it;//retornando o objeto da classe iterador
}

Iterator *Persistencia::obterTodasAsPessoasNome(char letra)
{//primeiramente fazera uma copia da agenda apenas dos nomes q iniciarem com a letra informada como parametro
	Pessoa *conjunto = new Pessoa[tamanho];  // Reservando um espaço na memoria de um vetor da classe Pessoa...
	std::string nome;  //essa var e necessaria para verificar a primeira letra do nome com a letra do parametro
	int pos2=0;  //indice de uso do novo vetor
	for(unsigned int pos=0; pos<indiceUso; pos++){  //verificar cada posicao da agenda
		agenda[pos].obterNome(nome);  //obtendo o nome de cada posicao
		if(nome[0]==letra){  //comparando a primeira letra do nome com a letra informada como parametro
			conjunto[pos2]=agenda[pos];  //filtrando os objetos encontrados
			pos2++;   //incrementa mais um no indice de uso do novo vetor de objetos
		}
	}
	Iterator *it = new Iterator(conjunto,tamanho,pos2);
	return it; //retornando um objeto da classe Iterator
}

#endif /*CLASSEPERSISTENCIA_H_*/
