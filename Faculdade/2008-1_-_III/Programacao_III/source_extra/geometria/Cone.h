#ifndef CONE_H_
#define CONE_H_
class Cone
{
private:
	float altura;
	float raio;
	
public:
	Cone():altura(0),raio(0){};
	void atribuirAltura(float altura){this->altura=altura;}
	float obterAltura();
	void atribuirRaio(float raio){this->raio=raio;}
	float obterRaio();
	float geratriz(float raio);
	float volume(float altura, float raio);
	float areatotal(float altura, float raio);
	float arealateral(float raio);
	
};

float Cone::geratriz(float raio){
	float g;
	g = 2*raio;
	return g;
}

float Cone::volume(float altura, float raio){
	float v;
	v = (3.14*raio*raio*altura)/3;
	return v;
}

float Cone::areatotal(float altura, float raio){
	float total,g;
	g=geratriz(raio);
	total= (g+raio)*3.14*raio;
	return total;
	
}
float Cone::arealateral(float raio){
	float total,g;
	g=geratriz(raio);
	total=3.14*raio*g;
	return total;
}

#endif /*CONE_H_*/


/*    
    glColor3f(0.1,0.3,0);
    glBegin(GL_QUADS);
    glVertex3f(-0.8,0.4,0);
    glVertex3f(0.8,0.4,0);
    glVertex3f(0.8,-0.4,0);
    glVertex3f(-0.8,-0.4,0);
    
    glEnd();

    
    glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.8,-0.4,0);
    glVertex3f(-0.4,0.4,0);
	glVertex3f(0,-0.4,0);

	


    glColor3f(1,0,0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.8,0.4,0);
    glVertex3f(0.4,0.4,0);
	glVertex3f(0,0.4,0);

	
glEnd();
*/