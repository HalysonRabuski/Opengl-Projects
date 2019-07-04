#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <GL/glut.h>
#include <gl\gl.h>
#include <GL\freeglut_ext.h>

#define janela_altura 600
#define janela_largura 1000

int interval = 1000 / 60;
int resul_esq = 0;
int result_dir = 0;

//galinha
int galinhaRaio = 5;
int galinhaX = janela_largura/2;
int galinhaY = 17;
int galinhaAltura = 15;
int galinhaLargura = 7;


//propriedades de carros
int carroAltura = 29;
int carroLargura = 45;

//carro1
int xCarro1 = 0;
int yCarro1 = 46;

//carro 2
int xCarro2 = 0;
int yCarro2 = 99;

//carro 3
int xCarro3 = 0;
int yCarro3 = 149;

//carro 4
int xCarro4 = 0;
int yCarro4 = 199;

//carro 5
int xCarro5 = 0;
int yCarro5 = 249;

//carro 6
int xCarro6 = janela_largura;
int yCarro6 = 302;

//carro 7
int xCarro7 = janela_largura;
int yCarro7 = 352;
//carro 8
int xCarro8 = janela_largura;
int yCarro8 = 402;
//carro 9
int xCarro9 = janela_largura;
int yCarro9 = 452;
//carro 10
int xCarro10 = janela_largura;
int yCarro10 = 502;

// tamanho e velocidade das raquetes
int largura_raquete = 10;
int altura_raquete = 110;
int velocidade_raq = 5;



void keyboard(unsigned char key, int x, int y);
void display(void);
void tela(GLsizei w, GLsizei h);
std::string int2str(int x);
void drawText(float x, float y, std::string text);
void teclado();
void update(int value);
void desenhaCarro(int xCarro, int yCarro);
void desenhaCarrosCima(int xCarro, int yCarro);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PONG");
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
	
	if (GetAsyncKeyState(0X53)) galinhaY += 2;

}

void update(int value) {

	xCarro1 += 6;
	xCarro2 += 7;
	xCarro3 += 8;
	xCarro4 += 9;
	xCarro5 += 10;
	
	xCarro6 -= 10;
	xCarro7 -= 9;
	xCarro8 -= 8;
	xCarro9 -= 7;
	xCarro10 -= 6;

	if (xCarro1 >= janela_largura) {
		xCarro1 = 0;
	}
	if (xCarro2 >= janela_largura) {
		xCarro2 = 0;
	}
	if (xCarro3 >= janela_largura) {
		xCarro3 = 0;
	}
	if (xCarro4 >= janela_largura) {
		xCarro4 = 0;
	}
	if (xCarro5 >= janela_largura) {
		xCarro5 = 0;
	}
	if (xCarro6 <= 0) {
		xCarro6 = janela_largura;
	}
	if (xCarro7 <= 0) {
		xCarro7 = janela_largura;
	}
	if (xCarro8 <= 0) {
		xCarro8 = janela_largura;
	}
	if (xCarro9 <= 0) {
		xCarro9 = janela_largura;
	}
	if (xCarro10 <= 0) {
		xCarro10 = janela_largura;
	}

	if (((galinhaX + galinhaLargura) <= (xCarro1 + carroLargura) && (galinhaX + galinhaLargura >= xCarro1)) && (galinhaY + galinhaAltura >= yCarro1) && (galinhaAltura + galinhaY <= yCarro1 + carroAltura)||(galinhaX>=xCarro1)&&(galinhaX<=xCarro1+carroLargura)&&(galinhaY>=yCarro1)&&(galinhaY<=yCarro1+carroAltura)) {
		galinhaY = 17;
	}
	else if (((galinhaX + galinhaLargura) <= (xCarro2 + carroLargura) && (galinhaX + galinhaLargura >= xCarro2)) && (galinhaY + galinhaAltura >= yCarro2) && (galinhaAltura + galinhaY <= yCarro2 + carroAltura) || (galinhaX >= xCarro2) && (galinhaX <= xCarro2 + carroLargura) && (galinhaY >= yCarro2) && (galinhaY <= yCarro2 + carroAltura)) {
		galinhaY = 17;
	}

	//QUANDO ALGUM JOGADOR MARCA 5 PONTOS ELE PAUSA POR 2 SEGUNDOS E REINICIAR O PLACAR
	if (resul_esq == 5) {
		Sleep(2000);
		resul_esq = 0;
	}

	teclado();

	glutTimerFunc(interval, update, 0);

	glutPostRedisplay();
}

