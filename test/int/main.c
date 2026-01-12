#include "../../include/mylib.h"

int main(int argc, char *argv[]) {
	int taille = atoi(argv[3]), nb_sample = atoi(argv[2]), iteration = atoi(argv[1]);
	unsigned long long cycle_moy_seq, cycle_moy;
	cycle_moy = bench_prod_mat_int(iteration, nb_sample, taille);
	printf("pour des matrices de taille %d la multiplication AVX512 de int32 prend %llu cycles\n", taille, cycle_moy);
	cycle_moy_seq = bench_prod_mat_int_seq(iteration, nb_sample, taille);
	printf("pour des matrice de taille %d la multiplication en séquentiel prend %llu cycles\n", taille, cycle_moy_seq);
	return 0;
}
