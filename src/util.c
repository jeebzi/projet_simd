#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "util.h"

int32_t* transpose_matrice32(int32_t *matrice, int n, int m) {
	/*
	 * renvoie la matrice de int 32transposé NxM
	 */
	int32_t *dst;
	dst = (int32_t*) malloc(n*m*4);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			dst[j*n + i] = matrice[i*m + j];
		}
	}
	return dst;
}

void affiche_matrice32(int32_t *matrice, int n, int m) {
	int i=0, j;
	while (i < n) {
		j = 0;
		while (j < m) {
			printf("%d ", matrice[i*m + j]);
			j += 1;
		}
		printf("\n");
		i += 1;
	}
}

void seed_prng_highres(void) {
    unsigned s = (unsigned)time(NULL);
    s ^= (unsigned)clock();
    s ^= (unsigned)((uintptr_t)&s >> 4);
    /* mélanger encore un peu avec plusieurs appels rand() après srand */
    srand(s);
}

int32_t* creer_random_vecteur32(int n) {
	/* 
	 * retourne en vecteur d'entier 32 bit aléatoire
	 */
	int32_t *dst;
	dst = (int32_t*) malloc(n*4);
	int i = 0;
	while (i < n) {
		dst[i] = (int32_t) (rand() %(1<<31));
		i += 1;
	}
	return dst;
}

float* creer_random_vecteur_ps(int n) {
	float *dst;
	dst = (float*) malloc(n*sizeof(float));
	int i = 0;
	while (i < n) {
		dst[i] = (float) (rand() % (1 << 16));
		i += 1;
	}
	return dst;
}
