#include<stdlib.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>


void Desenha(void)
{
    float ang;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(1);
	for(ang=0; ang<2*3.14; ang+=3.14/100.0){
	glBegin(GL_LINE_LOOP);
	float x=cos(ang)*0.1;
	float y=sin(ang)*0.1;
	glVertex3f(x,y,0);
	glColor3f(0,1,0);}
	glEnd();
	
	glLineWidth(2);
	for(ang=0; ang<2*3.14; ang+=3.14/100.0){
	glBegin(GL_LINE_LOOP);
	glColor3f(0,1,1);
	glVertex2f(0.2*cos(ang),0.2*sin(ang));}
	glEnd();

	glLineWidth(6);
	for(ang=0; ang<2*3.14; ang+=3.14/100.0){
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,1);
	glVertex2f(0.3*cos(ang),0.3*sin(ang));}
	glEnd();

}
void Inicializa(void)
{
	//define a janela de visualiza��o 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	
	//Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	//especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(768,768);
	
	//Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Redondo");
	
	//Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);
	
	//Chama fun��o respons�vel por fazer as inicializa��es0
	Inicializa();
	
	//Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
	
	return 0;
}
