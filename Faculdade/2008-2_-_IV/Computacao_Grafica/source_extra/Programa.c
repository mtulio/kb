#include <stdlib.h>
#include <GL/glut.h>

void Desenha(void)
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	
	//glColor3f(0,0,0);
	//glBegin(GL_QUADS);

	//glVertex3f(0.8,0.5,0.5);
	//glVertex3f(0.8,-0.5,0.5);
	//glVertex3f(-0.8,-0.5,0.5);
	//glVertex3f(-0.8,0.5,-0.5);
	
	glColor3f(1,1,0); //cor amarela do primeiro triangulo
	
	glBegin(GL_TRIANGLES); //desenhando o primeiro triangulo
			
	glVertex3f(-0.4,0.5,0);
	glVertex3f(-0.8,-0.5,0);
	glVertex3f(0,-0.5,0);
		
	glColor3f(1,0,0); //cor vermelha do segundo triangulo
	
	glVertex3f(0.4,0.5,0);
	glVertex3f(0,-0.5,0);
	glVertex3f(0.8,-0.5,0);

	glColor3f(0,0,1); //cor azul do 3 triangulo - equilatero
	
	glVertex3f(-0.4,0.5,0);
	glVertex3f(0.4,0.5,0);
	glVertex3f(0,-0.5,0);

	glColor3f(0,0,1); //cor do quarto triangulo - retangulo
	
	glVertex3f(-0.8,0.5,0);
	glVertex3f(-0.4,0.5,0);
	glVertex3f(-0.8,-0.5,0);
	
	glColor3f(0,0,1);//cor do quinto triangulo - retangulo
	
	glVertex3f(0.4,0.5,0);
	glVertex3f(0.8,0.5,0);
	glVertex3f(0.8,-0.5,0);
	
	glEnd();
	//funcao q desenha retangulo: GL_QUAD
	//funcao q desenha triangulo: GL_TRIANGLE
	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{	
	if (key==27)
		
		exit(0);
}

void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	
}

int main(int argc,char ** argv){
	
	glutInit(&argc,argv);
	
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	
	glutInitWindowSize( 800,800 );
	
	glutCreateWindow("Primeiro Programa");
	
	glutDisplayFunc(Desenha);
	
	glutKeyboardFunc(Teclado);
	
	Inicializa();
	
	glutMainLoop();
	
	return 0;
}
