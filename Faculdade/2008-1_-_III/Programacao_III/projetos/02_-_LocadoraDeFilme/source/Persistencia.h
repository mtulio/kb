#ifndef PERSISTENCIA_H_
#define PERSISTENCIA_H_

#include<string>
#include<iostream>
#include<fstream>

#include"Cliente.h"
#include"Filme.h"
#include"Locacao.h"
#include"Iterator.h"

//***************************************************************************************
//          Classe Testada: OK - By MT                                                  *
//***************************************************************************************

//***********************************************************************************
//			CLASSE MAPEADOR DE DADOS DA PERSISTENCIA
//***********************************************************************************
//tem como responsabilidade de comandar aonde os dados vao ser gravados
//ele faz uma chamada de qual classe vai ser chamada
//e essa classe abrira o arquivo e realizara o metodo comandado

class MapeadorDeDados
{//inicio
   //Metodos
   public:
      MapeadorDeDados() {};
	  virtual ~MapeadorDeDados(){};
      virtual bool gravarDados(ItemPersistencia *item);
	  //tem como parametro um objeto da classe itemPersistencia
      virtual bool recuperarDados(ItemPersistencia *item);
      //sobrecarga de operador
      virtual bool recuperarDados(unsigned int &id, ItemPersistencia *item);
      virtual bool removerDados(ItemPersistencia *item);
      virtual Iterator *listagemGeralDeDados();

   //A estudar os metodo protected
   protected:
			virtual void gravarNoArmazenamento(ItemPersistencia *item)=0;
			virtual bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item) =0;
			virtual void removerNoArmazenamento(ItemPersistencia *item)=0;
			
			virtual Iterator *listarDadosNoArmazenamento()=0;			
};//fim definicao da classe MapeadorDeDados

//***************************************************************************************
bool MapeadorDeDados::gravarDados(ItemPersistencia *item)
/*Tem como funcao verificar se existe os dados, se nao existir eh enviado uma 
chamada para o metodo gravarNoArmazenamento() para armazenar os dados.
Se nao existir o metodo retornara false.*/
{
   if(!buscarNoArmazenamento(item->obterIdentificador(),item)) {
   //obterIdentificador retorna o codigo identificador do cliente
   //busca retorna os dados do "procuradO"
      gravarNoArmazenamento(item);
	  //com o metodo de "saida" do metodo busca e com a negaçao do mesmo
	  //eh enviado os dados para serem gravados com o metodo gravarNoArmazenamento
	  return true;//gravado com sucesso
   }
   return false;//nao eh possivel gravar
}//fim gravarDados

//***************************************************************************************
bool MapeadorDeDados::recuperarDados(ItemPersistencia *item)
/*Este metodo tem como funcao fazer uma chamada do metodo buscarNoArmazenamento
para verificar se existe os dados no disco"*/
{
    if(buscarNoArmazenamento(item->obterIdentificador(),item)) return true; //Encontrado
		else return false; // Nao encontrado
}//fim recuperarDados

//***************************************************************************************
bool MapeadorDeDados::recuperarDados(unsigned int &id, ItemPersistencia *item)
/*Tem como funcao recuperar os dados atraves de uma chamado do metodo buscarNoArmazenamento
tem como parametro de entrada um numero inteiro positivo e de saida um ponteiro
da classe ItemPersistencia retornado pelo argumento(parametro) do metodo buscarNoArmazenameto*/

{//inicio do metodo recuperar
   //std::cout<<"Teste recuperarDaDos na baseDeDados - OK"<<std::endl;
   //std::cout<<"buscarNoArmazenamento("<<id<<" ,item)"<<std::endl;
   if(buscarNoArmazenamento(id, item)) return true; //id encontrado e recuperado
      else return false; //id nao encontrado
}//fim do metodo recuperar

