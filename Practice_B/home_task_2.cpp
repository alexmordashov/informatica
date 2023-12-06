#include <iostream>
using namespace std;

class Bank {
private:
    double balance;
    string accountNumber;
public:
    Bank(double balance, const string accountNumber) : balance(balance), accountNumber(accountNumber) {}
    void top_up(double money) {
        balance += money;
        cout << "You top up your bank account with " << money << " conventional units" << endl;
        cout << "Balance: " << balance << " conventional units" << endl;
    }
    void get_money(double money) {
        if (money <= balance) {
            balance -= money;
            cout << "You have withdrawn " << money << " conventional units from your bank account" << endl;
            cout << "Balance: " << balance << " conventional units" << endl;
        }
        else {
            cout << "Error: there are not enough money in your bank account" << endl;
        }
    }
};

int main() {
    // Создание экземпляра класса "БанковскийСчет"
    Bank account(1000.0, "1234567890");

    account.top_up(500.0);
    account.get_money(300.0);
    return 0;
}