#include <iostream>
using namespace std;

class Dog {
public:
    string name;
    int age;
};
int main() {
    Dog dog1, dog2;

    dog1.name = "Max";
    dog1.age = 3;
    dog2.name = "Rex";
    dog2.age = 5;

    cout << "Dog 1: " << endl;
    cout << "Name: " << dog1.name << ", age: " << dog1.age << endl;
    cout << "Dog 2: " << endl;
    cout << "Name: " << dog2.name << ", age: " << dog2.age << endl;

    return 0;
}