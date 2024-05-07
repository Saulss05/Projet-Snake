#include<stdlib.h>
#include<stdio.h>
#include"Serpent.h"
#include"Grille.h"
		
		
void Grille_remplir_serpent(struct grille * G,struct serpent * S){
	S->tete.x = G->n/2;
	S->tete.y = G->m/2;
	G->tab[S->tete.x][S->tete.y] = "\33[42m:p";
}
/*	int i;
	struct section*N=S->corps->premier;
	struct coord dernier;
*/	
	
	
