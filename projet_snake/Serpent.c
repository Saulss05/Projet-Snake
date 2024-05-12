#include"Serpent.h"
#include<stdlib.h>
#include<stdio.h>
#include"Grille.h"
		
struct serpent * creer_serpent(int x,int y){
	struct serpent * S = malloc(sizeof(struct serpent));
	S->tete.x=x;
	S->tete.y=y;
	S->corps = nouvelle_liste();
	return S;
}		
		
void Grille_remplir_serpent(struct grille * G,struct serpent * S){
	int i;
	struct section *M=S->corps->premier;
	struct coord dernier;
	G->tab[S->tete.x][S->tete.y] = "\33[42m:p";
	dernier.x=S->tete.x;
	dernier.y=S->tete.y;
	while(M!=NULL){
		for(i=0;i<M->taille;i++){
			dernier.x+=1;
			G->tab[dernier.y][dernier.x]=M->couleur;
		}
		M=M->suivant;
	}
}
	
	
