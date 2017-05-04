#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>



void Desenha(void)
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
      
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
	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{	
	if (key==27)
		
		exit(0);
	
	if (key == 97)
	glutFullScreen();
	
	if (key == 65)
         {
            glutReshapeWindow(500,400);
            glutPositionWindow(100,100);
         }
}

void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	
}

void MenuWin(int op)
{
     printf("    Menu Windows:     ");
     switch(op)
               {
                      case 0:
                           printf("Opçao Triangulo");
                           break;
                      
                      case 1:
                           printf("Opçao Retangulo com Triangulos");
                           break;
                           
               }
               printf("\n");
               glutPostRedisplay();
}

void CriaMenu()
{
     int menu,submenu1;
     
     submenu1 = glutCreateMenu(MenuWin);
     glutAddMenuEntry("Triangulo",0);
     glutAddMenuEntry("Retangulo com Triangulos",1);
     
     menu = glutCreateMenu(MenuWin);
     glutAddSubMenu("Escolha",submenu1);
     
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc,char ** argv){
	
	glutInit(&a        rgc,argv);
	
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	
	glutInitWindowSize( 800,600 );
	
	glutCreateWindow("Quarto Trabalho");
	
	glutDisplayFunc(Desenha);
	
	
	
	glutKeyboardFunc(Teclado);
	
	Inicializa();
	CriaMenu();
	
	glutMainLoop();
	
	return 0;
}
