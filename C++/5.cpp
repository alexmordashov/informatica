#include <iostream>
using namespace std;

int main() {
    float m;
    cout << "Введите количество метров: ";
    cin >> m;
    cout << "Количество километров: " << m/1000;
    return 0;
}