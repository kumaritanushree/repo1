#include <opengl.h>
#include <stdio.h>

#define MAX 12
	


typedef struct vector vector;
struct vector
{
	float x;
	float y;
};

typedef vector point;







float max( float x, float y)
{
	return x>y?x:y;
}

float min(float x, float y)
{
	return x<y?x:y;
}
float dotProduct(vector v1, vector v2)
{
	return  v1.x * v2.x + v1.y * v2.y;
}



void myInit(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.5f, 0.6f, 0.60f);
glLineWidth(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-6, 6, -6, 6);
}

void myDisplay()
{
	int i,j,N;
	float dotw, dotd;
	vector d,w;
	vector edge, edge2;
	float t, tl=0, tu=1;
	
	point f, p1={-1,1}, p2={3,3};
float window[MAX][2];

	d.x = p2.x - p1.x;
	d.y = p2.y - p1.y;
	char nums[5][7]={"-6", "6", "(0,0)","-6","6"};
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5f, 0.6f, 0.60f);
	glBegin(GL_LINES);
		glVertex2f(-6,0);
		glVertex2f(6,0);
		glVertex2f(0,-6);
		glVertex2f(0,6);
	glEnd();

	RenderString(-6, -0.25,nums[0] );
	RenderString(5.6, -0.25, nums[1]);
	RenderString(0, -0.25, nums[2]);
	RenderString(0.25, -5.8, nums[3]);	
	RenderString(0.25, 5.8, nums[4]);	
	glFlush();
	
	
	printf("Enter number of vertices of clipping window\n");
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		printf("v%d ",i+1);
		scanf("%f%f",&window[i][0], &window[i][1]);
	}
	
	vector normal_list[N];
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	for(i = 0; i< N; i++)
		glVertex2f(window[i][0], window[i][1]);
		
	glEnd();
	glFlush();
	printf("enter p1 ");
	scanf("%f%f", &(p1.x), &(p1.y));
	printf("enter p2 ");
	scanf("%f%f", &(p2.x), &(p2.y));
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
	glEnd();
	glFlush();
	printf("d = %.0f, %.0f\n", d.x, d.y);	
	
	for(i=0; i<N; i++)
	{
	
		edge.x = window[ (i+1)%N ][0] - window[i][0];
		edge.y = window[ (i+1)%N ][1] - window[i][1];
		normal_list[i].x = - edge.y;
		normal_list[i].y = edge.x;
		edge2.x = window[ (i+2)%N ][0] - window[i][0];
		edge2.y = window[ (i+2)%N ][1] - window[i][1];
		//printf("v%dv%d:    %.0f %.0f n = %.0f,%.0f  dot = %.0f	",i+1, (i+3), edge2.x, edge2.y,normal_list[i].x, normal_list[i].y, dotProduct(normal_list[i], edge2) );
		if(dotProduct(normal_list[i], edge2) < 0)
		{
			normal_list[i].x = - normal_list[i].x;
			normal_list[i].y = - normal_list[i].y;
		}
	
		
		/*if(i == 0 || i ==7)
			j = 0;
		else if(i%2 == 1)
			j=i+1;*/
		
		f.x = window[i][0];
		f.y = window[i][1];
	
		w.x = p1.x - f.x;
		w.y = p1.y - f.y;
		dotd = dotProduct(d, normal_list[i]);
		dotw = dotProduct(w,normal_list[i]);
	
		if(dotd != 0)
		{
			t = -dotw/(float)dotd;
		//	printf("t = %.0f / %.0f \n", -dotw, dotd);
			if( dotd > 0)
				if( t > 1)
					return;
				else
					tl = max(t,tl);
			else
				if( t < 0)
					return;
				else
					tu = min(t, tu);
		}

		else
		{
			if( dotw < 0)
				return;
		}
		
		printf("normal:  %.0f,%.0f  f:  %.0f,%.0f\tw:  %.0f,%.0f\tdotw:  %.0f   dotd:  %.0f  tl:  %.2f  tu:  %.3f\n", normal_list[i].x, normal_list[i].y, f.x, f.y, w.x, w.y, dotw, dotd, tl, tu);
	}
	
	for(i = 0; i< N; i++)
		printf("net normals = %.0f,%.0f\t\n", normal_list[i].x, normal_list[i].y ); 
point p11,p22;



printf("tu : %.3f, tl : %.3f\n", tu, tl);
p11.x = p1.x + d.x * tl;
p11.y = p1.y + d.y *tl;

p22.x = p1.x + d.x * tu;
p22.y = p1.y + d.y *tu;
glColor3f(0,1,0);
glBegin(GL_LINES);
	glVertex2f(p11.x, p11.y);
	glVertex2f(p22.x, p22.y);
glEnd();
glFlush();
//printf("%.0f %.0f\t %.0f %.0f\n", p1.x, p1.y, p2.x, p2.y);

}




int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(600,600);
glutInitWindowPosition(720,120);
glutCreateWindow("Cyrus_Beck..||");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();


}
