#include <unistd.h>
#include <stdio.h>
#include <opengl.h>
#include <vector>

#include <iostream>

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
gluOrtho2D(-640, 640.0, -480.0, 480.0);
}


int sign (int x )
{
	if( x == 0)
		return 0;

	return (x / abs(x) );
}





void mh(int *x , int *y, float *d)
{
	(*y)++;
	(*d) = (*d)+2*(*y)+1;
}

void md(int *x, int *y, float *d)
{
	(*y)++;
	(*x)--;
	(*d) = (*d)+2*(*y)-2*(*x)+2;
}

void mv(int *x , int *y, float *d)
{
	(*x)--;
	(*d) = (*d)-2*(*x)+1;
}


void circle(int R,int cx, int cy)

{
	int x=0, y, limit;
	float d, d1,d2;
	struct point temp;
	std:: vector < point > arr;
	x = R;
	y = 0;
	d = 2*(1-R);
	limit = 0;

	
	
	while (x >= limit)
	{
		glBegin(GL_POINTS);
		glVertex2i(cx+x ,cy+ y);
		glEnd();
		glFlush();
		usleep(2000);
		if (d < 0)
		{
	
			d1 = 2*d+2*x-1;
			if(d1 <= 0)
				mh(&x , &y , &d);
			else
				md(&x,&y,&d);
		
		}
		else if	(d > 0)
		{
			d2 = 2*d -2*y-1;
			if (d2 <= 0)
				md(&x,&y,&d);
			else 
				mv(&x,&y,&d);
		
		}
		else
		{
			md(&x,&y,&d);
			
		}
	temp.x = x;
	temp.y = y;
	arr.push_back (temp);
	
	
	}
	int i;

	for (i =  arr.size(); i>0; i--)
	{
		glBegin(GL_POINTS);
		glVertex2i(cx-arr[i].x, cy+arr[i].y);
		glEnd();
		glFlush();
		usleep(2000);
		temp.x =-arr[i].x;
		temp.y = arr[i].y;
		arr.push_back(temp);
	}

	for (i = arr.size(); i>0; i--)
	{
		glBegin(GL_POINTS);
		glVertex2i(cx+arr[i].x,cy -arr[i].y);
		glEnd();
		glFlush();
		usleep(2000);
	}

		
	
}



void myDisplay(void)
{
	
	
	int r,xi, size,yi,di, limit,del,del1, center_x, center_y;
	point p;
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


	printf("enter radius\n");
	scanf("%d", &r);
	printf("enter center coordinates\n");
	scanf("%d%d", &center_x, &center_y);
	circle(r,center_x, center_y);

	
		
}







int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(720,120);
glutCreateWindow("Bresenhem's circle");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();

}
