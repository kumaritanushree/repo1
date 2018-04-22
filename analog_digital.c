#include <unistd.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#define PI 3.142092

typedef struct Point point;
struct Point
{
	int x, y;
};
void circle( int r );
void drawDigit(int x, int y, int scale, char i);

void RenderString(GLdouble x, GLdouble y, char *string)
{
	int n;
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2d(x, y);
    for (n=0; n<strlen(string); ++n) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[n]);
    }
}
void myInit(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.5f, 0.6f, 0.60f);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-100, 100, -100, 100);
}



void myDisplay()
{
	int i;
	float coss, sins,cosm, sinm, coshr, sinhr;
	char  times[10], n[12][3]={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
 	time_t T;
   	 struct  tm t ;
		glColor3f(1,1,1);
		circle(60);
		glColor3f(0.5, 0.5, 0.5);
		circle(58);
		glColor3f(0.5, 0.9, 0.2);
		for(i = 1; i<= 12; i++)
		{
			RenderString(50*sin( (i*30*PI)/180), 50*cos((i*30*PI)/180) , n[i-1]);
		}
     while(1)
     	{
     		T= time(NULL);
     		t = *localtime(&T);
		coss = cos((t.tm_sec * PI*6)/(float)180);
		sins = sin((t.tm_sec * PI*6)/(float)180);
		cosm = cos((t.tm_min * PI*6)/(float)180);
		sinm = sin((t.tm_min * PI*6)/(float)180);
		coshr = cos((((t.tm_hour%12)*30+ (t.tm_min/12)*6) *PI)/(float)180);
		sinhr = sin((((t.tm_hour%12)*30+ (t.tm_min/12)*6) *PI)/(float)180);

    		sprintf(times,"%02d:%02d:%02d",t.tm_hour, t.tm_min, t.tm_sec);
    		glLineWidth(1.0);
		for(i = 0; i< 8; i++)
    		{
			drawDigit(-20+6*i ,-70, 4, times[i]);
		}
		//glColor3f(1,0,0);
			glLineWidth(6.0);
			glColor3f(1,1,0);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(25 * sinhr, 25 * coshr);
		glEnd();
			glLineWidth(4.0);
			glColor3f(1,0,1);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(35 * sinm, 35 * cosm);
		glEnd();
			
		glLineWidth(2.0);
		glColor3f(0,0.5,0.5);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(40* sins,40*coss);
		glEnd();
	
		glFlush();	
		sleep(1);
		glColor3f(0,0,0);
		glLineWidth(2.0);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(40*sins, 40*coss);
		glEnd();
			glLineWidth(4.0);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(35 * sinm, 35 * cosm);
		glEnd();
			glLineWidth(6.0);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(25 * sinhr, 25 * coshr);
		glEnd();	
	
		 
		glFlush();
 	}
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



void drawDigit(int x, int y, int scale, char i)
{

	glLineWidth(2.0);

	glColor3f(0.12, 0,0);
	if(i != ':')
	{
	glBegin(GL_LINES);
		glVertex2i(x,y); //1
		glVertex2i(x+(scale), y);
		
			
		glVertex2i(x+(scale), y);//2
		glVertex2i(x+(scale), y-(scale));
		
		glVertex2i(x+(scale), y-(scale));//3
		glVertex2i(x+(scale), y-(scale*2));

		glVertex2i(x+(scale), y-(scale*2));//4
		glVertex2i(x, y-(scale*2));

		glVertex2i(x, y-(scale*2));//5
		glVertex2i(x, y-(scale));

		glVertex2i(x, y-(scale));//6
		glVertex2i(x+(scale), y-(scale));

		glVertex2i(x, y-(scale));//7
		glVertex2i(x,y);
	glEnd();
	}
	glColor3f(1,0,0);
	switch(i)
	{
		case '1':
	
			glBegin(GL_LINES);
				
				glVertex2i(x+(scale), y);
				glVertex2i(x+(scale), y-(scale));
				
				glVertex2i(x+(scale), y-(scale));
				glVertex2i(x+(scale), y-(scale*2));
			glEnd();
			break;

		case '2':
			glBegin(GL_LINES);
				glVertex2i(x,y);
				glVertex2i(x+(scale), y);
				
				
				glVertex2i(x+(scale), y);
				glVertex2i(x+(scale), y-(scale));
				
				glVertex2i(x+(scale), y-(scale*2));
				glVertex2i(x, y-(scale*2));

				glVertex2i(x, y-(scale*2));
				glVertex2i(x, y-(scale));

				glVertex2i(x, y-(scale));
				glVertex2i(x+(scale), y-(scale));

			glEnd();
			break;
		case '3':
			glBegin(GL_LINES);
				glVertex2i(x,y);
				glVertex2i(x+(scale), y);
				
				glVertex2i(x+(scale), y);
				glVertex2i(x+(scale), y-(scale));
				
				glVertex2i(x+(scale), y-(scale));
				glVertex2i(x+(scale), y-(scale*2));

				glVertex2i(x+(scale), y-(scale*2));
				glVertex2i(x, y-(scale*2));

				glVertex2i(x, y-(scale));
				glVertex2i(x+(scale), y-(scale));

			glEnd();
			break;
		
		case '4':
			glBegin(GL_LINES);
			
				glVertex2i(x+(scale), y);
				glVertex2i(x+(scale), y-(scale));
			
				glVertex2i(x+(scale), y-(scale));
				glVertex2i(x+(scale), y-(scale*2));
	
				glVertex2i(x, y-(scale));
				glVertex2i(x+(scale), y-(scale));
	
				glVertex2i(x, y-(scale));
				glVertex2i(x,y);
			glEnd();
			break;
		case '5':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
				
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));
		
				glVertex2i(x+(scale), y-(scale*2));//4
				glVertex2i(x, y-(scale*2));
		
				glVertex2i(x, y-(scale));//6
				glVertex2i(x+(scale), y-(scale));
		
				glVertex2i(x, y-(scale));//7
				glVertex2i(x,y);
			glEnd();
			break;
		
		case '6':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
			
			
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));

				glVertex2i(x+(scale), y-(scale*2));//4
				glVertex2i(x, y-(scale*2));
		
				glVertex2i(x, y-(scale*2));//5
				glVertex2i(x, y-(scale));
	
				glVertex2i(x, y-(scale));//6
				glVertex2i(x+(scale), y-(scale));
	
				glVertex2i(x, y-(scale));//7
				glVertex2i(x,y);
			glEnd();
			break;
			
		case '7':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
		
			
				glVertex2i(x+(scale), y);//2
				glVertex2i(x+(scale), y-(scale));
		
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));

			glEnd();
			break;
			
		case '8':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
		
				glVertex2i(x+(scale), y);//2
				glVertex2i(x+(scale), y-(scale));
		
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));

				glVertex2i(x+(scale), y-(scale*2));//4
				glVertex2i(x, y-(scale*2));

				glVertex2i(x, y-(scale*2));//5
				glVertex2i(x, y-(scale));

				glVertex2i(x, y-(scale));//6
				glVertex2i(x+(scale), y-(scale));

				glVertex2i(x, y-(scale));//7
				glVertex2i(x,y);
			glEnd();
			break;
			
		case '9':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
	
		
				glVertex2i(x+(scale), y);//2
				glVertex2i(x+(scale), y-(scale));
	
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));

				glVertex2i(x+(scale), y-(scale*2));//4
				glVertex2i(x, y-(scale*2));


				glVertex2i(x, y-(scale));//6
				glVertex2i(x+(scale), y-(scale));

				glVertex2i(x, y-(scale));//7
				glVertex2i(x,y);
			glEnd();
			break;
			
		case '0':
			glBegin(GL_LINES);
				glVertex2i(x,y); //1
				glVertex2i(x+(scale), y);
		
			
				glVertex2i(x+(scale), y);//2
				glVertex2i(x+(scale), y-(scale));
		
				glVertex2i(x+(scale), y-(scale));//3
				glVertex2i(x+(scale), y-(scale*2));

				glVertex2i(x+(scale), y-(scale*2));//4
				glVertex2i(x, y-(scale*2));

				glVertex2i(x, y-(scale*2));//5
				glVertex2i(x, y-(scale));


				glVertex2i(x, y-(scale));//7
				glVertex2i(x,y);
			glEnd();
			break;
		case ':':
			glBegin(GL_POINTS);
				glVertex2i(x+(scale/2), y-(scale/2));
				glVertex2i(x+(scale/2), y-(scale*1.5));
			glEnd();
			break;
	}

	glFlush();

}





void circle(int radius)
{
   glBegin(GL_LINE_LOOP);
 
   for (int i=0; i <= 360; i++)
   {
      float degInRad = (i*3.14)/180;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
   }
 
   glEnd();
}



