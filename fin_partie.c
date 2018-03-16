#include <stdlib.h>
#include <stdio.h>


/*fonction parcours-récupération des scores */

int vainqueur (int vainqueur, int units_j1, int units_j2){

	if(units_j1==0 && units_j2!=0)
		vainqueur=2;
		
		
	if (units_j1!=0 && units_j2==0)
		vainqueur=1;

	else if(units_j1==0 && units_j2==0)
		vainqueur=3;

	else
		{
			vainqueur=0;
	}
	
	return vainqueur;
}

	

void end ( int vainqueur){