//***************************************************************************************
bool MapeadorDeDados::removerDados(ItemPersistencia *item)//chamado da classe persistencia
/*Tem como funcao fazer uma chamada para remover os dados em disco.
Primeiro eh feita a busca para verificar se existe e logo apos e feita a chamado do
metodo para remover os dados*/
{
   if(buscarNoArmazenamento(item->obterIdentificador(),item)){
      //recebe o item(objeto da classe Cliente) como parametro da busca
      removerNoArmazenamento(item);
      //chama o metodo remover da classe MapeadorDeCliente
	  //arquivo removido e retornado true
	  return true; //item removido
   }
   else return false; //item nao removido, nao encontrado
}//fim removerDados

//******************************************************************************
Iterator *MapeadorDeDados::listagemGeralDeDados()
/*Esta classe do tipo Iterator tem com funcao fazer uma chamada do metodo 
que faz uma listagem de todos os dados no arquivo o listarDadosNoArmazenamento.
E retornara um objeto da classe Iterator com todos esses dados*/
{
   return listarDadosNoArmazenamento();        
}//fim listagemGeralDeDados


//***********************************************************************************

//			Classe MAPEADOR DE DADOS DO CLIETNE na PERSISTENCIA

//***********************************************************************************

//Esta classe manipula os dados do cliente no disco
class MapeadorDeCliente:  public MapeadorDeDados
/*Definicao da classe MapeadorDeCliente que herda a classe MapeadorDeDados.
MapeadorDeCliente: sub-classe. MapeadorDeDados: super-classe.
Quando eh feito uma heranca, a classe super-classe pode fazer uma chamada dos metodos 
de sua sub-classe diretamente.*/
{
   //Atributos
   private:
      //Esse atributo armazenara o nome do arquivo em disco
      const std::string nomeDoArquivoNoDisco;
   
   //Metodos
   public:
      /*Construtor*/
      MapeadorDeCliente();
      /*Definicao dos metodos*/
      void gravarNoArmazenamento(ItemPersistencia *item);
      bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item);
      //tem como parametro de entrada um numero de identificacao e de saida 
      //os dados do respectvo number de identificao procurado
      void removerNoArmazenamento(ItemPersistencia *item);
      //remove um nome do arquivo 
      
      Iterator *listarDadosNoArmazenamento();
};//fim da definicao da classe MaperadorDeCliente

//******************************************************************************
MapeadorDeCliente::MapeadorDeCliente():
					nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
/*Tem como funcao verificar se o arquivo existe, se nao existir o criara*/
{
   std::fstream arquivo;
   //abrindo um arquivo para leitura
   arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
   
   //se o arquivo nao foi aberto, criara um arquivo para escrita e o limpara
   if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);
   
   //fechando o arquivo   
   arquivo.close();
}//fim do construtor

//******************************************************************************
bool MapeadorDeCliente::buscarNoArmazenamento(unsigned int id, ItemPersistencia *item)
/*Tem como funcao buscar no arquivo em disco o id informado como paramentro de entrada
e retornar ao argumento do metodo o objeto do id se encontrado.*/

