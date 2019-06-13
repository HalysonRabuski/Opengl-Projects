#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <GL/glut.h>
#include <gl\gl.h>
#include <GL\freeglut_ext.h>


#define janela_altura GetSystemMetrics(SM_CYSCREEN)
#define janela_largura GetSystemMetrics(SM_CXSCREEN)

int interval = 1000 / 60;
int resul_esq = 0;
int resul_dir = 0;

// ball
float xBola = janela_largura / 2;
float yBola = janela_altura / 2;
float xDirBola = -1.0f;
float yDirBola = 0.0f;
int bolaTamanho = 8;
int bolaVel = 10;

// tamanho e velocidade das raquetes
int largura_raquete = 10;
int altura_raquete = 110;
int velocidade_raq = 5;

// raquete esquerda
float xRaqEsq = 10.0f;
float yRaqEsq = janela_altura/2;

// raquete direita
float xRaqDir = janela_largura - largura_raquete - 10;
float yRaqDir = 50;

void keyboard(unsigned char key, int x, int y);
void display(void);
void tela(GLsizei w, GLsizei h);
std::string int2str(int x);
void drawText(float x, float y, std::string text);
void teclado();
void update(int value);
void manterDir(float& x, float& y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//glutInitWindowSize(janela_largura, janela_altura);
	//glutInitWindowPosition(0, 0);
	glutCreateWindow("PONG");
	glutFullScreen();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutTimerFunc(interval, update, 0);
	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutMainLoop();

	return(0);
}

void keyboard(unsigned char key, int x, int y) {
	
	//ESC FECHA
	if (key == 27) {
		glutDestroyWindow(0);
		exit(0);
	}

}

void teclado() {
	//MOVIMENTAÇÃO DA RAQUETE ESQUERDA
	if (yRaqEsq + altura_raquete <= janela_altura) {
		if (GetAsyncKeyState(0X57)) yRaqEsq += velocidade_raq;
	}

	if (yRaqEsq >= 0) {
		if (GetAsyncKeyState(0X53)) yRaqEsq -= velocidade_raq;
	}

	//MOVIMENTAÇÃO DA RAQUETE DIREITA
	if (yRaqDir + altura_raquete <= janela_altura) {
		if (GetAsyncKeyState(VK_UP)) yRaqDir += velocidade_raq;
	}

	if (yRaqDir >= 0) {
		if (GetAsyncKeyState(VK_DOWN)) yRaqDir -= velocidade_raq;
	}
}

void update(int value) {
	xBola += xDirBola * bolaVel;
	yBola += yDirBola * bolaVel;

	// colisao com raquete esquerda
	if (xBola < xRaqEsq + largura_raquete && xBola > xRaqEsq && yBola < yRaqEsq + altura_raquete && yBola > yRaqEsq) {
		xDirBola = fabs(xDirBola);
		yDirBola = ((yBola - yRaqEsq) / altura_raquete) - 0.5f;
	}

	//colisao com raquete direita
	if (xBola < xRaqDir + largura_raquete && xBola > xRaqDir && yBola < yRaqDir + altura_raquete && yBola > yRaqDir) {
		xDirBola = -fabs(xDirBola);
		yDirBola = 0;
		yDirBola = ((yBola - yRaqEsq) / altura_raquete) - 0.5f;
	}

	// ponto do lado esquerdo (positivo para o lado direito)
	if (xBola < 0) {
		++resul_dir;
		xBola = janela_largura / 2;
		yBola = janela_altura / 2;
		xDirBola = fabs(xDirBola);
		yDirBola = 0;
	}
	
	// ponto no lado direito (positivo para o esquerdo)
	if (xBola > janela_largura) {
		++resul_esq;
		xBola = janela_largura / 2;
		yBola = janela_altura / 2;
		xDirBola = -fabs(xDirBola);
		yDirBola = 0;
	}

	// colisao cima
	if (yBola > janela_altura) {
		yDirBola = -fabs(yDirBola);
	}

	//colisao baixo
	if (yBola < 0) {
		yDirBola = fabs(yDirBola);
	}

	//QUANDO ALGUM JOGADOR MARCA 5 PONTOS ELE PAUSA POR 2 SEGUNDOS E REINICIAR O PLACAR
	if (resul_esq == 5) {
		Sleep(2000);
		resul_esq = 0;
		resul_dir = 0;
	}
	else if (resul_dir == 5) {
		Sleep(2000);
		resul_esq = 0;
		resul_dir = 0;
	}



	manterDir(xDirBola,yDirBola);

	teclado();

	glutTimerFunc(interval, update, 0);

	glutPostRedisplay();
}

void manterDir(float& x, float& y) {
	float tamanho = sqrt((x * x) + (y * y));
	if (tamanho != 0.0f) {
		tamanho = 1.0f / tamanho;
		x *= tamanho;
		y *= tamanho;
	}
}

void desenho() {
	
	glColor3f(1, 1, 1);
	//PONTUAÇÃo

	drawText(janela_largura / 2 - 10, janela_altura - 15 , int2str(resul_esq) + ":" + int2str(resul_dir));

	//RAQUETE ESQUERDA
	glBegin(GL_QUADS);
	glVertex2f(xRaqEsq, yRaqEsq);
	glVertex2f(xRaqEsq + largura_raquete, yRaqEsq);
	glVertex2f(xRaqEsq + largura_raquete, yRaqEsq + altura_raquete);
	glVertex2f(xRaqEsq, yRaqEsq + altura_raquete);
	glEnd();

	//RAQUETE DIREITA
	glBegin(GL_QUADS);
	glVertex2f(xRaqDir, yRaqDir);
	glVertex2f(xRaqDir + largura_raquete, yRaqDir);
	glVertex2f(xRaqDir + largura_raquete, yRaqDir + altura_raquete);
	glVertex2f(xRaqDir, yRaqDir + altura_raquete);
	glEnd();

	
	glColor3f(1, 1, 1); // cor
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(xBola, yBola);     //olho direito
	glEnd();



	glutPostRedisplay();
}

//desenhar texto
void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

//transformar int em string
std::string int2str(int x) {
	std::stringstream ss;
	ss << x;
	return ss.str();
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, janela_largura, janela_altura);
	desenho();

	glutSwapBuffers();
}


void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}	