#include <GL/glut.h>
#include <stdio.h>


void MANGA(){
	
	glClearColor(0,0,0,1);        //limpeza da janela 
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,50.0,0.0,50.0);

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); //limpa

	glCOLOR3d(1,0,0);
	
	for(int i=0; i<10; i++){
		glPopMatrix();

		glBegin(GL_QUADS); 
			glVertex2D(0,0);
			glVertex2D(20,0);
			glVertex2D(20,20);
			glVertex2D(0,20);
		glEnd();

		glPushMatrix();	
        }
	glFlush();
		

} 


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("GIOVANNI BRUNO");

	glutDisplayFunc(MANGA);
	glutMainloop();

}
