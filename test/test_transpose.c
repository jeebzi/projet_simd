#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
	int32_t matrice[4] = {1, 2, 3, 4};
	int32_t *transpose = transpose_matrice32(matrice, 2, 2);
}
