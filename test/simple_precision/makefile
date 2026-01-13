INCLUDES= -I../../include -L../../src -lmylib
CFLAGS= -Wall -g -mavx512f -mavx512dq
DBUG = -O0 -fno-omit-frame-pointer
SIZES = 8 16 32 64 128 256 512
ITER = 100
SAMPLES = 50
BIN = ./main.exe
OUT = results.txt
.PHONY: clean bench

main.exe: main.c
	gcc $(CFLAGS) $< $(INCLUDES) -o $@


clean:
	rm main.exe

bench:
	@echo "Benchmark lancé"
	@echo "taille,mode,cycles" > $(OUT)
	@for n in $(SIZES); do \
		$(BIN) $(ITER) $(SAMPLES) $$n >> $(OUT); \
	done
