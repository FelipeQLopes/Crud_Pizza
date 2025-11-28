all:
	gcc main.c modulos/ingrediente.c modulos/pizza.c -o main

run:
	./main || main.exe