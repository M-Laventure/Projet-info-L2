#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonction_map.h"
#include <time.h>




int main (int argc, char ** argv){
srand(time(NULL));
int entered_size;
int ** MainMap ; /**pointeur sur notre carte créée dans le tas**/;

printf("Programme working...\n");



do{
printf("Entrez la taille de votre matrice (pas plus de 30)\n");
scanf("%d",&entered_size);
}while(entered_size>=30);


MainMap = Map_Maker1(&entered_size);
init_obstacle(MainMap,&entered_size);
AfficherMap(MainMap,&entered_size);
return 0;
}