//tem como parametro de entrada o nro identificador de um cliente
//tem como responsabilidade apenas buscar se existe um "id" dentro do arquivo
//e se encontrado esse "id" sera armazenado em um objeto da classe pessoa
//e retornado como parametro
{
   std::fstream arquivo;
   //aloca um objeto na memoria para leitura e escrita

   std::string linha;
   Cliente pessoaAux;
   Cliente *pessoa;

   /*Convertendo um objeto da calsse ItemPerssitencia para um objeto da classe Cliente*/
   pessoa = static_cast<Cliente *>(item);
    
   //Abre o arquivo para leitura
   arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
   
   //le a 1 linha do arquivo
   getline(arquivo,linha);
   while( !arquivo.eof() ){
   //este laço busca se existe o nro de identificacao no arquivo ate o fim do mesmo

      pessoaAux.materializar(linha);
      //materializar: tem como parametro uma string e funcao arqmazenar os dados no atributo      
      if( id==pessoaAux.obterIdentificador() ){
      //compara o nro identificador informado no parametro com o obtido no arquivo
               
         //se encontrado fechara o arquivo
         arquivo.close();
		 std::string nome,email;
		 unsigned int id;
         long telefone;
		 pessoaAux.obter(id,nome,telefone,email);
		 //recebera os dados do obj temporario e armazenara eles em um novo objeto
		 //este novo objeto e o paramentro de saida q foi reservado um espaco na memoria na declaracao do 
		 //parametro e na declaracao do obje pessoa da classe Cliente
		 
		 //apos atribuido este objeto retornara como parametro
         pessoa->atribuir(id,nome,telefone,email);
		 
		 //O objetivo desse metodo eh buscar um id no arquivo e retornar o objeto
		 //do mesmo como parametro, apos ter feito esse procedimento sem nenhum
		 //problema retornara true
         return true;
      }//fim if
      
      //le a proxima linha do arquivo se nao entrar no if
      getline(arquivo,linha);
	
   }//fim while
   //Fechara o arquivo apos a verificacao de todas as linhas do mesmo
   arquivo.close();
   
   //Caso nao encontre retornara false
   return false;
}//fim buscarNoArmazenamento

//******************************************************************************
void MapeadorDeCliente::gravarNoArmazenamento(ItemPersistencia *item)
//este metodo tem como responsabilidade apenas gravar os dados dentro do arquivo em disco
{
   Cliente *cliente;
   
   // Convertendo da variavel polimorfica do tipo ItemPersistencia para uma do tipo Cliente
   cliente=static_cast<Cliente *>(item);
   
   // Gravar no arquivo	
   std::ofstream arquivo;
   //abre o arquivo para escrita no fim do mesmo
   arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);

   //o comando desmaterializar da classe cliente retorna uma string
   //com todos os atributos nessa mesma string
   std::string linha = cliente->desmaterializar();

   //escrevendo a string dentro do arquivo
   arquivo<<linha<<std::endl;
   
   //fechando o arquivo
   arquivo.close();	
   
   //retornando ao ponto de chamada do metodo	
}//fim gravarNoArmazenamento

//******************************************************************************
void MapeadorDeCliente::removerNoArmazenamento(ItemPersistencia *item)
/*Tem como funcao remover um objeto informado no arquivo em disco*/
{
   // Criando Arquivo Auxiliar
   std::fstream arquivoAux;	
   //criando e abrindo arquivo para escrita  e limpando o mesmo
   arquivoAux.open("ArquivoTemporario.txt",std::ios::out|std::ios::trunc);	

   //  Abrindo arquivo Original para leitura
   std::fstream arquivo;
   arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
   
   std::string linha;
   Cliente pessoaAux;	

   //obtendo o numero identificador do cliente q vai ser apagado
   unsigned int id = item->obterIdentificador();
   
   getline(arquivo,linha);
   //lendo a primeira linha do arquivo original

   while( !arquivo.eof() ){
   
      //O metodo materializar armazena todos os dados contido na linha informada
      //guarda nos parametros do objeto
      pessoaAux.materializar(linha);
      //if tem como funcao fazer a copia de todos os dados com o id diferente do id 
      //a ser excluido
      if(id!=pessoaAux.obterIdentificador()) arquivoAux<<linha<<std::endl;
      
      //le a proxima linha do arquivo
      getline(arquivo,linha);

   }//fim while
   
   //fecha o arquivo original
   arquivo.close();
   //fecha o arquivo que foi feito a copia
   arquivoAux.close();
   
   //Apagando o arquivo original do disco
   std::remove("ArquivoDeCliente.txt");
   //Renomeando o arquivo temporario para o nome do arquivo original
   std::rename("ArquivoTemporario.txt","ArquivoDeCliente.txt");

   //retorna ao ponto de chamada do metodo			

}//fim removerNoArmazenamento

