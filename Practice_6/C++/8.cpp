#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "Введите число: ";
    cin >> a;
    float b = sqrt(a);
    for (int i = 2; i < b + 1; i++) {
        if (a % 2 == 0 && a != 2) {
            cout << "Не простое";
            return 0;
        }
    }
    cout << "Простое";
    return 0;
}