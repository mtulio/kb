#ifndef CLINDRO_H_
#define CLINDRO_H_
class Cilindro 
{
private:
	float raio;
	float altura;
	
public:
	Cilindro():raio(0), altura(0){};
	void atribuirRaio(float raio){this->raio=raio;}
	float obterRaio();
	void atribuirAltura(float altura){this->altura=altura;}
	float obterAltura();
	float areaLateral(float raio);
	float area(float raio);
	float volume(float raio,float volume);
	
};

float Cilindro::areaLateral(float raio){
	float total;
	total= 4*(3.14)*(raio*raio);
	return total;
}
float Cilindro::area(float raio){
	float total,l;
	l=areaLateral(raio);
	total=l+(2*3.14*(raio*raio));
	return total;
}
float Cilindro::volume(float raio, float altura){
	float vol;
	vol=(3.14*raio*raio)*altura;
	return vol;
}
#endif /*CLINDRO_H_*/
