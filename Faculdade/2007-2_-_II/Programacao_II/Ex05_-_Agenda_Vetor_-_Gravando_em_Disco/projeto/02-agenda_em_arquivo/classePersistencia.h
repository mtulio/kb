#ifndef CLASSEPERSISTENCIA_H_
#define CLASSEPERSISTENCIA_H_
#include"classePessoa.h"
#include"classeIterador.h"
#include<string>
#include<fstream>
//*****************************************************************
//      Esta classe manipula a agenda em arquivo...
//       cria, apaga, atribui, obtem, faz uma copia para listagem geral,
//       diretamente no arquivo em disco, filtra um arquivo por letra
//       e o mais interessante sao nos metodos de listagemGeral e listagemPorNome
//       pois quando eles sao enviados para o iterador, eles virarão um vetor novamente 
//       como no trabalho da Agenda em Vetor
//*****************************************************************
class Persistencia
{
	//Atributos
	private:
		std::string nomeDoArquivoNoDisco;
		
	//Metodos
		//o busca e privado por causa que apenas os metodos de sua classe vao acessa-lo
		//nessas condicoes nao ha necessidade do busca ser publico
        bool busca(const std::string &nome,Pessoa &objPessoa)const;
	public:
		Persistencia();//Construtor
		~Persistencia(){};//destrutor
		int atribuir(const Pessoa &objeto);//Armazenar um nome dentro do arquivo
		bool obter(const std::string &nome, Pessoa & objPessoa)const;
		bool apagar(const std::string &nome);
		Iterator* obterTodasAsPessoas();
		Iterator* obterTodasAsPessoasPorNome(char letra);
		std::string obterNomeDoArquivo(){return nomeDoArquivoNoDisco;}
		
};//fim da declaracao da classe 

//***********************************************************************************************

Persistencia::Persistencia():nomeDoArquivoNoDisco("ArquivoAgenda.txt")//o construtor tem como objetivo criar o arquvivo
//A unica maneira de iniciar os atributos e pelos construtores da sua classe
//o Construtor desta classe esta iniciando o atributo do tipo string com o nome 
//do arquivo para ser criado, ou seja, o nome do arquivo e a extensao do arquivo(txt)
//logo depois ele instanciara um objeto na memoria do tipo fstream...
/* fstream (f de file + stream). Esta biblioteca define 3 novos tipos de dados:
    * ofstream (apenas para a direção output – out to a file. serve para criar 
         arquivos e escrever, não serve para ler)
    * ifstream (apenas na direcção input – from a file . serve para ler arquivos, 
         receber dados dos arquivos, não serve para criar nem escrever)
    * fstream (este conjuga os dois tipos anteriores, input e output to file. 
         cria arquivo, escreve e lê informação dos arquivos.
*/
{
	std::fstream arquivo;//instanciando um objeto na memoria do tipo fstream
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
/* Esta função tem como primeiro argumento o nome e localização do arquivo a ser 
aberto. O segundo membro tem a ver se queremos abrir num modo diferente do defaut.
modos de abertura:
      ios::app : acrescenta ao fim do arquivo  (apend - Anexar)
      ios::ate : se o arquivo ja existe, o programa vai para o final do mesmoo  (ate, at end - no final)
      ios::in : abre o arquivo para entrada (leitura). As informações serao lidas no arquivo, o arquivo n sera criado se n existir 
      ios::out : abre o arquivo para escrita (saida). As informações serao escritas no arquivo, por padrao o arquivo existente conteudo sera substituido
      ios::nocreat : nao cria se o arquivo nao existe (uma falha)
      ios::noreplace : se o arquivo ja existir ocorre uma falha.
      ios::binary : abre o arquivo em modo binario ("NAO ENTENDI")
      ios::trunc : elimina o arquivo se jah existe e recria (default)

NO CASO DO CONSTRUTOR ELE ESTA USANDO ios::in, POIS INICIALMENTE ELE CRIARA UM 
NOVO ARQUIVO PARA LEITURA SE NAO EXISTIR
*/
	if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc);//..criara um novo arquivo pra escrita, e o limpará com o comando trunc
    //if: VERIFICARA SE O ARQUIVO ABRIU, o metodo is_open() verifica se o arquivo foi aberto
    // e retornara bool, 1 abriu e 0 para falha, e se ocorrer falha a negacao permitira a entrada 
    //no if e executara um comando para a criacao de um novo arquivo do tipo de saida(ios::out)
    // e limpara(ios::trunc) os dados existentes dentro do arquivo
	arquivo.close();
	//este metodo fecha o arquivo que foi testado a abertura ou criado
}

