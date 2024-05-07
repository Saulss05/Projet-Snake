#ifndef _SERPENT_H
#define _SERPENT_H
#include"Grille.h"


struct serpent{
	struct coord tete;
	struct liste *corps;
};

	
void Grille_remplir_serpent(struct grille*,struct serpent*);


#endif
