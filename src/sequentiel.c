#include "sequentiel.h"

int64_t* prod_mat32_seq(int32_t *A, int32_t *B, int n, int m) {
	int64_t *dst = (int64_t*) calloc(n*m, sizeof(int64_t));
	int i, j, k
