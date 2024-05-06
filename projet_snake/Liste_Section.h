#ifndef _SERPENT_H
#define _SERPENT_H

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

struct section *creer_section (int,char*);

void desallouer_section (struct section **);

struct liste *nouvelle_liste();

void ajouter_section_debut(struct liste *, struct section *);

void ajouter_section_queue(struct liste *, struct section *);

struct section *extraire_maillon_debut(struct liste *);

void detruire_liste (struct liste **);

#endif
