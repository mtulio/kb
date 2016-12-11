#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class FiguraGeometrica
{
    public:
		FiguraGeometrica(float r=0 ):raio(r){};
		float obterRaio() {return raio;};  // Normal
		void atribuirRaio(float r ) {raio = r;}; // Normal
		virtual float areaTotal() = 0; // Virtual Pura
		virtual float volume() = 0; // Virtual Pura
		virtual string tipoFigura() = 0; // Virtual Pura
    protected:
		float raio;
};

class Esfera : public FiguraGeometrica
{
    public:
// chamando construtor pai
		Esfera(float r=0) : FiguraGeometrica(r) {}; 

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 4*3.14*raio*raio; }; 
		float volume(){return ((float)4/3)*3.14*raio*raio*raio;}; 
		string tipoFigura() { return "Esfera";};
    
};

class Cilindro : public FiguraGeometrica
{
    public:
// chamando construtor pai e inicializando o atributo
		Cilindro (float r, float a) : FiguraGeometrica(r), altura(a) {};

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 2*3.14*raio*(altura+raio);};
		float volume() {return 3.14*raio*raio*altura;};
		string tipoFigura() {return "Cilindro";};

// Métodos Normais
		float obterAltura() {return altura;};  // Normal
		void atribuirAltura(float a) {altura = a;}; // Normal

// Método Virtual
		virtual float areaLateral() {return 2*3.14*raio*altura;}; // Virtual

    protected:
		float altura;
};


class Cone : public Cilindro
{
    public:
// chamando construtor pai
		Cone(float r, float a) : Cilindro(r,a) {};

//polimorfismo de sobreposicao por substituicao
//obrigatorio porque na classe FiguraGeometrica este sao Vituais Puros
		float areaTotal() {return 3.14*raio*(geratriz()+raio);};
		string tipoFigura() {return "Cone";};
		float areaLateral() { return 3.14*raio*geratriz();};

//polimorfismo de sobreposicao por refinamento
		float volume() {return 1.0/3.0 * Cilindro::volume();}; 
	
// Método Normal	
		float geratriz() {return sqrt((altura*altura)+(raio*raio));};
};

int main(void)
{

//Instancia das Classes Esfera, Cilindro e Cone;
    Esfera objetoEsfera(5);
    Cilindro objetoCilindro(5,5);
    Cone objetoCone(3,4);

//variável polimorfica (implementada em C++ utilizando Referência)
// Acesso aos elementos do objetoEsfera através da Variável Polimorfica
		FiguraGeometrica &ptFiguraGeometrica = objetoEsfera;

    cout<<endl<<"Figura: "<<ptFiguraGeometrica.tipoFigura()<<endl;// do Filho
		ptFiguraGeometrica.atribuirRaio(7); // Do Pai - Normal
		cout<<endl<<"Raio: "<<ptFiguraGeometrica.obterRaio()<<endl; // Do pai - Normal
    cout << "Area Total: " << ptFiguraGeometrica.areaTotal() << endl; //Do filho
    cout << "Volume: " << ptFiguraGeometrica.volume() << endl ;// Do filho



// Acesso aos elementos do objetoCilindro através da Variável Polimorfica
		FiguraGeometrica &ptFiguraGeometrica2 = objetoCilindro;

    cout<<endl<<"Figura: "<<ptFiguraGeometrica2.tipoFigura()<<endl; // do Filho
		ptFiguraGeometrica2.atribuirRaio(7); // Do Pai - Normal
		cout<<endl<<"Raio: "<<ptFiguraGeometrica2.obterRaio()<<endl; // Do pai - Normal
 		objetoCilindro.atribuirAltura(5);// do Filho Normal
		cout<<endl<<"Altura: "<<objetoCilindro.obterAltura()<<endl;// do Filho Normal
    cout<<"Area Total: "<<ptFiguraGeometrica2.areaTotal()<<endl;// do Filho
    cout<<"Volume: "<<ptFiguraGeometrica2.volume()<<endl;// do Filho
    cout<<"Areal Lateral: "<<objetoCilindro.areaLateral()<<endl ;// do Filho

// Acesso aos elementos do objetoCone através da Variável Polimorfica
		FiguraGeometrica &ptFiguraGeometrica3 = objetoCone;

    cout<<endl<<"Figura: "<<ptFiguraGeometrica3.tipoFigura()<<endl ;
		ptFiguraGeometrica3.atribuirRaio(7); // Do Pai - Normal
		cout<<endl<<"Raio: "<<ptFiguraGeometrica3.obterRaio()<<endl; // Do pai - Normal
 		objetoCone.atribuirAltura(5);// do Filho Normal
		cout<<endl<<"Altura: "<<objetoCone.obterAltura()<<endl;// do Filho Normal
    cout<<"Area Total: "<<ptFiguraGeometrica3.areaTotal()<<endl;
    cout<<"Volume: "<<ptFiguraGeometrica3.volume()<<endl;
    cout<<"Areal Lateral: "<<objetoCone.areaLateral()<<endl ;
    cout<<"Geratriz: "<<objetoCone.geratriz()<<endl ;

    cin.get();cin.get();
}

