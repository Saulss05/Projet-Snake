all: Grille.o Main.o Serpent.o Liste_Section.o Fonction_Jeu_1_serpent.o
	gcc Grille.o Liste_Section.o Serpent.o Fonction_Jeu_1_serpent.o Main.o -o snake -lncurses
	
Grille.o: Grille.c Grille.h
	gcc -c -Wall -pedantic -std=c99 Grille.c

Liste_Section.o: Liste_Section.c Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Liste_Section.c
	
Serpent.o: Serpent.c Serpent.h Grille.h Liste_Section.h
	gcc -c -Wall -pedantic -std=c99 Serpent.c
	
Fonction_Jeu_1_serpent.o: Fonction_Jeu_1_serpent.c Fonction_Jeu_1_serpent.h Serpent.h Grille.h
	gcc -c -Wall -pedantic -std=c99 Fonction_Jeu_1_serpent.c -lncurses

Main.o: Main.c Grille.h Serpent.h
	gcc -c -Wall -pedantic -std=c99 Main.c -lncurses

clean: rm *.o snake

