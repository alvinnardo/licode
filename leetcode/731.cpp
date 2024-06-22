#include "../template/head.h"
#include <bits/stdc++.h>

class MyCalendarTwo {
  public:
    // 思路：模拟
    // 时间: O(n2)，空间 O(n)
    vector<pair<int, int>> dur1, dur2;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto &dur : dur2) {
            if (end <= dur.first || start >= dur.second) {
                continue;
            }
            return false;
        }

        for (auto &dur : dur1) {
            if (!(end <= dur.first || start >= dur.second)) {
                dur2.emplace_back(max(dur.first, start), min(dur.second, end));
            }
        }

        dur1.emplace_back(start, end);
        return true;
    }
};

int main(int argc, char *argv[]) {
    MyCalendarTwo MyCalendar = MyCalendarTwo();
    cout << MyCalendar.book(10, 20) << endl; // returns true
    cout << MyCalendar.book(50, 60) << endl; // returns true
    cout << MyCalendar.book(10, 40) << endl; // returns true
    cout << MyCalendar.book(5, 15) << endl;  // returns false
    cout << MyCalendar.book(5, 10) << endl;  // returns true
    cout << MyCalendar.book(25, 55) << endl; // returns true

    return 0;
}
