#include <stdio.h>
#include "opengl.h"

void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.5f, 0.6f, 0.60f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640, 640.0, -480.0, 480.0);
}


int sign (int x )
{
	if( x == 0)
		return 0;

	return (x / abs(x) );
}





void myDisplay(void)
{
	int e, temp, s1, s2, interchange,i,x1, y1, x2, y2, len;
	int x, y, dx, dy;


	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	printf("enter x1 and y1\n");
	scanf("%d%d", &x1, &y1);
	printf("enter x2 and y2\n");
	scanf("%d%d", &x2, &y2);

	

	
	glColor3f(1.0, 0.0, 0.0);
	x = x1;
	y = y1;
	dx = abs(x2 - x1 );
	dy = abs(y2 - y1);
	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);
	
	if( dy > dx )
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	else
		interchange = 0;

	e = 2 * dy - dx;

	glBegin( GL_POINTS );
	for(i = 1; i <= dx; i++)
	{
		glVertex2i( x, y );
		while( e > 0)
		{
			if( interchange == 1)
				x = x + s1;
			else
				y = y + s2;

			e = e - 2 * dx;
		}

		if( interchange == 1)
			y = y + s2;
			
		else
			x = x + s1;

		e = e + 2 * dy;
	}
	glVertex2i( x, y );

	glEnd();
	glFlush();
		
}




int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("bresenhem's line algorithm");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();

}
