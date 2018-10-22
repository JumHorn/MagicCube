#ifndef _CUBE_H_
#define _CUBE_H_

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
};

#endif
