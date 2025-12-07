#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int32_t* transpose_matrice32(int32_t *matrice, int n, int m) {
	/*
	 * renvoie la matrice de int 32transposé NxM
	 */
	int32_t *dst;
	dst = (int32_t*) malloc(n*m*4);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			dst[j*m + i] = matrice[i*m + j];
		}
	}
	return dst;
}

