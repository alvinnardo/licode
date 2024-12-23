#include "../template/head.h"
#include <bits/stdc++.h>
struct cmp {
    // 距离先取大的，如果距离相同，则取位置小的那个
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        int disa = a.second >> 1, disb = b.second >> 1;
        if (disa == disb) {
            return a.first + disa > b.first + disb;
        }
        return disa < disb;
    }
};

class ExamRoom {
  public:
    // 思路：红黑树 + 优先队列
    // 用红黑树保存有人的位置，优先队列保存长度
    // 删除时，红黑树可以先删除，队列中先不删除，先判断一下是否存在且是否为后续节点
    // 时间 O(nlogn)，空间 O(n)

    int m_end = 0;
    set<int> ss;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    ExamRoom(int n) : m_end(n - 1) {}

    int seat() {
        while (!pq.empty()) {
            auto &t = pq.top();
            auto pos1 = ss.find(t.first);
            auto pos2 = ss.find(t.first + t.second);
            if (pos1 == ss.end() || pos2 == ss.end() ||
                // 不指向一个位置，但下一个位置不是
                pos1 != pos2 && next(pos1) != pos2 ||
                // 指向同一个位置，但后面还有其它元素
                pos1 == pos2 && next(pos1) != ss.end()) {
                pq.pop();
            } else {
                break;
            }
        }

        if (ss.empty()) {
            ss.insert(0);
            pq.emplace(0, 0);
            return 0;
        }

        int min_val = -1, min_dis = INT_MIN;
        int elected = -1, res = -1;
        if (!pq.empty() && pq.top().second != 0) {
            min_val = pq.top().first;
            min_dis = pq.top().second >> 1;
            elected = 0;
            res = min_val + min_dis;
        }

        if (*ss.begin() != 0 && *ss.begin() >= min_dis) {
            min_val = 0;
            min_dis = *ss.begin();
            elected = 1;
            res = min_val;
        }

        if (*ss.rbegin() != m_end && m_end - *ss.rbegin() > min_dis) {
            min_val = m_end;
            min_dis = 0;
            elected = 2;
            res = min_val;
        }

        if (elected == 0) {
            ss.insert(res);
            pq.emplace(min_val, res - min_val);
            pq.emplace(res, pq.top().first + pq.top().second - res);
            pq.pop();

        } else if (elected == 1) {
            ss.insert(min_val);
            pq.emplace(min_val, min_dis);
        } else if (elected == 2) {
            ss.insert(min_val);
            pq.emplace(min_val, min_dis);
            auto pos = ss.find(min_val);
            if (ss.size() > 1) {
                pq.emplace(*std::prev(pos), *ss.rbegin() - *std::prev(pos));
            }
        }

        return res;
    }

    void leave(int p) {
        if (ss.size() == 2) {
            if (*ss.rbegin() == p) {
                pq.emplace(*ss.begin(), 0);
            }
        } else {
            auto pos1 = ss.find(p);
            if (*ss.begin() == p) {
            } else if (*ss.rbegin() == p) {
                pq.emplace(*std::prev(pos1), 0);
            } else {
                // 更新距离
                pq.emplace(*std::prev(pos1),
                           *std::next(pos1) - *std::prev(pos1));
            }
        }
        ss.erase(p);
    }
};

int main(int argc, char *argv[]) {
    // ExamRoom examRoom(10);
    // cout << examRoom.seat() << endl; // 0
    // cout << examRoom.seat() << endl; // 9
    // cout << examRoom.seat() << endl; // 4
    // cout << examRoom.seat() << endl; // 2
    // examRoom.leave(4);
    // cout << examRoom.seat() << endl; // 5
    ExamRoom examRoom(30);
    cout << examRoom.seat() << endl; // 0
    cout << examRoom.seat() << endl; // 29
    cout << examRoom.seat() << endl; // 14
    cout << examRoom.seat() << endl; // 7
    cout << examRoom.seat() << endl; // 21
    cout << examRoom.seat() << endl; // 25
    examRoom.leave(7);
    examRoom.leave(0);
    cout << examRoom.seat() << endl; // 0
    examRoom.leave(25);
    examRoom.leave(29);
    examRoom.leave(21);
    cout << examRoom.seat() << endl; // 29
    cout << examRoom.seat() << endl; // 7
    cout << examRoom.seat() << endl; // 21

    return 0;
}
