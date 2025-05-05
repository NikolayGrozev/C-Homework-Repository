all: zad.exe

zad.exe: zad.c DynamicArray.o
	gcc zad.c DynamicArray.o -o zad.exe

tests.exe: tests.c DynamicArray.o
	gcc tests.c DynamicArray.o -o tests.exe

DynamicArray.o: DynamicArray.h DynamicArray.c
	gcc -c DynamicArray.c -o DynamicArray.o

clean:
	del *.exe *.o