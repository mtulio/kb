#include<stdlib.h>
#include<GL/glut.h>

void Desenha(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 0.0f);
   glutWireCube(80);
   glFlush();     
}//fim da função desenha

//funcao para especificar o volume da visualização
void EspecificaParametrosVisualizacao(void)
{
     //especifica sistemas de coordenadas de projecao
     glMatrixMode(GL_PROJECTION);
     
     //inicializa sistemas de coordenadas de projecao
     glLoadIdentity();
     
     //especifica a projecao paralela ortografica(esquerda, direita, inferior
     // superior, plano frontal, plano traseiro)
     glOrtho(-65.0,65.0, -65.0, 65.0, -200.0, 200.0);
     
     //especifica o sistema de oordenadas do modelo
     glMatrixMode(GL_MODELVIEW);
     
     //inicializa o sistema de coordenadas do modelo
     glLoadIdentity();
     
     //especifica posicao do observador e do alvo
     gluLookAt(40,60,100,0,0,0,0,1,0);
}//fim especifica parametros visualizacao

//funcao callback chamada quando o tamanho da janela é alterdo
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     //para prevenir uma divisao por zero
     if(h==0) h=1;
     
     //especifica as dimensoes do viewpoint
     glViewport(0,0,w,h);
     
     EspecificaParametrosVisualizacao();
}//fim da funcao altera tamanho

//Funcao responsavel por inicializar parametros e variaveis
void Inicializa(void)
{
     glClearColor(0.0f,0.0f,0.0f,0.0f);
}//fim inicializa
