/* Mise en oeuvre attaque */
void attaquer(unite_s *tab_ordrejeu, int id_unite, int **Map);
void calcul_dmg(unite_s *tab_ordrejeu, int id_unite, int id_cible);
int block(unite_s *tab_ordrejeu, int id_cible);
int trajectoire_bloque(int **Map, unite_s *tab_ordrejeu, int id_cible, int id_unite);
int est_a_portee(unite_s *tab_ordrejeu, int **Map, int id_unite, int id_cible);
int est_vulnerable(unite_s *tab_ordrejeu, int id_unite, int id_cible);

