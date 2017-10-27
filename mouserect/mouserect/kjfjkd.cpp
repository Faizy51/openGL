#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<conio.h>
using namespace std;
char fz[6]={"faizy"};
void draw_square(int x,int y)
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glRotatef(1,0,0,0);
	glTranslatef(1,1,0);
	
	glRasterPos2f(x+10,y+10);
	for(int i=0;i<6;i++)
		//glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,fz[i]);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,fz[i]);
	/*glBegin(GL_QUADS);
	glVertex2i(x+10,y+10);
	glVertex2i(x-10,y+10);
	glVertex2i(x-10,y-10);
	glVertex2i(x+10,y-10);
	glEnd();*/
	Sleep(20);
	glutPostRedisplay();
	glFlush();
	
}
void myMouse(int button,int state,int x,int y)
{
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		exit(0);
	else //if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		while(button!=GLUT_RIGHT_BUTTON) draw_square(x,y);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor3f(1,0,1);
	
}
void main(int argc,char *argv[])
{
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
		//glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(700,700);
        glutCreateWindow("Mouse program");
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,700,0,700,-1000,1000);
		//gluOrtho2D(0,700,0,700);
		glEnable(GL_DEPTH_TEST);
		glutMouseFunc(myMouse);
        glutDisplayFunc(display);
        glutMainLoop();
}