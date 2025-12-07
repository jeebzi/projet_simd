#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
//
__m512i* matrice_into_vecteur(int32_t *matrice, int n, int m) {
	/*prend en entrée une matrice de taille n, m et renvoie
	 * sa représentation pour le SIMD
	 */
	__m512i *vecteur, m512;
	vecteur = (__m512i*) malloc(64 * ((n * m) / 8));

	int i = 0, j, indice_vecteur=0;
	while (i < n) {
		j = 0;
		while ((m - j) >= 8) {
			m512 = _mm512_set_epi64(matrice[i*m+(j + 7)], matrice[i*m+(j + 6)], matrice[i*m+(j + 5)], matrice[i*m+(j + 4)], matrice[i*m+(j + 3)], matrice[i*m+(j + 2)], matrice[i*m+(j + 1)], matrice[i*m+(j + 0)]);
			_mm512_storeu_epi64((void*)&vecteur[indice_vecteur], m512);
			//vecteur[i + j] = m512;
			j += 8;
			indice_vecteur += 1;
		}
		if (m != j) { // il reste des valeur dans la lignes de ma matrice en rentrer dans un vecteur
			int64_t *reste;
			reste = (int64_t*) calloc(8, 8);
			int ecart = m - j, k=0;
			while (k<ecart) {
				reste[k] = matrice[i*m + j];
				j += 1;
				k += 1;
			}
			m512 = _mm512_loadu_epi64(reste);
			_mm512_storeu_epi64((void*)&vecteur[indice_vecteur], m512);
			indice_vecteur += 1;
		}
		i += 1;
	}
	return vecteur;
}

void affiche_vecteur(__m512i *vecteur, int n, int m) {
	/* affiche sur le terminal les valeurs de la matrice n*m représenté dans le vecteur de m512
	 */
	for (int i = 0; i < n*((m+7)/8); i++) {
		for (int j=0; j < 8; j++)
		printf("%lld ", vecteur[i][j]);
		printf("\n");
	}
}

int64_t prod_scalaire32(__m512i A, __m512i B) {
	/*
	 * effectue le produit scalaire entre A et B et renvoie le résutltat sur 64 bit
	 */
	int64_t dst = 0;
	__m512i C = _mm512_mullo_epi64(A, B);

	int64_t *res = (int64_t*) &C;
	int i = 0;
	while (i<8) {
		dst += res[i];
		i += 1;
	}
	return dst;
}


