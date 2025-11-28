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

	int i = 0, j;
	while (i < n) {
		j = 0;
		while ((m - j) >= 8) {
			m512 = _mm512_set_epi64(matrice[i*(j + 7)], matrice[i*(j + 6)], matrice[i*(j + 5)], matrice[i*(j + 4)], matrice[i*(j + 3)], matrice[i*(j + 2)], matrice[i*(j + 1)], matrice[i*(j + 0)]);
			vecteur[i*m + j] = m512;
			j += 2;
		}
		if (m != j) { // il reste des valeur dans la lignes de ma matrice en rentrer dans un vecteur
			int64_t *reste;
			reste = (int64_t*) calloc(6, 8);
			int ecart = m - j;
			while (ecart < m) {
				reste[m - (ecart - (m - j) + 1)] = matrice[i*m + j];
				ecart += 1;
			}
		}
		i += 1;
	}
	return vecteur;
		}

int main() {
	int32_t *matrice;
	int n = 8, m = 8;
	matrice = (int32_t*) calloc(n*m, sizeof(int32_t));
	matrice[3] = 1;
	__m512i* vecteur;
	vecteur = matrice_into_vecteur(matrice, n, m);
	for (int i = 0; i < n*m; i++) {
		printf("%lld\n", vecteur[i/n][i%n]);
	}
	return 0;
}
