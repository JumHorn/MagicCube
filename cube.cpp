#include"cube.h"
#include<opengl/glu.h>

Cube::Cube()
{}

Cube::~Cube()
{}

void Cube::initializeGL()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
}

void Cube::resizeGL(int width,int height)
{}

void Cube::paintGL()
{}

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

