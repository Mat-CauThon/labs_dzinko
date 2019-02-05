main: main.o circles.dll
	g++ -o main main.o circles.dll
main.o: main.cpp circles.hpp
	g++ -c main.cpp
circles.o: circles.cpp circles.hpp
	g++ -c circles.cpp -I/Library/Developer/CommandLineTools/usr/local/include
circles.dll: circles.o
	g++ -shared -o circles.dll circles.o -L/Library/Developer/CommandLineTools/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
clean:
	*.o main
