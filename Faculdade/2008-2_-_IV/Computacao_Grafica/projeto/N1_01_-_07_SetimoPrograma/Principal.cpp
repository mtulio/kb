#include<stdlib.h>
#include<GL\glut.h>

void Desenha(void)
{
   GLint width;
   
   //limpa a janela de visualização com a cor de fundo definida preciamente
   glClear(GL_COLOR_BUFFER_BIT);
   
   //especifica a cor vermelha
   glColor3f(1.0f,0.0f,0.0f);
   
   //empilha atributo
   //(espessura da linha default é 1)     
   glPushAttrib(GL_LINE_BIT);
   
   glPushAttrib(GL_CURRENT_BIT);
   
   // cor azul
   glColor3f(0.0f,0.0f,1.0f);
   
   //espessura da linha
   glLineWidth(5);
   
   //Desenha linhas de espessura 5 e cor azul na parte inferior da janela
   glBegin(GL_LINES);
                      glVertex2f(-40.0f,-40.0f);
                      glVertex2f(40.0f,-40.0f);
                      glVertex2f(-40.0f,-30.f);
                      glVertex2f(40.0f,-30.0f);
   glEnd();
   
   glGetIntegerv(GL_LINE_WIDTH,&width);
   
   glPopAttrib();
   
   glBegin(GL_LINES);
                     glVertex2f(-40.0f,-5.0f);
                     glVertex2f(40.0f,5.0f);  
                     glVertex2f(-40.0f,5.0f);
                     glVertex2f(40.0f,5.0f);
   glEnd();
   
   glPopAttrib();
   
   glBegin(GL_LINES);
                     glVertex2f(-40.0f,30.0f);
                     glVertex2f(40.0f,30.0f);  
                     glVertex2f(-40.0f,40.0f);
                     glVertex2f(40.0f,40.0f);
   glEnd();
   
   glFlush();
     
}//fim do metodo desenha

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
  if(h==0) h=1;
  
  glViewport(0,0,w,h);
  
  glMatrixMode(GL_PROJECTION);
  
  glLoadIdentity();
  
  if(w<=h) gluOrtho2D(-50.0f,50.0f,-50.0f*h/w,50.0f*h/w);
  else gluOrtho2D(-50.0f*w/h,50.0f*w/h,-50.0f,50.0f);
  
}//fim altera

//funcao inicializa
void Inicializa(void)
{
   glClearColor(1.0f,1.0f,1.0f,1.0f);     
     
}//fim da funcao inicializa

//programa principal

int main(void)
{
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowPosition(5,5);
    
    glutInitWindowSize(450,450);
    
    glutCreateWindow("DESENHO DE LINHAS");
    
    glutDisplayFunc(Desenha);
    
    glutReshapeFunc(AlteraTamanhoJanela);
    
    Inicializa();
    
    glutMainLoop();
    
    return 0;
    
}//fim doprincipal
