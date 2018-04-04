void attaquer(unite_s *tab_ordrejeu, int id_unite, int **Map);
void calcul_dmg(unite_s *tab_ordrejeu, int id_unite, int id_cible);
int block(unite_s *tab_ordrejeu, int id_cible);
int trajectoire_bloque(int **Map, unite_s *tab_ordrejeu, int id_cible, int id_unite);
int est_a_portee(unite_s *tab_ordrejeu, int **Map, int id_unite, int id_cible);
int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible);




extern void attaquer(unite_s*tab_ordrejeu, int id_unite, int **Map){
/* fonction principale de la mise en oeuvre de l'attaque*/
	
	int id_cible;
	printf("entrez id_cible : "); // on demande l'id de la cible
	scanf("%i", &id_cible);
		if(est_a_portee(tab_ordrejeu, Map, id_unite, id_cible-1)){ // on vérifie si la portée de l'unité permet l'attaque sur la cible
			if(!block(tab_ordrejeu, id_cible)){ //determine si l'attaque est bloquée ou non
				calcul_dmg(tab_ordrejeu, id_unite, id_cible-1); //non bloquée, donc on autorise l'attaque
				printf("l'attaque est passée");
			}
			else{ 
				printf("\n attaque bloquée");
			}
		}
		else{
			printf("cible incorrecte ou trop éloignée \n");
		}
}

int est_a_portee(unite_s *tab_ordrejeu,int **Map, int id_unite, int id_cible){
	/* cette fonction determine si la portée de l'unité permet l'attaque de la cible*/
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
			
		if(tab_ordrejeu[id_unite].coord.y == tab_ordrejeu[id_cible].coord.y){
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
	/*cette fonction dertermine si un obstacle est sur la trajectoire*/
	if(tab_ordrejeu[id_unite].coord.y < tab_ordrejeu[id_cible].coord.y){
		int ytemp = tab_ordrejeu[id_unite].coord.y;
		while(ytemp!=tab_ordrejeu[id_cible].coord.y){
			ytemp++;
			if(Map[tab_ordrejeu[id_unite].coord.x][ytemp]!=0){
				return 0;
				
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
	/* cette fonction détermine si l'attaque est bloquée*/
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
	printf("%i degats sur %i pv",degats, tab_ordrejeu[id_cible].stats.vie);
	tab_ordrejeu[id_unite].stats.vie= tab_ordrejeu[id_cible].stats.vie - degats;
	if (tab_ordrejeu[id_cible].stats.vie<1){
		printf("L'unite adverse est morte");
	}
	
}

extern int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible){
	if ((tab_ordrejeu[id_unite].type + tab_ordrejeu[id_cible].type==3)||(tab_ordrejeu[id_unite].type ==3)){
		return 1;
	}
	else{
	 return 0;
	}
} 


