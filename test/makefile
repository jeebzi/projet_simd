CFLAGS= -Wall -g -mavx512f -mavx512dq

test_trans.exe: test_transpose.c
	gcc -Wall -g test_transpose.c -I../include -L../src -lmylib -o test_trans.exe

prod_scalaire.exe: prod_scalaire.c
	gcc $(CFLAGS) prod_scalaire.c -I ../include -L../src -lmylib -o prod_scalaire.exe

