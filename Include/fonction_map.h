
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
void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map);
void deplacer(unite_s *tab_ordrejeu, int id_unite, int **Map);
void attaquer(unite_s *tab_ordrejeu, int id_unite);
int verif_range_deplacement(int x, int y, int id_unite, unite_s* tab_ordrejeu);
int** Convertit_map(int taille_matrice,**map, int x_unite, int y_unite,int x_arrivee, int y_arrivee);
int est_chemin (int **tab_chemin,int taille_matrice,int x_arrivee,int y_arrivee);

/* Mise en oeuvre attaque */
//void calcul_dmg(*tab_ordrejeu, id_unite, id_cible);
//int trajectoire_bloque(int **Map,unite_s *tab_ordrejeu, int id_cible, int id_unite);
//int est_a_portée(unite_s *tab_ordrejeu, int id_unite, int id_cible);

/* Mise en oeuvre deplacement */
int est_libre(unite_s* tab_ordrejeu, int id_unite)

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



extern void  compo_unit(int **Map, int *credit, int joueur,unite_s *tab_ref,unite_s *tabjoueur){
	/* cette fonction compose les deux equipes, joueur1 puis joueur2.*/
	int num_unite;
	int nb_unite = 0;
	unite_s unite_courante;
	printf("\n composition de l'équipe du joueur %i : %i credits total \n \n", joueur,(*credit));
	for(int i=0; i<9;i++){
		printf("Entrez %i pour deployer %s (cout: %i) \n",i,tab_ref[i].nom,tab_ref[i].stats.credit);
	}
	printf("Entrez 10 pour voir la map\n\n");
	while ((*credit)>9){	//10 etant le coût de l'unite la plus basse
		unite_courante = saisie_unite(tab_ref);
		if (verif_credit(credit,unite_courante.stats.credit)){ // verification credit>= cout de l'unite
			add_tab_joueur(tabjoueur,unite_courante,nb_unite,joueur); // si oui, on l'insère dans le tab du joueur associé
			coord_unite(Map,nb_unite,tabjoueur,joueur); //puis on le place sur la map, mais sans distinction avec les autres unites pour le moment
			nb_unite ++;
		}
		else{}
			
	}
}

extern void coord_unite(int **Map,int nb_unite,unite_s *tabjoueur, int joueur){
/* cette fonction, pour chaque unité selectionner, demande x,y afin de la placer sur la map, et de modifier la structure de l'unite*/
	int x,y;
	do{
	printf("Coordonnée x: ");	// demande des coordonnées de placements
	scanf("%i",&x);
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
	}while (Map[y][x] !=0);

	Map[y][x] = -2;		// -2 etant le numero non affiché, afin que le joueur2 puissse selectionné son equipe sans avantages
;
	tabjoueur[nb_unite].coord.x =x;
	tabjoueur[nb_unite].coord.y = y;
	
	
	

}

extern int verif_credit(int * credit, int credit_unite){
/* cette fonction vérifie si l'unite selectionné peut etre acheté par le joueur*/
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
/* a partir du numero rentré par le joueur, cette fonction nous retourne l'unite associé (toutes etant référencé dans tab_ref)*/
	int id_unite;
	printf("Selectionnez une unité à déployer \n");
	scanf("%i",&id_unite);
	return tab[id_unite];
}

extern void add_tab_joueur(unite_s *tab_joueur,unite_s unite_courante, int nb_unite, int joueur){
/* cette fonction ajoute l'unite selectionner dans le tableau ordre_de_jeu, en distinguant j1 et j2*/
	tab_joueur[nb_unite] = unite_courante;
	tab_joueur[nb_unite].id_joueur = joueur;	
}

extern void ordre_jeu(unite_s *tab_ordrejeu, unite_s *tab_j1,unite_s *tab_j2){
/* cette fonction creer un tableau contenant les unités du joueur1 et 2, de manière alterné (entassement à la fin si difference de taille)*/
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
/* cette fonction place les unites (cette fois non caché et de manière définitive) sur la  map*/
	int i =0;
	while(tab_ordrejeu[i].id_joueur !=0){
		Map[tab_ordrejeu[i].coord.x][tab_ordrejeu[i].coord.y]=tab_ordrejeu[i].id_unite;
		i++;
	}
}