void desenho() {

	glColor3f(1, 1, 1);
	//PONTUAÇÃO
	drawText(janela_largura / 2 - 10, janela_altura - 15, int2str(resul_esq));


	//calçada inferior
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.4, 1);
	glVertex2f(0, 0);
	glVertex2f(0,35);
	glVertex2f(janela_largura, 35);
	glVertex2f(janela_largura, 0);
	glEnd();

	//calçada superior
	glBegin(GL_QUADS);
	glVertex2f(0, 580);
	glVertex2f(0, 545);
	glVertex2f(janela_largura, 545);
	glVertex2f(janela_largura, 580);
	glEnd();

	glColor3f(1, 1, 1); //branco

	//linha 1
	glLineStipple(8, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 86);
	glVertex2f(janela_largura, 86);
	glEnd();

	//linha 2
	glBegin(GL_LINES);
	glVertex2f(0, 137);
	glVertex2f(janela_largura, 137);
	glEnd();

	//linha 3
	glBegin(GL_LINES);
	glVertex2f(0, 188);
	glVertex2f(janela_largura, 188);
	glEnd();

	//linha 4
	glBegin(GL_LINES);
	glVertex2f(0, 239);
	glVertex2f(janela_largura, 239);
	glEnd();
	glutPostRedisplay();

	//amarelo
	glColor3f(1, 1, 0);

	//linhas amarelas
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 290);
	glVertex2f(janela_largura, 290);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, 295);
	glVertex2f(janela_largura, 295);
	glEnd();

	//branco
	glColor3f(1, 1, 1);

	//linha 5
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 342);
	glVertex2f(janela_largura, 342);
	glEnd();

	//linha 6
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 393);
	glVertex2f(janela_largura, 393);
	glEnd();

	//linha 7
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 444);
	glVertex2f(janela_largura, 444);
	glEnd();

	//linha 8
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(0, 495);
	glVertex2f(janela_largura, 495);
	glEnd();

	glColor3f(0.35, 1, 0);
	
	//carros
	desenhaCarro(xCarro1, yCarro1);

	glColor3f(0.56, 0.2, 0.7);
	desenhaCarro(xCarro2, yCarro2);

	glColor3f(0.98, 0.1, 0.7);
	desenhaCarro(xCarro3, yCarro3);

	glColor3f(0, 0, 1);
	desenhaCarro(xCarro4, yCarro4);

	glColor3f(1, 0, 0);
	desenhaCarro(xCarro5, yCarro5);

	glColor3f(0, 1, 1);
	desenhaCarrosCima(xCarro6, yCarro6);

	glColor3f(0.4, 1, 0.2);
	desenhaCarrosCima(xCarro7, yCarro7);

	glColor3f(1, 0.2, 0.1);
	desenhaCarrosCima(xCarro8, yCarro8);

	glColor3f(0.3, 1, 0.8);
	desenhaCarrosCima(xCarro8, yCarro8);

	glColor3f(1, 0, 0.2);
	desenhaCarrosCima(xCarro9, yCarro9);

	glColor3f(0.2, 0.9, 0.6);
	desenhaCarrosCima(xCarro10, yCarro10);

	glColor3f(1, 1, 0);
	//galinha CABEÇA
	float ang;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		ang = (2 * 3.1415 * i) / 200;
		glVertex2f(cos(ang) * galinhaRaio + galinhaX+galinhaLargura, sin(ang) * galinhaRaio + galinhaY+galinhaAltura);
	}
	glEnd();

	//corpo
	glBegin(GL_QUADS);
	glVertex2d(galinhaX,galinhaY);
	glVertex2d(galinhaX, galinhaY + galinhaAltura);
	glVertex2d(galinhaX + galinhaLargura, galinhaY + galinhaAltura);
	glVertex2d(galinhaX + galinhaLargura, galinhaY);
	glEnd();

	//rabo
	glDisable(GL_LINE_STIPPLE);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2d(galinhaX, galinhaY);
	glVertex2d(galinhaX - 10, galinhaY - 2);
	glEnd();

	//pata
	glBegin(GL_LINES);
	glVertex2d(galinhaX+galinhaLargura/2, galinhaY);
	glVertex2d(galinhaX, galinhaY - 5);
	glEnd();

	//pata
	glBegin(GL_LINES);
	glVertex2d(galinhaX + galinhaLargura / 2, galinhaY);
	glVertex2d(galinhaX + galinhaLargura, galinhaY - 5);
	glEnd();

	//bico
	glBegin(GL_LINES);
	glVertex2d(galinhaX + galinhaLargura, galinhaY+galinhaAltura);
	glVertex2d(galinhaX + galinhaLargura+10, galinhaY + galinhaAltura);
	glEnd();

}

