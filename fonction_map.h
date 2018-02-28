
/**Prototype à mettre dans un fichier.h**/
int** Map_Maker1(int * ); //fonction qui initialise la carte
void AfficherMap(int **, int * );//fonction qui affiche la carte
int  unitTosize(int *);//fonction redéfinie la taille de la map
void init_obstacle(int **, int *);
void placement_auto1(int **, int *, int * , char );
int placement_manuel(int **, int *, int, int);
void mouv(int **, int *);

/********************Créer MAP*****************************************************/

extern int** Map_Maker1(int * size) {//reçoit un pointeur sur size pour ne rien perdre.

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

/***********************************Afficher la map************************************/

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

/********************************************Taile de la matrice en fonction du nombre d'unité******************************/

extern int  unitTosize(int *nombre_units){	
	int n_units=(*nombre_units);

	int taille_matrice = 4;
	/*A améliorer*/
	
	if(n_units<3){
		taille_matrice = 4;
		}
	else if (n_units<10){
		taille_matrice = 12;
		}

	else {taille_matrice = 24;}

	return taille_matrice;

}


/********************Génération d'obstacles ********************************************/

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



/********************placement_auto***************************************/

extern void placement_auto1(int **tableau, int *taille_map, int * entered_units, char side){
	
	int i=0;
	int coord_y=0;
	int coord_x=0;
	int nombre_units;
	nombre_units=(* entered_units);
	int size_map;
	size_map =(*taille_map);
	int zone_j = (*taille_map)/4;
	printf("%i \n",zone_j);
	int max;
	int min=0;
	
	//choix du côté
	if (side =='g')
	{

		// initialisation de rand
		//rand()%(max-min+1)+min  
		max = zone_j-1;
		for (i=0;i<nombre_units;i++){
			coord_y = rand()%(max-min+1)+min ;  
			coord_x = rand()%(*taille_map);
			if (tableau[coord_x][coord_y] !=0){
				i--;

			}
			else{
				tableau[coord_x][coord_y] =2+i;
			}

		}
	}else{
		// initialisation de rand côté droit
		//rand()%(max-min+1)+min  
		
		max = size_map-1;
		min = 3*zone_j;
		for (i=0;i<nombre_units;i++){
			coord_y = rand()%(max-min+1)+min ; 
			coord_x = rand()%(*taille_map);
			if (tableau[coord_x][coord_y] !=0){
				i--;
			}
			else{
				tableau[coord_x][coord_y] =-2-i;
			}
		}
	}
}

/**********************placement_manuel********************************/

extern int placement_manuel(int **tableau, int *taille_map, int archer_total, int soldat_total){
	int i=0;
	int coord_x=0;
	int coord_y=0;
	int unite_total=archer_total+soldat_total;
	int soldat_pose=0;
	int archer_pose=0;
	int type_unite=0;	
	/* a faire : limite coordxy(limite carte et superposable),ajouter coter*/
	while(i<unite_total){/* Tant que nb d'unités déployable pas atteints */
		printf("Il vous reste %i archer(s) et %i soldat(s) a placer \n",(archer_total-archer_pose),(soldat_total-soldat_pose));
		printf("Donnez le type de l'unité que vous voulez déployer ,2 pour archer,3 pour soldat \n");
		scanf("%i",&type_unite);
		if(type_unite==2){
			if(archer_total==archer_pose){
				printf("Le nombre d'archers total est atteint!\n");
			}
			else{
				printf("Entrez sa position sous la forme 'x,y'\n");
				scanf("%i,%i",&coord_x,&coord_y);
				printf("\n");
					if((coord_y>=1 && coord_y<(*taille_map))&&(coord_x>0 && coord_x<=((*taille_map)/4))){
						if(tableau[coord_y-1][coord_x-1]==0 ){
							tableau[coord_y-1][coord_x-1]=type_unite;
							//creer_unite(type_unite,1,i);
							i++;
							archer_pose ++;
							AfficherMap(tableau,taille_map);
						}
						else{
							printf("Une unité se situe déjà sur cet emplacement, recommencez la saisie.\n");
						}
					}		
					else{
						printf("Vous devez placer une unité dans votre zone de départ, recommencez la saisie.\n");
					}
			}
		}
		if(type_unite==3){
			if(soldat_total==soldat_pose){
				printf("Le nombre de soldats total est atteint!\n");
			}
			else{
				printf("Entrez sa position sous la forme 'x,y'\n");
				scanf("%i,%i",&coord_x,&coord_y);
				printf("\n");
					if((coord_y>=1 && coord_y<(*taille_map))&&(coord_x>0 && coord_x<=((*taille_map)/4))){
						if(tableau[coord_y-1][coord_x-1]==0 ){
							tableau[coord_y-1][coord_x-1]=type_unite;
							i++;
							soldat_pose ++;
							AfficherMap(tableau,taille_map);
						}
						else{
							printf("Une unité se situe déjà sur cet emplacement, recommencez la saisie.\n");
						}
					}		
					else{
						printf("Vous devez placer une unité dans votre zone de départ, recommencez la saisie.\n");
					}
			}
		}
		type_unite=0;		
	}
}




/*******Gestion des mouvements automatiques: version test******************************/
extern void mouv_avancer(int **Map, int *size){

int i, j;
int taille_matrice = (*size); //je stocke la taille, pour eviter de mettre des notations *
	
	for (i=0;i<taille_matrice;i++){
		for(j=0;j<taille_matrice;j++){
			if((Map[i][j]!=0)&&(Map[i][j]!=1)){
				if (Map[i][j-1]==0){
					Map[i][j-1]=Map[i][j];
					Map[i][j]=0;
						
				}
			}
			
	}
		

}}

extern void mouv_reculer(int **Map, int *size){

int i, j;
int taille_matrice = (*size); //je stocke la taille, pour eviter de mettre des notations *
	
	for (i=0;i<taille_matrice;i++){
		for(j=0;j<taille_matrice;j++){
			if((Map[i][j]!=0)&&(Map[i][j]!=1)){
				if (Map[i][j+1]==0){
					Map[i][j+1]=Map[i][j];
					Map[i][j]=0;
						
				}
			}
			
	}
		

}}
