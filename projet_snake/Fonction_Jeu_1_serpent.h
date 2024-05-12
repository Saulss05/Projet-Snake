#ifndef _Fonction_JEU_1_SERPENT_H
#define _Fonction_JEU_1_SERPENT_H
#include"Grille.h"
#include "Serpent.h"

void jeu(struct grille* G, struct serpent* S);

int gameover1(struct grille* G, struct serpent* S);

void manger_fruit(struct serpent* S);

#endif




