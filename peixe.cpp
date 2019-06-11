#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 500
#define janela_largura 800
GLfloat  circ_pnt = 500;
GLfloat  ang, raioX = 200.0f, raioY = 150.0f;

// Coordenadas variáveis para X e Y
float tx = 0.0;
float ty = 0.0;

// Número de passos movidos por Loop de animação
float xStep = 4;
float yStep = 4;

// Variável flag para saber a direção do peixe
float x = 0;

// Variável de rotação
float rot = 180.0;

// Define o nível de R, G e B
float r = 0.6;
float g = 0.7;
float b = 0.6;

// Declaração de funções
void anima(int valor);
void peixe();
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);

// Main
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Peixe");
	glutReshapeFunc(tela);
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(150, anima, 10);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar
	return(0);
}

// Função de animação
void anima(int valor) {

	if ((tx) > (120)) {
		xStep = -xStep;
		x = 1;
	}

	if ((tx) < (-120)) {
		xStep = -xStep;
		x = 0;
	}

	if ((ty) > (10) || (ty) < (-30)) {
		yStep = -yStep;
	}

	ty += yStep;
	tx += xStep;

	glutPostRedisplay();
	glutTimerFunc(95, anima, 1);
}

void ambiente() {

	// Aquario
	
	ang, raioX = 200.0f, raioY = 150.0f;
	glRotatef(180, 0, 0, 0);
	glColor3f(0.20, 0.20, 0.20);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt/2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	// Água
	circ_pnt = 500;
	ang, raioX = 190.0f, raioY = 140.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(0.25, 0.77, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();


}

// Desenha o peixe
void peixe() {

	glTranslated(tx, ty, 0);
	glRotatef(rot, 0.0, 0.0, 1.0);

	if (x == 1) { // Quando o peixe bater no aquário ele muda de direção
		glRotatef(180.0, 0.0, 1.0, 0.0);
	}

	// PEIXE
	circ_pnt = 500;
	ang, raioX = 20.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioX - 50);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(20, -50);
	glVertex2f(45, -70);
	glVertex2f(45, -30);
	glEnd();




}

// Função para utilizar o teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'q':
		r = 0.2;
		g = 0.5;
		b = 0.8;
		break;

	case 'w':
		r = 0.0;
		g = 0.0;
		b = 0.0;
		break;

	case 'e':
		r = 0.6;
		g = 0.2;
		b = 0.1;
		break;

	case 'r':
		r = 1.0;
		g = 0.8;
		b = 1.0;
		break;
	}
}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0.35f, 1.0f, 0.35f, 1.0f); // cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	ambiente();
	peixe();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
