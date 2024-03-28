#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int firstDayBeenInAllRooms(const vector<int> &nextVisit) {
    // 找规律，主要是差值
    // 差分数组
    // 下一个值 = 前面的累加值 + 差值 + 最后一天包围的2

    int sz = nextVisit.size();
    if (sz == 1)
        return 0;

    int mod = 1e9 + 7;
    vector<int> vec;
    long long tmp = 0;
    for (int i = 0; i < sz - 1; i++) {
        if (i == 0) {
            vec.push_back(2); // [0,X] 结果是 2
            continue;
        }

        tmp = 0;
        if (nextVisit[i] == 0) {
            // 从 0 开始到 i - 1
            tmp = tmp + vec[i - 1] + vec[i - 1] + 2;
        } else {
            // 从 k 开始 到 i - 1，就是 vec[i-1] - vec[k - 1]
            tmp = tmp + vec[i - 1] + vec[i - 1] - vec[nextVisit[i] - 1] + 2;
        }
        vec.push_back((tmp + mod) % mod); // 可能有负值
    }

    // printVector(vec);
    return vec.back();
}

int main(void) {
    cout << firstDayBeenInAllRooms({0, 1, 0, 1, 1}) << endl; // 20
    cout << firstDayBeenInAllRooms({0, 0}) << endl;          // 2
    cout << firstDayBeenInAllRooms({0, 0, 1}) << endl;       // 6
    cout << firstDayBeenInAllRooms({0, 1, 1}) << endl;       // 4
    cout << firstDayBeenInAllRooms({0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48}); // 86417750
    return 0;
}

