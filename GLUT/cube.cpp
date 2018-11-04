#include"cube.h"
#include"GLUT/glut.h"

Cube::Cube():xrotate(0.0f),yrotate(0.0f),zrotate(0.0f)
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
	glRotatef(xrotate,1.0f,0.0f,0.0f);
	glRotatef(yrotate,0.0f,1.0f,0.0f);
	glRotatef(zrotate,0.0f,0.0f,1.0f);

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

void Cube::timerEvent()
{
	xrotate+=0.5;
	yrotate+=0.5;
	zrotate+=0.5;
	paintGL();
}

void Cube::mouseMoveEvent(int x,int y)
{
	if(mousestate!=GLUT_DOWN)
	{
		xmouse=x;
		ymouse=y;
	}
	int dx=xmouse-x;
	int dy=ymouse-y;
	xrotate+=dy*0.01;
	yrotate+=dx*0.01;
	paintGL();
}

void Cube::mousePressEvent(int button,int state,int x,int y)
{
	xmouse=x;
	ymouse=y;
	mousestate=state;
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

void timerFun(int value)
{
	c.timerEvent();
	glutTimerFunc(50,timerFun,0);
}

void mouseMove(int x,int y)
{
	c.mouseMoveEvent(x,y);
}

void mousePress(int button,int state,int x,int y)
{
	c.mousePressEvent(button,state,x,y);
}
