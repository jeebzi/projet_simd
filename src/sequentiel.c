#include "sequentiel.h"

int64_t* prod_mat32_seq(int32_t *A, int32_t *B, int n, int h, int m) {
	int64_t *dst = (int64_t*) calloc(n*m, sizeof(int64_t));
	int i, j, k;

	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			k = 0;
			while (k < h) {
				dst[i * m + j] += A[i * h + k] * B[k * m + j];
				k += 1;
			}
			j += 1;
		}
		i += 1;
	}
	return dst;
}

float* prod_mat_ps_seq(float *A, float *B, int n, int h, int m) {
	float *dst = (float*) calloc(n*m, sizeof(float));
	int i, j, k;

	i = 0;
	while (i < n) {
		j = 0;
		while (j < m) {
			k = 0;
			while (k < h) {
				dst[i * m + j] += A[i * h + k] * B[k * m + j];
				k += 1;
			}
			j += 1;
		}
		i += 1;
	}
	return dst;
}
