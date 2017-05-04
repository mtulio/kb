#include<stdlib.h>
#include<GL\glut.h>
#include<math.h>
//#define M_PI 3.1415

void Desenha(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   
   //desenhando o 1o ponto
   glColor3f(0.0f,0.0f,0.0f);   
   glPointSize(5.0f);
   glBegin(GL_POINTS);
           glVertex2f(-0.80f,0.6f);
   glEnd();
   
   //desenhando o 2o ponto
   glColor3f(0.0f,0.0f,0.0f);   
   glPointSize(5.0f);
   glBegin(GL_POINTS);
           glVertex2f(-0.60f,0.80f);
   glEnd();

   //desenhando o 3o ponto
   glColor3f(0.0f,0.0f,0.0f);   
   glPointSize(5.0f);
   glBegin(GL_POINTS);
           glVertex2f(-0.40f,0.60f);
   glEnd();

//*******

//desenhando o Poligono
   glColor3f(1,1,0);
   glBegin(GL_POLYGON);
           glVertex2f(0.20f,0.50f);//1
           glVertex2f(0.40f,0.60f);//2
           glVertex2f(0.60f,0.60f);//3
           glVertex2f(0.80f,0.50f);//4
           glVertex2f(0.60f,0.40f);//5
           glVertex2f(0.40f,0.40f);//6
   glEnd();
   
   
   
   /*
   glPointSize(10.0f);
   
   glColor3f(1.0f,0.0f,0.0f);
   glBegin(GL_POINTS);
                      glVertex2f(0.50f,0.50f);
   glEnd();
     */ 
   
   /*
   //desenha um criculo
   glPointSize(5.0f);
   float ang=1;//, M_PI=3.1415;
   //float M_PI=3.1415;
   glColor3f(1,0,0);
   glBegin(GL_POINTS);
   for(ang=0;ang<2*M_PI;ang+=M_PI/7.0)
                                      glVertex2f(20*cos(ang),20*sin(ang));
   glEnd();
   */
      
   glFlush();
     
}//fim do metodo desenha

//funcao inicializa
void Inicializa(void)
{
   glClearColor(1.0f,1.0f,1.0f,1.0f);     
     
}//fim da funcao inicializa

//programa principal

int main(void)
{
    
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //glutInitWindowPosition(5,5);
    
    glutInitWindowSize(450,450);
    
    glutCreateWindow("DESENHO DE LINHAS");
    
    glutDisplayFunc(Desenha);
    
    //glutReshapeFunc(AlteraTamanhoJanela);
    
    Inicializa();
    
    glutMainLoop();
    
    return 0;
    
}//fim doprincipal