//******************************************************************************
Iterator *MapeadorDeCliente::listarDadosNoArmazenamento()
/*Tem como funcao listar todos os dados que estao dentro do arquivo e retorna-lo
como um objeto ponteiro vetor da classe Iterator*/
{
      //Cliente *cliente;
      //cliente = static_cast<Cliente *>(vetItem);
      
   //Criando dois objetos para leitura
   std::ifstream arquivoLer, arquivoCopiar;    

   //Abrindo o arquivo Original 
   arquivoLer.open(nomeDoArquivoNoDisco.c_str());

   std::string linha;
   int contador=0;
   
   //lendo a primeira linha do arquivo
   getline(arquivoLer,linha);

   //este laco tem como objetivo verificar quantas linhas contem no arquivo
   for(contador=0; !arquivoLer.eof() ; contador++){
      getline(arquivoLer,linha);
   }//fim for
   //Fechando o arquivo original
   arquivoLer.close();
   
   //Abrindo o arquivo original para fazer copia
   arquivoCopiar.open(nomeDoArquivoNoDisco.c_str());
      
   //Criando um vetor de objetos da classe cliente
   //o tamanho eh a quantidade de linhas do arquivo
   Cliente *itemVetor = new Cliente[contador];

   //lendo a primeira linha do arquivo
   getline(arquivoCopiar,linha);
   
   //Este for tem como funcao "andar" cada posicao do vetor armazenando os objetos
   for(unsigned int pos=0; !arquivoCopiar.eof() ;pos++){
      //O metodo materializar extrai os dados da string e os coloca nos atributos do objeto
      //e esse objeto eh armazenado em sua devida posicao no vetor
      itemVetor[pos].materializar(linha);
      //Le a proxima linha do arquivo ate o fim do mesmo
      getline(arquivoCopiar,linha);
   }
   
   //Fecha o arquivo
   arquivoCopiar.close();
   
   //Cria um objeto ponteiro da classe Iterator com os seus respectivos arqumentos
   Iterator *it = new Iterator(itemVetor, contador, contador);
   
   //esse objeto eh retornado ao metodo
   return it;      
}//fim do metodo listagem geral no armazenamento


//***********************************************************************************

//			CLASSE MAPEADOR DE DADOS DO FILME NA PERSISTENCIA

//***********************************************************************************
/*
ESTA CLASSE TEM A FUNCAO DE MANIPULAR O ARQUIVO EM DISCO
ENTAO OS SEGUINTES METODOS: GRAVAR, BUSCAR, REMOVER
E ATRIBUTOS O NOME DO ARQUIVO Q VAI ARMAZENAR OS DADOS NO DISCO
*/
class MapeadorDeFilme: public MapeadorDeDados
{//inicio da classe
          //atributos
          private:
                  const std::string nomeDoArquivoFilmeNoDisco;
          //metodos
          public:
              //aprimorar o condtrutor
              MapeadorDeFilme();
              //construir os metodos...
              void gravarNoArmazenamento(ItemPersistencia *item);
	  		  bool buscarNoArmazenamento(unsigned int id,ItemPersistencia *item);
	  		  //tem como parametro de entrada um numero de identificacao e de saida 
              //os dados do respectvo number de identificao procurado
	  		  void removerNoArmazenamento(ItemPersistencia *item);
	  		  //remove um nome do arquivo       
	  		  Iterator *listarDadosNoArmazenamento();
};//fim da classe mapeador de dados do filme
//CONSTRUIR

MapeadorDeFilme::MapeadorDeFilme(): 
                 nomeDoArquivoFilmeNoDisco("ArquivoDeFilme.txt")
{
                 std::fstream arquivo;
                 arquivo.open(nomeDoArquivoFilmeNoDisco.c_str(),std::ios::in);
                 if(!arquivo.is_open()) arquivo.open(nomeDoArquivoFilmeNoDisco.c_str(),std::ios::out|std::ios::trunc);
                 arquivo.close();                
}//fim do metodo construtor

