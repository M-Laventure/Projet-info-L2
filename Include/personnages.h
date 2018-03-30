#include <stdlib.h> 
#include <stdio.h>
#define N 100
//typedef enum {witcher, mage, scoiatel, nains, spectre, wyvern, goule, leshen , cyclope, doppler} id_classe;


//Chaque unité possède une certaine portée d'attaque verticale et horizontale

typedef struct {
 int hor;
 int vert;
} range;


typedef struct
	{
		int credit;
		int vie;
		int atq;
		int def;
		range portee_attaque;
		int deplacement;
	}	unite_stats;

typedef struct{
	int x;
	int y;
	} unite_coord;

typedef struct{
	 
	 int id_joueur;
	 int id_unite ;
	 int id_classe;
	 int type;      //0 les deux, 1 humanoide, 2 monstre
	 char nom[20];
  	 unite_stats stats;
	 unite_coord coord;
} unite_s ;
