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
    string x, y;
    cout << "x => "; cin >> x;
    cout << "y => "; cin >> y;
    if (!t_ar) {
        //int x, y;
        //cout << "x => "; cin >> x;
        //cout << "y => "; cin >> y;
        ini_ar(n_ar, stoi(x), stoi(y), iv);
        print_ar(t_ar, iv);
    }
    else {
        //double x, y;
        //cout << "x => "; cin >> x;
        //cout << "y => "; cin >> y;
        ini_ar(n_ar, stod(x), stod(y), dv);
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
        int sort_type;
        cout << "What sorting do you want to use?\n"
                "0 - SortBubble\n"
                "1 - QSort\n"
                " => ";
        cin >> sort_type;
        if (!t_ar) {
            if (sort_type) {
                myQsort(iv, 0, iv.size() - 1, cnt);
            }
            else {
                mySortBubble(iv, cnt);
            }
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
            if (sort_type) {
                myQsort(dv, 0, dv.size() - 1, cnt);
            }
            else {
                mySortBubble(dv, cnt);
            }
            print_ar(t_ar, dv);
            cout << "Which element do you want to find?" << endl;
            double element;
            cin >> element;
            if (x.size() >= y.size())
            	cout << "Index of your element: " << myBinSearch(dv, cnt, element, x) << endl;
            else
                cout << "Index of your element: " << myBinSearch(dv, cnt, element, y) << endl;
            cout << "Number of iterations: "
                 << cnt << endl;
        }
    }
    int a;
    cin >> a;
    return 0;
}
