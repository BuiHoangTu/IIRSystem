import sys
import matplotlib.pyplot as plt
import numpy as np

i = 0
input_f = []
while(i < 100):
    i += 1
    input_s = sys.stdin.readline()
    tmp_f = float(input_s)
    input_f.append(tmp_f)

yn = np.array(input_f)
n = np.arange(start=0, stop=100, step=1)

plt.xlabel("n")
plt.ylabel("yn")
plt.title("Title")
plt.plot(n, yn, color= 'blue')
plt.stem(n, yn)
#plt.grid()
plt.show()
