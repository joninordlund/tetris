CXX = g++
FLAGS = -Wall -std=c++0x
LIB_FILES = shape.cpp shapestore.cpp tetrisboard.cpp
SRC = ${LIB_FILES}

lib:
	rm -f libtetris.a
	${CXX} ${FLAGS} -c ${LIB_FILES}
	ar -cvq libtetris.a shape.o shapestore.o tetrisboard.o
	
clean:
	rm -f main
