#  @brief  Build instructions for acm
#  @file Makefile
#  @author xiyanxiyan10
#  @CreatedTime 2014/09/04
#  @LastChanged 2014/09/15

.PHONY:debug all

SRC 	= $(wildcard *.c)
SRCC 	= $(wildcard *.cpp)
BIN 	+= $(patsubst %.c, %.out, $(SRC))
BIN     += $(patsubst %.cpp, %.cout, $(SRCC))

all:${BIN}

%.out:%.c
	gcc -o $@ $^ -DDEBUG -g -Wall -lm

%.cout:%.cpp
	g++ -o $@ $^ -DDEBUG -g -Wall
clean:
	rm *.cout *.out
