all: zad.exe

zad.exe: zad.c books.o
	gcc zad.c books.o -o zad.exe

books.o: books.c books.h
	gcc -c books.c -o books.o

clean:
	del *.o *.exe