#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include<math.h>

void Desenha(void)
// funcoa que tem como objetivo desenhar uma tela em branco
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

void DesenhaTriangulo(void)
// funcao que tem como objetivo desenhar um triangulo na tela
{
    glClearColor(1,1,1,0); // define como cor branca da janela de fundo
	glClear(GL_COLOR_BUFFER_BIT);

// Desenhando os triangulos
   // desenhando o primeiro triangulo 
   glBegin(GL_TRIANGLES);
   
   //dando cores para cada vertice:    
   glColor3f(0,1,0); //verde
   glVertex2f(-0.4,-0.5);   
   
   glColor3f(1,1,0); //amarelo
   glVertex2f(0,0.5);
   
   glColor3f(0,0,1); //verde
   glVertex2f(0.4,-0.5);

   glEnd(); // fim do triangulo 1
       
   glFlush();     
}// fim desenha Triangulo

void DesenhaTrianguloRetangulo(void){
     
   glClearColor(1,1,1,0); // define como cor branca do fundo da janela
   glClear(GL_COLOR_BUFFER_BIT);
        
   //Desenhando o retangulo 
   glBegin(GL_QUADS); 

   glColor3f(0,0,0); //Define a cor preta 
   glVertex2f(-0.8,0.5);
    
   glColor3f(1,0,0);
   glVertex2f(0.8,0.5);
    
   glColor3f(0,0,0);
   glVertex2f(0.8,-0.5);
    
   glColor3f(1,0,0);
   glVertex2f(-0.8,-0.5);

   glEnd(); // end do retangulo
        
// Desenhando os triangulos
   // desenhando o primeiro triangulo 
   glBegin(GL_TRIANGLES);
   
   glColor3f(1,1,0); //amarelo
   glVertex2f(-0.4,0.5);   
 
   glColor3f(0,1,0); //verde
   glVertex2f(0,-0.5);
   
   glColor3f(0,1,0); //verde
   glVertex2f(-0.8,-0.5);

   glEnd(); // fim do triangulo 1
   
    //desenhando o segundo triangulo
    glBegin(GL_TRIANGLES);
    
    glColor3f(0,1,0); // amarelo
    glVertex2f(0.4,0.5);
    
    glColor3f(1,1,0); // amarelo
    glVertex2f(0.8,-0.5);
    
    glColor3f(1,1,0); // amarelo
    glVertex2f(0,-0.5);
    
    glEnd(); // fim do 2 triangulo
    //comando que define o fim dos comandos da OPenGL

	glFlush();
}//fim da função para desenhar um triangulo retangulo

