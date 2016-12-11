#include <stdlib.h>
#include <GL/glut.h>

void Desenha(void)
{
	glClearColor(0,0,0,0); // define como cor branca da janela
	glClear(GL_COLOR_BUFFER_BIT);
    
    // comando que define a cor para o proximo obj a ser criado

    
    //Desenhando o retangulo de cor preta
    glBegin(GL_QUADS); 

    glColor3f(1,1,1); //Define a cor preta 

    glVertex2f(-0.8,0.5);
    glVertex2f(0.8,0.5);
    glVertex2f(0.8,-0.5);
    glVertex2f(-0.8,-0.5);

    glEnd(); // end do retangulo
        
// Desenhando os triangulos
   // desenhando o primeiro triangulo 
   glBegin(GL_TRIANGLES);
   
   glColor3f(0,1,0); //verde

   glVertex2f(-0.4,0.5);   
   glVertex2f(0,-0.5);
   glVertex2f(-0.8,-0.5);

   glEnd(); // fim do triangulo 1
   
    //desenhando o segundo triangulo
    glBegin(GL_TRIANGLES);
    
    glColor3f(1,1,0); // amarelo
    
    glVertex2f(0.4,0.5);
    glVertex2f(0.8,-0.5);
    glVertex2f(0,-0.5);
    
    glEnd(); // fim do 2 triangulo
    
    //comando que define o fim dos comandos da OPenGL

	glFlush();
}// fim do Metodo desenha

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
	
	glutInitWindowSize( 600,600 );
	
	glutCreateWindow("Primeiro Programa");
	
	glutDisplayFunc(Desenha);
	
	glutKeyboardFunc(Teclado);
	
	Inicializa();
	
	glutMainLoop();
	
	return 0;
}
