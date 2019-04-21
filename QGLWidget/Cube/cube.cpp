#include "cube.h"

Cube::Cube(QWidget *parent)
	: QGLWidget(parent), xrotate(0.0f), yrotate(0.0f), zrotate(0.0f)
{
	startTimer(50);
}

Cube::~Cube()
{

}

void Cube::initializeGL()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	cubes = glGenLists(27);
	for (int i = 0; i < 27; i++)
	{
		glNewList(cubes + i, GL_COMPILE);
		glBegin(GL_QUADS);
		//near
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		//far
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		//top
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		//down
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		//left
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		//right
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glEnd();
		glEndList();
	}
}

void Cube::resizeGL(int width, int height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Cube::paintGL()
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -20.0f);
	glRotatef(xrotate, 1.0f, 0.0f, 0.0f);
	glRotatef(yrotate, 0.0f, 1.0f, 0.0f);
	glRotatef(zrotate, 0.0f, 0.0f, 1.0f);

	for (int i = 0; i < 3; i++)
	{
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -2.0*i + 2.0f);
		for (int j = 0; j < 9; j++)
		{
			glPushMatrix();
			glTranslatef((j % 3) * 2 - 2.0f, (j / 3) * 2 - 2.0f, 0);
			glCallList(cubes + i * 9 + j);
			glPopMatrix();
		}
		glPopMatrix();
	}
}

void Cube::keyPressEvent(QKeyEvent * event)
{
}

void Cube::timerEvent(QTimerEvent * event)
{
	xrotate += 0.5;
	yrotate += 0.5;
	zrotate += 0.5;
	updateGL();//QGLWidget window redraw and we can't invoke paintGL to redraw
	QGLWidget::timerEvent(event);
}
