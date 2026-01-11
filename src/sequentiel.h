#ifndef SEQ_H
#define SEQ_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int64_t* prod_mat32_seq(int32_t *A, int32_t *B, int n, int h, int m);
float* prod_mat_ps_seq(float *A, float *B, int n, int h, int m);
double* prod_mat_pd_seq(double *A, double *B, int n, int h, int m);


#endif
