#include<ncurses.h>
#include "Fonction_Jeu_1_serpent.h"
#include "Serpent.h"
#include"Grille.h"

int gameover1(struct grille* G, struct serpent* S){
	if ((S->tete.x < 0 || S->tete.y <0 || S->tete.x == G->n  || S->tete.y == G->m)){
		return -1;
	}
	else{
		return 0;
	}
}

void jeu(struct grille* G, struct serpent* S){

  int ch,ch_dern;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  int temps=1;

  halfdelay(temps);
  

  


do{
  
    ch = getch();
    
 

   if (ch==-1){ 
   
   	 S->tete.x++;
   }

    else{
       
      ch_dern=ch; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    
    }
    printf("\33[2J"); 
    printf("\33[H");
    switch(ch_dern) {  
        case KEY_UP:  
           S->tete.y--;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	Grille_tirage_fruit(G);
           	Grille_remplir(G);
           }
           break;
        case KEY_DOWN: 
            S->tete.y++;
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	Grille_tirage_fruit(G);
           	Grille_remplir(G);
           }
           break;
        case KEY_LEFT: 
           S->tete.x--;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	Grille_tirage_fruit(G);
           	Grille_remplir(G);
           }
           break; 
        case KEY_RIGHT: 
           S->tete.x++;    
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	Grille_tirage_fruit(G);
           	Grille_remplir(G);
           }           
           break;
        default:
          break;
      }
      
   fflush(stdout);  
   
  } while ( gameover1(G,S)!= -1);
  	endwin(); 
}
