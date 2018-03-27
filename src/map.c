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
	unite_s *tab_j1 = malloc(10*sizeof(unite_s)); 
	unite_s *tab_j2 = malloc(10*sizeof(unite_s)); ;
	unite_s *tab_ordrejeu =malloc(20*sizeof(unite_s));

	do{
	printf("Combien de crédits souhaitez-vous ?(entre 10 et 100)\n");
	scanf("%d",&credit);
	}while(credit>=100 || credit<10);  /*****Entrez nombre d'unités*****/
	int creditmax = credit;
	entered_size= unitTosize(&credit); /*****Convertir NOMBRE D'unités EN TAILLE*********/
	MainMap = Map_Maker1(&entered_size);

	init_obstacle(MainMap, &entered_size);
	AfficherMap(MainMap,&entered_size);

	compo_unit(MainMap,&credit,joueur,tab_ref,tab_j1);
	AfficherMap(MainMap,&entered_size);
	printf(" Début composition joueur 2");
	scanf("%i",&v);
	joueur++;
	credit = creditmax;
	compo_unit(MainMap,&credit,joueur,tab_ref,tab_j2);

	ordre_jeu(tab_ordrejeu,tab_j1,tab_j2);
	place_unite(MainMap,tab_ordrejeu);
	printf("Carte a jour : \n");
	
	
	int i=0;
	while(!victoire(tab_ordrejeu)){
		if(tab_ordrejeu[i].stats.vie !=0){
			AfficherMap(MainMap,&entered_size);
			printf("\n Tour : %s n %i du joueur %i  \n ",tab_ordrejeu[i].nom,tab_ordrejeu[i].id_unite,tab_ordrejeu[i].id_joueur);
			tour_unite(tab_ordrejeu,i,MainMap);
		}
		i++;
		if (i==20)i=0;
	
	}
	return 0;
}
