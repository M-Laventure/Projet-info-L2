#include <stdlib.h>
#include <stdio.h>
#include <structures.h>

#define N /*le nombre d'unités maximum*/


typedef struct unite unite;

void saisie_unite (){
	int * nb_archers;
	int * nb_soldats;
	do
		{ 
			printf("Saisir le nombre d'archers" \n);
			scanf("%i", &nb_archers);
			printf("Saisir le nombre d'infanterie" \n);
			scanf("%i", &nb_infanterie);
		}
	while (nb_archers<0 || nb_infanterie<0 && nb_archers<=N || nb_soldats<=N);
		
}
	

/*	unite creer_unite(int id_type, int id_joueur, int id_unite){
		unite random ; 
		if(id_type==3){
			
*/		


