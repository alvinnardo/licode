#include "../template/head.h"
#include <bits/stdc++.h>

class SeatManager {
  public:
    // 思路：堆
    // reserver 单词时间 O(logn)，总时间 O(mlogn)，m 是调用次数
    // SeatManager 时间 O(nlogn)
    // 空间 O(n)
    // 因为题目给出 unreserve 时都是成立的，所以不需要保存不能预约的
    priority_queue<int, vector<int>, std::greater<int>> pq;
    SeatManager(int n) {
        // 最小堆
        for (int i = 1; i <= n; i++) {
            pq.push(i);
        }
    }

    int reserve() {
        int t = pq.top();
        pq.pop();
        return t;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};

int main(int argc, char *argv[]) {
    SeatManager seatManager(5);
    cout << seatManager.reserve() << endl; // 1
    cout << seatManager.reserve() << endl; // 2
    seatManager.unreserve(2);
    cout << seatManager.reserve() << endl; // 2
    cout << seatManager.reserve() << endl; // 3
    cout << seatManager.reserve() << endl; // 4
    cout << seatManager.reserve() << endl; // 5
    seatManager.unreserve(5);

    return 0;
}
