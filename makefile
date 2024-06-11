all: prog.exe
	.\prog.exe

prog.exe: main.o dron.o view.o
	gcc -o prog dron.o view.o main.o -lncursesw
	del *.o

main.o: main.c inc/config.h
	gcc -c -o main.o main.c

dron.o: src/dron.c inc/dron.h
	gcc -c -o dron.o src/dron.c

view.o: src/view.c inc/view.h
	gcc -c -o view.o src/view.c