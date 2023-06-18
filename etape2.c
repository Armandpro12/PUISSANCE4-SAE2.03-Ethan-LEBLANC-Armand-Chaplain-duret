#include <stdio.h>

#define TAILLE_GRILLE 6


int hauteur_colonne ( int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne );
int poser_jeton (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int joueur);
void init_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
void affiche_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);

int main () {
	
	int grille[TAILLE_GRILLE][TAILLE_GRILLE];

	init_grille (grille);
	affiche_grille (grille);

	printf ("%d\n", poser_jeton ( grille, 0, 1 ) ) ;
	poser_jeton ( grille, 0, 2 );
	printf ("%d", poser_jeton ( grille, 6, 1) );

	printf("\nHauteur colonne : %d\n", hauteur_colonne(grille, 0));

	poser_jeton ( grille, 0, 1 )  ;
	poser_jeton ( grille, 0, 2 )  ;
	poser_jeton ( grille, 0, 1 )  ;
	poser_jeton ( grille, 0, 2 )  ;
	
	printf ("%d", poser_jeton ( grille, 0, 1) );

	printf("\n");
	affiche_grille (grille);
}