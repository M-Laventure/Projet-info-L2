
//**Prototype à mettre dans un fichier.h**/
int** Map_Maker1(int * ); //fonction qui initialise la carte
void AfficherMap(int **, int * );//fonction qui affiche la carte
int  unitTosize(int *);//fonction redéfinie la taille de la map
void init_obstacle(int **, int *);
void placement_auto1(int **, int *, int * , char );
int placement_manuel(int **, int *, int, int);
void  compo_unit(int **Map, int *credit, int joueur,unite_s *tab,unite_s *tabjoueur);
int verif_credit(int * credit, int credit_unite);
unite_s * init_tab();
unite_s saisie_unite(unite_s * tab);
void add_tab_joueur(unite_s *tab_joueur,unite_s unite_courante, int nb_unite, int joueur);
void coord_unite(int **Map,int nb_unite,unite_s *tabjoueur, int joueur);
void ordre_jeu(unite_s *tab_ordrejeu, unite_s *tab_j1,unite_s *tab_j2);
void place_unite(int **Map,unite_s *tab_ordrejeu );
int victoire(unite_s *tab_ordrejeu);
void tour_unite(unite_s *tab_ordrejeu, int id_unite);
void deplacer(unite_s *tab_ordrejeu, int id_unite);
void attaquer(unite_s *tab_ordrejeu, int id_unite);
/********************Créer MAP*****************************************************/

extern int** Map_Maker1(int * size) { //reçoit un pointeur sur size pour ne rien perdre

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
			if (Map[i][j]==-2)
				printf("%4d",0);
			else
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
	
	if(n_units<20){
		taille_matrice = 4;
		}
	else if (n_units<100){
		taille_matrice = 10;
		}

	else {taille_matrice = 20;}

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
		if (tableau[coord_x][coord_y] ==-1){
			i--;
		}
		else{
			tableau[coord_x][coord_y] =-1;

		}
	}
}



extern void  compo_unit(int **Map, int *credit, int joueur,unite_s *tab_ref,unite_s *tabjoueur){
	int num_unite;
	int nb_unite = 0;
	unite_s unite_courante;
	printf("\n composition de l'équipe du joueur %i : %i credits total \n \n", joueur,(*credit));
	for(int i=0; i<9;i++){
		printf("Entrez %i pour deployer %s (cout: %i) \n",i,tab_ref[i].nom,tab_ref[i].stats.credit);
	}
	printf("Entrez 10 pour voir la map\n\n");
	while ((*credit)>5){
		unite_courante = saisie_unite(tab_ref);
		if (verif_credit(credit,unite_courante.stats.credit)){
			add_tab_joueur(tabjoueur,unite_courante,nb_unite,joueur);
			coord_unite(Map,nb_unite,tabjoueur,joueur);
			nb_unite ++;
		}
		else{}
			
	}
}

extern void coord_unite(int **Map,int nb_unite,unite_s *tabjoueur, int joueur){
	int x,y;
	do{
	printf("Coordonnée x: ");
	scanf("%i",&x);
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
	}while (Map[y][x] !=0);

	Map[y][x] = -2;
;
	tabjoueur[nb_unite].coord.x =x;
	tabjoueur[nb_unite].coord.y = y;
	
	
	

}

extern int verif_credit(int * credit, int credit_unite){
	if ((*credit)>=credit_unite){
		*credit= *credit - credit_unite;
		printf("%i crédits restants \n", (*credit));
		return 1;
	}

	else{
		printf(" crédits insuffisants, veuillez choisir un autre type d'unité \n");
		return 0;
	}
		
}

extern unite_s saisie_unite(unite_s *tab){
	int id_unite;
	printf("Selectionnez une unité à déployer \n");
	scanf("%i",&id_unite);
	return tab[id_unite];
}

extern void add_tab_joueur(unite_s *tab_joueur,unite_s unite_courante, int nb_unite, int joueur){
	tab_joueur[nb_unite] = unite_courante;
	tab_joueur[nb_unite].id_joueur = joueur;	
}

extern void ordre_jeu(unite_s *tab_ordrejeu, unite_s *tab_j1,unite_s *tab_j2){
	int id = 1;
	int i =0;
	while (tab_j1[i].id_joueur!= 0 || tab_j2[i].id_joueur !=0){
		if (tab_j1[i].id_joueur !=0){
			tab_j1[i].id_unite = id;
			tab_ordrejeu[id-1]=tab_j1[i];
			id++;
		}
		if (tab_j2[i].id_joueur !=0){
			tab_j2[i].id_unite = id;
			tab_ordrejeu[id-1]=tab_j2[i];
			id++;
		}
		i++;
	} 
}

