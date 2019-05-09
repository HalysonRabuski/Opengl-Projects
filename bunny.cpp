#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535898
#define janela_altura 400
#define janela_largura 600
void display(void);
void tela(GLsizei w, GLsizei h);
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("Halyson_Páscoa"); // cria janela
												 //glutFullScreen();
	glutReshapeFunc(tela); // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}
void desenhar()
{
	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 45.0f, raioY = 55.0f;
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);         //CORPO
	}
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}

	glEnd();

	raioX = 30;
	raioY = 35;
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY+70);     //CABEÇA
	}
	glEnd();
	
	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY + 70);
	}
	glEnd();

	raioX = 20;
	raioY = 10;
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX+30, sin(ang)*raioY-50);       //PÉ
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX + 30, sin(ang)*raioY - 50);
	}
	glEnd();

	raioX = 20;
	raioY = 10;
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX - 30, sin(ang)*raioY - 50);    //PÉ
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX - 30, sin(ang)*raioY - 50);
	}
	glEnd();


	raioX = 12;
	raioY = 12;
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY);    //MAO ESQ
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 40, sin(ang) * raioY);
	}
	glEnd();

	
	glColor3f(1.0, 1.0, 1.0); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 40, sin(ang) * raioY);    //MAO DIR
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 40, sin(ang) * raioY);
	}
	glEnd();

	raioX = 20;
	raioY = 30;
	glColor3f(0.9, 0.9, 0.98); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);     //MANCHA DA BARRIGA
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	raioX = 7;
	raioY = 20;
	glColor3f(1, 1, 1); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 15, sin(ang) * raioY+110);     //ORELHA ESQ
	}
	glEnd();

	raioX = 7;
	raioY = 20;
	glColor3f(1, 1, 1); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 15, sin(ang) * raioY + 110);     //ORELHA DIR
	}
	glEnd();

	
	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(-5, 55);
	glVertex2f(-5, 50);                 //DENTE
	glVertex2f(0, 50);
	glVertex2f(0, 55);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(0, 50);
	glVertex2f(5, 50);                    //DENTE
	glVertex2f(5, 55);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glPointSize(8.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(10, 80);     //olho direito
	glEnd();


	glColor3f(0, 0, 0); // cor
	glBegin(GL_POINTS);
	glVertex2f(-10, 80);     //olho esquerdo
	glEnd();

	glColor3f(0, 0, 0); // cor
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2f(0, 65);     //boca
	glEnd();


	raioX = 20;
	raioY = 30;
	glColor3f(0.12, 0.56, 1); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 100, sin(ang) * raioY - 35);     //OVO AZUL
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX + 100, sin(ang) * raioY - 35);
	}
	glEnd();

	glColor3f(0.24, 0.7, 0.44); // cor
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(100, -5);     //LAÇO VERDE - PART ESQ
	glVertex2f(80, -15);
	glVertex2f(80, 5);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(100, -5);     //LAÇO VERDE
	glVertex2f(80, -15);
	glVertex2f(80, 5);
	glVertex2f(100, -5);
	glEnd();

	glColor3f(0.24, 0.7, 0.44); // cor
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(100, -5);     //LAÇO VERDE - PART DIR
	glVertex2f(120, -15);
	glVertex2f(120, 5);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(100, -5);     //LAÇO VERDE
	glVertex2f(120, -15);
	glVertex2f(120, 5);
	glVertex2f(100, -5);
	glEnd();

	raioX = 20;
	raioY = 30;
	glColor3f(0.24, 0.7, 0.44); // cor
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 100, sin(ang) * raioY - 35);     //OVO VERDE
	}
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++)
	{
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX - 100, sin(ang) * raioY - 35);
	}
	glEnd();

	glColor3f(0.12, 0.56, 1); // cor
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-100, -5);     //LAÇO AZUL - PART ESQ
	glVertex2f(-80, -15);
	glVertex2f(-80, 5);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(-100, -5);     //LAÇO VERDE
	glVertex2f(-80, -15);
	glVertex2f(-80, 5);
	glVertex2f(-100, -5);
	glEnd();

	glColor3f(0.12, 0.56, 1); // cor
	glPointSize(2.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-100, -5);     //LAÇO VERDE - PART DIR
	glVertex2f(-120, -15);
	glVertex2f(-120, 5);
	glEnd();

	glColor3f(0, 0, 0); // cor
	glBegin(GL_LINE_STRIP);
	glVertex2f(-100, -5);     //LAÇO VERDE
	glVertex2f(-120, -15);
	glVertex2f(-120, 5);
	glVertex2f(-100, -5);
	glEnd();



		
}
void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // cor do fundo
	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPESA
								  // Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush(); // execute o desenho
}
void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}