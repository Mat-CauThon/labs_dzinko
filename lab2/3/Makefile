main: main.o create_white.o pool_new.o pool_delete.o
	g++ main.o create_white.o pool_new.o pool_delete.o -o main
main.o: main.cpp create_white.hpp pool_new.hpp pool_delete.hpp image.h
	g++ -c main.cpp
create_white.o: create_white.cpp create_white.hpp image.h
	g++ -c create_white.cpp
pool_new.o: pool_new.cpp image.h pool_new.hpp
	g++ -c pool_new.cpp
pool_delete.o: pool_delete.cpp image.h pool_delete.hpp
	g++ -c pool_delete.cpp
clean:
	*.o main
