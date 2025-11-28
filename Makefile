all:
	gcc main.c modulos/ingrediente.c modulos/pizza.c -o main

run:
	./main || main.exe

crun:
	gcc main.c modulos/ingrediente.c modulos/pizza.c -o main
	./main || main.exe