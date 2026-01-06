#ifndef bench_h
#define bench_h
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static __inline__ unsigned long long rdtscp(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtscp" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

unsigned long long bench_prod_mat_int(int iteration, int nb_sample, int taille);
unsigned long long bench_prod_mat_int_seq(int iteration, int nb_sample, int taille);

#endif
