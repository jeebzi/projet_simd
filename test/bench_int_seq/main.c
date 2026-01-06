#include "../../include/mylib.h"

int main(int argc, char *argv[]) {
	int taille = atoi(argv[3]), nb_sample = atoi(argv[2]), iteration = atoi(argv[1]);
	unsigned long long cycle_moy;
	cycle_moy = bench_prod_mat_int_seq(iteration, nb_sample, taille);
	printf("pour des matrice de taille %d la multiplication en séquentiel prend %llu cycles\n", taille, cycle_moy);
	return 0;
}
