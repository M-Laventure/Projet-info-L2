#include <stdlib.h>
#include <stdio.h>

typedef struct unite unite;
	 struct unite
	 {
	 int id_type;
	 int * id_joueur;
	 int * id_unite;
	 int atq;
	 int lp;
	 int range;
	 } ;


struct unite soldats={
	.id_type=3;
	.id_joueur;
	.id_unite;
	.atq=2;
	.lp=4;
	.range=1;
};



struct unite archers={
	.id_type=2;
	.id_joueur;
	.id_unite;
   .atq=1;
	.lp=2;
	.range=3;
};


int main(){

	unite soldat;
	unite archer;
	printf("%d\n", soldat.atq);
}
