#include <iostream>
#include <vector>

class Product {
private:
    double price;
    double weight;
public:
    Product(double price, double weight) : price(price), weight(weight) {}
    double getTotalPrice() const{
        if (price > 0 && weight > 0) {
            return price * weight;
        }
        throw std::invalid_argument("Invalid price or weight");
    }
};
class Apple : public Product {
private:
    std::string variety;
public:
    Apple(double price, double weight, std::string variety)
            : Product(price, weight), variety(variety) {}
    std::string getVariety() const {
        return variety;
    }
};
class Orange : public Product {
private:
    std::string origin;
public:
    Orange(double price, double weight, std::string origin)
            : Product(price, weight), origin(origin) {}
    std::string getOrigin() const {
        return origin;
    }
};
int main() {
    std::vector<Product*> shapes;
    shapes.push_back(new Apple(5, 10, "Golden"));
    shapes.push_back(new Apple(-3, 10, "Granny"));
    shapes.push_back(new Apple(3, -10, "Granny"));

    shapes.push_back(new Orange(12, 4, "Verna"));
    shapes.push_back(new Orange(0, 23, "Washington"));
    shapes.push_back(new Orange(45, 0, "Washington"));

    for (const auto& shape: shapes) {
        try {
            std::cout << "Total price: " << shape -> getTotalPrice() << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}