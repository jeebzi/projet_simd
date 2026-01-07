#ifndef PRODMAT_H
#define PRODMAT_H

#include <immintrin.h>
#include <inttypes.h>

__m512i* matrice_into_vecteur(int32_t *matrice, int n, int m);

void affiche_vecteur(__m512i *vecteur, int n, int m);
int64_t prod_scalaire32(__m512i A, __m512i B);
int64_t* produit_matrice32_vectoriel(__m512i *A, __m512i *B, int n, int m);
float* produit_matrice_ps_vectoriel(__m512 *A, __m512 * B, int n, int m);
__m512* matrice_into_vecteur_ps(float *matrice, int n, int m);

#endif
