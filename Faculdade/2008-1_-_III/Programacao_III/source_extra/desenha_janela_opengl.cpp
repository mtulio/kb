#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

// desenha janela

void Desenha(void)
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//recebe comando teclado

void Teclado(unsigned char key, int x, int y)
{	
	if (key==27)
		
		exit(0);
	
	if (key == 97)
	glutFullScreen();
	
	if (key == 65)
         {
            glutReshapeWindow(300,100);
            glutPositionWindow(50,50);
         }
}
// inicializa o programa e aplica cor de fundo

void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	
}


//menu que é exibido ao usuario
void MenuWin(int op) 
{
     printf("    Menu Windows:     ");
     switch(op)
               {
                      case 0:
                           printf("Opçao Triangulo");
                           break;
                      
                      case 1:
                           printf("Opçao Retangulo / Triangulos");
                           break;
                           
               }
               printf("\n");
               glutPostRedisplay();
}

// Recebe informaçoes teclado

void CriaMenu()
{
     int menu,submenu1;
     
     submenu1 = glutCreateMenu(MenuWin);
     glutAddMenuEntry("Triangulo",0);
     glutAddMenuEntry("Retangulo / Triangulos",1);
     
     menu = glutCreateMenu(MenuWin);
     glutAddSubMenu("MENU",submenu1);
     
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// janela inicial
int main(int argc,char ** argv){
	
	glutInit(&argc,argv);
	
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	
	glutInitWindowSize( 800,600 );
	
	glutCreateWindow("programa 4");
	
	glutDisplayFunc(Desenha);
	
	
	
	glutKeyboardFunc(Teclado); // funçao teclado
	
	Inicializa();
	CriaMenu();
	
	glutMainLoop();
	
	return 0;
}
