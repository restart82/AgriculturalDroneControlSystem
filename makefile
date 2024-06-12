all: prog.exe
	.\prog.exe

prog.exe: main.o dron.o view.o session.o field.o
	gcc -o prog dron.o view.o session.o field.o main.o -lncursesw

main.o: main.c inc/config.h
	gcc -c -o main.o main.c

dron.o: src/dron.c inc/dron.h
	gcc -c -o dron.o src/dron.c

view.o: src/view.c inc/view.h
	gcc -c -o view.o src/view.c

session.o: src/session.c inc/session.h
	gcc -c -o session.o src/session.c

field.o: src/field.c inc/field.h
	gcc -c -o field.o src/field.c