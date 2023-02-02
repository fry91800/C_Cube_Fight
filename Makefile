all:
	gcc src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
