#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Введите число: ";
    cin >> m;
    for (int i = 1; i < 11; i++) {
        cout << m << " * " << i << " = " << m * i << endl;
    }
    return 0;
}