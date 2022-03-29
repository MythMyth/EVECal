CC = g++

build/EveCal: build/main.o
	$(CC) build/main.o -o build/EveCal
build/main.o: main.cpp
	$(CC) -c main.cpp -o build/main.o