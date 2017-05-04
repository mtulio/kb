

#ifndef ESFERA_H_
#define ESFERA_H_
class Esfera
{
private:
	 float raio;
	
public:
	Esfera():raio(0){};
	void atribuirRaio( float raio){ this->raio=raio;}
	 float obterRaio();
	 float area(float raio);
	float volume(float raio);
	
};

float Esfera::area( float raio){
	 float total;
	total= (4*3.14)*(raio*raio);
	return total;
}
 float Esfera::volume(float raio){
	float total;
	total= 3.14*4*(raio*raio*raio);
	return total;
}
#endif /*ESFERA_H_*/
