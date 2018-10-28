#include"cube.h"
#include"GLUT/glut.h"

Cube::Cube()
{}

Cube::~Cube()
{}

void Cube::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Cube::resizeGL(int width,int height)
{
	if(height==0)
		height=1;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Cube::paintGL()
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-5.0f);

	glBegin(GL_QUADS);
		//near
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glVertex3f( -1.0f, 1.0f, 1.0f);
		glVertex3f( -1.0f, -1.0f, 1.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
		//far
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( -1.0f, -1.0f, -1.0f);
		glVertex3f( -1.0f, 1.0f, -1.0f);
		//top
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
		glVertex3f( -1.0f, 1.0f, -1.0f);
		glVertex3f( -1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		//down
		glColor3f(1.0f,1.0f,0.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
		glVertex3f( -1.0f, -1.0f, 1.0f);
		glVertex3f( -1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		//left
		glColor3f(1.0f,0.0f,1.0f);
		glVertex3f( -1.0f, 1.0f, 1.0f);
		glVertex3f( -1.0f, 1.0f, -1.0f);
		glVertex3f( -1.0f, -1.0f, -1.0f);
		glVertex3f( -1.0f, -1.0f, 1.0f);
		//right
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f( 1.0f, 1.0f, 1.0f);
		glVertex3f( 1.0f, -1.0f, 1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, 1.0f, -1.0f);
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

