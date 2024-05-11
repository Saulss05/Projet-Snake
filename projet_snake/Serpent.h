#ifndef _SERPENT_H
#define _SERPENT_H
#include"Grille.h"

struct section{
    int taille;
    char* couleur; 
    struct section*suivant;
};

struct liste{
    struct section *premier;
    struct section *dernier;
    int longueur;
};

struct serpent{
	struct coord tete;
	struct liste *corps;
};

	
void Grille_remplir_serpent(struct grille*G ,struct serpent*S);


#endif
