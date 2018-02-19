#include<stdio.h>
#include<stdlib.h>
#include "fonction_map.h"

int placement_manuel(int **mat, int taille_map){
	int i;
	int nb_unite =(taille_map/2)
	int coord_x;
	int coord_y;
	int type_unite;
	
	while(i<nb_unite){/* Tant que nb d'unités déployable pas atteints */
		printf("Donnez le type de l'unité que vous voulez déployer");
		scanf("%i",&type_unite);
		printf("Entrez sa position");
		scanf("%i,%i",&coord_x,&coord_y);
		//mat[coord_x][coord_y]=unite.id;
		i++;
	}
}

int placement_auto(){
	
}
