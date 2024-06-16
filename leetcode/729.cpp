#include "../template/head.h"
#include <bits/stdc++.h>

class MyCalendar {
  public:
    vector<pair<int, int>> vec;
    MyCalendar() {}

    bool book(int start, int end) {
        for (auto &v : vec) {
            if (!(v.second <= start || v.first >= end)) {
                return false;
            }
        }

        vec.emplace_back(start, end);
        return true;
    }
};

int main(int argc, char *argv[]) {
    MyCalendar myCalendar;
    cout << myCalendar.book(10, 20) << endl; // return True
    cout << myCalendar.book(15, 25) << endl; // return False
    cout << myCalendar.book(20, 30) << endl; // return True

    return 0;
}
