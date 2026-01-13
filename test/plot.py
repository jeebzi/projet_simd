import matplotlib.pyplot as plt
import sys

sizes = []
avx = []
seq = []

with open(sys.argv[1]) as f:
    f.readline()
    for line in f:
        n, mode, cycles = line.strip().split(",")
        if mode == "AVX512":
            sizes.append(int(n))
            avx.append(int(cycles))
        else:
            seq.append(int(cycles))

plt.plot(sizes, avx, label="AVX512")
plt.plot(sizes, seq, label="Séquentiel")
plt.legend()
plt.show()

