#ifndef CUBE_H
#define CUBE_H

#include <QGLWidget>
#include <GL/glu.h>//must be after QGLWidget

class Cube : public QGLWidget
{
public:
	Cube(QWidget *parent = 0);
	~Cube();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

	void keyPressEvent(QKeyEvent *event);
	void timerEvent(QTimerEvent *event);

private:
	GLfloat xrotate;
	GLfloat yrotate;
	GLfloat zrotate;

	GLuint cubes;
};

#endif // CUBE_H
