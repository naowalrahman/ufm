run: compile
	./main

compile: data.c data.h process.c process.h display.c display.h main.c
	gcc -c data.c process.c display.c main.c -Wall
	gcc data.o process.o display.o main.o -o main -Wall

clean:
	rm *.o
	rm main
