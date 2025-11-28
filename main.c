#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "count.h"
#include <inttypes.h>

#define LIG 20
#define COL 20

void vecteur_aleatoire(int64_t *vect, int n) {
	/* renvoie un vecteur d'entier aléatoire de n éléments
	 */
	srand(time(NULL));
	int i = 0;
	while (i < n) {
		vect[i] = (int64_t)rand();
		i += 1;
	}
}

void creer_matrice_float(int n, int m, float matrice[n][m]) {
	/* creer une matrice de floattant aléatoire avec n ligne et n colonnes
	 */
	int i= 0, j;
	while (i < n) {
		j = 0;
		int64_t vecteur[m];
		vecteur_aleatoire(vecteur, m);
		while (j < m) {
			matrice[i][j] = (float)vecteur[j];
			j += 1;
		}
		i += 1;
	}
}

void creer_vecteur_float(float *vecteur, int n) {
	int64_t i_vecteur[n];
	vecteur_aleatoire(i_vecteur, n);
	int i = 0;
	while (i < 0) {
		vecteur[i] = (float)i_vecteur[i];
		i += 1;
	}
}


void creer_matrice_double(int n, int m, double matrice[n][m]) {
	/* creer une matrice de double aléatoire avec n ligne et n colonnes
	 */
	int i= 0, j;
	while (i < n) {
		j = 0;
		int64_t vecteur[m];
		vecteur_aleatoire(vecteur, m);
		while (j < m) {
			matrice[i][j] = (double)vecteur[j];
			j += 1;
		}
		i += 1;
	}
}

void creer_matrice_int(int n, int m, int64_t matrice[n][m]) {
	/* creer une matrice de int64 aléatoire avec n ligne et n colonnes
	 */
	int i= 0, j;
	while (i < n) {
		j = 0;
		int64_t vecteur[m];
		vecteur_aleatoire(vecteur, m);
		while (j < m) {
			matrice[i][j] = vecteur[j];
			j += 1;
		}
		i += 1;
	}
}

void creer_vecteur_double(double *vecteur, int n) {
	int64_t i_vecteur[n];
	vecteur_aleatoire(i_vecteur, n);
	int i = 0;
	while (i < 0) {
		vecteur[i] = (double)i_vecteur[i];
		i += 1;
	}
}

void produit_vect_matrice(int n, int m, float *res, float *v, float mat[n][m]) {
	/* effectur le produit vecteur matrice avec un vecteur et une matrice
	 * le vecteur a le même nombre d'élément que de colonne de la matrice
	 */
	
	int i = 0;
	while (i < n) {
		res[i] = 0.0f;
		int j = 0;
		while (j < m) {
			res[i] += mat[i][j] * v[j];
			j += 1;
		}
		i += 1;
	}
}

void produit_matrice_vecteur(int n, int m, double *res, double *v, double mat[n][m]) {
	/* effectue le produit matrice avec un vecteur et une matrice
	 * le vecteur a le même nombre d'élément que de lignes de la matrice
	 */
	
	int i = 0;
	while (i < n) {
		res[i] = 0.0f;
		int j = 0;
		while (j < m) {
			res[i] += mat[j][i] * v[j];
			j += 1;
		}
		i += 1;
	}
}

void produit_matrice(int n, int m, int64_t res[n][m], int64_t mat1[n][m], int64_t mat2[n][m]) {
	int i = 0, j, k;
	while (i < n) {
		j = 0;
		while (j < m) {
			res[i][j] = 0;
			k = 0;
			while (k < n) {
				res[i][j] += mat1[i][k] * mat2[k][j];
				k += 1;
			}
			j += 1;
		}
		i += 1;
	}
}

int bench_prod_matrice(int iteration, int nb_sample) {
	int cycle_moy = 0;
	int i, j, debut, fin, nb_cycle, min;
	
	int64_t matrice_resultat[LIG][COL];

	int64_t matrice1[LIG][COL];
	creer_matrice_int(LIG, COL, matrice1);
	int64_t matrice2[LIG][COL];
	creer_matrice_int(LIG, COL, matrice2);

	//chauffe le cache
	i = 0;
	while (i < 100) {
		produit_matrice(LIG, COL, matrice_resultat, matrice1, matrice2);
		i += 1;
	}

	i = 0;
	while (i < nb_sample) {

		int64_t matrice1[LIG][COL];
		creer_matrice_int(LIG, COL, matrice1);
		int64_t matrice2[LIG][COL];
		creer_matrice_int(LIG, COL, matrice2);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtsc();
			produit_matrice(LIG, COL, matrice_resultat, matrice1, matrice2);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min) // mise à jour du nombre de cycle min
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;

	

}

int bench_prod_vect_mat(int iteration, int nb_sample) {
	int cycle_moy = 0;
	int i, j, debut, fin, nb_cycle, min;
	
	float vecteur_resultat[LIG];
	float vecteur[COL];
	creer_vecteur_float(vecteur, COL);

	float matrice[LIG][COL];
	creer_matrice_float(LIG, COL, matrice);

	//chauffe le cache
	i = 0;
	while (i < 100) {
		produit_vect_matrice(LIG, COL, vecteur_resultat, vecteur, matrice);
		i += 1;
	}

	i = 0;
	while (i < nb_sample) {
		float vecteur[COL];
		creer_vecteur_float(vecteur, COL);

		float matrice[LIG][COL];
		creer_matrice_float(LIG, COL, matrice);
		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtsc();
			produit_vect_matrice(LIG, COL, vecteur_resultat, vecteur, matrice);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min) // mise à jour du nombre de cycle min
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;

	

}

int bench_prod_mat_vect(int iteration, int nb_sample) {
	int cycle_moy = 0;
	int i, j, debut, fin, nb_cycle, min;
	
	double vecteur_resultat[LIG];
	double vecteur[COL];
	creer_vecteur_double(vecteur, COL);

	double matrice[LIG][COL];
	creer_matrice_double(LIG, COL, matrice);

	//chauffe le cache
	i = 0;
	while (i < 100) {
		produit_matrice_vecteur(LIG, COL, vecteur_resultat, vecteur, matrice);
		i += 1;
	}

	i = 0;
	while (i < nb_sample) {
		double vecteur[COL];
		creer_vecteur_double(vecteur, COL);

		double matrice[LIG][COL];
		creer_matrice_double(LIG, COL, matrice);
		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtsc();
			produit_matrice_vecteur(LIG, COL, vecteur_resultat, vecteur, matrice);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min) // mise à jour du nombre de cycle min
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}


int main() {
	int cycle;
	cycle = bench_prod_matrice(200, 30);
	printf("nbre de cycle: %d\n", cycle);
	return 0;
}
