INCLUDES= -I../../include -L../../src -lmylib
CFLAGS= -Wall -g -mavx512f -mavx512dq
DBUG = -O0 -fno-omit-frame-pointer

main.exe: main.c
	gcc $(CFLAGS) $< $(INCLUDES) -o $@
