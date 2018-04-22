#include <stdio.h>
#include <opengl.h>
#include <math.h>
#define PI 3.141592


void myInit(void)
{

	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-640,640,-480,480);
}

void myDisplay()
{
float xp,yp, x, y, delcos, delsin,a ,b, cx, cy;

int i;

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

	printf("enter mazor axis length and minor axis length\n");
	scanf("%f%f",&a, &b);
	
	printf("enter center\n");
	scanf("%f%f",&cx, &cy);
	x= a*cos(0);
	y = b *sin(0);
	delcos= cos((2*PI)/1440);
	delsin = sin((2*PI)/1440);

	glColor3f(1,0,1);	
	glBegin(GL_POINTS);

	for(i=0; i<=1440; i++)
	{
		xp = x;
		yp = y;
		x = xp*delcos - (a/b)*yp*delsin;
		y = (b/a)*xp*delsin + yp*delcos;
		glVertex2f(cx+x, cy+y);
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
	glutCreateWindow("Ellipse _polygon....!!!!!");
	myInit();
	glutDisplayFunc(myDisplay);
	
	
	glutMainLoop();

}
