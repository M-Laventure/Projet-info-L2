#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char *nom_joueur(){
	char *chaine; // 100 caractères + '\0' terminal
	chaine = malloc(100*sizeof(char));
	printf("Saisissez le nom du joueur (pas plus de 100 car.) : ");
	fgets(chaine, 101, stdin);
	chaine[strlen(chaine)-1]='\0';
	return chaine;
}