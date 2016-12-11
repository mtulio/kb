#include <stdlib.h>
#include <GL/glut.h>

GLfloat win, deslocamentoX,deslocamentoY;
GLsizei largura, altura;

void Desenha (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	
	glBegin(GL_QUADS);
		glVertex2f(-15.0f,-15.0f);
		glVertex2f(-15.0f,  5.0f);
		glVertex2f( 15.0f,  5.0f);
		glVertex2f( 15.0f,-15.0f);
	glEnd();
	
	
	glColor3f(0.0f, 0.0f, 0.0f);
	
	glBegin(GL_QUADS);
		glVertex2f(-4.0f,-14.5f);
		glVertex2f(-4.0f, 0);
		glVertex2f(4.0f, 0);
		glVertex2f(4.0f,-14.5f);
    	glVertex2f(7.0f, -5.0f);
		glVertex2f(7.0f, -1.0f);
		glVertex2f(13.0f, -1.0f);
		glVertex2f(13.0f,-5.0f);
	glEnd();
	
	
	glColor3f(1.0f, 1.0f, 1.0f);
	
           	glBegin(GL_LINES);
 
                      glVertex2f(7.0f, -3.0f);
                      glVertex2f(13.0f, -3.0f);
                       glVertex2f(10.0f, -1.0f);
                        glVertex2f(10.0f, -5.0f);
                         glEnd();

	glColor3f(0.3f, 0.0f, 0.2f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-15.0f, 5.0f);
	glVertex2f(0, 17.0f);
	glVertex2f(15.0f, 5.0f);
	glEnd();
	
	glFlush();
}

void ParametrosVisualizacao (void)
{
     	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
		if (largura <= altura) 

		gluOrtho2D (-win+deslocamentoX,win+deslocamentoX,-win*altura/largura+deslocamentoY, win*altura/largura+deslocamentoY);

             else

        gluOrtho2D (-win*largura/altura+deslocamentoX, win*largura/altura+deslocamentoX, -win+deslocamentoY, win+deslocamentoY);

       	     glMatrixMode(GL_MODELVIEW);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as vari�veis
	largura = w;
	altura = h;

	// Especifica as dimens�es da Viewport
	glViewport(0, 0, largura, altura);
	ParametrosVisualizacao();
}
void TeclasEspeciais(int key, int x, int y)
{
     switch (key)
     {
            case GLUT_KEY_UP:
                 deslocamentoY-=2;
                 break;
            case GLUT_KEY_DOWN:
                 deslocamentoY+=2;
                 break;
            case GLUT_KEY_LEFT:
                 deslocamentoX+=2;
                 break;
            case GLUT_KEY_RIGHT:
                 deslocamentoX-=2;
                 break;
            case GLUT_KEY_PAGE_UP:
                 if(win>0){
                           win+=5.0f;
                           }
                 break;     
            case GLUT_KEY_PAGE_DOWN:
                 if(win<900){
                           win-=5.0f;
                           }
                 break;     
     }
	ParametrosVisualizacao();
    glutPostRedisplay();
}

void Teclado (unsigned char key, int x, int y)
{
     if((key == 27) || (key ==13))
     exit(0);
}



void Inicializa(void)
{
     glClearColor(0.0f,0.0f,1.0f,0.0f);
     win=50.0f;
     deslocamentoX=0;
     deslocamentoY=0;
}

int main(int argc,char ** argv){
	
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

	glutInitWindowPosition(5,5); 

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450); 

	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Exemplo Zoom e Pan");

	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);
	
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutSpecialFunc(TeclasEspeciais);

	// Registra a fun��o callback que ser� chamada a cada intervalo de tempo
	glutKeyboardFunc(Teclado);

	// Chama a fun��o respons�vel por fazer as inicializa��es 
	Inicializa();

	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();

	return 0;
}  

            
