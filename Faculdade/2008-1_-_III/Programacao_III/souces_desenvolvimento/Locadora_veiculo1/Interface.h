#ifndef INTERFACE_H_
#define INTERFACE_H_

#include<iostream>
#include<iomanip>
#include"ControleCliente.h"
#include"ControleVeiculo.h"
#include"ControleLocacao.h"
#include"Persistencia.h"
using namespace std;

class Interface
{
private:
	// se nao colocasse static nao era possivel a chamada de metodos enrte si 
	// dentro desse arquivo
	static void menuCliente(Persistencia *locadora);
	static void lerDadosCliente(Cliente *cliente);
	static void escreverDadosCliente(Cliente *cliente);
	
	static void menuVeiculo(Persistencia *locadora);
	static void lerDadosVeiculo(Veiculo *veiculo);
	static void escreverDadosVeiculo(Veiculo *veiculo);
	
	static void menuLocacao(Persistencia *locadora);
	static void lerDadosLocacao(Locacao *locacao, Persistencia *locadora);
	static void lerDadosDevolucao(Locacao *locacao, Persistencia *locadora);
	
public:
	static void menuPrincipal(Persistencia *locadora);
	
	
};


void Interface::menuPrincipal(Persistencia *locadora)
{
	try{
		int opcao=1;
		
		
		while(opcao){
			system("clear");
			cout<<endl<<"\tMENU PRINCIPAL"<<endl;
			cout<<endl<<" 1 - Manter Cliente";
			cout<<endl<<" 2 - Manter Veiculo";
			cout<<endl<<" 3 - Manter Locacao";
			cout<<endl<<" 0 - Sair do programa";
			cout<<endl<<" Digite a Opcao: ";
			cin>>opcao;
			
			switch(opcao){
			case 1:{
				menuCliente(locadora);
				break;
			}//fim case 1
			case 2:{
				menuVeiculo(locadora);
				break;
			}//fim case 2
			case 3:{
				menuLocacao(locadora);
				break;
			}//fim case 3
			case 0:{
				cout<<" Saindo do programa.. TECLE ENTER!"<<endl;
				cin.get();cin.get();
				exit(1);
			}//fim case 0
			}//fim switch			
		}//fim while		
	}//fim try
	catch(string msg){
		cout<<" Erro: "<<msg<<endl;
	}	
}//fim menu principal


//***********************************************************************
// 			MENU CLIENTE

