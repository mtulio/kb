#include <stdlib.h>
#include <GL/glut.h>

int             Width;

void Desenha (void)
{

     GLint width;
     glColor3f(1.0f,0.0f,0.0f);
     glPushAttrib(GL_LINE_BIT);
     glPushAttrib(GL_CURRENT_BIT);
     glColor3f(0.0f,0.0f,1.0f);
     glLineWidth(5);

}


void RenderScene(void)
	{
	 // Limpa a janela com a cor especificada como cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10);
    glGetIntegerv(GL_LINE_WIDTH,&Width);
        glColor3f(0.0f,1.0f,0.0f);
glPushAttrib(GL_CURRENT_BIT);	
    glColor3f(0.0f,1.0f,1.0f);
    glPushAttrib(GL_CURRENT_BIT);    
    glColor3f(1.0f,0.0f,1.0f);

    glViewport(0,0,400,600); // 1a. viewport a esquerda da janela

     glBegin(GL_LINES);
       glVertex2f (0.0, -1);
       glVertex2f (0.0, 1);
       glVertex2f (-1, 0.0);
       glVertex2f (1, 0.0);
     glEnd();
     glPopAttrib();
          glBegin(GL_QUADS);
       glVertex2f (-0.4, 0.3);
       glVertex2f (-0.4, 0.7);
       glVertex2f (-0.8, 0.7);
       glVertex2f (-0.8, 0.3);
     glEnd();
     glPopAttrib();
               glBegin(GL_QUADS);
       glVertex2f (0.4, -0.3);
       glVertex2f (0.4, -0.7);
       glVertex2f (0.8, -0.7);
       glVertex2f (0.8, -0.3);
     glEnd();
    
    // Chamadas de funções OpenGL para desenho
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

Desenha();
    glColor3f(1.0f,0.0f,0.0f);
    glPushAttrib(GL_CURRENT_BIT);	
    glColor3f(0.0f,0.0f, 0.0f);
    glPushAttrib(GL_CURRENT_BIT);    
    glColor3f(0.75f,0.2f,1.0f);
     // define a 2a. viewport
     glViewport(410,0,400,600); // 2a. viewport a direita da janela
      
     glBegin(GL_LINES);
       glVertex2f (-0.8, -0.8);
       glVertex2f (0.8, 0.8);
       glVertex2f (0.8, -0.8);
       glVertex2f (-0.8, 0.8);
     glEnd();
   
   glPopAttrib();
     glBegin(GL_TRIANGLES);
       glVertex2f (-0.7, 0.4);
       glVertex2f (-0.8, -0.2);
       glVertex2f (-0.4, -0.2);

         glEnd();
glPopAttrib();
glBegin(GL_TRIANGLES);
       glVertex2f (0.7, 0.4);
       glVertex2f (0.8, -0.2);
       glVertex2f (0.4, -0.2);
       glEnd();
     // Recomeça a exibir o SRU                          
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();                                                  
     
     Desenha(); 
                   
  
     glutSwapBuffers();                                                                                                                                                                                                                                                                                                                        	  
    }

void Inicializa(void)
{
     glClearColor(1.0f,1.0f,1.0f,1.0f);
}

int main (void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(5,5);
    glutInitWindowSize(800,600);
    glutCreateWindow("Desenho distintos com Viewport");
    glutDisplayFunc(RenderScene);

    Inicializa();
    glutMainLoop();
    
    return 0;
}


         
              
     
