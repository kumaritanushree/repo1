#include <unistd.h>
#include <stdio.h>
#include <opengl.h>
#include <vector>
#define PI 3.141592
#define L 3
#define R 2
#define B 1
#define T 0
typedef struct Point Point;
struct Point
{
	float x;
	float y;
};

int logical(int p1code[], int p2code[])
{
	int i,sum = 0;
	for(i=0; i<4; i++)
		sum = sum + (p1code[i] + p2code[i])/2;
	return sum;
}


void visible(int p1code[], int p2code[], int sum1, int sum2,int *vflag)
{
	int inter;
	*vflag = 0;
	if(sum1 == sum2 && sum1 ==0 )
		*vflag = 1;
	else
	{
		inter = logical(p1code, p2code);
		if(inter != 0)
			*vflag = -1;
	}
}

void endpoint(Point p, int w[], int pcode[])
{
	if( p.x < w[0]) 
		pcode[L] = 1;
	else pcode[L] = 0;

	if( p.x > w[1])
		pcode[R] = 1;
	else
		pcode[R] = 0;
	
	if( p.y < w[2] )
		pcode[B] = 1;
	else
		pcode[B] = 0;
	
	if( p.y > w[3] )
		pcode[T] = 1;
	else
		pcode[T] = 0;

}

int sum(int pcode[] )
{
	int i, sum = 0;
	for( i = 0; i < 4; i++)
		sum = sum + pcode[i];
	return sum;
}


void myInit(void)
{
glClearColor(0.0,0.0,0.0,0.0);

glLineWidth(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-640, 1640, -480, 1480);
}

void swap(int p1code[], int p2code[])
{
	int i, temp;
	for( i = 0; i< 4; i++)
	{
		temp = p1code[i];
		p1code[i] = p2code[i];
		p2code[i] = temp;
	}
}
void myDisplay(void)
{
	int window[4]={0,1023, 0, 1023};
	int p1code[4], p2code[4],sum1, sum2,vflag,iflag=1, tempsum, i;
	Point p1={-250, 31}, p2={1220, 136},temp;
	float slope;
	
	char nums[5][7]={"-640", "1640", "(0,0)","-480","1480"};
	glColor3f(01.0f, 01.0f, 01.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
		glVertex2i(-640,0);
		glVertex2i(1640,0);
		glVertex2i(0,-480);
		glVertex2i(0,1480);
	glEnd();

	RenderString(-620, -40,nums[0] );
	RenderString(1540, -40, nums[1]);
	RenderString(0, -40, nums[2]);
	RenderString(25, -476, nums[3]);	
	RenderString(25, 1420, nums[4]);	
	glFlush();

	
	
	glColor3f(0,1,0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
		glVertex2i(window[L], window[B]);
		glVertex2i(window[L], window[T]);
		glVertex2i(window[R], window[T]);
		glVertex2i(window[R], window[B]);
	glEnd();
	glFlush();
	printf("enter p1 coordinates\n");
	scanf("%f%f", &(p1.x), &(p1.y));
	printf("enter p2 coordinates\n");
	scanf("%f%f", &(p2.x), &(p2.y));
	
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
	glEnd();
	glFlush();

	endpoint(p1, window, p1code);
	endpoint(p2, window, p2code);
	sum1 = sum(p1code);
	sum2 = sum(p2code);
	visible(p1code, p2code, sum1, sum2, &vflag);
	printf("sum1 = %d, sum2 = %d, vflag = %d\n", sum1, sum2, vflag);
	printf("p1code = %d%d%d%d, p2code = %d%d%d%d\n",p1code[0],p1code[1],p1code[2],p1code[3],p2code[0],p2code[1],p2code[2],p2code[3]);
	if( vflag == 1)
	{
		glColor3f(1,0,1);
		glBegin(GL_LINES);
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
		glEnd();
		glFlush();	
		
	}
	
	else if(vflag == -1)
	{
		// do nothing
	}
	
	else
	{
	if(p1.x == p2.x)
		iflag = -1;
	else if (p1.y == p2.y)
		iflag = 0;
	else
		slope = (p2.y - p1.y) / (p2.x - p1.x);
		printf("slope = %f\n", slope);

	while( vflag == 0 )
	{
		printf("p1 = %f, %f\t p2 = %f, %f\n", p1.x, p1.y, p2.x, p2.y);
		for(i = 1; i<= 4; i++)
		{
			if( p1code[4-i] != p2code[4-i] )	
			{
				if( p1code[4-i] == 0 )
				{
					temp = p1;
					p1 = p2;
					p2 = temp;
					swap(p1code, p2code);
					tempsum = sum1;
					sum1 = sum2;
					sum2 = tempsum;
				}
					printf("p1code = %d%d%d%d, p2code = %d%d%d%d\n",p1code[0],p1code[1],p1code[2],p1code[3],p2code[0],p2code[1],p2code[2],p2code[3]);

		printf("p1 = %f, %f\t p2 = %f, %f, iflag = %d\n", p1.x, p1.y, p2.x, p2.y, iflag);
				if( iflag != -1 && i<=2 )
				{
					p1.y = slope*( window[i-1] - p1.x ) + p1.y;
					p1.x = window[i-1];
					printf("window[%d] = %d, p1 -> %f, %f\n",i,window[i-1], p1.x, p1.y);
					endpoint( p1, window, p1code );
					sum1 = sum( p1code );
				}

				if( iflag != 0 && i > 2 )
				{
					if( iflag != -1 )
					{
						p1.x = (1/slope) * (window[i-1] - p1.y) + p1.x;
					}
					p1.y = window[i-1];
					endpoint(p1, window, p1code);
					sum1 = sum(p1code);
				}

				visible( p1code, p2code, sum1, sum2, &vflag);
				if( vflag == 1 )
				{
					glColor3f(1,0,1);
					glBegin(GL_LINES);
						glVertex2f(p1.x, p1.y);
						glVertex2f(p2.x, p2.y);
					glEnd();
					glFlush();	
					//draw line
				}

				else if (vflag == -1)
				{
					// exit 
				}
			}
		}
	}
	}
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(720,120);
glutCreateWindow("sutherland line clipping");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();

}
