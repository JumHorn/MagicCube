#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <boost/bind.hpp>
#include "cube.h"

int main(int argc, char *argv[])
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,640);
	glutCreateWindow("Magic Cube");
	
	// register callbacks
	Cube c;
	//glutDisplayFunc((void(*)())&boost::bind(&Cube::paintGL,&c));
	//glutReshapeFunc(resizeGL);
	
	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}
