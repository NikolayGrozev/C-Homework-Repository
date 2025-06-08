all: serialize.exe deserialize.exe

serialize.exe: serialize.c employee.o
	gcc serialize.c employee.o -o serialize.exe

deserialize.exe : deserialize.c employee.o
	gcc deserialize.c employee.o -o deserialize.exe

employee.o: employee.c employee.h
	gcc -c employee.c -o employee.o

clean:
	del *.exe *.o *.bin