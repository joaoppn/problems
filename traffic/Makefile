all: traffic.cpp
	sudo g++ traffic.cpp -o traffic
test: traffic
	./traffic < 01.in|diff - 01.out
	./traffic < 02.in|diff - 02.out
