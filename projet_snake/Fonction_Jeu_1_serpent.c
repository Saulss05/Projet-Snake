#include<ncurses.h>
#include "Fonction_Jeu_1_serpent.h"
#include "Serpent.h"
#include<string.h>
#include<stdlib.h>
#include"Grille.h"

int gameover1(struct grille* G, struct serpent* S){
	if (S->tete.x < 0 || S->tete.y <0 || S->tete.x == G->n  || S->tete.y == G->m || strcmp(G->tab[S->tete.x][S->tete.y],"\33[42m  ")==0){
		return -1;
	}
	else{
		return 0;
	}
}

char*generer_couleur(){
	int nb= 41 +rand()%7;
	char*couleur=(char*)malloc(sizeof(char)*8);
	if (couleur==NULL){
		fprintf(stderr,"Impossible allouer memoire\n");
	}
	snprintf(couleur,8,"\33[%dm  ",nb);
	return couleur;
}

void manger_fruit(struct serpent* S){
	struct section* Sec=creer_section(5,generer_couleur());
	ajouter_section_queue(S->corps,Sec);
}

int jeu(struct grille* G, struct serpent* S,int vitesse){

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  int score=0;
  int car=KEY_RIGHT;
  int est_fruit=1;
  int der_car=car;
  ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
  
  printf("\33[2J"); 
  printf("\33[H");
    
  Grille_remplir_serpent(G,S);
  Grille_tirage_fruit(G);
  Grille_remplir(G);
  Grille_redessiner(G);
  halfdelay(vitesse);

do{
    est_fruit=1;
    car = getch();    

   if (car==-1){ 
   	car=der_car;
   }

    else{
      	car=car; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    }
   
   
    switch(car) {  
    
        case KEY_UP:
           if(der_car==KEY_DOWN && S->corps->premier!=NULL){
           	 //ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
          	 //S->tete.x++;
           	 der_car=KEY_DOWN;
           }
           else{
           	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,1));
           	S->tete.x--;
           	der_car=KEY_UP;
           }
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;
           
        case KEY_DOWN: 
            if(der_car==KEY_UP && S->corps->premier!=NULL){
            	//ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,1));
           	//S->tete.x--;
           	der_car=KEY_UP;
           }
            else{
            	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
            	S->tete.x++;
            	der_car=KEY_DOWN;
            }
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
            	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;
           
        case KEY_LEFT: 
           if(der_car==KEY_RIGHT && S->corps->premier!=NULL){
           	//ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,2));
          	//S->tete.y++;   
           	der_car=KEY_RIGHT;
           }
           else{
           	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
           	S->tete.y--;
           	der_car=KEY_LEFT;
           }
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }
           break;

        case KEY_RIGHT:
           if(der_car==KEY_LEFT && S->corps->premier!=NULL){
           	//ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
           	//S->tete.y--;
           	der_car=KEY_LEFT;
           }
           else{
          	ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,2));
           	S->tete.y++;   
          	 der_car=KEY_RIGHT;
           } 
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           	score++;
           }           
           break;
        default:
          break;
      }
      
   fflush(stdout);  
   Grille_redessiner(G);
   printf("\33[2J"); 
   printf("\33[H");
   Grille_vider(G);
   if(est_fruit!=1){
   	do{
   		Grille_tirage_fruit(G);
   	}while(strcmp(G->tab[G->fruit.x][G->fruit.y],"\33[42m:p")==0 || strcmp(G->tab[G->fruit.x][G->fruit.y],S->corps->premier->couleur)==0);
   }
   Grille_remplir(G);
   Grille_remplir_serpent(G,S);
   
  } while ( gameover1(G,S)!= -1);
  endwin();
  //Grille_desallouer(G);
  return 1;


}
