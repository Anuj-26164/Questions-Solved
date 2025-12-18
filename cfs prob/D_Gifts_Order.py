import numpy as np
import matplotlib.pyplot as plt

def even_odd_decomposition(x, t):
    x_neg = np.interp(-t, t, x)  # Reflecting x(t) to get x(-t)
    x_even = (x + x_neg) / 2
    x_odd = (x - x_neg) / 2
    return x_even, x_odd

# Continuous signal (triangular function)
t = np.linspace(-5, 5, 1000)
x_t = np.where((t >= 0) & (t <= 5), t, 0)  # Triangle from 0 to 5
x_even, x_odd = even_odd_decomposition(x_t, t)

# Plot continuous signal decomposition
plt.figure(figsize=(12, 5))
plt.subplot(1, 3, 1)
plt.plot(t, x_t, label='Original Signal x(t)')
plt.legend()
plt.grid()

plt.subplot(1, 3, 2)
plt.plot(t, x_even, label='Even Component x_e(t)', color='g')
plt.legend()
plt.grid()

plt.subplot(1, 3, 3)
plt.plot(t, x_odd, label='Odd Component x_o(t)', color='r')
plt.legend()
plt.grid()
plt.show()

# Discrete-time signal
t_n = np.array([-1, 0, 1, 2, 3, 4, 5])
x_n = np.array([0, 2, 4, 3, 2, 1, 0])
x_even_n, x_odd_n = even_odd_decomposition(x_n, t_n)

# Plot discrete signal decomposition
plt.figure(figsize=(12, 5))
plt.subplot(1, 3, 1)
plt.stem(t_n, x_n, basefmt='b', label='Original Signal x[n]')
plt.legend()
plt.grid()

plt.subplot(1, 3, 2)
plt.stem(t_n, x_even_n, basefmt='g', label='Even Component x_e[n]')
plt.legend()
plt.grid()

plt.subplot(1, 3, 3)
plt.stem(t_n, x_odd_n, basefmt='r', label='Odd Component x_o[n]')
plt.legend()
plt.grid()
plt.show()