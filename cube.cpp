#include<opengl/gl.h>
#include<opengl/glu.h>
#include"cube.h"

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

void paintGL()
{}
