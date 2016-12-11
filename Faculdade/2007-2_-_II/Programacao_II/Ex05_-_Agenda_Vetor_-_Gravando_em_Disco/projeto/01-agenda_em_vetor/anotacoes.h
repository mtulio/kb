/* classe Persistencia
 * tem como objetivo armazenar os dados no vetor
 * e alterada para jogar dentro e arquivos
 *  
 * /
 
 //classeInterface
 /*  responsabilidade de ler, escrever, comunicar com o usuario 
  * 
 */
 
 //classe Controle
 /* listagem geral, solicita obter todos os vetores
  * faz uma copia, pega a copia dos valores/nomes e manda pra interface.
  * n pode enviar o original, pois pode ser perdido.  
  * 
 */
 
 //classe Iterador
 /* como fazer a copia: estrutura e chamado de iterador(nova classe) >> padroes de projeto, veiculo pelo qual manda os dados para algum lugar, elemento que monta os pacotes pra enviar
  * iterador=tamnho, IU, controlador de posição(posição) e objeto da classe Conjunto.
  * construtor, cria um vetor de pessoas... identico o da persistencia
  * a diferença q o otro e estatico e esse e dinamico, no construtor faz a copia da agenda
  * pois o iterator e o veiculo de transporte
  * iterador *it=new iterador(conjunto, tamanho, IU)
  * iterator, tem a facilidade de trabalhar com os vetores, pra alterar a posição pra imprimir na tela
  * it::proximo() : verifica se ainda existe a posição cada vez q verifica ate o ultimo
  * return !static_cast<bool>(indiceUso)  ??????? na classe persistencia 
  * 
 */
 
 // a jogada: dar a cada classe a sua responsa
 
 
 /* trabalho
  * listagem organizada>>saida de dados, classe Interface, listar com o inico da letra do nome
  * 1. obter todas as pessoas, construir outro metodo de obter todas as pessoas, imprimir o 1 caractere
  * >>olhar a classe string, search, pesquisa na string e ve se existe a palavra ou n... 
  * depois usar um if... pq search retorna V ou F
  * se a lista vier vazia n podera imprimir
  * antes de imprimir na tela verificar se existe ou n...o iterador tem um metodo estaVazio();
  * CORRIGIR na classe Interface, ele n verificou se existe algum nome no vetor >> xamar o metodo estar vaizio dentro da classe interface 
  * 
  * *************************************************************************************************************************************
  * 
  * BIblioteca
  * #include<fstream> // biblioteca para trabalhar com arquivos
  * 
  * - Criando um objeto arquivo
  * ifstream nomeDoArquivo; // arquivo de entrada - vai la no disco pega o arquivo le todo o conteudo dele e traz para a memoria
  * tiro da memoria secundaria leio e trago pra a memoria principal
  *  
  * ofstream nomeDoArquivo; // arquivo de saida - 
  * fstream nomeDoArquivo;  
  * 
  * -criando e abrindo um objeto arquivo 
  * ifstream nomeDoArquivo("nomeArquivonodico");//quando eu coloquei ifstream eu falei q e um arquivo
  * de entrada...
  * 
  * 
  * ofstream nomeDoArquivo("nomedoarquivonodisco");
  * fstream nomeDoArquivo("nomedoarquivonodisco");
  * 
  * 
  * - Abrindo arquivos
  * 
  * ifstream::open("nomearquivodisco",ios::in); // ao abrir o arquivo disse q e somente de entrada
  * quando voce coloca o in voce ta dizendo vai la abre o arquivo que eu quero ler ele, se ele nao encontrar o arquivo ele fala que nao existe
  * 
  * ofstream::open("nomearquivo",ios::out/ios::trunc); // esse e para sair.... se existe ele esvazia
  * se nao existe ele cria
  * 
  * fstream::open("nomearquivodisco",ios::in/ios::out); // fstream e uma caracterista que tanto voce ler e o quanto voce escrever....
  * se ele te da a possibilidade d eler o arquivo tem que existir... se ele existe ele abre
  *  o arquivo existe ? sim
  * entao abre
  * ai ele fica "esperando" voce dar a ordem se voce quer ler ou escrever
  * 
  * 
  * -teste de abertura do arquivo
  * 
  * boolis.open(); para perguntar se abriu ou nao...
  * 
  * -fechando um arquivo
  * 
  * close(); se vc abriu voce tem que fexar... usa-se para fexar o arquivo
  * 
  * -teste do fim do arquivo
  * 
  * bool eof();     
  * open e um metodo da classe ifstream,ofstream,fstream
  *
 */
 
