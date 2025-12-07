#include "mylib.h"
#include <stdio.h>

int main() {
	__m512i A, B;
	int64_t C;
	A = _mm512_set_epi64(1, 1, 1, 1, 1, 1, 1, 1);
	B = _mm512_set_epi64(1, 2, 3, 4, 5, 6, 7, 8);
	C = prod_scalaire32(A, B);
	printf("%ld\n", C);
	return 0;
}
