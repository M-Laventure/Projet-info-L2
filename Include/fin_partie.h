int victoire(unite_s *tab_ordrejeu);


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
