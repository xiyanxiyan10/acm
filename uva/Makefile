.PHONY:debug all

SRC 	= $(wildcard *.c)
SRCC 	= $(wildcard *.cpp)
BIN 	+= $(patsubst %.c, %.out, $(SRC))
BIN     += $(patsubst %.cpp, %.cout, $(SRCC))

all:${BIN}

%.out:%.c
	gcc -o $@ $^ -DDEBUG -g -Wall

%.cout:%.cpp
	g++ -o $@ $^ -DDEBUG -g -Wall
clean:
	rm *.cout *.out