void DesenhaCasa(void)
//inicio do metodo desenha casa
{
glClearColor(1,1,1,0); // define como cor branca do fundo da janela
   glClear(GL_COLOR_BUFFER_BIT);
        
   //Desenhando o retangulo 
   glBegin(GL_QUADS); 

   glColor3f(1,1,0); //Define a cor preta 
   glVertex2f(-0.9,0.4);
    
//   glColor3f(1,0,0);
   glVertex2f(0.9,0.4);
    
  // glColor3f(0,0,0);
   glVertex2f(0.9,-0.9);
    
   //glColor3f(1,0,0);
   glVertex2f(-0.9,-0.9);

   glEnd(); // end do retangulo
//********************************
//telhado
      //desenhando o triangulo
   glBegin(GL_TRIANGLES);
   
   glColor3f(1,0,0); //amarelo
   glVertex2f(-0.9,0.4);   
 
//   glColor3f(0,1,0); //verde
   glVertex2f(0,0.9);
   
  // glColor3f(0,1,0); //verde
   glVertex2f(0.9,0.4);

   glEnd(); // fim do triangulo 1
//********************************    
    //JANELA esquerda
    glBegin(GL_QUADS); 
   glColor3f(1,0,0); //Define a cor preta 
   glVertex2f(-0.7,-0.2);
  // glColor3f(1,0,0);
  glVertex2f(-0.4,-0.2);
  // glColor3f(0,0,0);
   glVertex2f(-0.4,-0.6);
   //glColor3f(1,0,0);
   glVertex2f(-0.7,-0.6);
    
    glEnd();
    
    
glBegin(GL_TRIANGLES);

glColor3f(0,0,0);

glVertex2f(-0.4,-0.6);
glVertex2f(-0.55,-0.2);
glVertex2f(-0.7,-0.6);

glEnd();
    
//********************************    
    //Porta
    
    glBegin(GL_QUADS);
    
    glColor3f(0,0,0);
    
    glVertex2f(-0.15,0);
    glVertex2f(0.15,0);
    glVertex2f(0.15,-0.9);
    glVertex2f(-0.15,-0.9);

glEnd();    
//************************
//2a janela
    glBegin(GL_QUADS); 
   glColor3f(1,0,0); //Define a cor preta 
   glVertex2f(0.7,-0.2);
 // glColor3f(1,0,0);
   glVertex2f(0.4,-0.2);
  // glColor3f(0,0,0);
   glVertex2f(0.4,-0.6);
   //glColor3f(1,0,0);
   glVertex2f(0.7,-0.6);
    
    glEnd();

glBegin(GL_TRIANGLES);

glColor3f(0,0,0);

glVertex2f(0.4,-0.6);
glVertex2f(0.55,-0.2);
glVertex2f(0.7,-0.6);

glEnd();


//***********************************    
      //desenhando um circulo com uma propria função 
// tentando desenhar uma circunferencia
// DESISTO DE DESENHAR UM CIRCULO
float PI = 3.1415, angle;
GLfloat circle_points = 100;
glBegin(GL_LINE_LOOP);

for( int i=0; i<circle_points; i++)
{//inicio for
glColor3f(0,0,0);
          angle = 2*PI*1/circle_points;
          glVertex2f(cos(angle), sin(angle));
}//fim for

glEnd();




/*   int i, num_linhas=2000; 
    GLfloat angulo, raio; 
    
    angulo = 2 * M_PI / num_linhas; 
    
    glBegin(GL_LINE_LOOP); 
    for(i = 1; i <= num_linhas; i++) 
    { 
        glVertex2f(cos(i * angulo) * raio, sin(i * angulo) * raio); 
    } 
    glEnd(); 
  */     
       
       
       
   glFlush();   
     
     
}// fim do metodo desenha casa

void Teclado(unsigned char key, int x, int y)
{	
	if (key==27) // pressionando a tecla esc saira do programa		
		exit(0);
	
	if (key == 97) // pressinando a tecla "a" ajustara pra tela inteira
       glutFullScreen();
	
	if (key == 65) // pressionando a tecla "A" ajustara a tela como definida abaixo
    {
       glutReshapeWindow(500,400);
       glutPositionWindow(100,100);
    }
}// fim da funcao teclado

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
           case 1:{
              printf("Opçao Triangulo");
              glutDisplayFunc(DesenhaTriangulo);
              break;
           }//fim case 0
           case 2:{
              printf("Opçao Retangulo com Triangulos");
              glutDisplayFunc(DesenhaTrianguloRetangulo);
              break;
           }// fim case 1
           case 3: {
              printf("Desenha Casa");
              glutDisplayFunc(DesenhaCasa);
              break;
           }// fim case 2
           case 0: {
              printf("Limpa");
              glutDisplayFunc(Desenha);
              break;
           }// fim case 2
        }// fim switch
        printf("\n");
        glutPostRedisplay();
}//fim da funcao MenuWin

void CriaMenu()
{
     int menu,submenu1;
     submenu1 = glutCreateMenu(MenuWin);
     glutAddMenuEntry("Triangulo",1);
     glutAddMenuEntry("Retangulo com Triangulos",2);
     glutAddMenuEntry("Desenha Casa",3);
     glutAddMenuEntry("Limpa",0);
     
     menu = glutCreateMenu(MenuWin);
     glutAddSubMenu("Escolha a opção",submenu1);
     
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}// fim da funcao CriaMenu

int main(int argc,char ** argv){
	
	glutInit(&argc,argv);

	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	
	glutInitWindowSize( 700,500 );
	
	glutCreateWindow("Sexto Trabalho");
	
	glutDisplayFunc(Desenha); //desenha a tela

	glutKeyboardFunc(Teclado);
	
	Inicializa();

	CriaMenu();
	
	glutMainLoop();
	
	return 0;
}// fim do programa principal
