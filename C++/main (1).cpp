#include <iostream>
#include <string>

int main() {
    std::string a;
    std::cout << "Введите строку(латинские буквы): ";
    std::cin >> a;
    int c = 0;
    std::string str1 = "aoieuy";
    for (char i : a) {
        if (str1.find(tolower(i)) != std::string::npos) {
            c++;
        }
    }
    std::cout << c << std::endl;
    return 0;
}