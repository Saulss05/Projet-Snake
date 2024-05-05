#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Liste_Section.h"

struct section *creer_section (int t,char*c) {
  struct section *s = malloc(sizeof(struct section));
  s->taille = t;
  s->couleur=c;
  s->suivant = NULL;
  return s;
}

void desallouer_section (struct section **m) {
  if (*m != NULL) {
    free((*m)->taille);
    free((*m)->couleur);
    free(*m);
    *m = NULL;
  }
}

struct liste *nouvelle_liste() {
  struct liste *l = malloc(sizeof(struct liste));
  l->premier = NULL;
  l->dernier = NULL;
  l->longueur = 0;
  return l;
}

void ajouter_section_debut(struct liste *l, struct section *s) {
  if (l->longueur==0) {
      l->dernier = s; 
    }
  s->suivant = l->premier;
  l->premier = s;
  ++l->longueur;
}

void ajouter_maillon_queue(struct liste *l, struct section*s) {
  s->suivant = NULL;
  if (l->longueur==0) {
    l->premier = s;
  }
  else {
  l->dernier->suivant = s;
  }
  l->dernier = s;
  ++l->longueur;
}

struct section *extraire_maillon_debut(struct liste *l) {
  struct section *s = l->premier;
  if (s != NULL) {
    l->premier = s->suivant;
    --l->longueur;
    if (l->longueur==0){ 
        l->dernier = NULL; 
    }
    s->suivant = NULL;
  }
  return s;
}

void detruire_liste (struct liste **l){
  if (*l != NULL) {
    while ((*l)->longueur!=0) {
      struct section *s = extraire_maillon_debut_liste(*l);
      desallouer_section(&s);
    }
    free(*l);
    *l = NULL;
  }
}
