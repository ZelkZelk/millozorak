CC=cc 
CFLAGS=-Wall
SDL=`sdl-config --cflags --libs` -lSDL_ttf

all: millo
millo: millo.o
	$(CC) $(CFLAGS) -o millo.exe millo.o $(wildcard lib/*.c) $(SDL)
millo.o: millo.c $(wildcard lib/*.h) $(wildcard lib/*.c)
	$(CC) $(CFLAGS) -o millo.o -c millo.c $(SDL) 
clean:
	rm -f millo.exe millo.o
run: millo
	./millo.exe
