#include <iostream>
using namespace std;

int main() {
    float tc, tf;
    cout << "Введите температуру в *C: ";
    cin >> tc;
    tf = 1.8 * tc + 32;
    cout << "Температура в *F: " << tf;
    return 0;
}