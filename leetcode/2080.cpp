#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：哈希表 + 二分查找
// 时间 O(n + klogn)，k 是查询次数，空间 O(n)
class RangeFreqQuery {
  public:
    // <数字：位置>，记录每次出现的位置，下标的差就是出现次数
    unordered_map<int, vector<int>> umap;
    RangeFreqQuery(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            umap[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        // 左面大于等于，右边小于等于
        if (umap.count(value) == 0) {
            return 0;
        }

        auto &vec = umap[value];
        auto l = lower_bound(vec.begin(), vec.end(), left) - vec.begin();
        if (l == vec.size()) {
            return 0;
        }
        auto r = upper_bound(vec.begin(), vec.end(), right) - vec.begin() - 1;

        return r - l + 1;
    }
};

int main(int argc, char *argv[]) {
    RangeFreqQuery *rangeFreqQuery =
        new RangeFreqQuery({12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56});
    cout << rangeFreqQuery->query(1, 11, 4) << endl;  //  1
    cout << rangeFreqQuery->query(1, 2, 4) << endl;   //  1
    cout << rangeFreqQuery->query(0, 11, 33) << endl; //  2
    cout << rangeFreqQuery->query(0, 0, 12) << endl;  //  1
    cout << rangeFreqQuery->query(0, 0, 33) << endl;  //  0

    // printVector(getNRandom(1, 100, 30));
    // int k = 5;
    // while (k--) {
    //     int t = getRandom(0, 29);
    //     int p = -1;
    //     while (p < t) {
    //         p = getRandom(0, 29);
    //     }
    //     cout << t << "," << p << "," << getRandom(1, 100) << endl;
    // }

    return 0;
}
