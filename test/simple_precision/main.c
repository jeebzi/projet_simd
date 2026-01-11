#include "../../include/mylib.h"

int main(int argc, char **argv) {
	int n = atoi(argv[3]);
	int iteration = atoi(argv[1]);
	int nb_sample = atoi(argv[2]);
	unsigned long long cycle_moy;
	cycle_moy = bench_prod_mat_ps(iteration, nb_sample, n);
	printf("matrice de float de taille %d multiplication AVX512 prend %llu cycles\n", n, cycle_moy);
	return 0;
}

