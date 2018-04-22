#include <unistd.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592
typedef struct point point;
struct point
{
	int x, y;
};

void myInit(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.5f, 0.6f, 0.60f);
glLineWidth(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-600.0, 600.0, -600.0, 600.0);
}

int random(int x)
{
	return rand()%3;
}
void myDisplay(void)
{
	point p[3]={
			{-600,-310},
			{600,30},
			{300,600}
		};
	point p2;
	int a,index;
	index = random(3);
	p2=p[index];
	glBegin(GL_POINTS);;
	for(a=0;a<80000;a++)
	{
		glVertex2i(p2.x, p2.y);
		index = random(3);
		p2.x = (p2.x + p[index].x)/2;
		p2.y = (p2.y + p[index].y)/2;

	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(600,600);
glutInitWindowPosition(120,120);
glutCreateWindow("My First attempt");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();

}