extern void place_unite(int **Map,unite_s *tab_ordrejeu ){
	int i =0;
	while(tab_ordrejeu[i].id_joueur !=0){
		Map[tab_ordrejeu[i].coord.x][tab_ordrejeu[i].coord.y]=tab_ordrejeu[i].id_unite;
		i++;
	}
}


extern int victoire(unite_s *tab_ordrejeu){
	int i =0;
	int vict_j1= 1 ;
	int vict_j2= 1 ;
	while(tab_ordrejeu[i].id_joueur !=0){
		if (tab_ordrejeu[i].id_joueur==1 && tab_ordrejeu[i].stats.lp !=0)
			vict_j2 =0;
		if (tab_ordrejeu[i].id_joueur==2 && tab_ordrejeu[i].stats.lp !=0)
			vict_j1 =0;
		i++;
	}
	return (vict_j1 && vict_j2);
}
extern void tour_unite(unite_s *tab_ordrejeu, int id_unite){
	int choix ;
	printf ("Choix: 1 -attaquer, 2 -deplacer,autre -passer\n");
	scanf("%i",&choix);
	if(choix == 1){
		attaquer(tab_ordrejeu, id_unite);
	}
	if(choix == 2){
		deplacer(tab_ordrejeu, id_unite); 
		printf(" Choix: 1 -attaquer, autre -passer\n");
		scanf("%i",&choix);
		if (choix==1){
			attaquer(tab_ordrejeu,id_unite);
		}
	}
}


extern void deplacer(unite_s *tab_ordrejeu, int id_unite){
	printf("deplacement echoué \n");
}

	/*int x,y;
	do{
	printf("Coordonnée x: ");
	scanf("%i",&x);
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
	}
	while(!verif_chemin()||!verif_verif_range_deplacement(int x, int y))
		
}		
	
	
extern int verif_range_deplacement(int x, int y, unite_s* tab_ordrejeu){
		if (abs(tab_ordrejeu[id_unite].coord.x-x)+abs(tab_ordrejeu[id_unite].coord.y-y) <= tab_ordrejeu[id_unite].stats.deplacement.portee_hor+ tab_ordrejeu[id_unite].stats.deplacement.portee_vert){
			return 1;
		}
		else{
			printf("Points de déplacement insuffisants");
			return 0;
		}

}
	//Un cas particulier si tab_ordrejeu[id_unite].nom== wyvern ou spectre
	//algo : |coord_depart x-coord_arrivé x|+|coord_depart y-coord_arrivé y| <= points de déplacement 
		alors return 1;
		
		si coord ordonné*/
	

extern void attaquer(unite_s *tab_ordrejeu, int id_unite){
	printf("attaque échouée \n");
}

extern unite_s * init_tab(){
	unite_s * tab_unite = NULL;
	tab_unite = malloc(10*sizeof(unite_s)); //2 structures
//id_j,id_unite,nom,(credit,lp,atq,def,(atq hor,vert,diag),(dep hor,vert,diag),(type,faiblesse,bonus))
	
	unite_s witcher  = {0,0, 0, "witcher", {40, 10, 4, 4, {3,1,1} ,{3,1,1} ,{3,3,0} },{0,0}};
	unite_s mage     = {0,0 ,1, "mage",    {15, 5,  6, 2, {3,1,1} ,{2,1,1} ,{1,2,2} }};
	unite_s scoiatel = {0,0 ,2, "scoiatel",{10, 6,  3, 2, {3,1,1} ,{3,1,1} ,{1,2,2} }};
	unite_s nains    = {0,0,3, "nain",   {10, 8,  3, 3, {2,1,1} ,{2,1,1} ,{1,2,2} }};
	unite_s spectre  = {0,0, 4, "spectre", {10, 6,  2, 4, {3,1,1} ,{3,1,1} ,{2,1,1} }};
	unite_s wyvern   = {0,0, 5, "wyvern",  {20, 10, 4, 4, {3,1,1} ,{3,1,1} ,{2,1,1} }};
	unite_s leshen   = {0,0, 6, "leshen",  {15, 8,  4, 4, {3,1,1} ,{2,1,1} ,{2,1,1} }};
	unite_s cyclope  = {0,0, 7, "cyclope", {15, 10, 4, 3, {2,1,1} ,{2,1,1} ,{2,1,1} }};
	unite_s doppler  = {0,0, 8, "doppler", {10, 5,  2, 2, {2,1,1} ,{4,1,1} ,{3,3,0} }};
	tab_unite[0] = witcher ;
	tab_unite[1] = mage ;
	tab_unite[2] = scoiatel ;
	tab_unite[3] = nains ;
	tab_unite[4] = spectre ;
	tab_unite[5] = wyvern ;
	tab_unite[6] = leshen ;
	tab_unite[7] = cyclope ;
	tab_unite[8] = doppler ;
	
	return tab_unite;

}

