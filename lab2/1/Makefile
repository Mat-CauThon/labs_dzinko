main: main.o create_white.o create_black.o create_color.o
	g++ main.o create_white.o create_black.o create_color.o -o main
main.o: main.cpp create_black.hpp create_white.hpp create_color.hpp image.h
	g++ -c main.cpp
create_white.o: create_white.cpp create_white.hpp image.h
	g++ -c create_white.cpp
create_black.o: create_black.cpp create_black.hpp image.h
	g++ -c create_black.cpp
create_color.o: create_color.cpp create_color.hpp image.h
	g++ -c create_color.cpp
clean:
	*.o main