bool MapeadorDeFilme::buscarNoArmazenamento(unsigned int id, ItemPersistencia *item)
{//inicio do metodo busca
     std::fstream arquivo;
     std::string linha;
     Filme filmeAux;
     Filme *filme;
     filme=static_cast<Filme *>(item);
     //convertendo o ponteiro "item" em um objeto da classe Filme
     // e armazenando no objeto ponteiro filme
     
     //abrir o arquivo para leitura
     arquivo.open(nomeDoArquivoFilmeNoDisco.c_str(), std::ios::in);
     //ler a primeira linha do arquivo
     getline(arquivo, linha);
     while(!arquivo.eof()){
     //verificando ate xegar ao fim do arquivo      
           filmeAux.materializar(linha);
           //"colocando" os dados q estao em uma string nos seus respectivos atributos
           if(id==filmeAux.obterIdentificador()){
                   arquivo.close();
                   //fechar o arquivo
                   std::string nome;
                   int precoCompra, precoVenda;
                   bool situacao;
                   filmeAux.obter(id, nome, precoCompra, precoVenda, situacao);
                   filme->atribuir(id, nome, precoCompra, precoVenda, situacao);                   
                   //usa-se "->" para uma chamada de um metodo para um ponteiro
                   return true;
           }//fim do if
           getline(arquivo, linha);
     }//fim do arquivo
     arquivo.close();
     return false;    
}//fim do metodo busca



void MapeadorDeFilme::gravarNoArmazenamento(ItemPersistencia *item)
{//inicio do metodo gravar no armazenamento
          //criar um objeto da classe filme e converter o objeto de entrada de
          //parametro da classe ItemPersistencia para um objeto da classe Filme
          Filme *filme;
          filme=static_cast<Filme *>(item);
          //convertendo o obj da classe ItemPersistencia para um obj da classe Filme
          
          std::fstream arquivo;
          std::string linha;
          arquivo.open(nomeDoArquivoFilmeNoDisco.c_str(),std::ios::out|std::ios::app);
          //abrindo o arquivo para escrita no fim do arquivo
          linha=filme->desmaterializar();
          //convertendo o arquivo em uma linha

          arquivo<<linha<<std::endl;
          //escrevendo o arquivo em disco          
          arquivo.close();
          //fechando o arquivo            
          
            //EM CONSTRUCAO    
}//fim do metodo gravar no armazenamento

void MapeadorDeFilme::removerNoArmazenamento(ItemPersistencia *item)
/*
Procedimentos para construcao desse metodo:
- abrir o arquivo original 
- criar um novo arquivo para escrita
- fazer a copia do original, sem o nome do arquivo q sera removido,para um arquivo temporario
- apagar o arquivo original
- renomear o temporario com o nome do arquivo original
*/
{//inicio do metodo remover
          //criando um arquivo para copia da agenda
          std::string arquivoTemporario="ArquivoTemp.txt";
          std::ofstream arqTemp;
          arqTemp.open(arquivoTemporario.c_str(),std::ios::trunc);
          
          //abrindo o arquivo original
          std::ifstream arquivoOriginal;
          arquivoOriginal.open(nomeDoArquivoFilmeNoDisco.c_str());
          
          //
          std::string linha;
          Filme filmeAux;
          //com o id q eu vou encontrar o filme
          unsigned int id=item->obterIdentificador();
          
          //le a primeira linha do arquivo
          getline(arquivoOriginal, linha);
          while(!arquivoOriginal.eof()){
          //repetira enquanto n xegar no fim do arquivo
                     filmeAux.materializar(linha);
                     if(id!=filmeAux.obterIdentificador()){
                           arqTemp<<linha<<std::endl;
                     }
                     getline(arquivoOriginal, linha);
          }//fim do while
          
          arquivoOriginal.close();
          arqTemp.close();
          remove("ArquivoDeFilme.txt");
          rename("ArquivoTemp.txt", "ArquivoDeFilme.txt");
          
}//fim do metodo remover

