a.out : main.o cube.o
	g++ main.o cube.o -framework opengl -framework GLUT -Wno-deprecated-declarations
main.o : main.cpp
	g++ -c main.cpp -Wno-deprecated-declarations
cube.o : cube.cpp
	g++ -c cube.cpp -Wno-deprecated-declarations
clean :
	rm main.o cube.o
