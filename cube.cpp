#include"cube.h"
#include"GLUT/glut.h"

Cube::Cube()
{}

Cube::~Cube()
{}

void Cube::initializeGL()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glColor3f(1.0f,0.0f,0.0f);
}

void Cube::resizeGL(int width,int height)
{
	if(height==0)
		height=1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,width,height);
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Cube::paintGL()
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 0.0f, 10.0f,
			0.0f, 0.0f,  0.0f,
			0.0f, 1.0f,  0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f, 0.0f);
		glVertex3f( 2.0f, 0.0f, 0.0);
		glVertex3f( 0.0f, 2.0f, 0.0);
	glEnd();
	glutSwapBuffers();
}

//global varible
Cube c;


//called to draw sence
void RenderSence(void)
{
	c.paintGL();
}

//set up the rendering state
void SetupRC(void)
{
	c.initializeGL();
}

//called by GLUT library when the window has change size
void ChangeSize(GLsizei w,GLsizei h)
{
	c.resizeGL(w,h);
}

