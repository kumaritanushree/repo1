#ifndef __OPENGL_H

	#define __OPENGL_H
	
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	#include <math.h>
	#include <string.h>
	#define PI 3.141592
	
/*function to render a string using OpenGL*/


	void RenderString(GLdouble x, GLdouble y, char *string)
	{
		int n;
    		glColor3f(1.0, 1.0, 1.0);
    		glRasterPos2d(x, y);
    		for (n=0; n<strlen(string); ++n) {
        		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[n]);
    		}
	}
	
#endif
