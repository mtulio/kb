// PRODUCT BY MARCO TULIO
#include"MapeadorDeDadosCliente.h"

using namespace std;

//CONSTRUTOR
MapeadorDeDadosCliente::MapeadorDeDadosCliente():
	nomeDoArquivoNoDisco("ArquivoDeCliente.txt")
	{
		std::fstream arquivo;
		try{			
			arquivo.open(nomeDoArquivoNoDisco.c_str(), std::ios::in);
			//se o arquivo nao foi aberto é porque nao foi criado, entao cria um novo
			// para escrita e o limpa
			if(!arquivo.is_open()) arquivo.open(nomeDoArquivoNoDisco.c_str(),std::ios::out|std::ios::trunc); 
			// se o arquivo nao abriu ou nao pode ser criado por algum motivo e retornado um erro
			if(!arquivo.is_open()) throw string("> MpDdCli-Cst: ERRO AO ABRIR/CRIAR ARQUIVO DE CLIENTE");
			arquivo.close();
		}//fim try
		catch(string msg){
			arquivo.close();
			throw msg;
		}//fim throw	
		
	}//fim construtor

bool MapeadorDeDadosCliente::buscarNoArmazenamento(int id, ItemPersistencia *objeto)
{
	/* PREMISSA: 
	 * - BUSCAR um objeto do tipo cliente no arquivo
	 *  
	 */
	// declarando fora do try para que o "arquivo" possa ser enchergado pelo catch
	fstream arquivo;
	try
	{// inicio try
		
		// DECLARANDO 
		
		string linha;
		Cliente clienteAux;
		Cliente *cliente;
		
		//convertendo o objeto(tipo ItemPersistencia) para o tipo Cliente
		cliente = static_cast<Cliente *>(objeto);
		
		//abrindo um arquivo para leitura
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		//verificando se o arquivo foi aberto
		if(!arquivo.is_open()) throw string("> MpDdCli-Bsc: ERRO AO ABRIR O ARQUIVO DE CLIENTE");
		
		//lendo a linha do arquivo
		getline(arquivo, linha);
		
		//laco para repetir linha por linha ate o fim do arquivo
		// para a busca do arquivo no disco, 
		// "REPETE ENQUANTO NAO CHEGUE AO FIM DO ARQUIVO"
		while(!arquivo.eof())
		{//inicio while
			// armazenando os dados do arquivo no objeto atraves do metodo amterializar
			clienteAux.materializar(linha);
			//verificando se o id passado como parametro e o mesmo di id encontrado no arquivo
			if(id == clienteAux.obterIdentificador()){
				// se for o mesmo, apenas fechara o arquivo retornara o status que encontrou o objeto
				// afinal essa eh a finalidade do metodo. Buscar no arquivo o objeto
				// ah.. os valores do id encontrado jah se encontra no ponteiro cliente que aponta
				// pro objeto "objeto" passado como parametro.. como eh um ponteiro, os dois apontam pro 
				// mesmo espaço na memoria
				arquivo.close();
				if(arquivo.is_open()) throw string("> MpDdCli-Bsc: ERRO AO FECHAR O ARQUIVO DE CLIENTE");
				// como cliente e o parametro objeto sao os mesmos(apontam pro mesmo)... a alteracao em cliente alterara em objeto
				cliente->materializar(linha);
				 //ARQUIVO ENCONTRADOOOOOOO
				return true;
			}//fim if
			getline(arquivo, linha);			
		}//fim while
		// se chegou ate aqui eh porque nao encontrou o objeto
		// entao e so fechar o arquivo e retornar falso
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdCli-Bsc: ERRO AO FECHAR O ARQUIVO DE CLIENTE");
		return false;		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	}//fim catch	
}//fim do buscar

void MapeadorDeDadosCliente::gravarNoArmazenamento(ItemPersistencia *objeto)
{
	/* PREMISSAS: 
	 * - armazenar os dados de um objeto do tipo cliente no disco
	 * - antes desse metodo ser chamado, jah foi verificado se o arquivo existe e todos as outras exigencias
	 * entao eh so gravar fisicamente msm
	 *  
	 */
	 // declarando fora do try para que se ocorra algum erro o catch possa enchergar o "arvuico"
	 ///criando objeto para escrita
	 ofstream arquivo;
	 try{
	 	//fazendo a conversao de pai para filho
	 	Cliente *cliente;
	 	cliente = static_cast<Cliente *>(objeto);
	 	if(cliente==0) throw string("> MpDdCli-Grv: PONTEIRO NAO ALOCADO / CONVERSAO NAO EFETUADA");
	 	 
	 	arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::app);
		//if(!arquivo.is_open()) throw string("> MpDdCli-Grv: ERRO AO ABRIR O ARQUIVO DE CLIENTE"); 
	 	
	 	string linha = cliente->desmaterializar();
	 	// escrevendo no FIM ( atraves do ios::app ) arquivo
	 	arquivo<<linha<<endl;	 	
	 	
	 	//depois de escrito no arquvo basta fecha-lo
	 	arquivo.close();
	 	// se o arquivo ainda continuar aberto ocorrera um erro
	 	if(arquivo.is_open()) throw string("> MpDdCli-Grv: ERRO AO FECHAR O ARQUIVO DE CLIENTE");
	 	
	 	// FINALIZANDO O METODO 	
	 }//fim try
	 catch(string msg)
	 {
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		if(arquivo.is_open()) arquivo.close();
		throw msg;		
	 }//fim catch	
}//fim do gravar

