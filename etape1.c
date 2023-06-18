#include <stdio.h>
#define TAILLE_GRILLE 6


void init_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
void affiche_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);

int main () {
	
	int grille[TAILLE_GRILLE][TAILLE_GRILLE];

	init_grille (grille);
	affiche_grille (grille);

	grille[0][0] = 1;
	grille[0][2] = 2;

	printf("\n");
	affiche_grille (grille);
}