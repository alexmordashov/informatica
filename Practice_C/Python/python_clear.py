import math
import time


def calculate_sin_n_times(n):
    start = time.time()
    for i in range(n):
        result = math.sin(1.57)
    end = time.time()
    return end - start


print(calculate_sin_n_times(10000000))
print(calculate_sin_n_times(100000000))
print(calculate_sin_n_times(1000000000))
