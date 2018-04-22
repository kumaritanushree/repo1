#include <unistd.h>
#include <stdio.h>
#include "opengl.h"
#include <vector>
//#include <stdlib.h>


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
gluOrtho2D(-640,640,-480,480);
}



void myDisplay(void)
{
	int i, centerx, centery,size, r,x,y, cx, cy;
	float p;
	point pt;
	std::vector<point> array;
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


	printf("enter center coordinates\n");
	scanf("%d%d",&cx, &cy);
	printf("enter radius\n");
	scanf("%d",&r);
	p=5/4.0 - r;
	x = r;
	y = 0;

	glColor3f(1,0,1);
	for(i = 0; y!=x; i++)
	{
		pt.x = x;
		pt.y = y;
		array.push_back(pt);
		glBegin(GL_POINTS);
			glVertex2i(cx+x, cy+y);
		glEnd();
		glFlush();
		usleep(12000);
		if( p < 0)
		{
			y++;
			p = p + 2*y + 1;
		}

		else
		{
			x--;
			p = p  - 2*x+1;
		}
	}


	usleep(300000);
	size = array.size();
	for( i =0; i<=size; i++)
	{
		pt.x = array[i].y;
		pt.y = array[i].x;
		glBegin(GL_POINTS);
			glVertex2i(cx+pt.x, cy+pt.y );
		glEnd();
		array.push_back(pt);
		
	}
	glFlush();
	usleep(300000);
	size = array.size();
	for( i =0; i<=size; i++)
	{
		pt.x = - array[i].x;
		pt.y = array[i].y;
		glBegin(GL_POINTS);
			glVertex2i(cx+pt.x, cy+pt.y );
		glEnd();
		array.push_back(pt);
		
	}
	glFlush();
	usleep(300000);
	size = array.size();
	for( i =0; i<=size; i++)
	{
		pt.x =  array[i].x;
		pt.y = - array[i].y;
		glBegin(GL_POINTS);
			glVertex2i(cx+pt.x, cy+pt.y );
		glEnd();
		array.push_back(pt);
		
	}
	glFlush();


}



int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(720,120);
	glutCreateWindow("Mid point circle");
	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();

}
