#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Grille.h"
#include"Serpent.h"

int main(int argc,char**argv){
	srand(time(NULL));
	int n;
	int m;
	if(argc!=3){
		fprintf(stderr,"Erreur nombre d'arguments\n");
		return EXIT_FAILURE;
	}
	n=atoi(argv[1]);
	m=atoi(argv[2]);
	struct grille *G=Grille_allouer(n,m);
	struct serpent *S=malloc(sizeof(struct serpent));
	Grille_vider(G);
	Grille_tirage_fruit(G);
	Grille_remplir(G);
	Grille_remplir_serpent(G,S);
	Grille_redessiner(G);
}	
	
