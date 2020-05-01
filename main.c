#include "ogl64.h"
void main()
{
	void * zbuffer, scratch;
	int scratch_length;
	glInit(zbuffer, scratch, scratch_length);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);                        
	glEnable(GL_DEPTH_TEST);                        
	glDepthFunc(GL_LEQUAL);  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f); 
	glBegin(GL_TRIANGLES);	// Drawing Using Triangles
		glColor3f(1.0f,0.0f,0.0f); 
		glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
		glColor3f(0.0f,0.0f,1.0f); 
		glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
	glEnd();
	glTranslatef(3.0f,0.0f,0.0f); 
	glColor3f(0.5f,0.5f,1.0f);              // Set The Color To Blue One Time Only
    glBegin(GL_QUADS);                  // Start Drawing Quads
        glVertex3f(-1.0f, 1.0f, 0.0f);          // Left And Up 1 Unit (Top Left)
        glVertex3f( 1.0f, 1.0f, 0.0f);          // Right And Up 1 Unit (Top Right)
        glVertex3f( 1.0f,-1.0f, 0.0f);          // Right And Down One Unit (Bottom Right)
        glVertex3f(-1.0f,-1.0f, 0.0f);          // Left And Down One Unit (Bottom Left)
    glEnd();                        // Done Drawing A Quad
	return 0;
}