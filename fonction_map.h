
/**Prototype à mettre dans un fichier.h**/
extern int** Map_Maker1(int * size); //fonction qui initialise la carte
extern void AfficherMap(int **Map, int * size);//fonction qui affiche la carte

extern int** Map_Maker1(int * size) //reçoit un pointeur sur size pour ne rien perdre.
{
 int **Map;
 int i,j;
int taille_matrice = (*size); //je stocke la taille, pour eviter de mettre des notations *
Map= malloc(taille_matrice*sizeof(int*));
/*on alloue une valeur à la matrice**/
if (Map ==NULL){
	printf("Allocation impossible\n");
	exit(EXIT_FAILURE);

}
 for (i=0;i<taille_matrice;i++)
	{
		Map[i] = malloc(taille_matrice*sizeof(int));
		for(j=0;j<taille_matrice;j++)
		{
			
			Map[i][j]=0;  /*valeur mise à zéro*/
			
		}

   	
	}
	return  Map;

}


extern void AfficherMap(int **Map, int * size){
/*if((i==0)||(i==size-1)||(j==0)||(j==size-1)){ //bout de code affiche les contours de la map
				printf(" *");
			}else printf("  ");*/
int i, j;
int taille_matrice = (*size); //je stocke la taille, pour eviter de mettre des notations *
	
for (i=0;i<taille_matrice;i++)
	{
		for(j=0;j<taille_matrice;j++)
		{
			printf("%4d", Map[i][j]); // %4d pour bien séparer les chiffres la ligne
		}
	printf ( "\n");
	}
}

extern void init_obstacle(int **tableau, int *taille_map){
	int nb_obstacle = (*taille_map);
	int i=0;
	int coord_x=0;
	int coord_y=0;
	int zone_j = (*taille_map)/4;
	printf("%i \n",zone_j);
	
 // initialisation de rand

	for (i=0;i<nb_obstacle;i++){
		coord_y = rand()%((*taille_map)-(2*zone_j))+zone_j;
		coord_x = rand()%(*taille_map);
		if (tableau[coord_x][coord_y] ==1){
			i--;
		}
		else{
			tableau[coord_x][coord_y] =1;
		}
	}
}