Iterator *MapeadorDeFilme::listarDadosNoArmazenamento()
{
      //Filme filme;
      //filme = static_cast<Filme *>(item);
      
      std::ifstream arquivoLer, arquivoCopiar;    
          
      arquivoLer.open(nomeDoArquivoFilmeNoDisco.c_str());
      
      std::string linha;
      
      int contador=0;
      
      getline(arquivoLer,linha);
      
      for(contador=0;!arquivoLer.eof();contador++){
            getline(arquivoLer,linha);
      }
      arquivoLer.close();
      
      arquivoCopiar.open(nomeDoArquivoFilmeNoDisco.c_str());
      
      getline(arquivoCopiar,linha);
      
      Filme *itemVetor = new Filme[contador];
      
      for(unsigned int pos=0;!arquivoCopiar.eof();pos++){
                 itemVetor[pos].materializar(linha);
                 
                 getline(arquivoCopiar,linha);
      }
      
      arquivoCopiar.close();
      
      Iterator *it = new Iterator(itemVetor, contador, contador);

      //vetItem=it;
      return it;     
      
}//fim do metodo listagem geral no armazenamento




//***********************************************************************************

//			CLASSE MAPEADOR DE DADOS DA LOCAÇÃO NA PERSISTENCIA

//***********************************************************************************

class MapeadorDeLocacao: public MapeadorDeDados
/* esta classe controla os dados no disco da locacao
 - como atributo deve ter o nome do arquivo em disco
 - como metodos deve conter a busca, gravação e remoção -  como os outros
*/
{
        private:
               const std::string nomeDoArquivoLocacaoNoDisco;
        public:
               MapeadorDeLocacao();
               bool buscarNoArmazenamento(unsigned int id, ItemPersistencia *item);
               void gravarNoArmazenamento(ItemPersistencia *item);
               void removerNoArmazenamento(ItemPersistencia *item);
               Iterator *listarDadosNoArmazenamento();     
};//fim da classe Mapeador de dados da locacao

MapeadorDeLocacao::MapeadorDeLocacao(): 
                 nomeDoArquivoLocacaoNoDisco("ArquivoDeLocacao.txt")
{//inicio do construtor
                 std::fstream arquivo;
                 arquivo.open(nomeDoArquivoLocacaoNoDisco.c_str(), std::ios::in);
                 if(!arquivo.is_open()) arquivo.open(nomeDoArquivoLocacaoNoDisco.c_str(), std::ios::out|std::ios::trunc);
                 //se nao aberto cria um novo arquivo
                 arquivo.close();                 
}//fim do construtor

bool MapeadorDeLocacao::buscarNoArmazenamento(unsigned int id, ItemPersistencia *item)
{//inicio do metodo de busca
     //std::cout<<"Teste buscar no armazenamento!!! - entrou, inicio"<<std::endl;
     std::fstream arquivo;
     std::string linha;
     Locacao locacaoAux;
     Locacao *locacao;
     //convertendo o objeto ponteiro item em um objeto da classe locacao
     locacao=static_cast<Locacao *>(item);

     arquivo.open(nomeDoArquivoLocacaoNoDisco.c_str(), std::ios::in);
     
     //std::cout<<"Buscar no armazenamento - antes do while ok!"<<std::endl;
     //std::cout<<"Linha: "<<linha<<std::endl;
     getline(arquivo, linha);
     while(!arquivo.eof()){
          
          //std::cout<<"buscar no armazenamento - dentro do while!- ok!"<<std::endl;
          locacaoAux.materializar(linha);
          //std::cout<<"Depois de materializar, desm: "<<locacaoAux.desmaterializar()<<std::endl;
          if(id==locacaoAux.obterIdentificador()){
                   arquivo.close();
                   std::string titulo;
                   unsigned int idLocacao, idCliente, idFilme;
                   int precoLocacao;
                   bool situacao;
                   locacaoAux.obter(idLocacao, idCliente, idFilme, precoLocacao, situacao);
                                      
                   locacao->atribuir(idLocacao, idCliente, idFilme, precoLocacao, situacao);
                   //std::cout<<"Teste buscaNoArmazenamento - OK!"<<std::endl;
                   //std::cout<<"idL: "<<idLocacao<<"\nidCliente: "<<idCliente<<"\nidFilme: "<<idFilme<<"P.Loc: "<<precoLocacao<<"\nSit: "<<situacao<<std::endl;

                   //linha=locacaoAux.desmaterializar();
                   //locacao->materializar(linha);
                   return true;             
          }
          getline(arquivo, linha);
     }
     arquivo.close();
     return false;
}//fim do metodo de busca

