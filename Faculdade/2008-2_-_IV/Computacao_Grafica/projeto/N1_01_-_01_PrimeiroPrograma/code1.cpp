#include<stdlib.h>
#include<GL/glut.h>


void Desenha(void)
{
     glClearColor(1,1,1,0);
     glClear(GL_COLOR_BUFFER_BIT);
     
     glColor3f(1,0,0);
     
     glBegin(GL_TRIANGLES);
     
     glVertex3f(-0.5,-0.5,0);
     glVertex3f(0.0,0.5,0);
     glVertex3f(0.5,-0.5,0);
     glEnd();
     
     glFlush();
}

void Teclado(unsigned char key,int x, int y)
{
     if(key == 27) exit(0);
     
}


void Inicializa(void)
{
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(-1.0,1.0,-1.0,1.0);
     glMatrixMode(GL_MODELVIEW);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    
    glutInitWindowSize(400,400);
    
    glutCreateWindow("Primeiro Programa");
    
    glutDisplayFunc(Desenha);
    
    glutKeyboardFunc(Teclado);
    
    Inicializa();
    
    glutMainLoop();
    
    return 0;
    
}
