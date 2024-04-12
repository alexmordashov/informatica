#include <iostream>
#include "head.h"
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    vector<int> iv;
    vector<double> dv;
    size_t n_ar;
    bool t_ar;
    cout << "Which array to create?\n"
            "0 - int\n"
            "1 - double" << endl;
    cout << " => ";
    cin >> t_ar;
    cout << "Enter the length of the array: ";
    cin >> n_ar;
    cout << "Enter the interval of random numbers [x, y]:" << endl;
    if (!t_ar) {
        int x, y;
        cout << "x => "; cin >> x;
        cout << "y => "; cin >> y;
        ini_ar(n_ar, x, y, iv);
        print_ar(t_ar, iv);
    }
    else {
        double x, y;
        cout << "x => "; cin >> x;
        cout << "y => "; cin >> y;
        ini_ar(n_ar, x, y, dv);
        print_ar(t_ar, dv);
    }
    cout << "What function do you want to run?\n"
            "0 - SortBubble\n"
            "1 - Qsort\n"
            "2 - BinSearch" << endl;
    cout << " => ";
    int func;
    cin >> func;
    int cnt {};
    if (func == 0) {
        if (!t_ar) {
            auto start = system_clock::now();
            mySortBubble(iv, cnt);
            auto end = system_clock::now();
            cout << "Number of iterations: "
                 << cnt << endl;
            print_ar(t_ar, iv);
            auto elapsed = end - start;
            cout << "Execution speed: "
                 << duration_cast<microseconds>(elapsed).count()
                 << " mcs"
                 << endl;
        }
        else {
            mySortBubble(dv, cnt);
            cout << "Number of iterations: "
                 << cnt << endl;
            print_ar(t_ar, dv);
        }
    }
    else if (func == 1) {
        if (!t_ar) {
            auto start = system_clock::now();
            myQsort(iv, 0, iv.size() - 1, cnt);
            auto end = system_clock::now();
            cout << "Number of iterations: "
                 << cnt << endl;
            print_ar(t_ar, iv);
            auto elapsed = end - start;
            cout << "Execution speed: "
                 << duration_cast<microseconds>(elapsed).count()
                 << " mcs"
                 << endl;
        }
        else {
            myQsort(dv, 0, dv.size() - 1, cnt);
            cout << "Number of iterations: "
                 << cnt << endl;
            print_ar(t_ar, dv);
        }
    }
    else if (func == 2) {
        if (!t_ar) {
            myQsort(iv, 0, iv.size() - 1, cnt);
            print_ar(t_ar, iv);
            cout << "Which element do you want to find?" << endl;
            int element;
            cin >> element;
            auto start = system_clock::now();
            auto end = system_clock::now();
            cout << "Index of your element: " << myBinSearch(iv, cnt, element) << endl;
            cout << "Number of iterations: "
                 << cnt << endl;
            auto elapsed = end - start;
            cout << "Execution speed: "
                 << duration_cast<microseconds>(elapsed).count()
                 << " mcs"
                 << endl;
        }
        else {
            myQsort(dv, 0, dv.size() - 1, cnt);
            print_ar(t_ar, dv);
            cout << "Which element do you want to find?" << endl;
            double element;
            cin >> element;
            cout << "Index of your element: " << myBinSearch(dv, cnt, element) << endl;
            cout << "Number of iterations: "
                 << cnt << endl;
        }
    }
    int a;
    cin >> a;
    return 0;
}