void MapeadorDeLocacao::gravarNoArmazenamento(ItemPersistencia *item)
{//inicio do metodo gravar
     std::ofstream arquivo;
     arquivo.open(nomeDoArquivoLocacaoNoDisco.c_str(), std::ios::app);
     
     std::string linha;
     Locacao *locacao;
     locacao=static_cast<Locacao *>(item);
     linha=locacao->desmaterializar();
     arquivo<<linha<<std::endl;
     arquivo.close();
}//fim do metodo gravar

void MapeadorDeLocacao::removerNoArmazenamento(ItemPersistencia *item)
{//inicio do metodo remover
      std::fstream arqOriginal, arqTemp;
      std::string nomeArquivoTemporario="ArqTemp.txt";
      
      arqOriginal.open(nomeDoArquivoLocacaoNoDisco.c_str(), std::ios::in);
      arqTemp.open(nomeArquivoTemporario.c_str(), std::ios::out|std::ios::trunc);
      
      std::string linha;
      
      Locacao locacaoAux;
      Locacao *locacao;
      locacao=static_cast<Locacao *>(item);
      getline(arqOriginal, linha);
      while(!arqOriginal.eof()){
             locacaoAux.materializar(linha);
             if(locacaoAux.obterIdentificador()!=locacao->obterIdentificador()){
                     arqTemp<<linha<<std::endl;
             }
             getline(arqOriginal, linha);
      }//fim do arquivo
      arqOriginal.close();
      arqTemp.close();
      remove("ArquivoDeLocacao.txt");
      rename("ArqTemp.txt","ArquivoDeLocacao.txt");      
}//fim do metodo remover

Iterator *MapeadorDeLocacao::listarDadosNoArmazenamento()
{
      //Locacao locacao;
      //locacao = static_cast<Locacao *>(vetItem);
      
   std::ifstream arquivoLer, arquivoCopiar;    
          
      arquivoLer.open(nomeDoArquivoLocacaoNoDisco.c_str());
      
      std::string linha;
      
      int contador=0;
      
      getline(arquivoLer,linha);
      
      for(contador=0;!arquivoLer.eof();contador++){
            getline(arquivoLer,linha);
      }
      arquivoLer.close();
      
      arquivoCopiar.open(nomeDoArquivoLocacaoNoDisco.c_str());
      
      getline(arquivoCopiar,linha);
      
      Locacao *itemVetor = new Locacao[contador];
      
      for(unsigned int pos=0;!arquivoCopiar.eof();pos++){
                 itemVetor[pos].materializar(linha);
                 
                 getline(arquivoCopiar,linha);
      }
      
      arquivoCopiar.close();
      
      Iterator *it = new Iterator(itemVetor, contador, contador);
      
      return it; 
      
}//fim do metodo listagem geral no armazenamento



/*************************************************************************************
                                                                                     *
                      CLASSE PERSISTENCIA                                            *
                                                                                     *
//***********************************************************************************/

class Persistencia
{
   //Atributos
   private:
      MapeadorDeDados  *baseDeDados[3];
	  //SERA UM VETOR PARA ARMAZENAR AS OPCOES PARA A ABERTURA DO ARQUIVO
	  //um objeto vetor da classe mapeador de dados
   
