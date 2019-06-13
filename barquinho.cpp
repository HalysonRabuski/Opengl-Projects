#include <stdlib.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(400, 400);  // tamanho da janela

	//glutFullScreen();  // full screen

	glutInitWindowPosition(10, 300); // posicao inicial da janela

	glutCreateWindow("Barquinho");   /// cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(&resize); // 

	glutDisplayFunc(display);

	glutMainLoop();

	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '\x1B':
		exit(EXIT_SUCCESS);
		break;
	}
}

void resize(GLsizei w, GLsizei h)
{

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

   // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
	{
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else
	{
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);


}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 1.0f, 0.2f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0.6f);
	glVertex2f(0, 0);
	glVertex2f(0, 75);
	glVertex2f(150, 75);
	glVertex2f(150, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.25f, 0.15f);
	glVertex2f(150, 0);
	glVertex2f(150, 90);          //PIER            
	glVertex2f(190, 90);
	glVertex2f(190, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0.4f, 0);
	glVertex2f(190, 0);
	glVertex2f(190, 90);    //GRAMA
	glVertex2f(300, 90);
	glVertex2f(300, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.36f, 0.2f, 0.09f);
	glVertex2f(45, 75);
	glVertex2f(30, 100);
	glVertex2f(120, 100);       //CASCO DO BARQUINHO
	glVertex2f(105, 75);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.3f, 0.1f);
	glVertex2f(45, 100);
	glVertex2f(45, 110);          //RETANGULO EM CIMA DO BARQUINHO
	glVertex2f(80, 110);
	glVertex2f(80, 100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(50, 103);
	glVertex2f(50, 106);
	glVertex2f(53, 106);
	glVertex2f(53, 103);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(55, 103);
	glVertex2f(55, 106);
	glVertex2f(58, 106);
	glVertex2f(58, 103);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(80, 100);
	glVertex2f(80, 140);
	glVertex2f(95, 140);
	glVertex2f(95, 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(80, 135);
	glVertex2f(95, 135);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.36f, 0.2f, 0.0f);
	glVertex2f(210, 90);
	glVertex2f(210, 130);
	glVertex2f(225, 130);
	glVertex2f(225, 90);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0.2f, 0);
	glVertex2f(217.5, 215);
	glVertex2f(190, 130);
	glVertex2f(245, 130);
	glEnd();

	glFlush(); // executa o desenho
}