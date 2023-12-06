#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double getArea() {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Rectangle rect(4, 5);
    Circle circle(3);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Circle area: " << circle.getArea() << endl;

    return 0;
}