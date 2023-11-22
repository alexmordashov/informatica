#include <iostream>
using namespace std;

int main() {
    int a, b = 1;
    cout << "Введите число: ";
    cin >> a;
    for (int i = 1; i < a + 1; i++) {
        b = b * i;
    }
    cout << "Факториал числа " << a << ": " << b;
    return 0;
}
