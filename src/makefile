FLAG = -mavx512f -mavx512dq -Wall -g

libmylib.a: util.o prod_matrice_simd.o io.o bench.o
	ar crs libmylib.a prod_matrice_simd.o util.o io.o bench.o


prod_matrice_simd.o: prod_matrice_simd.c prod_matrice_simd.h
	gcc -mavx512f -mavx512dq -Wall -g -c prod_matrice_simd.c -o prod_matrice_simd.o

util.o: util.c util.h
	gcc -mavx512f -Wall -g -c util.c -o util.o
io.o: io.c io.h
	gcc $(FLAG) -c io.c

bench.o: bench.c bench.h util.c prod_matrice_simd.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm *.exe
