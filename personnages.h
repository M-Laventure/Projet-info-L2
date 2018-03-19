#include <stdlib.h> 
#include <stdio.h>

#define MAX_WITCHER 20
#define MAX_MAGE 15 
#define SCOIATEL 10 
#define NAIN 10
#define SPECTRE 10
#define MAX_WYVERN 20
#define MAX_LESHEN 15
#define MAX_CYCLOPE 10
#define MAX_DOPPLER 10

#define N 10


	
/*
typedef enum {witcher, mage, scoiatel, nains, spectre, wyvern, goule, leshen , cyclope, doppler} id_unite;
*/	
typedef struct{
	
	int id_type; //0 les deux, 1 humanoide, 2 monstre
	int bonus;
	int faiblesse;
} type;
 
 
typedef struct {
 int portee_hor;
 int portee_vert;
 int portee_diag;
} range;
/*typedef enum {
		aveuglement, poison, immobilisation, etourdissement
}*/
typedef struct
	{
		int credit;
		int lp;
		int atq;
		int def;
		range attaque;
		range deplacement;
		type character;
		/*alteration capacite_spe;*/
	}	unite_stats;


typedef struct 
 {
	 
	 int id_joueur;
	 int id_unite ;
	// stats caracteristiques;//
	 char nom[20];
  	 unite_stats stats;
	
	 } unite_s ;
	 
	 

