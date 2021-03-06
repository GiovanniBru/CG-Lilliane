//Giovanni Bruno Travassos de Carvalho- 11506849
// Equacao da Reta

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define Xi 3.0
#define Yi 3.0
#define Xf 9.0
#define Yf 7.0


void func(){
	float m;	
	float X[99] , Y[99];
		
	m=(Yf-Yi)/(Xf-Xi);

	X[0]=Xi+1;
	Y[0]=m*(X[0] - Xi) + Yi;
	
	for(int i=1;i<(Xf-Xi);i++){
		X[i] = X[i-1] + 1;	
		Y[i] = m*(X[i] - Xi) + Yi;
	}

	glClearColor(0,0,0,1);			
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1,1,1);
	glBegin(GL_LINE_LOOP);

		glVertex2d(Xi,Yi);
		glVertex2d(X[0],Y[0]);
		glVertex2d(X[1],Y[1]);
		glVertex2d(X[2],Y[2]);
		glVertex2d(X[3],Y[3]);	
		glVertex2d(X[4],Y[4]);		
		glVertex2d(Xf,Yf);		

	glEnd();

	glFlush();

}

int main(int argc, char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("EQUACAO DA RETA");

	glutDisplayFunc(func);
	glutMainLoop();

}
