#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "opengl.h"
#include "transform.h"




void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.5f, 0.6f, 0.60f);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	
	float v[][3]= {
			{50, 0, 1},
			{100, 0, 1},
			{75, 30, 1},
			{50, 60, 1},
			{100, 60, 1},
			{75, 30, 1}
		};

	float t[][3]={
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};
	int i,j;
	char nums[5][7]={"-640", "640", "(0,0)","-480","480"};

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex2i(-640,0);
		glVertex2i(640,0);
		glVertex2i(0,-480);
		glVertex2i(0,480);
	glEnd();

	RenderString(-640, -25,nums[0] );
	RenderString(600, -25, nums[1]);
	RenderString(0, -25, nums[2]);
	RenderString(25, -476, nums[3]);	
	RenderString(25, 460, nums[4]);	
	glFlush();

	
	glBegin(GL_TRIANGLES);
	for(i=0;i<6;i++)
	{
		glVertex2i((int)v[i][0], (int)v[i][1]);
	}
	glEnd();
	glFlush();

	translate(t,3,-75, -30);
	scale(t,3,2,2);
	translate(t,3,75,30);
	
	printf("press enter to continue\n");
	getchar();
	
	transform(v,6,t);


	glColor3f(1,0,0);
	
	glBegin(GL_TRIANGLES);
	for(i=0;i<6;i++)
	{
		glVertex2i( (int)v[i][0], (int)v[i][1] );
	}
	glEnd();
	glFlush();

	printf("press enter to continue\n");
	getchar();
	glColor3f(0,0,1);
	
	translate(v,6,-75, -30);
	rotate(v,6,90);
	translate(v,6,75,30);
	
	glBegin(GL_TRIANGLES);
	for(i=0; i<6; i++)
		glVertex2i( (int)v[i][0], (int)v[i][1] );
	glEnd();
	glFlush();
		
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(720,120);
	glutCreateWindow("Transformation...!!!");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}
