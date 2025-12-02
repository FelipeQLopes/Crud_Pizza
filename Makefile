all:
	gcc main.c modulos/menu.c modulos/ingrediente.c modulos/pizza.c modulos/pre_processamento.c -o main

run:
	./main

crun:
	make
	./main