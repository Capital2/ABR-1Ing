
all: arbre dico stack
	gcc -Wall arbre.o dico.o stack.o mainTest.c -o main
debug: arbre dico stack
	gcc -g -Wall arbre.o dico.o stack.o mainTest.c -o debug
arbre: arbre.c arbre.h
	gcc -c -Wall arbre.c
dico: dico.c dico.h
	gcc -c -Wall dico.c
stack: stack.c stack.h
	gcc -c -Wall stack.c
clean:
	rm *.o main debug