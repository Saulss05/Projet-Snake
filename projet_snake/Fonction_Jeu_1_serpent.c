#include "Fonction_Jeu_1_serpent.h"
#include "Serpent.h"
#include<ncurses>

void jeu(struct grille* G, struct serpent* S){

  int ch, ch_dern;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  int temps;

  halfdelay(temps);
  

  int gameover1(struct Grille* G, struct serpent* S){
	
	if ((S->tete.x < 0 || S->tete.y <0 || S->tete.x == G->n 0 || S->tete.y == G->m) return -1;
	
  }


do{
  
    ch = getch();
    
 

   if (ch==-1){ 
   
   	 S->tete.x++;

    else{
       
      ch_dern=ch; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    
    }
    
    switch(ch_dern) {  
        case KEY_UP:  
           S->tete.y--;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           Grille_tirage_fruit(*G);
           Grille_remplir(struct grille*G);
           }
           break;
        case KEY_DOWN: 
            S->tete.y++;
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y)){
           Grille_tirage_fruit(*G);
           Grille_remplir(struct grille*G);
           }
        case KEY_LEFT: 
           S->tete.x--;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y)){
           Grille_tirage_fruit(*G);
           Grille_remplir(struct grille*G);
           }
           break; 
        case KEY_RIGHT: 
           S->tete.x++;    
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y)){
           Grille_tirage_fruit(*G);
           Grille_remplir(struct grille*G);
           }           
           break;
        default:
          break;
      }
      
   fflush(stdout);  
   
  } while ( gameover1(*G, *S)!= -1);

    
  endwin(); 


}
