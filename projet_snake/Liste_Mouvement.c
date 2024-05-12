
struct maillon *creer_maillon (struct coord coord,unsigned direction) {
  struct maillon *m = malloc(sizeof(struct maillon));
  m->coord.x = coord.x;
  m->coord.y = coord.y;
  m->direction=direction;
  m->suivant = NULL;
  return m;
}


void detruire_maillon (struct maillon *m) {
  if (m != NULL) {
    free(m);
    m = NULL;
  }
}

struct liste_mouvement *nouvelle_liste_mouvement() {
  struct liste_mouvement *l = malloc(sizeof(struct liste_mouvement));
  l->premier = NULL;
  l->dernier = NULL;
  l->longueur = 0;
  return l;
}


void ajouter_maillon_debut_liste(struct liste_mouvement *l, struct maillon *m) {
  if (l->longueur==0) {  l->dernier = m; }
  m->suivant = l->premier;
  l->premier = m;
  ++l->longueur;
}


struct maillon *extraire_maillon_debut_liste(struct liste_mouvement *l) {
  struct maillon *m = l->premier;
  if (m != NULL) {
    l->premier = m->suivant;
    --l->longueur;
    if (l->longueur==0) { l->dernier = NULL; }
    m->suivant = NULL;
  }
  return m;
}


void detruire_liste_mouvement (struct liste_mouvement *l) {
  if (l != NULL) {
    while ((l)->longueur!=0) {
      struct maillon *m = extraire_maillon_debut_liste(l);
      detruire_maillon(m);
    }
    free(l);
    l = NULL;
  }
}
 
 
void ajouter_maillon_fin_liste(struct liste_mouvement *l,struct maillon *m)
{
  m->suivant=NULL;
	if(l->longueur==0)
	{
    l->premier=m;
	}
	else
	{
    l->dernier->suivant=m;
	}
  l->longueur++;
  l->dernier=m;
}
