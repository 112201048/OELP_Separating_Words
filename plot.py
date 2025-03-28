import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("data.txt")
n = data[:, 0]
probability = data[:, 1]

plt.figure(figsize=(10, 5))
plt.plot(n, probability, marker='o', linestyle='-')
plt.xlabel("n (Size of Sets)")
plt.ylabel("Probability that there exists i for which |S_i| != |T_i|")
plt.title("Probability vs. n")
plt.grid(True)
plt.show()
