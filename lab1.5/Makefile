main: main.o func.o
	g++ main.o func.o -o main
main.o: main.cpp func.hpp
	g++ -c main.cpp
func.o: func.cpp func.hpp
	g++ -c func.cpp
clean:
	*.o main
