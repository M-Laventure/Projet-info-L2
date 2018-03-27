#include <stdlib.h> 
#include <stdio.h>

	
/*
typedef enum {witcher, mage, scoiatel, nains, spectre, wyvern, goule, leshen , cyclope, doppler} id_unite;
*/	
typedef struct{
	
	int id_type; //0 les deux, 1 humanoide, 2 monstre
	int bonus;
	int faiblesse;
} type;

 
 
//Chaque unité possède une certaine portée d'attaque verticale et horizontale

typedef struct {
 int hor;
 int vert;
} range;
/*typedef enum {
		aveuglement, poison, immobilisation, etourdissement
}*/
typedef struct
	{
		int credit;
		int vie;
		int atq;
		int def;
		range portee_attaque;
		int deplacement;
		type character;
		/*alteration capacite_spe;*/
	}	unite_stats;

typedef struct{
	int x;
	int y;
	} unite_coord;

typedef struct{
	 
	 int id_joueur;
	 int id_unite ;
	 int id_classe;
	// stats caracteristiques;//
	 char nom[20];
  	 unite_stats stats;
	 unite_coord coord;
	
	 } unite_s ;
	 
	 

