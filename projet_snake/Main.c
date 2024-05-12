#include<stdio.h>
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
	int temp;
	int jeux;
	if(argc!=5){
		fprintf(stderr,"Erreur nombre d'arguments\n");
		return EXIT_FAILURE;
	}
	jeux=atoi(argv[4]);
	if(jeux!=1){
		printf("Erreur nom du jeu\n");
		}		
	temp=atoi(argv[3]);
	halfdelay(temp);
	n=atoi(argv[1]);
	m=atoi(argv[2]);
	struct grille *G=Grille_allouer(n,m);
	Grille_vider(G);
	Grille_tirage_fruit(G);
	Grille_remplir(G);
	struct serpent *Snake=creer_serpent((G->n)/2,(G->m)/2);
	struct section *Sec=creer_section(taille,couleur);
	ajouter_section_debut(Snake->corps,Sec);
	Grille_remplir_serpent(G,Snake);
	jeu(G,Snake);
	Grille_redessiner(G);
}	
	
