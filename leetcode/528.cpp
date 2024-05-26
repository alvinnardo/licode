#include "../template/head.h"
#include <bits/stdc++.h>

class Solution {
  public:
    // 思路：前缀和 + 二分查找
    // 初始化时间 O(n)，查询时间 O(logn)，空间 O(1)
    vector<int> &m_vec;
    int m_tot = 0;
    Solution(vector<int> &w) : m_vec(w) {
        for (int i = 1; i < m_vec.size(); i++) {
            m_vec[i] += m_vec[i - 1];
        }
        m_tot = m_vec.back();
        srand(time(NULL));
    }

    int pickIndex() {
        int r = rand() % m_tot + 1;
        return lower_bound(m_vec.begin(), m_vec.end(), r) - m_vec.begin();
    }
};

int main(int argc, char *argv[]) {
    vector<int> vec{1};
    Solution solution(vec);
    cout << solution.pickIndex() << endl;
    ;

    vec = {1, 3, 10, 12, 13};
    Solution solution2(vec);
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;
    cout << solution2.pickIndex() << endl;
    ;

    return 0;
}
