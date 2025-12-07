main.exe : main.c count.h
	gcc -Wall -g -o main main.c

prod_matrice_simd.exe : prod_matrice_simd.c
	gcc -mavx512f -Wall -g -o prod_matrice_simd.exe prod_matrice_simd.c

clean:
	rm *.exe
