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
void manger_fruit(struct serpent* S){
	struct section* Sec=creer_section(1,"\33[42m  ");
	ajouter_section_queue(S->corps,Sec);
}

void jeu(struct grille* G, struct serpent* S){

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  int car=KEY_RIGHT;
  int der_car=car;
  
  printf("\33[2J"); 
  printf("\33[H");
    
  Grille_remplir_serpent(G,S);
  Grille_redessiner(G);
  Grille_tirage_fruit(G);
  Grille_remplir(G);
  halfdelay(5);

do{
  
    car = getch();
    
 

   if (car==-1){ 
   
   	 car=der_car;
   }

    else{
       
      car=car; /* on sauvegarde la dernière touche utilisee pour avoir le direction*/     
    
    }
   
   
    switch(car) {  
        case KEY_UP:  
           if(gameover1(G,S)==-1){
           	endwin();
           	printf("Vous avez perdu\n");
           }
           S->tete.y--;
           der_car=KEY_UP;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	manger_fruit(S);
           }
           break;
        case KEY_DOWN: 
            if(gameover1(G,S)==-1){
           	endwin();
           	printf("Vous avez perdu\n");
           }	
            S->tete.y++;
            der_car=KEY_DOWN;
            if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	manger_fruit(S);
           }
           break;
        case KEY_LEFT: 
           if(gameover1(G,S)==-1){
           	endwin();
           	printf("Vous avez perdu\n");
           }
           S->tete.x--;
           der_car=KEY_LEFT;
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	manger_fruit(S);
           }
           break; 
        case KEY_RIGHT: 
           if(gameover1(G,S)==-1){
           	endwin();
           	printf("Vous avez perdu\n");
           }
           S->tete.x++;   
           der_car=KEY_RIGHT; 
           if(S->tete.x == G->fruit.x && S->tete.y == G->fruit.y){
           	manger_fruit(S);
           }           
           break;
        default:
          break;
      }
      
   fflush(stdout);  
   Grille_vider(G);
   Grille_remplir_serpent(G,S);
   Grille_remplir(G);
   printf("\33[2J"); 
   printf("\33[H");
   Grille_redessiner(G);
   
  } while ( gameover1(G,S)!= -1);
  endwin(); 


}
   fflush(stdout);  
   
  } while ( gameover1(G,S)!= -1);
  	endwin(); 
}
