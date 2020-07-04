//Giovanni Bruno - 11506849
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h> 

int primeira = 1;
int DirEsq = 0;
int CimaBaixo = 0;

void ABACAXI(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0,100.0,-100.0,100.0, -100, 100);

    glMatrixMode(GL_MODELVIEW);

    if(primeira){
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glRotated(90, 1, 0, 0);
        primeira = 0;
    }

    if(CimaBaixo){
        glRotated(CimaBaixo, 0, 1, 0);
        CimaBaixo = 0;
    }

    glPushMatrix();
    glTranslated(80, 0, 0);
    glRotated(10, 0, 0, 1);
    // Terra
    glColor3d(0,1,1);
    glutWireSphere(5, 10, 10);
    glTranslated(-80, 0, 0);
    
    glPopMatrix();
    glRotated(DirEsq, 0, 0, 1);
    // Sol
    glColor3d(1,1,0);
    glutSolidSphere(18, 10, 10);

    glColor3d(1,0,1);
    glutSolidSphere(10, 10, 10);

    glFlush();
}

void moverSetas(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            DirEsq = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            DirEsq = -10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            CimaBaixo = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            CimaBaixo = -10;
            glutPostRedisplay();
            break;
    }
}

/*void moverZ(unsigned char z){
	switch(z){
		case 'L';	
	}
}*/

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_SINGLE);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Giovanni Bruno");
    glutDisplayFunc(ABACAXI);
    glutSpecialFunc(moverSetas);
    //glutKeyboardFunc(moverZ);
    glutMainLoop();
}
