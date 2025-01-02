#include "../template/head.h"
#include <bits/stdc++.h>

class MyCalendar {
  public:
    // 思路：红黑树
    // 之前用 vector，查找是 O(n)
    // 查找时间 O(klogn)，空间 O(k)
    map<int, int> mm;
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = mm.upper_bound(start);
        // 找严格大于的后一个
        if (it != mm.end() && it->first < end) {
            return false;
        }
        // 找前一个
        if (!mm.empty()) {
            auto it2 = std::prev(it);
            if (it2 != it && it2 != mm.end() &&
                (it2->first == start || it2->second > start)) {
                return false;
            }
        }

        mm[start] = end;
        return true;
    }
};

class MyCalendar1 {
  public:
    vector<pair<int, int>> vec;
    MyCalendar1() {}

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
    // cout << myCalendar.book(10, 20) << endl; // return True
    // cout << myCalendar.book(15, 25) << endl; // return False
    // cout << myCalendar.book(20, 30) << endl; // return True
    cout << myCalendar.book(47, 50) << endl; // 1
    cout << myCalendar.book(33, 41) << endl; // 1
    cout << myCalendar.book(39, 45) << endl; // 0
    cout << myCalendar.book(33, 42) << endl; // 0
    cout << myCalendar.book(25, 32) << endl; // 1
    cout << myCalendar.book(26, 35) << endl; // 0
    cout << myCalendar.book(19, 25) << endl; // 1
    cout << myCalendar.book(3, 8) << endl;   // 1
    cout << myCalendar.book(8, 13) << endl;  // 1
    cout << myCalendar.book(18, 27) << endl; // 0

    return 0;
}
