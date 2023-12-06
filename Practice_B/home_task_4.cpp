#include <iostream>
using namespace std;

class Fruit {
public:
    virtual void getVitamins() = 0;
};

class Apple : public Fruit {
public:
    void getVitamins() {
        setlocale(LC_ALL, "Russian");
        wcout << L"Яблоко богато витамином C" << endl;
    }
};

class Orange : public Fruit {
public:
    void getVitamins() {
        setlocale(LC_ALL, "Russian");
        wcout << L"Апельсин богат витамином C" << endl;
    }
};

int main() {
    Fruit* fruits[3];
    fruits[0] = new Apple();
    fruits[1] = new Orange();
    fruits[2] = new Apple();
    for (int i = 0; i < 3; i++) {
        fruits[i]->getVitamins();
    }
    return 0;
}