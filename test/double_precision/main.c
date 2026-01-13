#include "../../include/mylib.h"

int main(int argc, char **argv) {
	int n = atoi(argv[3]);
	int iteration = atoi(argv[1]);
	int nb_sample = atoi(argv[2]);
	unsigned long long cycle_moy;
	cycle_moy = bench_prod_mat_pd(iteration, nb_sample, n);
	printf("%d,AVX512,%llu\n", n, cycle_moy);
	cycle_moy = bench_prod_mat_ps_seq(iteration, nb_sample, n);
	printf("%d,SEQ,%llu\n", n, cycle_moy);
	return 0;
}

