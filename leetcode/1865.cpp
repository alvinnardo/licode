#include "../template/head.h"
#include <bits/stdc++.h>

class FindSumPairs {
    // 思路：红黑树 + 哈希表 + 排序
  public:
    // m 指 nums1 大小，n 指 nums2 大小, k 指调用次数
    // 总时间 O(nlogn + mklogn)，总空间 O(n)
    // 查询用的时间比较多，用一个哈希表优化一下时间

    vector<int> m_nums1;
    vector<int> m_nums2;
    map<int, int> m_map;
    unordered_map<int, int> umap; // 存放计算过的结果
    // 时间 O(mlogm + nlogn)
    FindSumPairs(vector<int> &&nums1, vector<int> &&nums2)
        : m_nums1(nums1), m_nums2(nums2) {
        sort(m_nums1.begin(), m_nums1.end());
        for (int i = 0; i < m_nums2.size(); i++) {
            m_map[m_nums2[i]]++;
        }
    }

    // 时间 O(logn)
    void add(int index, int val) {
        umap.clear();
        if (--m_map[m_nums2[index]] == 0) {
            m_map.erase(m_nums2[index]);
        }
        m_nums2[index] += val;
        m_map[m_nums2[index]]++;
    }

    // 时间 O(mlogn)
    int count(int tot) {
        if (umap.count(tot)) {
            return umap[tot];
        }
        int cnt = 0;
        for (int i = 0; i < m_nums1.size(); i++) {
            int ret = tot - m_nums1[i];
            if (ret < m_map.begin()->first) {
                break;
            }

            if (m_map.count(ret)) {
                cnt += m_map[ret];
            }
        }
        umap[tot] = cnt;
        return cnt;
    }
};

int main(int argc, char *argv[]) {

    FindSumPairs findSumPairs =
        FindSumPairs({1, 1, 2, 2, 2, 3}, {1, 4, 5, 2, 5, 4});
    cout << findSumPairs.count(7) << endl; // 8
    findSumPairs.add(3, 2);
    cout << findSumPairs.count(8) << endl; // 2
    cout << findSumPairs.count(4) << endl; // 1
    findSumPairs.add(0, 1);
    findSumPairs.add(1, 1);
    cout << findSumPairs.count(7) << endl; // 11

    return 0;
}
