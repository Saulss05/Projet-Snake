#include<stdlib.h>
#include<stdio.h>
#include"Serpent.h"
#include"Grille.h"
		
		
void Grille_remplir_serpent(struct grille * G,struct serpent * S){
	int i;
	S->tete.x = G->n/2;
	S->tete.y = G->m/2;
	G->tab[S->tete.x][S->tete.y] = "\33[42m:p";
	struct section *M=S->corps->premier;
	struct coord dernier;
	dernier.x=S->tete.x;
	dernier.y=S->tete.y;
	while(M!=NULL){
		for(i=0;i<M->taille;i++){
			dernier.x+=1;
			G->tab[dernier.x][dernier.y]="\33[42  ";
		}
		M=M->suivant;
	}
}
/*	int i;
	struct section*N=S->corps->premier;
	struct coord dernier;
*/	
	
	