void desenhaCarro(int xCarro, int yCarro) {
	glBegin(GL_QUADS);
	glVertex2f(xCarro, yCarro);
	glVertex2f(xCarro, yCarro + carroAltura);
	glVertex2f(xCarro + carroLargura, yCarro + carroAltura);
	glVertex2f(xCarro + carroLargura, yCarro);
	glEnd();

	glColor3f(0, 0, 0);
	//RODAS
	glBegin(GL_QUADS);
	glVertex2f(xCarro + 5, yCarro + carroAltura);
	glVertex2f(xCarro + 5, yCarro + carroAltura + 3);
	glVertex2f(xCarro + 15, yCarro + carroAltura + 3);
	glVertex2f(xCarro + 15, yCarro + carroAltura);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro + carroLargura - 20, yCarro + carroAltura);
	glVertex2f(xCarro + carroLargura - 20, yCarro + carroAltura + 3);
	glVertex2f(xCarro + carroLargura - 10, yCarro + carroAltura + 3);
	glVertex2f(xCarro + carroLargura - 10, yCarro + carroAltura);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro + 5, yCarro);
	glVertex2f(xCarro + 5, yCarro - 3);
	glVertex2f(xCarro + 15, yCarro - 3);
	glVertex2f(xCarro + 15, yCarro);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro + carroLargura - 20, yCarro);
	glVertex2f(xCarro + carroLargura - 20, yCarro - 3);
	glVertex2f(xCarro + carroLargura - 10, yCarro - 3);
	glVertex2f(xCarro + carroLargura - 10, yCarro);
	glEnd();

	//parachoque fronteiro e traseiro
	glBegin(GL_QUADS);
	glVertex2f(xCarro + carroLargura, yCarro+5);
	glVertex2f(xCarro + carroLargura +3, yCarro+5);
	glVertex2f(xCarro + carroLargura +3, yCarro+carroAltura - 5);
	glVertex2f(xCarro + carroLargura, yCarro + carroAltura - 5);
	glEnd();
}

void desenhaCarrosCima(int xCarro, int yCarro) {
	glBegin(GL_QUADS);
	glVertex2f(xCarro, yCarro);
	glVertex2f(xCarro, yCarro + carroAltura);
	glVertex2f(xCarro - carroLargura, yCarro + carroAltura);
	glVertex2f(xCarro - carroLargura, yCarro);
	glEnd();

	glColor3f(0, 0, 0);
	//RODAS
	glBegin(GL_QUADS);
	glVertex2f(xCarro - 5, yCarro + carroAltura);
	glVertex2f(xCarro - 5, yCarro + carroAltura + 3);
	glVertex2f(xCarro - 15, yCarro + carroAltura + 3);
	glVertex2f(xCarro - 15, yCarro + carroAltura);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro - carroLargura + 20, yCarro + carroAltura);
	glVertex2f(xCarro - carroLargura + 20, yCarro + carroAltura + 3);
	glVertex2f(xCarro - carroLargura + 10, yCarro + carroAltura + 3);
	glVertex2f(xCarro - carroLargura + 10, yCarro + carroAltura);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro - 5, yCarro);
	glVertex2f(xCarro - 5, yCarro - 3);
	glVertex2f(xCarro - 15, yCarro - 3);
	glVertex2f(xCarro - 15, yCarro);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(xCarro - carroLargura + 20, yCarro);
	glVertex2f(xCarro - carroLargura + 20, yCarro - 3);
	glVertex2f(xCarro - carroLargura + 10, yCarro - 3);
	glVertex2f(xCarro - carroLargura + 10, yCarro);
	glEnd();

	//parachoque fronteiro e traseiro
	glBegin(GL_QUADS);
	glVertex2f(xCarro - carroLargura, yCarro + 5);
	glVertex2f(xCarro - carroLargura - 3, yCarro + 5);
	glVertex2f(xCarro - carroLargura - 3, yCarro + carroAltura - 5);
	glVertex2f(xCarro - carroLargura, yCarro + carroAltura - 5);
	glEnd();
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

	glClearColor(0.63, 0.63, 0.63, 1);
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