//***********************************************************************************************

bool Persistencia::busca(const std::string &nome, Pessoa &objPessoa)const//01.3 >> recebe um nome para verificar e o objeto a ser verificado
//este metodo tem como parametros de entrada um nome e de saida um objeto da classe pessoa
// O busca tem como funcao buscar um nome informado dentro do arquivo e se encontrado
//retornar os dados deste nome "compactado" dentro do objeto da classe pessoa objPessoa 
//que vai ser o parametro de saida.
{// inicio do metodo
	std::fstream arquivo;//criando um objeto da classe fstream
	std::string linha,nomeAux;
	//A variavel linha tem como ojetivo receber a linha do arquivo, 
    //e o nomeAux seria um nome temporario,que vai estar no arquivo, para verificar 
    //se o nome (PARAMETRO) e igual ao nomeAux
	Pessoa pessoaAux;
    //criando um objeto "temporario" da classe pessoa, para receber os dados 
    // existentes no arquivo
	arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::in);
    //abre um arquivo para leitura (ios::in)
	getline(arquivo,linha);
    //DEFINICAO: armazena no buffer tudo o que foi digitado, INCLUSIVE os espaços. e termina em \n ou endl (fim de linha)
    //armazena na variavel linha a primeira linha do arquivo aberto
	while(!arquivo.eof()){
 //"eof - end of file">>metodo bool que verifica o fim do arquivo, 
 // o lacao se repetirá enquanto n for o fim do arquivo
		pessoaAux.atribuir(linha);
  // enviando uma string, q contem os dados(nome;telefone;email;) da linha do arquivo, 
  // para o metodo atribuir da classe pessoa
  		pessoaAux.obterNome(nomeAux);
  // chamada do metodo obterNome da classe pessoa q retorna como parametro a copia 
  // do atributo nome(da classe pessoa) e armazenara na variavel nomeAux
		if(nome==nomeAux){
  // verifica se o nome q foi enviado como parametro do metodo busca e igual ao nome da linha 
  // q foi atribuida
			arquivo.close();
			// se encontrou o nome, fechara o arquivo, pois n precisara mais usar o arquivo
            // pois todos os dados(nome,telefone,email)jah estao dentro do objeto auxiliar 
            // da classe pessoa(pessoaAux)
			pessoaAux.obter(linha);
            // como os dados do nome buscado estao dentro de um objeto auxiliar, 
            //faz-se essa chamado do metodo obter que "compacta" as informações novamente dentro 
            // da string e a envia como parametro q sera armazenado na variavel string linha 
			objPessoa.atribuir(linha);
            // como o objetivo do metodo busca eh buscar um nome no arquivo, "empacotar" os dados 
            // e retorna-lo como um parametro, ele xama o metodo atribuir q tem uma string com os dados
            // no metodo atribuir ele separará a string e guardara seus respectivos atributos no objeto objPessoa
            // e "devolvera" como parametro do metodo busca.
            return true;
            //SERVICO FEITO, nome encontrado, atribuido, "compactado" em um objeto 
            //da classe pessoa e enviado como parametro com sucesso.
		}
		getline(arquivo,linha);
		//caso n encontre o nome na linha pesquisada, o getline ira ler a proxima linha do arquivo
	}//fim do while
	//e vair ler linha por linha ate chegar ao fim do arquivo
	return false;
	// apos verificar linha por linha do arquivo e nao encontrar o nome desejado, 
    // retornara false que significa q o nome nao foi encontrado
}// fim do metodo busca

