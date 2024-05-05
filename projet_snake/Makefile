all: Grille.o Main.o Serpent.o Liste_Section.o
	gcc Grille.o Main.o -o snake
	
Grille.o: Grille.c Grille.h
	gcc -c -Wall -pedantic -std=c99 Grille.c

Serpent.o: Serpent.c Grille.h Serpent.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Serpent.c
	
Liste_Section.o: Liste_Section.c Grille.h Serpent.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Liste_Section.c

Main.o: Main.c Grille.h Liste_Section.h Serpent.h
	gcc -c -Wall -pedantic -std=c99 Main.c

	
clean: rm *.o snake

