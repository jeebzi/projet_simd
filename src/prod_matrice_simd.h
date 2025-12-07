#ifndef PRODMAT_H
#define PRODMAT_H

#include <immintrin.h>
#include <inttypes.h>

__m512i* matrice_into_vecteur(int32_t *matrice, int n, int m);

void affiche_vecteur(__m512i *vecteur, int n, int m);
int64_t prod_scalaire32(__m512i A, __m512i B);

#endif
