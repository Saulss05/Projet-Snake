#ifndef _SERPENT_H
#define _SERPENT_H
#include"Grille.h"

struct serpent{
	struct coord tete;
	struct liste *corps;
};

struct serpent * creer_serpent(int x,int y);

void Grille_remplir_serpent(struct grille*G ,struct serpent*S);
#endif
