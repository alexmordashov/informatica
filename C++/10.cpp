#include <algorithm> 
#include<iostream>
#include<string>
using namespace std; 
int main() 
{ 
    string str = "";
    cout << "Введите строку: ";
    cin >> str;
    reverse(str.begin(), str.end()); 
    cout << "\n" << str; 
    return 0;
}
