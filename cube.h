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
	void mouseMoveEvent(int x,int y);
	void mousePressEvent(int button,int state,int x,int y);
	void timerEvent();

private:
	GLfloat xrotate;
	GLfloat yrotate;
	GLfloat zrotate;

	int mousestate;
	int xmouse;
	int ymouse;
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
	//mouse press event
	void mousePress(int button,int state,int x,int y);
}

#endif