//***********************************************************************************************

int Persistencia::atribuir(const Pessoa &objeto)
//01.2 >> recebe um objeto da classe pessoa enviado pela classe controle
//O metodo atribuir recebe um objeto da classe pessoa(conjunto de dados como nome,telefone,email) como parametro,
// e tem como objetivo guarda-lo dentro do arquivo
{// inicio metodo
	std::string nome;
    //criando uma var string para receber o nome que o metodo obterNome da classe pessoa retorna
	objeto.obterNome(nome);
	// foi enviado um conjunto de dados como parametro, e preciso ter acesso ao nome dele
	// por isso a chamada do metodo obter nome da classe pessoa, ele retornara o nome "compactado" 
	Pessoa objPessoa;
	//Instanciando na memoria um objeto da classe pessoa usando o construtor "sem parametros"
	//LEMBRANDO - objPessoa n tera utilidade alguma neste programa pois, o busca exige como
	// parametros o nome e um objeto da classe pessoa, como eh OBRIGADO preencher estes parametros 
	//foi criado esse objeto, EH SO LEMBRAR DO METODO ATRIBUIR E DA UTILIDADE DA VARIAVEL POS NO if 
    // DO PROGRAMA AGENDA EM VETOR, ele eh a "putinha" temporaria q so recebe informacao q n vai ser usada futuramente... =D
	if(!busca(nome,objPessoa)) {//01.3 chamada do metodo busca, enviando como parametro o nome digitado pelo user e o novo objeto criado
	// enviando para o metodo busca o nome do objeto que foi informado como parametro do atribuir
    // se nao for encontrado nenhum nome, ele entrara no if atraves da negacao( ! ) e o busca 
    //"devolvera" os dados do nome buscado na agenda dentro de um objeto (objPessoa)
            std::ofstream arquivo;
            //instancia um objeto com nome arquivo do tipo ofstream - somente escrita
			arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::app);//std::ios::app>>acrescenta no fim do arquivo
			// abrira o arqivo da variavel string "nomeDoArquivoNoDisco" e vai para o fim do arquivo 
			// para comecar a anexar novas informacoes no arquivo
			std::string linha;//receberá a ultima linha
			// criara uma string para receber as informacoes "compactadas" atraves do metodo obter
			objeto.obter(linha);//retorna uma string com todos os valores
			// obter coloca todos os valores em uma var string e a retorna como parametro
			// sendo assim esses valores vao ser armazenados na variavel "linha"
			arquivo<<linha<<std::endl;//escreve a string no arquivo, endl: significa o enter no final de cada linha
			//LEMBRE-SE de cout<<variavel<<endl;
			// para escrever em um arquivo basta colocar o nome do arquivo q foi instanciado no inicio do 
			// metodo "<<" e a string q vai ser escrita no arquivo, no caso a var linha
			// e no fim da linha e colocado um "endl" para passar para a proxima linha
			arquivo.close();
            //fechara o arquivo		
			return 1;// INCLUSAO FEITA
			// o programador tem q saber o valor do retorno do metodo, para q "usuarios/classes" 
            // externas possam acessa-las e entede-las
			// neste caso 1 significa q a inclusao foi feita com sucesso
		}else return 2; //  NOME JAH EXISTE
		//caso n entre no if, n executara nenhuma dessas funcoes anteriores 
		//consequentemente n atribuira o nome, concluindo q o nome existe,
		//pois foi feito uma busca dele antes de ser atribuido
		
		//PARA MAIORES INFORMACOES SOBRE OS VALORES DE RETORNO, FAVOR VERIFICAR 
		// O PRIMEIRO CASE DO METODO "MENU PRINCIPAL" DA CLASSE INTERFACE
}// fim metodo atribuir

//***********************************************************************************************

