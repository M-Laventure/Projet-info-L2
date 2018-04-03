/* Mise en oeuvre attaque */
void attaquer(unite_s *tab_ordrejeu, int id_unite, int **Map);
void calcul_dmg(unite_s *tab_ordrejeu, int id_unite, int id_cible);
int block(unite_s *tab_ordrejeu, int id_cible);
int trajectoire_bloque(int **Map, unite_s *tab_ordrejeu, int id_cible, int id_unite);
int est_a_portee(unite_s *tab_ordrejeu, int **Map, int id_unite, int id_cible);
int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible);


extern void attaquer(unite_s *tab_ordrejeu, int id_unite, int **Map){
	int id_cible;
	printf("defense %i\n", tab_ordrejeu[id_unite].stats.def);
	printf("Saisir l'id de l'unité à attaquer \n");
	for (int i=0;i<9;i++){
		if(id_unite != i){
			if(est_a_portee(tab_ordrejeu, Map, id_unite, i)){
				printf("Attaquer %i \n", tab_ordrejeu[i].id_unite);
			}
		}
	}
	scanf("%i", &id_cible);
	printf("cible : vie : %i   def : %i \n", tab_ordrejeu[id_cible].stats.vie,tab_ordrejeu[id_cible].stats.def);
	if(block(tab_ordrejeu, id_cible)){
		printf("l'attaque a été bloqué \n");
	}
	else{
		printf("l'attaque a atteint sa cible \n");
		calcul_dmg(tab_ordrejeu, id_unite, id_cible);
	}
}

int est_a_portee(unite_s *tab_ordrejeu,int **Map, int id_unite, int id_cible){
		if(tab_ordrejeu[id_unite].coord.x == tab_ordrejeu[id_cible].coord.x ){
			if(abs(tab_ordrejeu[id_unite].coord.y-tab_ordrejeu[id_cible].coord.y)<=tab_ordrejeu[id_unite].stats.portee_attaque.vert){
				if(tab_ordrejeu[id_unite].id_classe==4 || tab_ordrejeu[id_unite].id_classe==5){
					return 1;
				}
				
				else{
					return trajectoire_bloque(Map, tab_ordrejeu, id_cible, id_unite);
				}
			}
			else{
				return 0;
			}
		}
			
		if(tab_ordrejeu[id_unite].coord.y == tab_ordrejeu[id_cible-1].coord.y){
			if(abs(tab_ordrejeu[id_unite].coord.x-tab_ordrejeu[id_cible].coord.x)<=tab_ordrejeu[id_unite].stats.portee_attaque.hor){
				if(tab_ordrejeu[id_unite].id_classe==4 || tab_ordrejeu[id_unite].id_classe==5){
					return 1;
				}
			else{
				return trajectoire_bloque(Map, tab_ordrejeu, id_cible, id_unite);
			}
		}
		
		else {
			return 0;
		}
	}
	else{
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
	}
			
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
	else{
		return 0;
	}
}



/*------------Mise en oeuvre calcul_dmg---------------------*/

extern int block(unite_s *tab_ordrejeu, int id_cible){
	int defense_cible=tab_ordrejeu[id_cible].stats.def;
	int blocage;
	srand(time(NULL));
	blocage= rand() % N;
	printf("%i \n", blocage);
	if(blocage<=defense_cible){
		return 1;
	}
	else {
		return 0;
	}
}


extern void calcul_dmg(unite_s *tab_ordrejeu, int id_unite, int id_cible){
	int degats;
	degats=tab_ordrejeu[id_unite].stats.atq + est_vulnerable(tab_ordrejeu, id_unite, id_cible);
	tab_ordrejeu[id_unite].stats.vie= tab_ordrejeu[id_unite].stats.vie - degats;
}

extern int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible){
	if (tab_ordrejeu[id_unite].type==1 && tab_ordrejeu[id_cible].type==2){
		return 1;
	}
	if (tab_ordrejeu[id_unite].type==2 && tab_ordrejeu[id_cible].type==1){
		return 1;
	}
	if (tab_ordrejeu[id_unite].type==0){
		return 1;
	}
	else{
	 return 0;
	}
} 


