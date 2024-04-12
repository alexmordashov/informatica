#include "head.h"
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

int Rnd (int a, int b) {
    int seed = system_clock::now().time_since_epoch().count();
    static default_random_engine rnd(seed);
    static uniform_int_distribution<int> d(a, b);
    return d(rnd);
}
double Rnd (double a, double b) {
    int seed = system_clock::now().time_since_epoch().count();
    static default_random_engine rnd(seed);
    static uniform_real_distribution<double> d(a, b);
    return d(rnd);
}

void mySortBubble(vector<int> &mas, int &r) {
    for (size_t i = 0; i < mas.size() - 2; i++)
        for (size_t j = 0; j < mas.size() - i - 1; j++) {
            r++;
            if (mas[j] > mas[j + 1]) {
                int buf = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = buf;
            }
        }
}

void mySortBubble(vector<double> &mas, int &r) {
    for (size_t i = 0; i < mas.size() - 2; i++)
        for (size_t j = 0; j < mas.size() - i - 1; j++) {
            r++;
            if (mas[j] > mas[j + 1]) {
                double buf = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = buf;
            }
        }
}

/* Быстрая сортировка */

void myQsort(vector<int> &mas, size_t l, size_t r, int &k) {
    size_t L = l, R = r;
    int M = mas[(l + r) / 2];
    do {
        k++;
        while (mas[l] < M) l++;
        while (mas[r] > M) r--;
        if (l <= r) {
            int buff = mas[l];
            mas[l]   = mas[r];
            mas[r]   = buff;
            l++;
            r--;
        }
    } while (l < r);
    if (L < r) myQsort(mas, L, r, k);
    if (l < R) myQsort(mas, l, R, k);
}

void myQsort(vector<double> &mas, size_t l, size_t r, int &k) {
    size_t L = l, R = r;
    double M = mas[(l + r) / 2];
    do {
        k++;
        while (mas[l] < M) l++;
        while (mas[r] > M) r--;
        if (l <= r) {
            double buff = mas[l];
            mas[l]   = mas[r];
            mas[r]   = buff;
            l++;
            r--;
        }
    } while (l < r);
    if (L < r) myQsort(mas, L, r, k);
    if (l < R) myQsort(mas, l, R, k);
}

/* Поиск */

int myBinSearch(vector<int> &mas, int &r, int x) {
    int L = 0, R = mas.size() - 1, q;
    while (L <= R) {
        q = (R + L) / 2;
        if (mas[q] < x)
            L = q + 1;
        else if (mas[q] > x)
            R = q - 1;
        else
            return q;
        r++;
    }
    return -1;
}

int myBinSearch(vector<double> &mas, int &r, double x) {
    int L = 0, R = mas.size() - 1, q;
    while (L <= R) {
        //cout << mas[q] << endl;
        q = (R + L) / 2;
        if (abs(mas[q] - x) < 1e - 9)
            return q;
        else if (mas[q] < x)
            L = q + 1;
        else if (mas[q] > x)
            R = q - 1;
        r++;
    }
    return -1;
}
