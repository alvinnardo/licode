#include "../template/head.h"
#include <bits/stdc++.h>

class MyCalendarThree {
  public:
    // 思路：差分数组 + 红黑树
    // 因为数值范围比较大，所以用红黑树
    // 总时间 O(n2)，空间 O(n)
    map<int, int> mm;
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        mm[startTime]++;
        mm[endTime]--;
        int t = 0, maxv = INT_MIN;
        for (auto &it : mm) {
            t += it.second;
            maxv = max(maxv, t);
        }
        return maxv;
    }
};

int main(int argc, char *argv[]) {

    MyCalendarThree cal;
    // 1
    cout << cal.book(10, 20) << endl;
    // 1
    cout << cal.book(50, 60) << endl;
    // 2
    cout << cal.book(10, 40) << endl;
    // 3
    cout << cal.book(5, 15) << endl;
    // 3
    cout << cal.book(5, 10) << endl;
    // 3
    cout << cal.book(25, 55) << endl;

    return 0;
}
