#include <iostream>
using namespace std;

class Transport {
protected:
    double speed;
    string type;
public:
    Transport(double s, string t) : speed(s), type(t) {}
};

class Car : public Transport {
private:
    string brand;
public:
    Car(double s, string t, string b) : Transport(s, t), brand(b) {}
};

class Bicycle : public Transport {
public:
    Bicycle(double s, string t) : Transport(s, t) {}
};