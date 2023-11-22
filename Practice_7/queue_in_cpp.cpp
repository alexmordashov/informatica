#include <iostream>
#include <queue>
#include <list>
using namespace std;

void print_queue(queue<string> q1) {
    while (!q1.empty()) {
        string a = q1.front().c_str();
        std::cout << a <<" ";
        q1.pop();
    }
    cout << endl;
}

int main() {
    queue<string> q;
    while (true) {
        string a;
        cout << "Что хотите сделать?\n1. Добавить элемент\n2. Извлечь элемент\n3. Ничего" << endl;
        cin >> a;
        if (a == "1") {
            string elem;
            cout << "Введите элемент: ";
            cin >> elem;
            q.push(elem);
            print_queue(q);
        }
        else if (a == "2") {
            if (!q.empty()) {
                cout << "Извлечен элемент: " << q.front() << endl;
                q.pop();
                print_queue(q);
            }
            else {
                cout << "Очередь пустая" << endl;
            }
        }
        else {
            exit(0);
        }
    }
    return 0;
}
