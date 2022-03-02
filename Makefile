
all: arbre dico
	gcc -Wall -Wno-unknown-pragmas arbre.o dico.o mainEval.c -o main

debug: arbre dico
	gcc -g -Wall -Wno-unknown-pragmas arbre.o dico.o mainTest.c -o debug

arbre: arbre.c arbre.h
	gcc -c -Wall -Wno-unknown-pragmas arbre.c

dico: dico.c dico.h
	gcc -c -Wall -Wno-unknown-pragmas dico.c

clean:
	rm *.o main debug