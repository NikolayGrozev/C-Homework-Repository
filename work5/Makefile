all: help.exe strcompare.exe strconcat.exe strlength.exe

help.exe: mystrings.o
	gcc zad.c mystrings.o -o zad.exe

mystrings.o:
	gcc -c mystrings.c -o mystrings.o

strcompare.exe: mystrings.o
	gcc strcompare.c mystrings.o -o strcompare.exe
strconcat.exe: mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.exe
strlength.exe: mystrings.o
	gcc strlength.c mystrings.o -o strlength.exe

clean:
	rm *.o *.exe
