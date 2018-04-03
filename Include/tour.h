void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map);


extern void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map){
	int choix ;
	printf ("Choix: 1 -attaquer, 2 -deplacer,autre -passer\n");
	scanf("%i",&choix);
	if(choix == 1){
		attaquer(tab_ordrejeu, id_unite, Map);
	}
	if(choix == 2){
		deplacer(tab_ordrejeu, id_unite, Map,taille_map); 
		printf(" Choix: 1 -attaquer, autre -passer\n");
		scanf("%i",&choix);
		if (choix==1){
			attaquer(tab_ordrejeu,id_unite, Map);
		}
	}
}
