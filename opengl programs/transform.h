#ifndef __TRANSFORM_H

	#define  __TRANSFORM_H
	#define PI 3.141592
	void translate( float vertices[][3], int n, int a, int b)
	{

		float trans[][3] = {
				{1,0,0},
				{0,1,0},
				{a,b,1}
				};
	
		float x[3], sum=0;
		int i, j, k,  p;
		for( i=0; i < n; i++)
		{
			
			for( j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					sum = sum + vertices[i][k]* trans[k][j];
				}
				x[j] = sum;
				sum = 0;
				}
	
				for(p = 0; p < 3; p++)
				vertices[i][p] = x[p];
		}
	
	
	
	}
	
	
	void rotate( float vertices[][3], int n, int angle)
	{
	
		float trans[][3] = {
				{cos((angle*PI)/180),sin((angle*PI)/180),0},
				{-sin((angle*PI)/180),cos((angle*PI)/180),0},
				{0,0,1}
				};
	
		float sum=0, x[3];
		int i, j, k, p;
		for( i=0; i < n; i++)
		{
			
			for( j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					sum = sum + vertices[i][k]* trans[k][j];
				}
				x[j] = sum;
				sum = 0;
			}
	
			for(p = 0; p < 3; p++)
				vertices[i][p] = x[p];
		}
	
	
	
	}
	
	
	void scale( float vertices[][3], int n, int a,int b)
	{
	
		float trans[][3] = {
				{a,0,0},
					{0,b,0},
				{0,0,1}
				};
	
		float x[3], sum=0;
		int i, j, k,  p;
		for( i=0; i < n; i++)
		{
			
			for( j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					sum = sum + vertices[i][k]* trans[k][j];
				}
				x[j] = sum;
				sum = 0;
			}
	
			for(p = 0; p < 3; p++)
				vertices[i][p] = x[p];
		}
	
		
	
	}
	
	
	void transform(float vertices[][3],int n, float trans[3][3])
	{
	
		float  x[3], sum=0;
		int  i, j, k, p;
		for( i=0; i < n; i++)
		{
			
			for( j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					sum = sum + vertices[i][k]* trans[k][j];
				}
				x[j] = sum;
				sum = 0;
			}
	
			for(p = 0; p < 3; p++)
				vertices[i][p] = x[p];
		}
	
	
	
	}
				
	void reflect( float vertices[][3],int n, char c)
	{

		float trans[][3] = {
				{1,0,0},
				{0,1,0},
				{0,0,1}
				};
		
		float x[3], sum=0;
		int i, j, k,  p;
		
		if(c == 'y')
			trans[0][0]=-1;
		else if( c == 'x')
			trans[1][1] = -1;
		for( i=0; i < n; i++)
		{
			
			for( j = 0; j < 3; j++)
			{
				for(k = 0; k < 3; k++)
				{
					sum = sum + vertices[i][k]* trans[k][j];
				}
				x[j] = sum;
				sum = 0;
				}
	
				for(p = 0; p < 3; p++)
				vertices[i][p] = x[p];
		}
	
	
	
	}
	
	
#endif
