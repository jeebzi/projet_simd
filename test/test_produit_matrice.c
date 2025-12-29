#include "mylib.h"

int main(int argc, char *argv[]) {
	seed_prng_highres();
	int n = atoi(argv[1]);
	//int32_t A[4] = {1, 2, 3, 4}, B[4] = {5, 6, 7, 8};
	int32_t *A = creer_random_vecteur32(n * n);
	int32_t *B = creer_random_vecteur32(n*n);
	int32_t *C = transpose_matrice32(B, n, n);

	// affiche_matrice32(A, n, n);
	// printf("\n");
	// affiche_matrice32(B, n, n);
	// printf("\n");
	// affiche_matrice32(C, n, n);
	// printf("\n");
	__m512i *A512, *B512;
	A512 = matrice_into_vecteur(A, n, n);
	B512 = matrice_into_vecteur(C, n, n);

	affiche_vecteur(A512, n, n);
	printf("\n");
	affiche_vecteur(B512, n, n);
	printf("\n");

	int64_t *D = produit_matrice32_vectoriel(A512, B512, n, n);
	affiche_matrice64(D, n, n);
}


