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
	int nb_vecteurs = n * ((m + 7) / 8);
	// vecteur = (__m512i*) malloc(sizeof(__m512i) * nb_vecteurs);
	if (posix_memalign((void**)&vecteur, 64, sizeof(*vecteur) * nb_vecteurs) != 0) {
		perror("posix_memalign");
		return NULL;
	}

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

__m512* matrice_into_vecteur_ps(float *matrice, int n, int m) {
	__m512 *vecteur, m512;
	int nb_vecteurs = n*((m + 15) / 16);
	if (posix_memalign((void**)&vecteur, 64, sizeof(*vecteur) * nb_vecteurs) != 0) {
		perror("posix_memalign");
		return NULL;
	}

	int i = 0, j, indice_vecteur=0;
	while (i < n) {
		j = 0;
		while ((m - j) >= 16) {
			m512 = _mm512_set_ps(matrice[i*m+(j + 15)], matrice[i*m+(j + 14)], matrice[i*m+(j + 13)], matrice[i*m+(j + 12)], matrice[i*m+(j + 11)], matrice[i*m+(j + 10)], matrice[i*m+(j + 9)],
				       	matrice[i*m+(j + 8)], matrice[i*m+(j + 7)], matrice[i*m+(j + 6)], matrice[i*m+(j + 5)], matrice[i*m+(j + 4)], matrice[i*m+(j + 3)], matrice[i*m+(j + 2)], matrice[i*m+(j + 1)], matrice[i*m+(j + 0)]);
			_mm512_storeu_ps((void*)&vecteur[indice_vecteur], m512);
			j += 16;
			indice_vecteur += 1;
		}
		if (m != j) {
			// float *reste;
			// reste = (float*) calloc(16, sizeof(float));
			float reste[16] = {0};
			int ecart = m - j, k=0;
			while (k < ecart) {
				reste[k] = matrice[i*m + j];
				j += 1;
				k += 1;
			}
			m512 = _mm512_loadu_ps(reste);
			// _mm512_storeu_ps((float*)&vecteur[indice_vecteur], m512);
			vecteur[indice_vecteur] = m512;
			indice_vecteur += 1;
		}
		i += 1;
	}
	return vecteur;
}

__m512d* matrice_into_vecteur_pd(double *matrice, int n, int m) {
	/*prend en entrée une matrice de taille n, m et renvoie
	 * sa représentation pour le SIMD
	 */
	__m512d *vecteur, m512;
	int nb_vecteurs = n * ((m + 7) / 8);
	if (posix_memalign((void**)&vecteur, 64, sizeof(*vecteur) * nb_vecteurs) != 0) {
		perror("posix_memalign");
		return NULL;
	}

	int i = 0, j, indice_vecteur=0;
	while (i < n) {
		j = 0;
		while ((m - j) >= 8) {
			m512 = _mm512_set_pd(matrice[i*m+(j + 7)], matrice[i*m+(j + 6)], matrice[i*m+(j + 5)], matrice[i*m+(j + 4)], matrice[i*m+(j + 3)], matrice[i*m+(j + 2)], matrice[i*m+(j + 1)], matrice[i*m+(j + 0)]);
			_mm512_storeu_pd((void*)&vecteur[indice_vecteur], m512);
			j += 8;
			indice_vecteur += 1;
		}
		if (m != j) { // il reste des valeur dans la lignes de ma matrice en rentrer dans un vecteur
			int64_t reste[8] = {0};
			int ecart = m - j, k=0;
			while (k<ecart) {
				reste[k] = matrice[i*m + j];
				j += 1;
				k += 1;
			}
			m512 = _mm512_loadu_pd(reste);
			vecteur[indice_vecteur] = m512;
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
		int64_t *vals = (int64_t*) &vecteur[i];
		for (int j=0; j < 8; j++)
			printf("%ld ", vals[j]);
		printf("\n");
	}
}

void affiche_vecteur_ps(__m512 *vecteur, int n, int m) {
	for (int i = 0; i < n*((m+15)/16); i++) {
		float *vals = (float*) &vecteur[i];
		for (int j=0; j < 16; j++)
			printf("%f ", vals[j]);
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

double prod_scalaire_pd(__m512d A, __m512d B) {
	double dst = 0;
	__m512d C = _mm512_mul_pd(A, B);

	double *res = (double*) &C;
	int i = 0;
	while (i<8) {
		dst += res[i];
		i += 1;
	}
	return dst;
}

float prod_scalaire_ps(__m512 A, __m512 B) {
	/*
	 * fait le produit scalaire entre des simple précisions
	 */
	float dst = 0;
	__m512 C = _mm512_mul_ps(A, B);
	float *res = (float*) &C;
	int i = 0;
	while (i < 16) {
		dst += res[i];
		i += 1;
	}
	return dst;
}


int64_t* produit_matrice32_vectoriel(__m512i *A, __m512i *B, int n, int m) {
	/*
	 * prend deux tableau de vecteur simd représentant des matrices, B est une matrice transposé
	 * renvoie la matrice de produit des deux
	 */
	int64_t *dst, somme;
	dst = (int64_t*) calloc(n*m, 8);
	int vecteur_par_ligne = (m + 7) / 8, cpt_vecteur = 0, i = 0, j, k;
	int x, y=0;
	while (y < n) {
		j = 0;
		x = 0;
		while (x < m) {
			k = 0;
			somme = 0;
			while (k < vecteur_par_ligne) {
				somme += prod_scalaire32(A[i + k], B[j + k]);
				cpt_vecteur += 1;
				k += 1;
			}
			dst[y*m + x] = somme;
			j += vecteur_par_ligne;
			x += 1;
		}
		i += vecteur_par_ligne;
		y += 1;
	}
	return dst;
}

float* produit_matrice_ps_vectoriel(__m512 *A, __m512 * B, int n, int m) {
	float *dst, somme;
	dst = (float*) calloc(n*m, sizeof(float));
	int vecteur_par_ligne = (m + 15) / 16, cpt_vecteur = 0, i = 0, j, k;
	int x, y=0;
	while (y < n) {
		j = 0;
		x = 0;
		while (x < m) {
			k = 0;
			somme = 0;
			while (k < vecteur_par_ligne) {
				somme += prod_scalaire_ps(A[i + k], B[j + k]);
				cpt_vecteur += 1;
				k += 1;
			}
			dst[y*m + x] = somme;
			j += vecteur_par_ligne;
			x += 1;
		}
		i += vecteur_par_ligne;
		y += 1;
	}
	return dst;
}


double* produit_matrice_pd_vectoriel(__m512d *A, __m512d *B, int n, int m) {
	double *dst, somme;
	dst = (double*) calloc(n*m, 8);
	int vecteur_par_ligne = (m + 7) / 8, cpt_vecteur = 0, i = 0, j, k;
	int x, y=0;
	while (y < n) {
		j = 0;
		x = 0;
		while (x < m) {
			k = 0;
			somme = 0;
			while (k < vecteur_par_ligne) {
				somme += prod_scalaire_pd(A[i + k], B[j + k]);
				cpt_vecteur += 1;
				k += 1;
			}
			dst[y*m + x] = somme;
			j += vecteur_par_ligne;
			x += 1;
		}
		i += vecteur_par_ligne;
		y += 1;
	}
	return dst;
}


