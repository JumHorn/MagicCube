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
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
	glutInitWindowSize(800,600);
	glutCreateWindow("Magic Cube");
	
	// register callbacks
	SetupRC();
	//paintGL
	glutDisplayFunc(RenderSence);
	//resizeGL
	glutReshapeFunc(ChangeSize);
	//timer function
	//glutTimerFunc(50,timerFun,0);
	//mouse function
	glutMotionFunc(mouseMove);
	glutMouseFunc(mousePress);

	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}
