#include<iostream>
#include<GL/glut.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
GLfloat vertices[4][3]={{0,0,0},{250,500,0},{250,200,100},{500,0,0}};

void display()
{		int m=1;
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1,1,1,1);
		glColor3f(1,0,0);
		divide_triangle(vertices[0],vertices[1],vertices[2],m);
        
        glFlush();
}
void triangle()
{
		glBegin(GL_TRIANGLES);
        glVertex2fv(a);
        glVertex2fv(b);
		glVertex2fv(c);
		glEnd();
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