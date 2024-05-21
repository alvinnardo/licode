#include "../template/head.h"
#include <bits/stdc++.h>
#include <numeric>

class Solution {
  public:
    // 思路：要保证每个点的概率相等，首先要选矩形，再选点
    // 由于面积不等，所以如果选矩形概率相等，那么点的概率就不相等了
    // 所以要根据矩形的大小来判断选矩形的概率，用面积的最大公倍数
    // 然后判断每个增长区间选取哪个矩形，判断的时候可以用二分
    // 初始化的时间 O(n)，查询的时间 O(logn)，空间 O(n)

    // 思路2：思路1 有问题，如果面积都特别大，那么最大公倍数会十分大，
    // 最大约为 400_0000^1000，溢出了
    // 计算每个矩阵中点的个数，然后用面积当作个数，前缀和计算区间概率和
    // 查找用二分查找
    // 初始化时间 O(n)，查询时间 O(logn)，空间 O(n)
    vector<vector<int>> &m_vec;
    vector<int> p_vec;
    int m_tot = 0;
    Solution(vector<vector<int>> &rects) : m_vec(rects), p_vec(rects.size()) {
        int sz = m_vec.size();
        for (int i = 0; i < sz; i++) {
            auto &t = m_vec[i];
            p_vec[i] = (t[2] - t[0] + 1) * (t[3] - t[1] + 1);
        }

        // 累加概率
        for (int i = 1; i < sz; i++) {
            p_vec[i] += p_vec[i - 1];
        }
        m_tot = p_vec.back();
        srand(time(NULL));
    }

    vector<int> pick() {
        // 从 [1, m_tot] 抽数
        int num = rand() % m_tot + 1;
        // 二分找区间，大于等于
        auto pos = lower_bound(p_vec.begin(), p_vec.end(), num) - p_vec.begin();

        auto &rec = m_vec[pos];

        return {rand() % (rec[2] - rec[0] + 1) + rec[0],
                rand() % (rec[3] - rec[1] + 1) + rec[1]};
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> vec({{-2, -2, 1, 1}, {2, 2, 4, 6}});
    // vec = {{99358434, 62418790, 99360410, 62419739},
    //        {9949520, 63556732, 9949788, 63556965}};
    Solution solution(vec);
    printVector(solution.pick());
    printVector(solution.pick());
    printVector(solution.pick());
    printVector(solution.pick());
    printVector(solution.pick());

    return 0;
}
