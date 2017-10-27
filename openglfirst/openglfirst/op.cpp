#include<iostream>
#include<GL/glut.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1,1,1,1);
		glColor3f(1,0,0);
        glBegin(GL_TRIANGLES);
        glVertex2i(0,0);
        glVertex2i(100,100);
		glVertex2i(100,0);
		glEnd();
        glFlush();
}

void main(int argc,char *argv[])
{
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(500,500);
        glutCreateWindow("Sample program");
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,500,0,500);
        glutDisplayFunc(display);
        glutMainLoop();
        getch();
}