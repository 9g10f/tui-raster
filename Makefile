build: src/main.c
	gcc src/main.c -o main.o -lm

clean: main.o
	rm main.o
	gcc src/main.c -o main.o -lm