extern int victoire(unite_s *tab_ordrejeu){
/* cette fonction renvoit 1 si un gagnant existe, 0 sinon*/
	int i =0;
	int vict_j1= 1 ;
	int vict_j2= 1 ;
	while(tab_ordrejeu[i].id_joueur !=0){
		if (tab_ordrejeu[i].id_joueur==1 && tab_ordrejeu[i].stats.vie !=0)
			vict_j2 =0;
		if (tab_ordrejeu[i].id_joueur==2 && tab_ordrejeu[i].stats.vie !=0)
			vict_j1 =0;
		i++;
	}
	return (vict_j1 || vict_j2);
}
extern void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map){
	int choix ;
	printf ("Choix: 1 -attaquer, 2 -deplacer,autre -passer\n");
	scanf("%i",&choix);
	if(choix == 1){
		attaquer(tab_ordrejeu, id_unite);
	}
	if(choix == 2){
		deplacer(tab_ordrejeu, id_unite, Map); 
		printf(" Choix: 1 -attaquer, autre -passer\n");
		scanf("%i",&choix);
		if (choix==1){
			attaquer(tab_ordrejeu,id_unite);
		}
	}
}



extern int** Convertit_map(int taille_matrice,**map, int x_unite, int y_unite,int x_arrivee, int y_arrivee) { //reçoit un pointeur sur size pour ne rien perdre
/* Cete fonction convertit le plateau en un tableau simplifié ,destiné à la recherche de chemin*/
int **tab_chemin;
int i,j;

tab_chemin = malloc(taille_matrice*sizeof(int*));
/*on alloue une valeur à la matrice**/
	if (tab_chemin ==NULL){
	printf("Allocation impossible\n");
	exit(EXIT_FAILURE);

	}
 	for (i=0;i<taille_matrice;i++)
	{
		tab_chemin[i] = malloc(taille_matrice*sizeof(int));
		for(j=0;j<taille_matrice;j++)
		{
			
			tab_chemin[i][j]=0;  /*valeur mise à zéro*/
			if Map[i][j] !=0 {
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
					if (j>0)&&((tab_chemin[i][j+1]==1) || (tab_chemin[i][j+1]==2)) //case dessus
						tab_chemin[i][j]==10;
					if (j<taille_matrice)&&((tab_chemin[i][j-1]==1) || (tab_chemin[i][j-1]==2))//case dessous
						tab_chemin[i][j]==10;
					if (i>0)&&((tab_chemin[i-1][j]==1) || (tab_chemin[i-1][j]==2)) //case gauche
						tab_chemin[i][j]==10;
					if (i<taille_matrice)&&((tab_chemin[i+1][j]==1) || (tab_chemin[i+1][j]==2)) //case droite
						tab_chemin[i][j]==10;
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
	if ((tab_chemin[x_arrivee][y_arrivee+1]==1) || (tab_chemin[x_arrivee][y_arrivee+-1]==1) ||  (tab_chemin[x_arrivee+1][y_arrivee]==1) ||  (tab_chemin[x_arrivee-1][y_arrivee]==1))
		return 1;
	else
		return 0;
}	
			


extern void deplacer(unite_s *tab_ordrejeu, int id_unite, int ** Map){
	int x,y;
	do{
	printf("Coordonnée x: ");
	scanf("%i",&x);
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
	}
	while(!verif_range_deplacement(x, y, id_unite, tab_ordrejeu)|| Map[x][y]!=0);
	}
	
	/*Map[tab_ordrejeu[id_unite-1].coord.x][tab_ordrejeu[id_unite-1].coord.y]=0;
	
	tab_ordrejeu[id_unite-1].coord.x=x;
	tab_ordrejeu[id_unite-1].coord.y=y;
	printf("%i",id_unite);
	Map[x][y]=id_unite;
}*/
	
	
	
	 																													/* Vérifie que les coordonnées saisies par le 																															joueur  permettent le déplacement : on ne peut  																										          	saisir des coordonnées où se trouve un obstacle  																											            ou une unité*/ 
	 																													
																												



// Renvoie faux si les coordonnées saisies désignent un obstacle ou une unité	
// si l'unité a déplacer est un spectre ou une wyvern, le déplacement est possible à travers les obstacles et les autres unités	


int est_libre(unite_s* tab_ordrejeu, int id_unite){
	if(tab_ordrejeu[id_unite].id_classe==5||tab_ordrejeu[id_unite].id_classe==4){  		
		return 1;																									    						
	}
	else{
		return 0;
	}
}

extern int verif_range_deplacement(int x, int y, int id_unite, unite_s* tab_ordrejeu){
	if (abs(tab_ordrejeu[id_unite].coord.x-x)+abs(tab_ordrejeu[id_unite].coord.y-y) <= tab_ordrejeu[id_unite].stats.deplacement){
			return 1;
		}
	else{
		printf("Points de déplacement insuffisants \n");	
		return 0;
	}
}



	//Un cas particulier si tab_ordrejeu[id_unite].nom== wyvern ou spectre
	//algo : |coord_depart x-coord_arrivé x|+|coord_depart y-coord_arrivé y| <= points de déplacement 
	/*	alors return 1;
		
		si coord ordonné*/
	


extern void attaquer(unite_s *tab_ordrejeu, int id_unite){
	int id_cible;
	printf("Saisir l'id de l'unité à attaquer");
}
	/*for (int i=0;i<9;i++){
		if(est_a_portee(tab_ordrejeu,id_unite,i){
			printf("Attaquer %i \n", tab_ordrejeu[i].id_unite);
		}
	}
	scanf("%i", &id_cible);
	calcul_dmg(*tab_ordrejeu, id_unite, id_cible);
	printf("attaque échouée \n");
}
*/
/*Vérifie d'abord si l'unité possède assez de portée verticale ou horizontale pour atteindre la cible
si la portée est suffisante vérifie si son champ d'attaque n'est pas bloqué par un obstacle (objet !=0 sur la map) 
Cas particulier : si l'unité courante est une wyvern ou un spectre, on vérifie seulement la portée'*/

/*
int est_a_portee(unite_s *tab_ordrejeu, int id_unite, int id_cible){
		if(tab_ordrejeu[id_unite].coord.x == tab_ordrejeu[id_cible].coord.x ){
			if(abs(tab_ordrejeu[id_unite].coord.y-tab_ordrejeu[id_cible].coord.y)<=tab_ordrejeu[id_unite].stats.portee_attaque.vert){
				if(tab_ordrejeu[id_unite].id_classe==4 || tab_ordrejeu[id_unite].id_classe==5){
					return 1;
				}
				
				else{
					return trajectoire_bloque(**Map, *tab_ordrejeu, id_cible, id_unite);
				}
			}
			else{
				return 0;
			}
		}
			
		if(tab_joueur[id_unite].coord.y == tab_ordrejeu[id_cible].coord.y){
			if(abs(tab_ordrejeu[id_unite].coord.x-tab_ordrejeu[id_cible].coord.x)<=tab_ordrejeu[id_unite].stats.portee_attaque.hor){
				if(tab_ordrejeu[id_unite].id_classe==4 || tab_ordrejeu[id_unite].id_classe==5){
					return 1;
				}
			else{
				return trajectoire_bloque(**Map, *tab_ordrejeu, id_cible, id_unite);
			}
		}
		
		else {
			return 0;
		}
}

int trajectoire_bloque(int **Map,unite_s *tab_ordrejeu, int id_cible, int id_unite){

	if(tab_ordrejeu[id_unite].coord.y < tab_ordrejeu[id_cible].coord.y){
		int ytemp = tab_ordrejeu[id_unite].coord.y;
		while(ytemp!=tab_ordrejeu[id_cible].coord.y){
			ytemp++;
			if(Map[tab_ordrejeu[id_unite].coord.x][ytemp]!=0){
				return 0;
				break;
			}
		}
		return 1 ;
	}
	
	 if (tab_ordrejeu[id_unite].coord.y > tab_ordrejeu[id_cible].coord.y){
		int ytemp = tab_ordrejeu[id_unite].coord.y;
		while(ytemp!=tab_ordrejeu[id_cible].coord.y){
			ytemp--;
			if(Map[tab_ordrejeu[id_unite].coord.x][ytemp]!=0){
				return 0;
				break;
			}
		}
		return 1;
		
	if(tab_ordrejeu[id_unite].coord.x < tab_ordrejeu[id_cible].coord.x){
		int xtemp = tab_ordrejeu[id_unite].coord.x;
		while(xtemp!=tab_ordrejeu[id_cible].coord.x){
			xtemp++;
			if(Map[xtemp][tab_ordrejeu[id_unite].coord.y]!=0){
				return 0;
				break;
			}
		}
		return 1 ;
	}

	if(tab_ordrejeu[id_unite].coord.x > tab_ordrejeu[id_cible].coord.x){
		int xtemp = tab_ordrejeu[id_unite].coord.x;
		while(xtemp!=tab_ordrejeu[id_cible].coord.x){
			xtemp--;
			if(Map[xtemp][tab_ordrejeu[id_unite].coord.y]!=0){
				return 0;
				break;
			}
		}
		return 1 ;
	}
}

/*
int attaque_possible(unite_s *tab_ordrejeu, int id_unite, int id_cible){
	if(tab_ordrejeu[id_unite].id_classe==4 || tab_ordrejeu[id_unite].id_classe==5)
		return est_a_portee(tab_ordrejeu, id_unite, id_cible);
	else{
		if(est_a_portee(tab_ordrejeu, id_unite, id_cible)){
		
		}
	}
}*/

/*------------Mise en oeuvre calcul_dmg---------------------*/

/*
void calcul_dmg(*tab_ordrejeu, id_unite, id_cible){
	int degats;
	degats=(tab_ordrejeu[id_unite].atq -rand(0,tab_ordrejeu[id_cible].stats.def)) + est_vulnerable(tab_ordrejeu, id_unite, id_cible);
	*tab_ordrejeu[id_unite].stats.vie= *tab_ordrejeu[id_unite].stats.vie - degats;
}

int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible){
	if (tab_ordrejeu[id_unite].type.id_type=1 && tab_ordrejeu[id_cible].type.id_type=2)
		return 1;
	if (tab_ordrejeu[id_unite].type.id_type=2 && tab_ordrejeu[id_cible].type.id_type=1)
		return 1;
		
	if (tab_ordrejeu[id_unite].type.id_type=0)
		return 1;
	
	else{
	 return 0;
	}
}

*/
	

extern unite_s * init_tab(){
	unite_s * tab_unite = NULL;
	tab_unite = malloc(10*sizeof(unite_s)); //2 structures
//id_j,id_unite,nom,(credit,lp,atq,def,(atq hor,vert),(deplacement),(type,faiblesse,bonus))
	
	unite_s witcher  = {0,0, 0, "witcher", {40, 10, 4, 4, {3,1} ,3 ,{3,3,0} },{0,0}};
	unite_s mage     = {0,0, 1, "mage",    {15, 5,  6, 2, {3,1} ,2 ,{1,2,2} }};
	unite_s scoiatel = {0,0 ,2, "scoiatel",{10, 6,  3, 2, {3,1} ,3 ,{1,2,2} }};
	unite_s nains    = {0,0, 3, "nain",    {10, 8,  3, 3, {2,1} ,2 ,{1,2,2} }};
	unite_s spectre  = {0,0, 4, "spectre", {10, 6,  2, 4, {3,1} ,3 ,{2,1,1} }};
	unite_s wyvern   = {0,0, 5, "wyvern",  {20, 10, 4, 4, {3,1} ,3 ,{2,1,1} }};
	unite_s leshen   = {0,0, 6, "leshen",  {15, 8,  4, 4, {3,1} ,2 ,{2,1,1} }};
	unite_s cyclope  = {0,0, 7, "cyclope", {15, 10, 4, 3, {2,1} ,2 ,{2,1,1} }};
	unite_s doppler  = {0,0, 8, "doppler", {10, 5,  2, 2, {2,1} ,4 ,{3,3,0} }};
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