bool Persistencia::obter(const std::string &nome, Pessoa &objPessoa)const
// Este metodo tem como parametros de entrada um nome e de saida um objeto da classe
// pessoa contendo todas as informacoes do paramatro de entrada
//PIMBA - EH MAIS DOCE DO QUE MAMAO COM ACUCAR  =D
// o objeto retornado pelo busca jah vai conter todas as informacoes necessarias 
// q o parametro de saida do metodo obter precisa, q eh um objeto com todos os dados
// do parametro de entrada
// \o/ DEPOIS DA BUSCA E ENCONTRADO O NOME, ESSE METODO SO RETORNA UM OBJETO COM 
// OS DADOS DO NOME COMO PARAMETRO
{
       if(busca(nome,objPessoa)){
// enviara o paramentro de entrada para o metodo busca, e se encontrado o busca 
//retornara um objeto da classe pessoa q jah sera o parametro do metodo obter
             return true;//nome obtido
             //se entrou no if e pq existe o nome na agenda consequentemente jah retornara verdadeiro
             // Q TESAOOOOO - OLHA O TAMANHO DO BLOCO DE COMANDOS DESSA PORCARIA
             /// NOOOOO PIREIIII 
       }else return false;
       //se n entrar no if eh pq n encontrou o nome, entao retornara false
}

//***********************************************************************************************

bool Persistencia::apagar(const std::string &nome)
//este metodo tem como parametro de entrada um nome para ser apagado da agenda
// PROCEDIMENTO - abrira o arquivo
{//procurar ate encontrar o nome, depois substitui-lo pelo ultimo numero
     Pessoa objPessoa;
     //criando um objeto da classe pessoa para fazer a atribuicao de cada linha da agenda
     
     std::ifstream arquivoAgenda;
     //instanciando um objeto do tipo ifstream para ler os dados da agenda
     arquivoAgenda.open(nomeDoArquivoNoDisco.c_str());
     //abrindo a agenda
     std::string linha,nomeAux;
     getline(arquivoAgenda,linha);
     //lendo a 1 linha do arquivo aberto
     
     std::ofstream arqTemp;
     //instanciando um objeto do tipo ofstream - escrita, para fazer a copia da agenda
     std::string arquivoTemporario="temp.txt";
     //armazenadno o nome do arquivo dentro da string "arquivoTemporario"
     arqTemp.open(arquivoTemporario.c_str(),std::ios::trunc);
     //criara um novo arquivo para escrita (ios::out) e logo depois limpara este novo arquivo (ios::trunc)
     while(!arquivoAgenda.eof()){
     //OBJETIVO DO WHILE - FAZER UMA *COPIA DA AGENDA PARA UM ARQUIVO TEMPORARIO, 
     // *AO FAZER ESSA COPIA ELE ELIMINARA DESSA COPIA O NOME(parametro) 
     // EFIM COPIARA TODOS OS NOMES EXCETO O NOME INFORMADO COMO PARAMETRO DE ENTRADA
     //CONDICAO - vai repetir enquanto n xegar no fim da agenda, 
     
            objPessoa.atribuir(linha);
            //enviando uma string para o metodo atribuir aos metodos da classe pessoa
            objPessoa.obterNome(nomeAux);
            //obtendo o nome do atributo, atraves do metodo obterNome, a linha q acabou de ser atribuida
            if(nome!=nomeAux){
            //Condicao para fazer a copia do aquivo, vai verificar linha por linha
            //se o nome q eh o parametro de entrada do metodo apagar 
            // e igual ao nome obtido da leitura da linha do arquivo
            // se os nomes forem diferentes a condicao do if sera verdadeira pela negacao 
            // e executara o bloco de comandos do if
                              arqTemp<<linha<<std::endl;
                              //ESSE COMANDO EH AONDE FAZ A COPIA DA AGENDA
                              //Ele vai escrever linha por linha da agenda 
                              // no arquivo temporario EXCETO O NOME INFORMADO PELO PARAMETRO
            }
            getline(arquivoAgenda,linha);
            //comando tem como funcao ler a proxima linha do arquivo e assim 
            //sucessivamente ate o fim do arquivo
     }//fim do while
     //apos sair do while sera o fim da agenda
     arquivoAgenda.close();
     arqTemp.close();
     //ao sair do laço fechara a agenda e o arquivo temporario,
     //E DENTRO DESTE ARQUIVO TEMPORARIO ESTARA A AGENDA SEM O NOME DESEJADO
     
     //PROXIMO PASSO - RESTAURAR O ARQUIVO TEMPORARIO PARA O ARQUIVO DA AGENDA
     std::ifstream copiaArqTemp;
     //instanciando um objeto para leitura
     copiaArqTemp.open(arquivoTemporario.c_str());
     //abrindo o arquivo temporario para leitura (ios::in)
     getline(copiaArqTemp,linha);
     //vai fazer a leitura da primeira linha da copia da agenda e armazenara essa string
     //na variavel "linha"
     
     std::ofstream restauracaoAgenda;
     //instanciando um objeto na memoria do tipo ofstream - escrita
     //esse objeto servira para restaurar a copia do arquivo temporario para a agenda
     restauracaoAgenda.open(nomeDoArquivoNoDisco.c_str(),std::ios::trunc);
     //este comando abrira o arquivo da agenda original, para escrita, e apagará todo 
     // o conteudo q existe dentro dele... 
     //PRA QUE FEZ ISSO?! Para copiar o arquivo temporario de volta pra dentro da agenda
     while(!copiaArqTemp.eof()){
     //While tem como funcao ler linha por linha do arquivo temporario ate o fim do arquivo
     //enquanto n xega ao fim do arquivo o laco se repetira
                        restauracaoAgenda<<linha<<std::endl;
                        //este comando copiara para dentro da agenda todas as linhas do arquivo temporario
                        //EH AQUI Q ESTA RETORNANDO A COPIA DO TEMPORARIO PARA A AGENDA ORIGINAL
                        getline(copiaArqTemp,linha);
                        //ira ler a proxima linha do arquivo temporario e armazenar na string linha
                        //e continuara o while ate o fim do arquivo temporario
     }
     //ao fim do while a copia do arquivo temporario jah foi restaurado para o arquivo original a Agenda
     //AGORA JAH PODE FECHAR OS DOIS ARQUIVOS E A AGENDA ESTARA SEM O NOME SOLICITADO
     //OU SEJA O NOME FOI APAGADO
     copiaArqTemp.close();
     restauracaoAgenda.close();  
     //fechando os dois arquivos
     return true;//se acontecer td dentro das "ordes" retornara q foi possivel apagar o arquivo
     //apos todos esses processos o nome foi apagado e retornara true para o metodo
}

