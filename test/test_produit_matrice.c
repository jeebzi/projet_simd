#include "mylib.h"

int main() {
	int32_t A[4] = {1, 2, 3, 4}, B[4] = {5, 6, 7, 8};
	int32_t *C = transpose_matrice32(B, 2, 2);
	__m512i *A512, *B512;
	A512 = matrice_into_vecteur(A, 2, 2);
	B512 = matrice_into_vecteur(C, 2, 2);
	affiche_vecteur(A512, 2, 2);
	affiche_vecteur(B512, 2, 2);
	int64_t *D = produit_matrice32_vectoriel(A512, B512, 2, 2);
	affiche_matrice64(D, 2, 2);
}


