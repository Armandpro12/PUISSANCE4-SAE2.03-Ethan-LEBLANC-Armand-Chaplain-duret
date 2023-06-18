#include <stdio.h>
#define TAILLE_GRILLE 6


int verifie_gagneDiagonale2 (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur);
int verifie_gagneDiagonale1 (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur);
int verifie_gagneHorizontale (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur);
int verifie_gagne (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne,int ligne, int joueur);
int scan_colonne(int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
int hauteur_colonne(int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne );
int poser_jeton(int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int joueur);
void init_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);
void affiche_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]);

int main () {
	
	int grille[TAILLE_GRILLE][TAILLE_GRILLE];
	
	init_grille (grille);
	
	int joueur;
	int nbCoups = 0;
	int colonne;
	affiche_grille (grille);
	
	do {
		colonne = scan_colonne(grille);
		if (nbCoups %2 == 0){
			joueur = 1;
			poser_jeton(grille, colonne, 1);
		}
		else {
			joueur = 2;
			poser_jeton(grille, colonne, 2);
		
		}
		nbCoups++;
		affiche_grille (grille);
	} while(nbCoups < TAILLE_GRILLE * TAILLE_GRILLE && verifie_gagne(grille, colonne, hauteur_colonne(grille, colonne) - 1, joueur) == 0);
	
	if (verifie_gagne(grille, colonne, hauteur_colonne(grille, colonne) - 1, 1) == 1) {
	
		printf("\nLe joueur 1 a gagné\n");
	}
	
	else if (verifie_gagne(grille, colonne, hauteur_colonne(grille, colonne) - 1, 2) == 2) {
	
		printf("\nLe joueur 2 a gagné\n");
	}
	else {
		printf("\nEgalité\n");
	
	}
	
	
}

void init_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]) {

	int ligne;
	int colonne;
	
	for (ligne = 0; ligne < TAILLE_GRILLE; ligne++) {	
		
		for (colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
			grille[ligne][colonne] = 0;
			
		}
	}
}

void affiche_grille (int grille[TAILLE_GRILLE][TAILLE_GRILLE]) {

	int ligne;
	int colonne;
	
	for (ligne = TAILLE_GRILLE-1; ligne > -1; ligne--) {	
		
		for (colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
			printf("|");
			if (grille[ligne][colonne] == 0) {
				
				printf(" ");
			}
			else if (grille[ligne][colonne] == 1) {
				printf("O");
			}
			else {
				printf("X");
			}
			
		}
		printf("|");
		printf("\n");
	}
}
	
int hauteur_colonne (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne ) {

	int ligne = 0;
	while (grille[ligne][colonne] != 0 && ligne < TAILLE_GRILLE + 1) {
		ligne++;

	}
	if(ligne < TAILLE_GRILLE){
		return ligne;
	} else {
		return TAILLE_GRILLE;
	}

	
}


int poser_jeton (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int joueur) {

	if (hauteur_colonne(grille, colonne) < TAILLE_GRILLE && grille[hauteur_colonne(grille, colonne)][colonne] == 0 && colonne < TAILLE_GRILLE) {
		
		if (joueur == 1) {
		
			grille[hauteur_colonne(grille, colonne)][colonne] = 1;
		}
		else {
		
			grille[hauteur_colonne(grille, colonne)][colonne] = 2;
		}
	
		return hauteur_colonne(grille, colonne)-1;
		
	}
	
	else if (colonne > TAILLE_GRILLE - 1) {
		return -2;
	}
	else if (hauteur_colonne(grille, colonne) > TAILLE_GRILLE - 1) {
		return -3;
	}
	else if (joueur != 1 || joueur != 2) {
		return -1;
	}
		
}

int scan_colonne(int grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
	
	int verif;
	int colonne;
	do {
		printf("Colonne : ");
		verif = scanf("%d", &colonne);
	} while (colonne-1 > TAILLE_GRILLE-1 || colonne-1 < 0 || verif != 1 || hauteur_colonne(grille, colonne-1) > TAILLE_GRILLE-1 || hauteur_colonne(grille, colonne-1) < 0);
	return colonne-1;

}

int verifie_gagneHorizontale (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur) {
	
	int nbPareilDroite = 0;
	int nbPareilGauche = 0;
	int ind = 1;
	
	while(ind < 4 && colonne - ind > -1) {
	
		if (grille[ligne][colonne - ind] == joueur) {		
			nbPareilGauche++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	ind = 1;
	
	while(ind < 4 && colonne + ind < TAILLE_GRILLE) {
	
		if (grille[ligne][colonne + ind] == joueur) {
			nbPareilDroite++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	
	if (nbPareilGauche + nbPareilDroite >= 3) {
		return 1;
	}
	else {
		return 0;
	}

}


int verifie_gagneVerticale (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur) {

	int nbPareil = 0;
	int ind = 1;
	while(ind < 4 && ligne - ind > -1) {
	
		if (grille[ligne - ind][colonne] == joueur) {		
			nbPareil++;
		}
		else {
			ind = 4;
		}
		ind++;
		
	}
	if (nbPareil >= 3) {
		return 1;
	}
	else {
		return 0;
	}
}

int verifie_gagneDiagonale1 (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur) {

	int nbPareilHautGauche = 0;
	int nbPareilBasDroit = 0;
	int ind = 1;
	
	while(ind < 4 && colonne - ind > -1 && ligne + ind < TAILLE_GRILLE) {
	
		if (grille[ligne + ind][colonne - ind] == joueur) {		
			nbPareilHautGauche++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	ind = 1;
	
	while(ind < 4 && colonne + ind < TAILLE_GRILLE && ligne - ind > -1) {
	
		if (grille[ligne - ind][colonne + ind] == joueur) {
			nbPareilBasDroit++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	
	if (nbPareilHautGauche + nbPareilBasDroit >= 3) {
		return 1;
	}
	else {
		return 0;
	}


}

int verifie_gagneDiagonale2 (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur) {

	int nbPareilHautDroit = 0;
	int nbPareilBasGauche = 0;
	int ind = 1;
	
	while(ind < 4 && ligne + ind < TAILLE_GRILLE && colonne + ind < TAILLE_GRILLE) {
	
		if (grille[ligne + ind][colonne + ind] == joueur) {		
			nbPareilHautDroit++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	ind = 1;
	
	while(ind < 4 && colonne - ind > -1 && ligne - ind > -1) {
	
		if (grille[ligne - ind][colonne - ind] == joueur) {
			nbPareilBasGauche++;
		}
		else {
			ind = 4;
		}
		ind++;
	}
	
	
	if (nbPareilBasGauche + nbPareilHautDroit >= 3) {
		return 1;
	}
	else {
		return 0;
	}


}

int verifie_gagne (int grille[TAILLE_GRILLE][TAILLE_GRILLE], int colonne, int ligne, int joueur) {

	if (verifie_gagneHorizontale(grille, colonne, ligne, joueur) == 1 || verifie_gagneVerticale(grille, colonne, ligne, joueur) == 1 || verifie_gagneDiagonale1(grille, colonne, ligne, joueur) == 1 || verifie_gagneDiagonale2(grille, colonne, ligne, joueur) == 1) {
		if (joueur == 1) {
			return 1;
		}
		else  {
			return 2;
		}
	}
	
	else {
		return 0;
	}
}




	
	
	
		





















