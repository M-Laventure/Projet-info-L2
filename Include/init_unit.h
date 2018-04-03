void  compo_unit(int **Map, int taille_map, int *credit, int joueur,unite_s *tab,unite_s *tabjoueur);
int verif_credit(int * credit, int credit_unite);
unite_s * init_tab();
unite_s saisie_unite(unite_s * tab);
void add_tab_joueur(unite_s *tab_joueur,unite_s unite_courante, int nb_unite, int joueur);
void coord_unite(int **Map,int taille_map,int nb_unite,unite_s *tabjoueur, int joueur);
void ordre_jeu(unite_s *tab_ordrejeu, unite_s *tab_j1,unite_s *tab_j2);
void place_unite(int **Map,unite_s *tab_ordrejeu );


extern void  compo_unit(int **Map,int taille_map, int *credit, int joueur,unite_s *tab_ref,unite_s *tabjoueur){
	/* cette fonction compose les deux equipes, joueur1 puis joueur2.*/

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
			coord_unite(Map,taille_map,nb_unite,tabjoueur,joueur); //puis on le place sur la map, mais sans distinction avec les autres unites pour le moment
			nb_unite ++;
		}
					
	}
}

extern void coord_unite(int **Map,int taille_map,int nb_unite,unite_s *tabjoueur, int joueur){
/* cette fonction, pour chaque unité selectionner, demande x,y afin de la placer sur la map, et de modifier la structure de l'unite*/
	int x,y;
	int placement;
	do{
	placement=0;
	printf("Coordonnée x: ");	// demande des coordonnées de placements
	scanf("%i",&x); 
	printf("Coordonnée y: ");
	scanf("%i",&y);
	printf("\n");
		if (joueur==1){
			if((y>=0 && y<taille_map)&&(x>=0 && x<(taille_map/4))){
				placement = 1;
			}
		}
		if (joueur==2){
			if((y>=0 && y<taille_map)&&(x<taille_map && x>2*(taille_map/4))){
				placement = 1;
			}
		}

	}while ((!placement || Map[x][y] !=0));

	Map[x][y] = -2;		// -2 etant le numero non affiché, afin que le joueur2 puissse selectionné son equipe sans avantages

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

extern unite_s * init_tab(){
	unite_s * tab_unite = NULL;
	tab_unite = malloc(10*sizeof(unite_s)); //2 structures
//id_j,id_unite,nom,(credit,vie,atq,def,(atq hor,vert),(deplacement),(type,faiblesse,bonus))
	
	unite_s witcher  = {0,0, 0, 3 ,"witcher", {40, 10, 4, 40, {3,1} ,3 }};
	unite_s mage     = {0,0, 1, 1 ,"mage",    {15, 5,  6, 20, {3,1} ,2 }};
	unite_s scoiatel = {0,0, 2, 1 ,"scoiatel",{10, 6,  3, 20, {3,1} ,3 }};
	unite_s nains    = {0,0, 3, 1 ,"nain",    {10, 8,  3, 30, {2,1} ,2 }};
	unite_s spectre  = {0,0, 4, 2 ,"spectre", {10, 6,  2, 40, {3,1} ,3 }};
	unite_s wyvern   = {0,0, 5, 2 ,"wyvern",  {20, 10, 4, 40, {3,1} ,3 }};
	unite_s leshen   = {0,0, 6, 2 ,"leshen",  {15, 8,  4, 40, {3,1} ,2 }};
	unite_s cyclope  = {0,0, 7, 2 ,"cyclope", {15, 10, 4, 30, {2,1} ,2 }};
	unite_s doppler  = {0,0, 8, 3 ,"doppler", {10, 5,  2, 20, {2,1} ,4 }};
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