//***********************************************************************************************

Iterator* Persistencia::obterTodasAsPessoas()
/*este metodo tem como objetivo:
1 - verificar quantas posicoes(linhas usadas) tem no programa
2 - CRIAR UMA COPIA DA AGENDA Q ESTA ATUALMENTE EM ARQUIVO E PASSA-LAS PARA DENTRO DE
DE UM VETOR DE OBJETOS DA CLASSE PESSOA
*/
{
	//1 FOR, TEM COMO FUNCAO ABRIR O ARQUIVO E CONTAR QTAS POSICOES QUE ESTAO SENDO USADAS
	std::ifstream agendaLer, agendaCopiar;
    //estava dando conflito ao usar um objeto para abrir o arquivo duas vezes
    //por isso foi instanciado dois objetos, para corrigir esse "conflito"
    //agendaLer - eh um objeto ifstream que vai ser usado para abrir a agenda 
    //  para leitura de qtas linhas contem na mesma
    //agendaCopiar - objeto criado para leitura e copias de cada linha da agenda
    // AMBOS SAO PARA LEITURA
	agendaLer.open(nomeDoArquivoNoDisco.c_str());
	//abrindo o arquivo agenda.txt
	std::string linha;
	//criando uma var string para leitura da linha do arquivo
	int contador=0;
	//iniciando o contador de linhas do arquivo com 0
    getline(agendaLer,linha);
	//vai ler a primeira linha da agenda
    for(contador=0;!agendaLer.eof();contador++){
    //este laco tem como objetivo verificar qtas linhas o arquivo tem, 
    // a responsabilidade de guardar qtas linhas fica com a variavel contador
                                              getline(agendaLer,linha);
                                              //lendo a proxima linha do arquivo
    }
    //ao fim do for jah podera saber a qtd de linhas tem dentro do arquivo
    //e asssim, a qtd de nomes, e a qtd de posicoes vao usar em um vetor
    //que vai ser criado logo abaixo
    agendaLer.close();
    //apos fazer a leitura feche a agenda, pois estou no fim do arquivo.
		
    // 2 PARTE:
    // ESSA PARTE DO METODO ABRE O ARQUIVO E ARMAZENA OS DADOS DENTRO DE UM VETOR DA CALSSE PESSOA

	agendaCopiar.open(nomeDoArquivoNoDisco.c_str());
	//abrindo a agenda novamente,

	getline(agendaCopiar,linha);
	//armazenara a primeira linha da agenda
	    
    Pessoa *agendaVetor = new Pessoa[contador];
    //CRIANDO UM PONTEIRO VETOR DE OBJETOS DA CLASSE "PESSOA" DO TAMANHO "CONTADOR"
	for(unsigned int pos=0;!agendaCopiar.eof();pos++){//for 2
	//Este for tem o objetivo de caminhar linha por linha da agenda
	// PRA QUE? para colocar os dados obtidos em cada linha dentro do vetor conjunto
	// ESSA EH A PARTE EM QUE O ARQUIVO VIRA UM OBJETO  ;D
        agendaVetor[pos].atribuir(linha);
        //preenchendo os dados em cada posicao do vetor
        // >> Que vetor? uma agenda em vetor q foi criada para receber todos os dados(nome, telefone e email)do arquivo
        // >> Como eh feito isso? atraves do metoto atribuir q tem como parametro de entrada uma string
        //    e no corpo deste metodo separara dessa string todos os atributos do objeto da classe pessoa
        // AGORA DENTRO DA POSICAO "pos" tera um objeto da classe pessoa com os dados que tinham na linha "linha"
        getline(agendaCopiar,linha);
        //le a proxima linha do arquivo e armazena na var "linha"		
	//Esse procedimento eh repetido ate q xegue no fim do arquivo
    }
    //APOS SAIR DO FOR: PRONTO CRIADO UMA NOVA AGENDA EM VETOR COM TODOS OS DADOS DO ARQUIVO
	agendaCopiar.close();//fechando arquivo
	//fechando a agenda em arquivo
	Iterator *it = new Iterator(agendaVetor,contador,contador);//parametros do construtor iterador
	//alocando dinamicamente um espaco na memoria do um objeto do tipo Iterator
	//verificar o construtor do iterator
	// mas eh assim: Iterator nomeObjeto(ObjetoDaClassePessoa, tamanho, IndiceUso)
	return it;
	//retornando para o metodo do tipo iterartor um objeto oterator
}

