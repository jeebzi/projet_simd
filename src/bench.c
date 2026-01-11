#include "bench.h"
#include "util.h"
#include "prod_matrice_simd.h"
#include "sequentiel.h"

unsigned long long bench_prod_mat_int(int iteration, int nb_sample, int taille) {
	unsigned long long cycle_moy = 0, nb_cycle;
	int i, j, debut, fin, min;

	//chauffe cache
	int32_t *matrice_A = creer_random_vecteur32(taille * taille);
	int32_t *matrice_B = creer_random_vecteur32(taille * taille);
	__m512i *A = matrice_into_vecteur(matrice_A, taille, taille);
	__m512i *B = matrice_into_vecteur(matrice_B, taille, taille);

	i = 0;
	while (i < 100) {
		produit_matrice32_vectoriel(A, B, taille, taille);
		i += 1;
	}

	//calcule du nombre de cycle moyen
	i = 0;
	while (i < nb_sample) {
		int32_t *matrice_A = creer_random_vecteur32(taille * taille);
		int32_t *matrice_B = creer_random_vecteur32(taille * taille);
		__m512i *A = matrice_into_vecteur(matrice_A, taille, taille);
		__m512i *B = matrice_into_vecteur(matrice_B, taille, taille);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtscp();
			produit_matrice32_vectoriel(A, B, taille, taille);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min)
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}

unsigned long long bench_prod_mat_int_seq(int iteration, int nb_sample, int taille) {
	unsigned long long cycle_moy = 0, nb_cycle;
	int i, j, debut, fin, min;

	//chauffe cache
	int32_t *A = creer_random_vecteur32(taille * taille);
	int32_t *B = creer_random_vecteur32(taille * taille);

	i = 0;
	while (i < 100) {
		prod_mat32_seq(A, B, taille, taille, taille);
		i += 1;
	}

	//calcule du nombre de cycle moyen
	i = 0;
	while (i < nb_sample) {
		int32_t *A = creer_random_vecteur32(taille * taille);
		int32_t *B = creer_random_vecteur32(taille * taille);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtscp();
			prod_mat32_seq(A, B, taille, taille, taille);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min)
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}

unsigned long long bench_prod_mat_ps(int iteration, int nb_sample, int taille) {
	unsigned long long cycle_moy = 0, nb_cycle;
	int i, j, debut, fin, min;

	//chauffe cache
	float *matrice_A = creer_random_vecteur_ps(taille * taille);
	float *matrice_B = creer_random_vecteur_ps(taille * taille);
	__m512 *A = matrice_into_vecteur_ps(matrice_A, taille, taille);
	__m512 *B = matrice_into_vecteur_ps(matrice_B, taille, taille);

	i = 0;
	while (i < 100) {
		produit_matrice_ps_vectoriel(A, B, taille, taille);
		i += 1;
	}

	//calcule du nombre de cycle moyen
	i = 0;
	while (i < nb_sample) {
		float *matrice_A = creer_random_vecteur_ps(taille * taille);
		float *matrice_B = creer_random_vecteur_ps(taille * taille);
		__m512 *A = matrice_into_vecteur_ps(matrice_A, taille, taille);
		__m512 *B = matrice_into_vecteur_ps(matrice_B, taille, taille);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtscp();
			produit_matrice_ps_vectoriel(A, B, taille, taille);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min)
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}

unsigned long long bench_prod_mat_pd(int iteration, int nb_sample, int taille) {
	unsigned long long cycle_moy = 0, nb_cycle;
	int i, j, debut, fin, min;

	//chauffe cache
	double *matrice_A = creer_random_vecteur_pd(taille * taille);
	double *matrice_B = creer_random_vecteur_pd(taille * taille);
	__m512d *A = matrice_into_vecteur_pd(matrice_A, taille, taille);
	__m512d *B = matrice_into_vecteur_pd(matrice_B, taille, taille);

	i = 0;
	while (i < 100) {
		produit_matrice_pd_vectoriel(A, B, taille, taille);
		i += 1;
	}

	//calcule du nombre de cycle moyen
	i = 0;
	while (i < nb_sample) {
		double *matrice_A = creer_random_vecteur_pd(taille * taille);
		double *matrice_B = creer_random_vecteur_pd(taille * taille);
		__m512d *A = matrice_into_vecteur_pd(matrice_A, taille, taille);
		__m512d *B = matrice_into_vecteur_pd(matrice_B, taille, taille);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtscp();
			produit_matrice_pd_vectoriel(A, B, taille, taille);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min)
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}

unsigned long long bench_prod_mat_ps_seq(int iteration, int nb_sample, int taille) {
	unsigned long long cycle_moy = 0, nb_cycle;
	int i, j, debut, fin, min;

	//chauffe cache
	float *A = creer_random_vecteur_ps(taille * taille);
	float *B = creer_random_vecteur_ps(taille * taille);

	i = 0;
	while (i < 100) {
		prod_mat_ps_seq(A, B, taille, taille, taille);
		i += 1;
	}

	//calcule du nombre de cycle moyen
	i = 0;
	while (i < nb_sample) {
		float *A = creer_random_vecteur_ps(taille * taille);
		float *B = creer_random_vecteur_ps(taille * taille);

		min = 0;
		j = 0;
		while (j < iteration) {
			debut = rdtscp();
			prod_mat_ps_seq(A, B, taille, taille, taille);
			fin = rdtscp();
			nb_cycle = fin - debut;
			if (j == 0 || nb_cycle < min)
				min = nb_cycle;
			j += 1;
		}
		cycle_moy += min;
		i += 1;
	}
	cycle_moy = cycle_moy / nb_sample;
	return cycle_moy;
}

