
all: arbre dico
	gcc -Wall arbre.o dico.o mainTest.c -o main

debug: arbre dico
	gcc -g -Wall arbre.o dico.o mainTest.c -o debug

arbre: arbre.c arbre.h
	gcc -c -Wall arbre.c

dico: dico.c dico.h
	gcc -g -c -Wall dico.c

clean:
	rm *.o main debug