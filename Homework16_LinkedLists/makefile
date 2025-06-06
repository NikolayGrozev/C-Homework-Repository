all: program.exe tests.exe

program.exe: program.c LinkedList.o
	gcc program.c LinkedList.o -o program.exe

tests.exe: tests.c LinkedList.o
	gcc tests.c LinkedList.o -o tests.exe

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c -o LinkedList.o

clean:
	del *.o *.exe