#ifndef UTIL_H
#define UTIL_H

#include <inttypes.h>
#include <time.h>
int32_t* transpose_matrice32(int32_t *matrice, int n, int m);
void affiche_matrice32(int32_t *matrice, int n, int m);
void seed_prng_highres(void);
int32_t* creer_random_vecteur32(int n);
float* creer_random_vecteur_ps(int n);
#endif