   //Metodos
   public:
      /*Construtor e Destrutor*/
      Persistencia();
      ~Persistencia();
      
      /*Definicao dos metodos*/
      bool gravar(ItemPersistencia *item);
      bool recuperar(ItemPersistencia *item);
      //usando sobrecarga de operador ou de metodo
      bool recuperar(unsigned int id, ItemPersistencia *item);
      bool remover(ItemPersistencia *item);
      bool alterar(ItemPersistencia *item);
      Iterator *listar(ItemPersistencia *item);			
};//fim da definicao da classe Persistencia

//******************************************************************************
Persistencia::Persistencia()
{
   baseDeDados[0] = new MapeadorDeCliente();
   //criando um objeto vetor da classe mapeadorDeDados q contem 
   //a classe mapeadorDeCliente
   baseDeDados[1] = new MapeadorDeFilme();
   //criando um objeto vetor da classe mapeadorDeDados q contem 
   //a classe mapeadorDeFilme
   baseDeDados[2] = new MapeadorDeLocacao();
   //criando um objeto vetor da classe mapeadorDeDados q contem   
   //a classe mapeadorDeLocacao
}//fim do construtor

//******************************************************************************
Persistencia::~Persistencia()
{
   if(baseDeDados)delete[] baseDeDados;

}//fim do destrutor

//******************************************************************************
bool Persistencia::gravar(ItemPersistencia *item)
//recebendo um objeto como parametro de uma chamada
{
   return baseDeDados[item->obterTipoDaClasse()]->gravarDados(item);
   //baseDeDados: um objeto da classe Mapeador de Dados
   //Mapeador de Dados
   //item->obterTipoClasse() : chamada do metodo da clsse ItemPersistencia q retorna o atributo tipoDaClasse
   //TIPO DE CLASSE SERIA SE ELA EH UMA PESSOA, FITA OU OUTRO
   //ENTAO BASE DE DADOS E UM VETOR COM APENAS 3 POSICOES PARA IDENTIFICAR EM
   //QUE BASE DE DADOS BUSCAR...CLIENTE, FILME OU PESSOA

}//fim do gravar

//******************************************************************************
bool Persistencia::recuperar(ItemPersistencia *item)
{     
   return baseDeDados[item->obterTipoDaClasse()]->recuperarDados(item);

}//fim do recuperar

//******************************************************************************
//usndo a sobrecarga de operador, os metodos com o mesmo nome se diferenciam pelo seu parametro
bool Persistencia::recuperar(unsigned int id, ItemPersistencia *item)
{//inicio do metodo recuperar
   //std::cout<<" Teste recuperar PERSISTENCIA OK!"<<std::endl;
   //std::cout<<"baseDeDados["<<item->obterTipoDaClasse()<<" ]recuperarDaDos("<<id<<", item);"<<std::endl;
   return baseDeDados[item->obterTipoDaClasse()]->recuperarDados(id, item);     

}//fim do metodo recuperar

//******************************************************************************
bool Persistencia::remover(ItemPersistencia *item)
{
   return baseDeDados[item->obterTipoDaClasse()]->removerDados(item);
   //apos feito todo o processo de remocao sera retornado o "status" da operacao				 

}//fim do remover

bool Persistencia::alterar(ItemPersistencia *item)
{//inicio do metodo alterar
   if(!remover(item)) return false;
   if(!gravar(item)) return false;
   return true;
       
}//fim do metodo alterar

//******************************************************************************

Iterator *Persistencia::listar(ItemPersistencia *item)
{ 
   //o parametro item so esta servindo para entrar dentro do vetor base de dados
   //para indicar em qual posicao ele devera entrar
   return baseDeDados[item->obterTipoDaClasse()]->listagemGeralDeDados();

}//fim do metodo listar

//******************************************************************************
#endif /*PERSISTENCIA_H_*/

