#FLAGS = -std=c++11 -Wall -Wextra -g -pedantic
FLAGS = -std=c++1z -Wall -Wextra -pedantic -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wrestrict -Wuseless-cast -Wformat=2


all: deq tester

deq: Deque.hpp deque.cpp
	g++ deque.cpp -o deq $(FLAGS)

tester: Deque.hpp test.cpp
	g++ test.cpp -o tester $(FLAGS) -ldl

.phony:clean

clean:
	rm -f deq tester
