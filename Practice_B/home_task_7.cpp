#include <iostream>
using namespace std;

class House {
public:
    int rooms;
    string address;
};

class Person {
public:
    string name;
    int age;
};

class Resident : public Person {
public:
    House* house;

    void liveinhouse(House* h) {
        house = h;
    }
};

int main() {
    House myHouse;
    myHouse.rooms = 3;
    myHouse.address = "123 Main St";

    Resident john;
    john.name = "John Doe";
    john.age = 30;
    john.liveinhouse(&myHouse);

    cout << john.name << " is " << john.age << " years old." << endl;
    cout << john.name << " lives in a house with " << john.house -> rooms << " rooms located at " << john.house ->
    address << "." << endl;

    return 0;
}