all:
	gcc main.c modulos/ingrediente.c modulos/pizza.c modulos/menu.c modulos/pre_processamento.c -o main

run:
	./main

crun:
	gcc main.c modulos/ingrediente.c modulos/pizza.c modulos/menu.c modulos/pre_processamento.c -o main
	./main