#include<ncurses.h>
#include "Fonction_Jeu_1_serpent.h"
#include "Serpent.h"
#include<string.h>
#include"Grille.h"

int gameover1(struct grille* G, struct serpent* S){
	if (S->tete.x < 0 || S->tete.y <0 || S->tete.x == G->n  || S->tete.y == G->m || strcmp("\33[42m:p","\33[42m  ")==0){
		return -1;
	}
	else{
		return 0;
	}
}
void manger_fruit(struct serpent* S){
	struct section* Sec=creer_section(1,"\33[42m  ");
	ajouter_section_queue(S->corps,Sec);
}

int jeu(struct grille* G, struct serpent* S){

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

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
  halfdelay(5);

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
           ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,1));
           S->tete.x--;
           der_car=KEY_UP;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           }
           break;
           
        case KEY_DOWN: 
            ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,3));
            S->tete.x++;
            der_car=KEY_DOWN;
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
            	est_fruit=0;
           	manger_fruit(S);
           }
           break;
           
        case KEY_LEFT: 
           ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,4));
           S->tete.y--;
           der_car=KEY_LEFT;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
           }
           break; 
           
        case KEY_RIGHT: 
           ajouter_section_mvt_debut(S->mvt,creer_section_mvt(S->tete,2));
           S->tete.y++;   
           der_car=KEY_RIGHT; 
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	est_fruit=0;
           	manger_fruit(S);
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
   	Grille_tirage_fruit(G);
   }
   Grille_remplir(G);
   Grille_remplir_serpent(G,S);
   
  } while ( gameover1(G,S)!= -1);
  endwin();
  return 1; 


}
