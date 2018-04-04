void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map);
void deplacer(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map);
void attaquer(unite_s *tab_ordrejeu, int id_unite, int **Map);


extern void tour_unite(unite_s *tab_ordrejeu, int id_unite, int **Map,int taille_map){
	/*cette fonction gère le tour d'une unité donné*/
	int choix ;
	printf ("Choix: 1 -attaquer, 2 -deplacer,autre -passer\n"); // autre doit tout de même rester un nombre
	scanf("%i",&choix);
	if(choix == 1){
		attaquer(tab_ordrejeu, id_unite, Map); // le tour prends fin car pas de déplacements après une attaque (cf règles)
	}
	if(choix == 2){
		deplacer(tab_ordrejeu, id_unite, Map,taille_map); 
		printf(" Choix: 1 -attaquer, autre -passer\n"); //impossible de se déplacer deux fois de suite
		scanf("%i",&choix);
		if (choix==1){
			attaquer(tab_ordrejeu,id_unite, Map);
		}
	}
}
