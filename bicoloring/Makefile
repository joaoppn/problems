all: color.cpp grafo.cpp grafo.h
	sudo g++ -g grafo.cpp color.cpp -o color
test:
	./color < 01.in|diff - 01.out
