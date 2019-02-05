main: main.o create_black.o
	g++ main.o create_black.o -o main
main.o: main.cpp create_black.hpp image.h
	g++ -c main.cpp
create_black.o: create_black.cpp create_black.hpp image.h
	g++ -c create_black.cpp
clean:
	*.o main
