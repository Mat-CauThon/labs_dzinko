main: main.o findVel.o mapClass.o enemyClass.o
	g++ -o main main.o mapClass.o enemyClass.o findVel.o -L/Library/Developer/CommandLineTools/usr/lib -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp enemyClass.hpp mapClass.hpp findVel.h
	g++ -std=c++11 -c main.cpp -I/Library/Developer/CommandLineTools/usr/include
findVel.o: findVel.cpp findVel.h
	g++ -c findVel.cpp
mapClass.o: mapClass.cpp mapClass.hpp
	g++ -c mapClass.cpp
enemyClass.o: enemyClass.hpp enemyClass.cpp findVel.h
	g++ -c enemyClass.cpp -I/Library/Developer/CommandLineTools/usr/include
