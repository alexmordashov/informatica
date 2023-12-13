#include <iostream>
#include <cmath>
#include <ctime>

// Блок extern "C" используется для объявления C-функции с именем calculate_sin_n_times, возвращающей тип float и принимающей параметр int n. Эта функция определена позже в коде.

extern "C" {
float calculate_sin_n_times(int n);
}

int main() {}

float calculate_sin_n_times(int n) {
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        double result = sin(1.57);
    }
    clock_t end = clock();

    // Вывод времени выполнения цикла в секундах
    std::cout << float(end - start) / CLOCKS_PER_SEC << std::endl;
    return 0;
}