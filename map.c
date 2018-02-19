#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "fonction_map.h"





int main (int argc, char ** argv){
	int v;

	srand(time(NULL));			/*initialisation du random*/
	int entered_size=0;
	int entered_units=0;
	int ** MainMap=NULL ; /**pointeur sur notre carte créée dans le tas**/;

	do{
	printf("Entrez le nombre d'unités(pas plus de 30)\n");
	scanf("%d",&entered_units);
	}while(entered_units>=30&&entered_units<1);  /*****Entrez nombre d'unités*****/

	entered_size= unitTosize(&entered_units); /*****Convertir NOMBRE D'unités EN TAILLE*********/
	printf("%d \n",entered_size);
	MainMap = Map_Maker1(&entered_size);
	AfficherMap(MainMap,&entered_size); /****MAP VIDE*****/
	printf("Press any key to continue...\n");
	scanf("%d",&v);
	init_obstacle(MainMap, &entered_size);
	AfficherMap(MainMap,&entered_size);

	printf("Press any key to continue...\n");
	scanf("%d",&v);
	placement_auto1(MainMap,&entered_size,&entered_units,'d');
	while(v>0){
	AfficherMap(MainMap,&entered_size);
	printf("Press any key to continue...\n");
	scanf("%d",&v);
	mouv(MainMap,&entered_size);
	}

              return 0;
}


