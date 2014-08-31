.PHONY:debug all

SRC 	= $(wildcard *.c)
SRCC 	= $(wildcard *.cpp)
BIN 	+= $(patsubst %.c, %.out, $(SRC))
BIN     += $(patsubst %.cpp, %.cout, $(SRCC))

all:${BIN}

%.out:%.c
	gcc -o a a.cpp -DDEBUG -g -Wall

%.cout:%.cpp
	g++ -o a a.cpp -DDEBUG -g -Wall
clean:
	rm *.cout *.out
