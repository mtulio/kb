#ifndef CLASSEPESSOA_H_
#define CLASSEPESSOA_H_
#include<string>
/*****************
"Armazenar os dados de uma Pessoa"
A classe pessoa tem como objetivo armazenar os dados(nome, telefone e email)
//************************/

class Pessoa
{
	//Atributos
		private:
				std::string nome;
				unsigned long telefone;
				std::string email;
				//tem tres atributos
				// nome, telefone e email
	//Metodos
		public:
				Pessoa(){};// construtor sem parametros server para istanciar objetos sem precisar inicializar os atributos
                //2 construtor com parametros
				Pessoa(const std::string &nome, unsigned long telefone, const std::string &email):
                             //dando valores iniciais aos meus atributos com o construtor com parametros...
							nome(nome),
                            telefone(telefone),
                            email(email)
                            {}; 
                 //construtor com parametros inline implicito pois o meu bloco de comandos esta na declaraçao do metodo
				void atribuirNome(const std::string &nome){
                     //O atributo nome esta recebendo o parametro nome..
                     this->nome/*atributo*/=nome/*var do parametro*/;
                     };
                    
				void obterNome(std::string &nome)const{
                     //tem como ojetivo enviar uma "copia" do atributo nome e enviar para para "fora" como parametro
                     ////O obternome significa que o parametro está recebendo o atributo
                     nome/*var parametro*/=this->nome/*atributo*/;
                     };
				void atribuirTelefone(unsigned long telefone){
                     //tem como objetivo armazenar os dados no atributo telefone
                     //o atributo telefone esta recebendo o parametro telefone....
                     this->telefone/*atributo*/=telefone/*parametro*/;
                     };
				
                unsigned long obterTelefone(){return telefone;}                    
                         
				void atribuirEmail(const std::string &email){
                     //o atributo email esta recebendo o parametro email....
                     this->email=email;
                     };
                     
				
                const std::string obterEmail(){return email;}
                     //o parametro email esta recebendo o atributo email
                     
};

#endif /*CLASSEPESSOA_H_*/
