#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "cube.h"

int main(int argc, char *argv[])
{
	// init GLUT and create window
	glutInit(&argc, argv);
	//center the window
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,(glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
	glutInitWindowSize(640,480);
	glutCreateWindow("Magic Cube");
	
	// register callbacks
	SetupRC();
	glutDisplayFunc(RenderSence);
	glutReshapeFunc(ChangeSize);
	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}
