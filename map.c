#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "personnages.h"
#include "fonction_map.h"


int main (int argc, char ** argv){
	int v;
	int joueur = 1;
	srand(time(NULL));			/*initialisation du random*/
	int entered_size=0;
	int credit =0;
	
	int ** MainMap=NULL ; /**pointeur sur notre carte créée dans le tas**/;

	unite_s *tab_ref = init_tab(); /********** Tableau reference unite***********/
	unite_s *tab_j1 ; 
	unite_s *tab_j2 ;
	unite_s *tab_ordrejeu;

	do{
	printf("Combien de crédits souhaitez-vous ?(entre 10 et 100)\n");
	scanf("%d",&credit);
	}while(credit>=100 || credit<10);  /*****Entrez nombre d'unités*****/
	int creditmax = credit;
	entered_size= unitTosize(&credit); /*****Convertir NOMBRE D'unités EN TAILLE*********/
	MainMap = Map_Maker1(&entered_size);
	AfficherMap(MainMap,&entered_size); /****MAP VIDE*****/
	printf("Press any key to continue...\n");
	scanf("%d",&v);
	init_obstacle(MainMap, &entered_size);
	AfficherMap(MainMap,&entered_size);

	printf("%i",tab_ref[0].stats.credit);


	compo_unit(MainMap,&credit,joueur,tab_ref,tab_j1);
	joueur++;
	credit = creditmax;
	compo_unit(MainMap,&credit,joueur,tab_ref,tab_j2);

	/*mouv_avancer(MainMap,&entered_size);*/
	

         return 0;
}