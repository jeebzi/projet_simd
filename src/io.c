#include "io.h"

void affiche_matrice64(int64_t *matrice, int n, int m) {
	int i = 0, j;
	while (i < n) {
		j = 0;
		while (j < m) {
			printf("%ld ", matrice[i*m + j]);
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}

void affiche_matrice_ps(float *matrice, int n, int m) {
	int i = 0, j;
	while (i < n) {
		j = 0;
		while (j < m) {
			printf("%f ", matrice[i*m + j]);
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}
