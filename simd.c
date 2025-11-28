#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include <immintrin.h>

#undef force_inline
#define force_inline __attribute__((always_inline))

int afficheVect256(const __m256i *A, char *var) {
	int64_t *t = (int64_t*) A;
	printf("%s = %16.16lX\n", var, t[0]);
	printf("%16.16lX\n", t[1]);
	printf("%16.16lX\n", t[2]);
	printf("%16.16lX\n", t[3]);
	return 0;
}

int prodScale256(int64_t *out, __m256i A, __m256i B) {
	__m256i t256;

	t256 = _mm256_mullo_epi64(A, B);
	int64_t *t = (int64_t*)&t256;

	*out = t[0]+t[1]+t[2]+t[3];

}


int main() {
	__m256i a256, b256, s256;
	int64_t a0 = 0, a1 = 1, a2 = 2, a3 = 3;
	int64_t a[4] = {0L, 1L, 2L, 3L};
	a256 = _mm256_set_epi64x(a[3], a[2], a[1], a[0]);
	b256 = _mm256_set1_epi64x(4);
	afficheVect256(&a256, "a256");
	afficheVect256(&b256, "b256");

	s256 = _mm256_add_epi64(a256, b256);
	afficheVect256(&s256, "s256");
	int64_t out;
	prodScale256(&out, a256, b256);
	printf("a.b = %16.16ld\n", out);
	return 0;
}
