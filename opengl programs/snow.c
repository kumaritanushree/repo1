#include "opengl.h"
#include <unistd.h>

#include <stdio.h>

void myInit (void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void koch(int x1, int y1, int x2, int y2, int it)
{
 float angle = 60*M_PI/180;
 int x3 = (2*x1+x2)/3;
 int y3 = (2*y1+y2)/3;

 int x4 = (x1+2*x2)/3;
 int y4 = (y1+2*y2)/3;

 int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
 int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);


 if(it > 0)
 {
  koch(x1, y1, x3, y3, it-1);
  koch(x3, y3, x, y, it-1);
  koch(x, y, x4, y4, it-1);
  koch(x4, y4, x2, y2, it-1);
 }
 else
 {

	glBegin(GL_LINE_STRIP);
	glColor3f(1,0,1);
		glVertex2i(x1, y1);
		glVertex2i(x3, y3);
		glVertex2i(x, y);
		glVertex2i(x4, y4);
		glVertex2i(x2, y2);
		
	glEnd();
	glFlush();

  
 }
}

void myDisplay(void)
{

	int x1,y1,x2,y2,x3,y3,it;
	
	char nums[5][7]={"-640", "640", "(0,0)","-480","480"};
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
		glVertex2i(-640,0);
		glVertex2i(640,0);
		glVertex2i(0,-480);
		glVertex2i(0,480);
	glEnd();

	RenderString(-640, -25,nums[0] );
	RenderString(580, -25, nums[1]);
	RenderString(0, -25, nums[2]);
	RenderString(25, -476, nums[3]);	
	RenderString(25, 460, nums[4]);	
	glFlush();

	printf("enter three co-ordinates\n");
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("enter number of iteration\n");
	scanf("%d",&it);
	koch(x1 ,y1 , x2, y2, it);
	koch(x2 ,y2 , x3, y3, it);
	koch(x3 ,y3 , x1, y1, it);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(720, 120);
	glutCreateWindow("My window....");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
