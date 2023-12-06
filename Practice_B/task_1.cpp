#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
using namespace std;

class Figure {
public:
    virtual double calculateArea() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        if (width < 0 || height < 0) {
            throw 1;
        }
        else {
            if (width == 0 || height == 0) {
                throw 2;
            }
        }
        return width * height;
    }
};

class Circle: public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        if (radius < 0) {
            throw 1;
        }
        else {
            if (radius == 0) {
                throw 2;
            }
        }
        return M_PI*radius*radius;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    vector<Figure*> shapes;
    shapes.push_back(new Rectangle(5, 10));
    shapes.push_back(new Rectangle(-3, 10));
    shapes.push_back(new Rectangle(0, 10));

    shapes.push_back(new Circle(5));
    shapes.push_back(new Circle(-3));
    shapes.push_back(new Circle(0));

    for (const auto& shape: shapes) {
        try {
            cout << "Area: " << shape -> calculateArea() << endl;
        }
        catch (int exeption) {
            if (exeption == 1) {
                wcout << L"Exception 1: Фигура с отрицательными сторонами" << endl;
            }
            else if (exeption == 2) {
                wcout << L"Exception 2: Фигура с нулевой площадью" << endl;
            }
        }
    }

    return 0;
}