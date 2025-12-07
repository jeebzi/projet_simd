libmylib.a: util.o prod_matrice_simd.o
	ar crs libmylib.a prod_matrice_simd.o util.o

prod_matrice_simd.exe : prod_matrice_simd.c
	gcc -mavx512f -Wall -g -o prod_matrice_simd.exe prod_matrice_simd.c

prod_matrice_simd.o: prod_matrice_simd.c prod_matrice_simd.h
	gcc -mavx512f -mavx512dq -Wall -g -c prod_matrice_simd.c -o prod_matrice_simd.o

util.o: util.c util.h
	gcc -mavx512f -Wall -g -c util.c -o util.o

clean:
	rm *.exe
