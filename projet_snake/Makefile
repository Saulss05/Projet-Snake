all: Grille.o Main.o
	gcc Grille.o Main.o -o snake
	
Grille.o: Grille.c Grille.h
	gcc -c -Wall -pedantic -std=c99 Grille.c
	
Main.o: Main.c Grille.h
	gcc -c -Wall -pedantic -std=c99 Main.c
	
clean: rm *.o snake