//***********************************************************************************************

Iterator* Persistencia::obterTodasAsPessoasPorNome(char letra)
//tem como funcao verificar na agenda se existe algum nome com a letra q e o parametro de entrada

{//tem como objetivo listar todos os arquivos por nome
    //1 FOR, TEM COMO FUNCAO ABRIR O ARQUIVO E CONTAR QTAS POSICOES ESTAO SENDO USADAS
		
    std::ifstream agendaLer, agendaCopiar;
    //estava dando conflito ao usar um objeto para abrir o arquivo duas vezes
    //por isso foi instanciado dois objetos, para corrigir esse "conflito"
    //agendaLer - eh um objeto ifstream que vai ser usado para abrir a agenda 
    //  para leitura de qtas linhas contem na mesma
    //agendaCopiar - objeto criado para leitura e copias de cada linha da agenda
    // AMBOS SAO PARA LEITURA
	agendaLer.open(nomeDoArquivoNoDisco.c_str());//abrindo o arquivo pra leitura
	//abrindo o arquivo agenda.txt
	std::string linha;
	//criando uma var string para leitura da linha do arquivo
	int contador=0;
	//iniciando o contador de linhas do arquivo com 0
    getline(agendaLer,linha);
	//vai ler a primeira linha da agenda
    for(contador=0;!agendaLer.eof();contador++){
    //este laco tem como objetivo verificar qtas linhas o arquivo tem, 
    // a responsabilidade de guardar qtas linhas fica com a variavel contador
                                              getline(agendaLer,linha);
                                              //lendo a proxima linha do arquivo
    }
    //APOS SAIR DO FOR: PRONTO CRIADO UMA NOVA AGENDA EM VETOR COM TODOS OS DADOS DO ARQUIVO
	agendaLer.close();
    //fechando a agenda em arquivo
		
    // 2 PARTE:
    // ESSA PARTE DO METODO ABRE O ARQUIVO E ARMAZENA OS DADOS DENTRO DE UM VETOR DA CALSSE PESSOA
	agendaCopiar.open(nomeDoArquivoNoDisco.c_str());
	//abrindo a agenda para leitura, foi especificado q e de entrada na instancia do objeto
	getline(agendaCopiar,linha);
	//lendo a primeira linha do arquivo   
    
	Pessoa *objAux = new Pessoa[contador];//criando um objeto para auxiliador para verificação
	//Este objeto tem como objetivo fazer uma copia completa da agenda, 
	//MAS NAO E ISSO A MINHA FINALIDADE, POR ISSO Q EH UM OBJETO AUXILIADOR
   
	for(unsigned int pos=0;!agendaCopiar.eof();pos++){
	//ESTE laco faz a copia do arquivo para uma agenda em vetor
        objAux[pos].atribuir(linha);
        //atribuir a linha dentro do objeto do veotr
        getline(agendaCopiar,linha);
        //le a proxima linha do arquivo		
	}
	//ao fim TERA UMA COPIA DA AGENDA DENTRO DE UM VETOR AUX DA CLASSE PESSOA
	agendaCopiar.close();
	//fechar o arquivo pois ele nao vai mais ser usado
	
	//VERIFICANDO SE EXISTE A LETRA DESEJADA
	Pessoa *agendaPorLetra = new Pessoa[contador];
	//criando um ponteiro vetor de pessoas (uma nova agenda em vetor)
	//essa realmente q te interessa
    std::string nome;
    //declarando esta var para verificar os nomes de cada objeto
    int pos2=0;
    //essa pos2, sera o indice de uso e o tamanho desse novo vetor
    //
    for(unsigned int pos=0; pos<contador; pos++){
    //ESTE FOR TEM COMO OBJETIVO CAMINHAR POSICAO POR POSICAO PARA VERIFICAR A 
    //PRIMEIRA LETRA DO NOME COM A LETRA DO PARAMENTRO DE ENTRADA
                 objAux[pos].obterNome(nome);
                 //obtendo o nome do objeto objetoAux(copia de toda a agenda) 
                 if (nome[0]==letra){
                 //compara a primeira posicao da string do nome com a letra digitada
                                     agendaPorLetra[pos2]=objAux[pos];
                                     //se a letra for igual, ele vai na agenda em vetor auxiliar
                                     //e armazena na agenda em vetor principal(cionjunto)
                                     pos2++;
                                     //incrementara indice de uso dessa nova agenda
                 }//fim do if
                 //se nao entrar no if vai continuar caminhando posicai por posicao no veto r ate o fim do vetor
    }//fim do for
    //
	//pos2: e o indentificador que indicará a quantidade de posições(indiceUso) usadas no vetor e tbm o tamanho
    
    Iterator *it = new Iterator(agendaPorLetra,pos2,pos2);//parametros do construtor iterador
	//alocando dinamicamente um espaco na memoria do um objeto do tipo Iterator
	//verificar o construtor do iterator
	// mas eh assim: Iterator nomeObjeto(ObjetoDaClassePessoa, tamanho, IndiceUso)
    return it;
    //retornando para o metodo do tipo iterartor um objeto oterator
}//fim do metodo
#endif /*CLASSEPERSISTENCIA_H_*/

/*
Que porcaria, terminei de comentar essa classe no dia
13/12/2007 as 05:38am
=(
n tah facil...
*/
