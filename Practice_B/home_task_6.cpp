#include <iostream>

class Figure {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Figure* figures[2];
    figures[0] = new Rectangle(4, 5);
    figures[1] = new Circle(3);

    for(int i = 0; i < sizeof(figures); i++) {
        std::cout << "Area of figure " << i + 1 << ": " << figures[i] -> calculateArea() << std::endl;
    }

    return 0;
}