// Bresenham

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>


void func(){
	glClearColor(1,1,1,1);			
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1,0,1);
	glTranslated(30,20,0);
	for(int i=0; i<100;i++){

		glPopMatrix();	
		
		glRotated(5,0,0,1);	
		glBegin(GL_QUADS);

			glVertex2d(0,0);
			glColor3d(10,0,0);
			glVertex2d(10,0);
			glColor3d(0,1,0);
			glVertex2d(10,10);	
			glVertex2d(0,10);		

		glEnd();
		glPushMatrix();	
	}
	glFlush();

}

int main(int argc, char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Kaio Moura ");

	glutDisplayFunc(func);
	glutMainLoop();

}
