#include<stdio.h>
#include<string.h>
#include<time.h>
#include<ncurses.h>
#include<stdlib.h>
#include"Grille.h"
#include"Serpent.h"
#include"Fonction_Jeu_1_serpent.h"

int main(int argc,char**argv){
	srand(time(NULL));
	int n;
	int m;
	int taille=4;
	char*couleur="\33[42m  ";
	int temps;
	char*jeux;
	
	if(argc!=5){
		fprintf(stderr,"Erreur nombre d'arguments\n");
		return EXIT_FAILURE;
	}
	jeux=argv[4];
	if(strcmp(jeux,"snake")!=0){
		printf("Ce jeu n'existe pas.\n");
		return EXIT_FAILURE;
		}		
		
	temps=atoi(argv[3]);
	halfdelay(temps);
	n=atoi(argv[1]);
	m=atoi(argv[2]);
	
	struct grille *G=Grille_allouer(n,m);
	Grille_vider(G);
	Grille_tirage_fruit(G);
	//Grille_remplir(G);
	struct serpent *Snake=creer_serpent((G->n)/2,(G->m)/2);
	printf("Serpent créé\n");
	//struct section *Sec=creer_section(taille,couleur);
	//ajouter_section_debut(Snake->corps,Sec);
	//Grille_remplir_serpent(G,Snake);
	//Grille_redessiner(G);
	if(jeu(G,Snake)==1){
		printf("GAMEOVER\n");
	}
	//Grille_desallouer(G);
}	
	
