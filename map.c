#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "fonction_map.h"
#include "personnages.h"


int main (int argc, char ** argv){
	int v;

	srand(time(NULL));			/*initialisation du random*/
	int entered_size=0;
	int credit =0;
	int ** MainMap=NULL ; /**pointeur sur notre carte créée dans le tas**/;

	do{
	printf("Combien de crédits souhaitez-vous ?(pas plus de 100)\n");
	scanf("%d",&credit);
	}while(credit>=100 && credit<1);  /*****Entrez nombre d'unités*****/

	entered_size= unitTosize(&credit); /*****Convertir NOMBRE D'unités EN TAILLE*********/
	printf("%d \n",entered_size);
	MainMap = Map_Maker1(&entered_size);
	AfficherMap(MainMap,&entered_size); /****MAP VIDE*****/
	printf("Press any key to continue...\n");
	scanf("%d",&v);
	init_obstacle(MainMap, &entered_size);
	AfficherMap(MainMap,&entered_size);

	printf("Press any key to continue...\n");
	scanf("%d",&v);
	placement_auto1(MainMap,&entered_size,&credit,'d');
	while(v>0){
	AfficherMap(MainMap,&entered_size);
	printf("Press any key to continue...\n");
	scanf("%d",&v);
	mouv_avancer(MainMap,&entered_size);
	}

              return 0;
}


