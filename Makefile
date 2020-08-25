FLAGS = -std=c++11 -Wall -Wextra -g -pedantic

all: deq

deq: deque.h deque.cpp
	g++ deque.cpp -o deq $(FLAGS)

.phony:clean

clean:
	rm -f deq
