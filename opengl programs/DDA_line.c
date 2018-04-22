#include <stdio.h>
#include "opengl.h"

void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.5f, 0.6f, 0.7f);
	glpointsize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640.0, -480.0, 480.0);
}




void myDisplay(void)
{
	int i,x1, y1, x2, y2, len;
	float x, y, dx, dy;
	
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();

	printf("enter x1 and y1\n");
	scanf("%d%d", &x1, &y1);
	printf("enter x2 and y2\n");
	scanf("%d%d", &x2, &y2);


	

	glColor3f(0,1,0);
	if( abs(x2 - x1) >= abs(y2 - y1))
		len = abs(x2 - x1);
	else
		len = abs(y2 - y1);
	
	dx = (x2 - x1) / (float)len;
	dy = (y2 - y1) / (float)len;

	x = x1 + 0.5;
	y = y1 + 0.5;

	i = 1;
	glBegin( GL_POINTS );

	while( i <= len )
	{
		glVertex2i( (int)x, (int)y );

		x = x + dx;
		y = y + dy;
		i++;
	}
	glEnd();
	
	
	glFlush();




		
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(720,120);
	glutCreateWindow("DDA line drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}
