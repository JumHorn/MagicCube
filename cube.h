#ifndef _CUBE_H_
#define _CUBE_H_

#include<OpenGL/gl.h>

class Cube
{
public:
	Cube();
	~Cube();

	void initializeGL();
	void resizeGL(int width,int height);
	void paintGL();

public:
	void keyPressEvent();
	void mouseMoveEvent();
	void timerEvent();

private:
	GLfloat xrotate;
	GLfloat yrotate;
	GLfloat zrotate;
};

extern "C"
{
	//called to draw sence
	void RenderSence(void);
	//set up the rendering state
	void SetupRC(void);
	//called by GLUT library when the window has change size
	void ChangeSize(GLsizei w,GLsizei h);
	//timer callback function
	void timerFun(int value);
	//mouse move event
	void mouseMove(int x,int y);
}

#endif