void Interface::menuCliente(Persistencia *locadora)
{
	try{
		ControleCliente ctrlCliente(locadora);
		int opcao=1;
		while(opcao){
			system("clear");
			cout<<endl<<"\tMENU CLIENTE"<<endl;
			cout<<endl<<" 1 - Incluir";
			cout<<endl<<" 2 - Alterar";
			cout<<endl<<" 3 - Consultar";
			cout<<endl<<" 0 - Retornar ao Menu Principal"<<endl;
			cout<<" Digite a Opcao: ";
			cin>>opcao;
			switch(opcao){
			case 1:{
				try{
					system("clear");
					cout<<" Incluir Cliente"<<endl;
					int id;
					cout<<" Digite o ID: ";
					cin>>id;
					Cliente cliente(id);
					
					if(ctrlCliente.consultarCliente(&cliente)){
						cout<<"\t ID Existente! Inclusao Cancelada!"<<endl;
						cout<<" ID: "<<cliente.obterIdentificador()<<endl;
						cout<<" Nome: "<<cliente.obterNome()<<endl;
						cout<<" Tecle Enter para continuar!"<<endl;
						cin.get();cin.get();
						break;
					}
					
					lerDadosCliente(&cliente);
					if(ctrlCliente.incluirCliente(&cliente))
					{
						cout<<" Cliente incluido com Sucesso!"<<endl;
						cin.get();cin.get();
						break;
					}
					else {
						cout<<" Erro inesperado na inclusao!"<<endl;
					}					
					break;
				}//fim try
				catch(string msg){
					cout<<"> Erro IntMnCli-Inc: "<<msg<<endl<<endl;
					cin.get();cin.get();
					break;
				}//fim catch
			}//fim case 1
			
			case 2:{ // ALTERACAO
				try{
					system("clear");
					cout<<" Alteração de Clientes"<<endl;
					int id;
					cout<<" Digite o ID: ";
					cin>>id;
					Cliente cliente(id);
				
					// mandar consultar, se encontrar vai alterar senao sai do case
					if(ctrlCliente.consultarCliente(&cliente)){
						escreverDadosCliente(&cliente);
						cout<<" Deseja realmente alterar o cliente(s/n)?:";
						cin.ignore();
						char resp;
						cin>>resp;
						if(resp!='S' && resp!='s') resp = 'n';
						if(resp=='S' || resp=='s'){
						lerDadosCliente(&cliente);
						if(ctrlCliente.alterarCliente(&cliente)){
							cout<<" Alteração efetuada com sucesso!"<<endl;
							cin.get();cin.get();
							break;
						}
						else {
							cout<<" Alteracao nao efetuada!"<<endl;
							cin.get();cin.get();
							break;
						}
						}//fim if resp
						else {
							cout<<" Alteracao Cancelada! Tecle Enter";
							cin.get();cin.get();
							break;
						}
					}// fim if consulta
					else{
						cout<<" Cliente nao cadastrado!"<<endl;
					}
					cin.get();cin.get();
					break;
				}//fim try
				catch(string msg){
					cout<<"> Erro IntMnCli-Alt: "<<msg<<endl<<endl;
					cin.get();cin.get();
					break;
					}//fim catch				
				}//fim case 2
			
			case 3:{ // consultar
				try{
					system("clear");
					cout<<" Consultar Cliente"<<endl;
					int id;
					cout<<" Digite o ID: ";
					cin>>id;
					Cliente cliente(id);
					
					if(ctrlCliente.consultarCliente(&cliente)){
						escreverDadosCliente(&cliente);
						cout<<" Consulta Efetuada...Tecle Enter para voltar!"<<endl;
						cin.get();cin.get();
						break;
					}
					else {
						cout<<" Cliente nao encontrado!"<<endl;
						cin.get();cin.get();
					}
					break;
				}//fim try
				catch(string msg){
					cout<<"> Erro IntMnCli-Cst: "<<msg<<endl<<endl;
					cin.get();cin.get();
					break;
				}//fim catch				
			}//fim case 3
			
			case 0:{ //retornando ao menu principal
				return;								
			}//fim case 3
			
			}//fim switch			
		}//fim while	
	}//fmi try
	catch(string msg){
		cout<<"> Erro IntMnCli - "<<msg<<endl<<endl;
	}//fim catch	
}//fim menu cliente

void Interface::lerDadosCliente(Cliente *cliente)
{
	string auxStr;
	long auxLong;
	
	cin.ignore(); //eh aconselhavel limpar o buffer apenas uma vez
	cout<<" Informe os seguintes dados cadastrais: "<<endl;
	
	cout<<"Nome: ";
	getline(cin, auxStr);
	cliente->atribuirNome(auxStr);
	
	cout<<"Endereco: ";
	getline(cin, auxStr);
	cliente->atribuirEndereco(auxStr);
	
	cout<<"Telefone: ";
	cin>>auxLong;
	cliente->atribuirTelefone(auxLong);
	
	cout<<"CNH: ";
	cin>>auxLong;
	cliente->atribuirCnh(auxLong);
	
	cout<<"CPF: ";
	cin>>auxLong;
	cliente->atribuirCpf(auxLong);	
}//fim ler dados

void Interface::escreverDadosCliente(Cliente *cliente)
{
	cout<<" Dados do Cliente"<<endl;
	cout<<"Nome: "<<cliente->obterNome()<<endl;
	cout<<"Endereco: "<<cliente->obterEndereco()<<endl;
	cout<<"Telefone: "<<cliente->obterTelefone()<<endl;
	cout<<"CNH: "<<cliente->obterCnh()<<endl;
	cout<<"CPF: "<<cliente->obterCpf()<<endl;
}