void MapeadorDeDadosCliente::removerNoArmazenamento(ItemPersistencia *objeto)
{
	 /* PREMISSAS: 
	 * - remover os dados de um objeto do tipo cliente no disco
	 * - antes desse metodo ser chamado, jah foi verificado se o arquivo existe e todos as outras exigencias
	 * entao eh so remover fisicamente msm
	 *  - criar um arquivo temporario para armazenar o novo arquivo SEM O OBJETO QUE SERA REMOVIDO
	 *  - depois eh preciso renomear para o padrao de arquivo de dados do cliente
	 *  - enfim precisa fazer uma copia
	 */
	
	// ***********************************************************************************************
	// FERRAMENTAS NECESSARIAS PARA MANIPULAR OS ARQUIVOS
	// O arquivo tem como responsabilidade manipular o arquivo orginal
	// e o arquivoBackup tem como responsabilidade manipular o arquivo de copia
	// ***********************************************************************************************
	fstream arquivo, arquivoBackup;
	try{
		// ***********************************************************************************************
		// CONTINUACAO DAS FERRAMENTAS		
		//abrindo arquivo original
		arquivo.open(nomeDoArquivoNoDisco.c_str(),ios::in);
		if(!arquivo.is_open()) throw string("> MpDdCli-Rem: ERRO AO ABRIR O ARQUIVO DE CLIENTE");
		
		//criando um novo arquivo com o ios::out e limpando com o ios:trunc
		string strArquivoBackup = "ArquivoBackupCliente.txt";
		arquivoBackup.open(strArquivoBackup.c_str(), ios::out|ios::trunc);
		if(!arquivo.is_open()) throw string("> MpDdCli-Rem: ERRO AO CRIAR O ARQUIVO DE BACKUP DO CLIENTE");
		// ***********************************************************************************************
		
		string linha;
		Cliente clienteAux;
		// UMA DAS GRANDES VANTAGENS DE TER O IDENTIFICADOR "NO PAI", nao eh preciso fazer a conversao para obter o id
		// o id jah esta no pai
		int id = objeto->obterIdentificador();

		// ***********************************************************************************************
		// MANIPULANDO O ARQUIVO para a COPIA DE TODOS "objetos que estao no arquivo" EXCETO o objeto que sera removido
		// lendo toda a linha do arquivo "arquivo" e armazenando na string linha
		getline(arquivo, linha);
		while(!arquivo.eof())
		{
			// materializando a linha encontrada no arquivo
			clienteAux.materializar(linha);
			// APENAS COPIARA O ARQUIVO QUE TIVER O ID DIFERENTE DA VAR "id"
			if(id != clienteAux.obterIdentificador())
			{//inicio if
				arquivoBackup<<linha<<endl;				
			}//fim if
			getline(arquivo, linha);
		}//fim do while
		//fechando os dois arquivos
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdCli-Rem: ERRO AO FECHAR O ARQUIVO DE CLIENTE");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdCli-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO CLIENTE");
		// ***********************************************************************************************
		
		// ELIMINANDO O ARQUIVO "DESATUALIZADO"
		remove("ArquivoDeCliente.txt");
		// RENOMEANDO O ARQUIVO "ATUALIZADO" ( SEM O NOME PASSADO COMO PARAMETRO)
		rename("ArquivoBackupCliente.txt" , "ArquivoDeCliente.txt");		
	}//fim try
	catch(string msg)
	{
		//se caso ocorreu um erro enquanto o arquvo esteja aberto.. esse comando o fechara
		arquivo.close();
		if(arquivo.is_open()) throw string("> MpDdCli-Rem: ERRO AO FECHAR O ARQUIVO DE CLIENTE");
		arquivoBackup.close();
		if(arquivoBackup.is_open()) throw string("> MpDdCli-Rem: ERRO AO FECHAR O ARQUIVO DE BACKUP DO CLIENTE");
		throw msg;		
	}//fim catch	
}//FIM REMOVER
