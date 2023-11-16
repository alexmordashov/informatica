#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "Введите год: ";
    cin >> a;
    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {
        cout << "Високосный год";
    }
    else {
        cout << "Невисокосный год";
    }
    return 0;
}
