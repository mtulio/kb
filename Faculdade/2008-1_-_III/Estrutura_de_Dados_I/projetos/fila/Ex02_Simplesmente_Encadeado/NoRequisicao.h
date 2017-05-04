#ifndef NOREQUISICAO_H_
#define NOREQUISICAO_H_
#include<string>
#include<iostream>

class NoRequisicao{
      private:
         std::string nome_cli;
         std::string cpf_cli;
         std::string end_cli;
         std::string tel_cli;
         std::string cel_cli;
         std::string model_pc;
         std::string num_serie_pc;      
      public:   
         //bool identificadorInicio=false;
         NoRequisicao *proximo;
                 
         NoRequisicao()/*:
        	 nome_cli(""),
        	 cpf_cli(""),
        	 tel_cli(""),
        	 cel_cli(""),
        	 end_cli(""),
        	 model_pc(""),
        	 num_serie_pc("")*/
        	 {}
         NoRequisicao(std::string nome):
        	nome_cli(nome)/*,
         	cpf_cli(),
         	tel_cli(),
         	cel_cli(),
           	end_cli(),
         	model_pc(),
         	num_serie_pc()*/
         	{}
         
         ~NoRequisicao()
         {
 	         //se o campo proximo apontar pra algum elemento
            if(proximo) delete proximo;
         }
         
         void atribuirNome(std::string nome){ nome_cli=nome;};
         std::string obterNome(){ return nome_cli;};
         
         void obter(std::string &nome_cli, std::string &cpf_cli, std::string &end_cli,
        		 std::string &tel_cli, std::string &cel_cli, std::string &model_pc, 
        		 std::string &num_serie_pc)const;
         
         void atribuir(std::string &nome_cli, std::string &cpf_cli, std::string &end_cli,
        		 std::string &tel_cli, std::string &cel_cli, std::string &model_pc, 
        		 std::string &num_serie_pc);
         
}; //fim da classe no requisicao

//Construtor


void NoRequisicao::obter(std::string &nome_cli, std::string &cpf_cli, std::string &end_cli,
		 std::string &tel_cli, std::string &cel_cli, std::string &model_pc, 
		 std::string &num_serie_pc)const
{
	nome_cli = this->nome_cli;
	cpf_cli = this->cpf_cli;
	//std::cout<<"   DENTRO NOREQ CPF: "<<this->cpf_cli<<std::endl;
	end_cli = this->end_cli;
	tel_cli = this->tel_cli;
	cel_cli = this->cel_cli;
	model_pc = this->model_pc;
	num_serie_pc = this->num_serie_pc;
}

void NoRequisicao::atribuir(std::string &nome_cli, std::string &cpf_cli, std::string &end_cli,
		 std::string &tel_cli, std::string &cel_cli, std::string &model_pc, 
		 std::string &num_serie_pc)
{
	this->nome_cli = nome_cli;
	this->cpf_cli = cpf_cli;
	this->end_cli = end_cli;
	this->tel_cli = tel_cli;
	this->cel_cli = cel_cli;
	this->model_pc = model_pc;
	this->num_serie_pc = num_serie_pc;
}

#endif /*NOREQUISICAO_H_*/
