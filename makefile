a.out : main.cpp
	g++ main.cpp -framework opengl -framework GLUT -Wno-deprecated-declarations
