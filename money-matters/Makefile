all: grafo.cpp grafo.h money.cpp
	sudo g++ -g grafo.cpp money.cpp -o money

test:
	./money < 01.in|diff - 01.out
	./money < 02.in|diff - 02.out
	./money < 03.in|diff - 03.out
