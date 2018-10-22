#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "cube.h"
extern Cube c;

int main(int argc, char *argv[])
{
	// init GLUT and create window
	glutInit(&argc, argv);
	//center the window
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,(glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutCreateWindow("Magic Cube");
	
	// register callbacks
	glutDisplayFunc(RenderSence);
	//glutReshapeFunc(resizeGL);
	
	c.initializeGL();	
	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}
