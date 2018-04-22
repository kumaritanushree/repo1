#include <unistd.h>
#include <stdio.h>
#include <opengl.h>
#include <math.h>
#include <vector>
#define PI 3.141592


typedef struct point point;

struct point
{
	int x, y;
};


void circle(int centerx, int centery, int r)
{
	
	glBegin(GL_POLYGON);
	for(int i=0; i<360; i++)
		
		glVertex2i(r*cos(i*PI/180)+centerx , r*sin(i*PI/180)+centery);
		
	glEnd();
	glFlush();

}

void myInit(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.5f, 0.6f, 0.60f);
glLineWidth(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	float x=0,y=0;
	int a=0;
	

	
	for(;;)
	{
	
		glColor3f(1,0,1);	
		glBegin(GL_LINE_LOOP);
		for(int i=0; i<360; i++)
		
			glVertex2i(350*cos(i*PI/180) , 200*sin(i*PI/180));
		
		glEnd();
		glFlush();
	
	
	
		if(a>360)
			a=0;
		
		
		x=350* cos((PI*a)/180);
		y=200* sin ((PI*a)/180);
		glColor3f(0,0,1);
		circle(x, y,50);
		usleep(19000);
		glColor3f(0,0,0);
		circle(x, y,50);
	glColor3f(1,0,1);	
		glBegin(GL_LINE_LOOP);
		for(int i=0; i<360; i++)
		
			glVertex2i(350*cos(i*PI/180) , 200*sin(i*PI/180));
		
		glEnd();
		glFlush();
		
		a++;

	}	
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(720,120);
glutCreateWindow("Ellipse......!!!!");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();

}
