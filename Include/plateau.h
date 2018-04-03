
/* Génération matrice plateau/obstacles */
int** Map_Maker(int * size ); //fonction qui initialise la carte
void AfficherMap(int **Map, int * size);//fonction qui affiche la carte
int  unitTosize(int *nombre_units);//fonction redéfinie la taille de la map
void init_obstacle(int **tableau, int *taille_map);

extern int** Map_Maker(int * size) { //reçoit un pointeur sur size pour ne rien perdre

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
			if (Map[j][i]==-2)   // on affiche pas les unites du joueur1 lors de la selection du joueur2
				printf("%4d",0);
			else
				printf("%4d", Map[j][i]); // %4d pour bien séparer les chiffres la ligne
		}
	printf ( "\n");

	}
}



extern int  unitTosize(int *nombre_units){
/* Cette fonction calcule la taille de la matrice en fonction du nombre de crédits choisit*/
	int taille_matrice=4;
	int n_units=(*nombre_units);
	if(n_units<20)
		taille_matrice = 4;
	else if (n_units<100)
		taille_matrice = 10;

	else taille_matrice = 20;

	return taille_matrice;

}


/********************Génération d'obstacles ********************************************/

extern void init_obstacle(int **tableau, int *taille_map){
	/* cette fonction initialise les obstacles sur la map*/
	int nb_obstacle = (*taille_map); //nb d'obstacle dépends de la taille de la map
	int i=0;
	int coord_x=0;
	int coord_y=0;
	int zone_j = (*taille_map)/4; // pas d'obstacle sur les extrémités de la carte
	printf("%i \n",zone_j);
	
 // initialisation de rand

	for (i=0;i<nb_obstacle;i++){
		coord_x = rand()%((*taille_map)-(2*zone_j))+zone_j; // y et x sont donc entre 24% et 75% de la longueur et largeur
		coord_y = rand()%((*taille_map)-(2*zone_j))+zone_j;
		
		if (tableau[coord_x][coord_y] ==-1){
			i--;	// si un obstacle est deja présent, on recommence
		}
		else{
			tableau[coord_x][coord_y] =-1;

		}
	}
}
