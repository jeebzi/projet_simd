#include "../../include/mylib.h"

int main(int argc, char *argv[]) {
	unsigned long long cycle = bench_prod_mat_int(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	printf("nombre de cycle moyen = %llu\n", cycle);
	return 0;
}
