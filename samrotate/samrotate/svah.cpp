#include<windows.h>
#include<wingdi.h>
#include<GL/glut.h>
GLfloat x[6]={50,100,150,200,250,300};
GLfloat y[6]={50,100,150,200,250,300};
int r=1;
void display()
{
	GLint i,j;
	glClear(/*GL_COLOR_BUFFER_BIT|*/GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor3f(1,0,0);
	glRotatef(r,1,1,0);
	glTranslatef(1,1,1);
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i],y[j]);
			glVertex2f(x[i+1],y[j]);
			glVertex2f(x[i+1],y[j+1]);
			glVertex2f(x[i],y[j+1]);
			glEnd();
		}
	}
	r+=0.5;
	glutPostRedisplay();
	Sleep(10);
	glutSwapBuffers();
	glFlush();
}
void main(int argc,char *argv[])
{
        glutInit(&argc,argv);
        //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
		glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(700,700);
        glutCreateWindow("Mesh program");
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,700,0,700,-1000,1000);
		//gluOrtho2D(0,700,0,700);
		glEnable(GL_DEPTH_TEST);
        glutDisplayFunc(display);
        glutMainLoop();
}