// 		FIM MENU CLIENTE
//***********************************************************

//**********************************************************
//		MENU VEICULO

void Interface::menuVeiculo(Persistencia *locadora)
{
	try{
		ControleVeiculo ctrlVeiculo(locadora);
		int opcao=1;
		while(opcao){
			system("clear");
			cout<<endl<<"\tMENU VEICULO"<<endl;
			cout<<endl<<" 1 - Incluir";
			cout<<endl<<" 2 - Alterar";
			cout<<endl<<" 3 - Consultar";
			cout<<endl<<" 0 - Retornar ao Menu Principal"<<endl;
			cout<<" Digite a Opcao: ";
			cin>>opcao;
			switch(opcao){
				case 1:{
					try{
						system("clear");
						cout<<" Incluir Veiculo"<<endl;
						int id;
						cout<<" Digite o ID: ";
						cin>>id;
						Veiculo veiculo(id);
						
						if(ctrlVeiculo.consultarVeiculo(&veiculo)){
							cout<<"\t ID Existente! Inclusao Cancelada!"<<endl;
							cout<<" ID: "<<veiculo.obterIdentificador()<<endl;
							cout<<" Modelo: "<<veiculo.obterModelo()<<endl;
							cout<<" Placa: "<<veiculo.obterPlaca()<<endl;
							cout<<" Tecle Enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
						
						lerDadosVeiculo(&veiculo);
						if(ctrlVeiculo.incluirVeiculo(&veiculo))
						{
							cout<<" Veiculo incluido com Sucesso!"<<endl;
							cin.get();cin.get();
							break;
						}
						else {
							cout<<" Erro inesperado na inclusao!"<<endl;
						}					
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnVei-Inc: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
					}//fim catch
				}//fim case 1
				
				case 2:{ // ALTERACAO
					try{
						system("clear");
						cout<<" Alteração de Veiculo"<<endl;
						int id;
						cout<<" Digite o ID: ";
						cin>>id;
						Veiculo veiculo(id);
					
						// mandar consultar, se encontrar vai alterar senao sai do case
						if(ctrlVeiculo.consultarVeiculo(&veiculo)){
							escreverDadosVeiculo(&veiculo);
							cout<<" Deseja realmente alterar o veiculo(s/n)?:";
							cin.ignore();
							char resp;
							cin>>resp;
							if(resp!='S' && resp!='s') resp = 'n';
							if(resp=='S' || resp=='s'){
							lerDadosVeiculo(&veiculo);
							if(ctrlVeiculo.alterarVeiculo(&veiculo)){
								cout<<" Alteração efetuada com sucesso!"<<endl;
								cin.get();cin.get();
								break;
							}
							else {
								cout<<" Alteracao nao efetuada!"<<endl;
								cin.get();cin.get();
								break;
							}
							}//fim if resp
							else {
								cout<<" Alteracao Cancelada! Tecle Enter";
								cin.get();cin.get();
								break;
							}
						}// fim if consulta
						else{
							cout<<" Veiculo nao cadastrado!"<<endl;
						}
						cin.get();cin.get();
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnVei-Alt: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
						}//fim catch				
					}//fim case 2
				
				case 3:{ // consultar
					try{
						system("clear");
						cout<<" Consultar Veiculo"<<endl;
						int id;
						cout<<" Digite o ID: ";
						cin>>id;
						Veiculo veiculo(id);
						
						if(ctrlVeiculo.consultarVeiculo(&veiculo)){
							escreverDadosVeiculo(&veiculo);
							cout<<" Consulta Efetuada...Tecle Enter para voltar!"<<endl;
							cin.get();cin.get();
							break;
						}
						else {
							cout<<" Veiculo nao encontrado!"<<endl;
							cin.get();cin.get();
						}
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnVei-Cst: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
					}//fim catch				
				}//fim case 3
				
				case 0:{ //retornando ao menu principal
					return;								
				}//fim case 3
				
				}//fim switch			
			}//fim while	
		}//fmi try
		catch(string msg){
			cout<<"> Erro IntMnCli - "<<msg<<endl<<endl;
		}//fim catch	
}//fim menu veiculo

void Interface::lerDadosVeiculo(Veiculo *veiculo)
{
	string auxStr;
	int auxInt;
	
	cin.ignore(); //eh aconselhavel limpar o buffer apenas uma vez
	cout<<" Informe os seguintes dados cadastrais: "<<endl;
	
	cout<<"Modelo: ";
	getline(cin, auxStr);
	veiculo->atribuirModelo(auxStr);
	
	cout<<"Marca: ";
	getline(cin, auxStr);
	veiculo->atribuirMarca(auxStr);
	
	cout<<"Placa: ";
	getline(cin, auxStr);
	veiculo->atribuirPlaca(auxStr);
	
	cout<<"Valor DE Compra: ";
	cin>>auxInt;
	veiculo->atribuirValorDeCompra(auxInt);
	
	cout<<"Valor De Venda: ";
	cin>>auxInt;
	veiculo->atribuirValorDeVenda(auxInt);
	
	// condicao para que na hora da alteracao
	// nao alterar a situacao do veiculo qdo ele estiver locado
	// se o veiculo estiver com a situacao igual a false
	if(veiculo->obterSituacao()==false){
		cout<<"O Veiculo esta locado[s/n]?:";
		char resp;
		cin>>resp;
		if(resp!='s' && resp!='S') resp='n';
		if(resp== 's' || resp=='S') veiculo->atribuirSituacao(true);
		else veiculo->atribuirSituacao(false);
	}	
}//fim ler dados veiculo

void Interface::escreverDadosVeiculo(Veiculo *veiculo)
{
	cout<<" Dados Do veiculo"<<endl;
	cout<<" Modelo: "<<veiculo->obterModelo()<<endl;
	cout<<" Marca: "<<veiculo->obterMarca()<<endl;
	cout<<" Placa: "<<veiculo->obterPlaca()<<endl;
	cout<<" Valor DE Compra: "<<veiculo->obterValorDeCompra()<<endl;
	cout<<" VAlor de Venda: "<<veiculo->obterValorDeVenda()<<endl;
	cout<<" Situacao: ";
	if(veiculo->obterSituacao()) cout<<" LOCADO"<<endl;
	else cout<<" NAO-LOCADO"<<endl;
}//fim escrever dados vceiculo



//******************************************************************
// MENU LOCACAO


void Interface::menuLocacao(Persistencia *locadora)
{
	try{
		ControleLocacao ctrlLocacao(locadora);
		int opcao=1;
		while(opcao){
			system("clear");
			cout<<endl<<"\tMENU LOCACAO"<<endl;
			cout<<endl<<" 1 - Locar";
			cout<<endl<<" 2 - Devolver";
			cout<<endl<<" 3 - Cancelar";
			cout<<endl<<" 0 - Retornar ao Menu Principal"<<endl;
			cout<<" Digite a Opcao: ";
			cin>>opcao;
			switch(opcao){
				case 1:{
					try{
						system("clear");
						cout<<" Locar Veiculo"<<endl;
						int id;
						cout<<" Digite o ID - Locacao: ";
						cin>>id;
						Locacao locacao(id);
						
						if(ctrlLocacao.consultarLocacao(&locacao)){
							cout<<"\t ID Existente! Locacao Cancelada!"<<endl;
							cout<<" ID Cliente: "<<locacao.obterIdCliente()<<endl;
							cout<<" ID Veiculo: "<<locacao.obterIdVeiculo()<<endl;
							cout<<" Tecle Enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
						
						lerDadosLocacao(&locacao, locadora);
						
						if(ctrlLocacao.incluirLocacao(&locacao))
						{
							cout<<" Locacao incluido com Sucesso!"<<endl;
							cin.get();cin.get();
							break;
						}
						else {
							cout<<" Erro inesperado na inclusao!"<<endl;
						}					
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnLoc-Loc: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
					}//fim catch
				}//fim case 1
				
				case 2:{ // Devolucao
					try{
						system("clear");
						cout<<" Devolucao de Veiculo"<<endl;
						int id;
						cout<<" Digite o ID: ";
						cin>>id;
						Locacao locacao(id);
						
						if(!ctrlLocacao.consultarLocacao(&locacao)){
							cout<<" ID Nao encontrado - DEVOLUCAO CANCELADA!"<<endl;
							cout<<" Tecle enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
						
						lerDadosDevolucao(&locacao, locadora);
						cout<<" Confirma a Devolucao[s/n]?: ";
						cin.ignore();
						char resp;
						cin>>resp;
						if(resp!='s' && resp!='S') resp = 'n';
						//apos confirmada a devolucao
						if(resp=='s' || resp=='S'){
							int auxInt, kmRodado, valorAPagar;
							
							cout<<" Digite o Km Final: ";
							cin>>auxInt;
							locacao.atribuirKmFinal(auxInt);
							
							// qtd de km q rodou, diferenca entre kmfinal e kminicial
							kmRodado = (locacao.obterKmFinal()) - (locacao.obterKmInicial());
							
							//valor a pagar eh a qtd de km rodados vezes o valor por km
							valorAPagar = kmRodado * (locacao.obterValoPorKm());
							
							// nem sempre o valor a pagar e o valor que pagou, pode haver 
							// desconto ou acrescimo, entao
							cout<<" Valor a ser Pago: $ "<<valorAPagar<<endl;
							
							cout<<" Digite o Valor Pago: ";
							cin>>auxInt;
							locacao.atribuirValorPago(auxInt);
							
							//alterando o status do veiculo
							// criando um obj do tipo veiculo e enviando o id pelo construtor
							Veiculo veiculo(locacao.obterIdVeiculo());
							ControleVeiculo ctrlVeiculo(locadora);
							
							//se encontrar o veiculo o altere
							if(ctrlVeiculo.consultarVeiculo(&veiculo)){
								veiculo.atribuirSituacao(false);
								ctrlVeiculo.alterarVeiculo(&veiculo);
							}
							else throw string("Ocorreu um erro inexperado na alteracao do Veiculo\n"
									"favor cheque a sua base de dados!");
						}//fim resp
						else {
							cout<<" DEVOLUCAO CANCELADA!"<<endl;
							cout<<" Tecle enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
										
						cin.get();cin.get();
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnLoc-Dev: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
						}//fim catch				
					}//fim case 2
				
				case 3:{ // cancelar
					try{
						system("clear");
						cout<<" Cancelar Locacao"<<endl;
						system("clear");
						cout<<" Devolucao de Veiculo"<<endl;
						int id;
						cout<<" Digite o ID: ";
						cin>>id;
						Locacao locacao(id);
						
						if(!ctrlLocacao.consultarLocacao(&locacao)){
							cout<<" ID Nao encontrado - CANCELAMENTO NAO EFETUADO!"<<endl;
							cout<<" Tecle enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
						
						lerDadosDevolucao(&locacao, locadora);
						cout<<" Confirma a Devolucao[s/n]?: ";
						cin.ignore();
						char resp;
						cin>>resp;
						if(resp!='s' && resp!='S') resp = 'n';
						//apos confirmada a devolucao
						if(resp=='s' || resp=='S'){
							// se vai cancelar nao vai registrar nenhum valor por km
							locacao.atribuirKmInicial(0);
							locacao.atribuirKmFinal(0);
							locacao.atribuirValorPago(0);
							locacao.atribuirValorPorKm(0);
													
							// eh preciso atualizar o veiculo tambem
							//alterando o status do veiculo
							// criando um obj do tipo veiculo e enviando o id pelo construtor
							Veiculo veiculo(locacao.obterIdVeiculo());
							ControleVeiculo ctrlVeiculo(locadora);
							
							//se encontrar o veiculo o altere
							if(ctrlVeiculo.consultarVeiculo(&veiculo)){
								veiculo.atribuirSituacao(false);
								ctrlVeiculo.alterarVeiculo(&veiculo);
							}
							else throw string("Ocorreu um erro inexperado na alteracao do status Veiculo\n"
										"favor cheque a sua base de dados!");
						}//FIM RESP
						else {
							cout<<" CANCELAMENTO CANCELADO =P!"<<endl;
							cout<<" Tecle enter para continuar!"<<endl;
							cin.get();cin.get();
							break;
						}
						
						
						cout<<" Locacao Cancelada com sucesso!"<<endl<<endl;
						cout<<" \tEnter Para Continuar!"<<endl;
						cin.get();cin.get();
						
						
						break;
					}//fim try
					catch(string msg){
						cout<<"> Erro IntMnLoc-Can: "<<msg<<endl<<endl;
						cin.get();cin.get();
						break;
					}//fim catch				
				}//fim case 3
				
				case 0:{ //retornando ao menu principal
					return;								
				}//fim case 3
				
				}//fim switch			
			}//fim while	
		}//fmi try
		catch(string msg){
			cout<<"> Erro IntMnCli - "<<msg<<endl<<endl;
		}//fim catch	
}//fim menu locacao

// este metodo le e valida os dados que esta sendo digitados
void Interface::lerDadosLocacao(Locacao *locacao, Persistencia *locadora)
{
	ControleCliente ctrlCliente(locadora);
	ControleVeiculo ctrlVeiculo(locadora);
	
	bool encontrado;
	int auxInt;
	cin.ignore();
	
	cout<<" Informe os dados para locacao:"<<endl;
	
	//lendo e validando o id do cliente
	auxInt=0;
	do{
		cout<<" ID Cliente: ";
		cin>>auxInt;
		Cliente cliTmp(auxInt);
		encontrado = ctrlCliente.consultarCliente(&cliTmp);
		if(!encontrado) cout<<" Cliente nao encontrado. Digite um ID valido!"<<endl;
	}while(!encontrado);
	locacao->atribuirIdCliente(auxInt);
	
	//auxInt=0;
	do{
		cout<<" ID Veiculo: ";
		cin>>auxInt;
		Veiculo veiTmp(auxInt);
		encontrado = ctrlVeiculo.consultarVeiculo(&veiTmp);
		if(!encontrado) cout<<" Veiculo nao encontrado. Digite um ID valido!"<<endl;
	}while(!encontrado);
	locacao->atribuirIdVeiculo(auxInt);
	
	//auxInt=0;
	cout<<" Valor Por Kilometro: ";
	cin>>auxInt;
	locacao->atribuirValorPorKm(auxInt);
	
	//auxInt=0;
	cout<<" Km Inicial: ";
	cin>>auxInt;
	locacao->atribuirKmInicial(auxInt);
	
	// na locacao o kmfinal e valor pago eh 0
	locacao->atribuirKmFinal(0);
	locacao->atribuirValorPago(0);
}//fim ler dados locacao

void Interface::lerDadosDevolucao(Locacao *locacao, Persistencia *locadora)
{
	ControleCliente ctrlCliente(locadora);
	ControleVeiculo ctrlVeiculo(locadora);
	
	
	cout<<" Dados da Locacao: "<<endl;
	
	Cliente cliTmp(locacao->obterIdCliente());
	ctrlCliente.consultarCliente(&cliTmp);
	cout<<" Nome Cliente: "<<cliTmp.obterNome()<<endl;
	
	Veiculo veiTmp(locacao->obterIdVeiculo());
	ctrlVeiculo.consultarVeiculo(&veiTmp);
	cout<<" Modelo Veiculo: "<<veiTmp.obterModelo()<<endl;
	cout<<" Marca Veiculo: "<<veiTmp.obterMarca()<<endl;
	
	cout<<" Km Inicial: "<<locacao->obterKmInicial()<<endl;
	cout<<" Valor Por Km:$ "<<locacao->obterValoPorKm()<<endl;
	
}//fim ler dev

#endif /*INTERFACE_H_*/
