int verif_range_deplacement(int x, int y, int id_unite, unite_s* tab_ordrejeu);
int** Convertit_map(int taille_matrice,int** tab_chemin,int **map, int x_unite, int y_unite,int x_arrivee, int y_arrivee);
int unite_aerien(unite_s* tab_ordrejeu, int id_unite);
int coord_correct(int taille_map,int **map,int id_unite,unite_s *tab_ordrejeu, int x_arrivee, int y_arrivee);
int est_chemin (int **tab_chemin,int taille_matrice,int x_arrivee,int y_arrivee);
void deplacer(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map);
int**Map_Maker(int *taille_matrice);

extern int** Convertit_map(int taille_matrice,int ** tab_chemin,int **map, int x_unite, int y_unite,int x_arrivee, int y_arrivee) { //reçoit un pointeur sur size pour ne rien perdre
/* Cete fonction convertit le plateau en un tableau simplifié ,destiné à la recherche de chemin*/

int i,j;

 	for (i=0;i<taille_matrice;i++)
	{
		for(j=0;j<taille_matrice;j++)
		{			  /*valeur mise à zéro*/
			if (map[i][j] !=0) {
				tab_chemin[i][j]= -1;
			}
			
		}
	tab_chemin[x_unite][y_unite] = 3;
	tab_chemin[x_arrivee][y_arrivee]=2;

   	
	}
	return  tab_chemin;

}


extern int est_chemin (int **tab_chemin,int taille_matrice,int x_arrivee,int y_arrivee){
/* 0 a coté d'un 1 ou 3 se transforme en 10
dans un 2nd parcours les 10 deviennent des 1
on verifie alors s'il y a un 1 a coté du 2 (case départ)
Notre objectif étant de ne transformer que les cases adjacentes en un appel de fonction, on fait deux parcours, sinon le tour de boucle serai affecté par la modification précédente*/
	int i, j;

	for (i=0;i<taille_matrice;i++) // premier parcours
		{
			for(j=0;j<taille_matrice;j++)
			{
			
				if (tab_chemin[i][j]==0){
					if(j>0){
						if ((tab_chemin[i][j-1]==1) || (tab_chemin[i][j-1]==3)){ //case dessus
							tab_chemin[i][j]=10;}
											
					}
					if(j<taille_matrice){
						if ((tab_chemin[i][j+1]==1) || (tab_chemin[i][j+1]==3)){//case dessous
							tab_chemin[i][j]=10;}
					}
					if (i>0){
						if((tab_chemin[i-1][j]==1) || (tab_chemin[i-1][j]==3)){ //case gauche
							tab_chemin[i][j]=10;}
						
					}
	
					if (i<taille_matrice-1){
						if((tab_chemin[i+1][j]==1) || (tab_chemin[i+1][j]==3)){ //case droite
							tab_chemin[i][j]=10;}
							
					}
				}
			}
	}
		
	for (i=0;i<taille_matrice;i++){ //second parcours
		for(j=0;j<taille_matrice;j++){

			if (tab_chemin[i][j]==10)
				tab_chemin[i][j]=1;
		}
	}

	//on verifie si on a un chemuin
	if ((tab_chemin[x_arrivee][y_arrivee+1]==1) || (tab_chemin[x_arrivee][y_arrivee+-1]==1) ||  (tab_chemin[x_arrivee+1][y_arrivee]==1) ||  (tab_chemin[x_arrivee-1][y_arrivee]==1)){
	
		return 1;
	}
	else
		return 0;

}	
			


extern void deplacer(unite_s *tab_ordrejeu, int id_unite, int ** Map, int taille_map){
	int x,y;
	do{
	printf("Coordonnée x: ");
	scanf("%i",&x);
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
	}
	while(!coord_correct(taille_map,Map,id_unite,tab_ordrejeu,x,y));
	printf("changement");
	Map[tab_ordrejeu[id_unite].coord.x][tab_ordrejeu[id_unite].coord.y]=0;
	tab_ordrejeu[id_unite].coord.x=x;
	tab_ordrejeu[id_unite].coord.y=y;
	Map[x][y] = id_unite+1;


	
}
	
	
extern int coord_correct(int taille_map,int **map,int id_unite,unite_s *tab_ordrejeu, int x_arrivee, int y_arrivee){
	if (verif_range_deplacement(x_arrivee, y_arrivee, id_unite, tab_ordrejeu)){
		
		if(map[x_arrivee][y_arrivee]==0){
			
			if (unite_aerien(tab_ordrejeu,id_unite)){
				return 1;
			}
			else{	
			
				int ** map_convertie=NULL ;
				map_convertie = Map_Maker(&taille_map);
				map_convertie = Convertit_map(taille_map,map_convertie,map,tab_ordrejeu[id_unite].coord.x,tab_ordrejeu[id_unite].coord.y,x_arrivee,y_arrivee);
				
				int chemin_possible = 0;

				for(int i=0; i< tab_ordrejeu[id_unite].stats.deplacement;i++){

			
					chemin_possible = est_chemin(map_convertie,taille_map,x_arrivee,y_arrivee);
					if (chemin_possible)
						
						return 1;
				}
			}
		}
	}
	
		
	return 0;
}																													
																												


// Renvoie faux si les coordonnées saisies désignent un obstacle ou une unité	
// si l'unité a déplacer est un spectre ou une wyvern, le déplacement est possible à travers les obstacles et les autres unités	


extern int unite_aerien(unite_s* tab_ordrejeu, int id_unite){

	if(tab_ordrejeu[id_unite-1].id_classe==5||tab_ordrejeu[id_unite-1].id_classe==4)  		
		return 1;																									    						
	else{
		return 0;
	}
}

extern int verif_range_deplacement(int x, int y, int id_unite, unite_s* tab_ordrejeu){ // prends x arrive, y arrivee
	if (abs(tab_ordrejeu[id_unite].coord.x-x)+abs(tab_ordrejeu[id_unite].coord.y-y) <= tab_ordrejeu[id_unite].stats.deplacement){
			return 1;
		}
	else{

		printf("Points de déplacement insuffisants %i \n",tab_ordrejeu[id_unite].stats.deplacement);	

		return 0;
	}
}
