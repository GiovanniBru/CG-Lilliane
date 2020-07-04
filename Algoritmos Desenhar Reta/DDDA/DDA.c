// DDA

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define Xi 3.0
#define Yi 3.0
#define Xf 9.0
#define Yf 7.0


void func(){
	float m;	
	float X[99] , Y[99];
		
	m=(Yf-Yi)/(Xf-Xi);

	X[0]=Xi + 1;
	Y[0]=Yi + m;
	
	for(int i=1;i<(Xf-Xi);i++){
		X[i] = X[i-1] + 1;	
		Y[i] = Y[i-1] + m;
	}

	glClearColor(1,1,1,1);			
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glBegin(GL_QUADS);
		glColor3d(0,0,0);
		glVertex2d(0,0);
		glVertex2d(16,0);
		glVertex2d(16,11);
		glVertex2d(0,11);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3d(1,0,0);
		glVertex2d(0,11);
		glVertex2d(16,11);
		glVertex2d(8, 15);
	glEnd();

	glBegin(GL_QUADS);
		glColor3d(0,0,1);
		glVertex2d(1,0);
		glVertex2d(3,0);
		glVertex2d(3,4);
		glVertex2d(1,4);
	
	glEnd();

	glBegin(GL_QUADS);
		glColor3d(0,1,0);
		glVertex2d(10,4);
		glVertex2d(10,7);
		glVertex2d(13,7);
		glVertex2d(13,4);

	glEnd();

	glFlush();

}

int main(int argc, char **argv){
	
	 clock_t t;

	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("DDA");

	glutDisplayFunc(func);
	glutMainLoop();

	t = clock();
	//t = clock() - t;
	printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

}
