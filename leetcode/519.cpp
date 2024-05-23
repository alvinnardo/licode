#include "../template/head.h"
#include <bits/stdc++.h>

class Solution {
  public:
    // 思路：拒绝采样 + 哈希表
    // 时间 O(1), 空间 O(k)，k 是翻后的 1 个数的最大值
    unordered_set<int> uset;
    int m_m, m_n;
    Solution(int m, int n) : m_m(m), m_n(n) { srand(time(NULL)); }

    vector<int> flip() {
        int m = 0, n = 0;
        while (true) {
            m = rand() % m_m, n = rand() % m_n;
            int t = m * 10000 + n;
            if (uset.find(t) == uset.end()) {
                uset.insert(t);
                break;
            }
        }

        return {m, n};
    }

    void reset() { uset.clear(); }
};

int main(int argc, char *argv[]) {
    Solution solution(3, 1);
    printVector(solution.flip());
    printVector(solution.flip());
    printVector(solution.flip());
    solution.reset();
    printVector(solution.flip());

    return 0;
}
