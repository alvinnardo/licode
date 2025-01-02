#include "../template/head.h"
#include <bits/stdc++.h>
int flipgame(vector<int> fronts, vector<int> backs) {
    // 思路：模拟
    // 使用两次扫描优化
    // 时间 O(n)，最差空间 O(n)

    unordered_set<int> ss;
    int sz = fronts.size();
    for (int i = 0; i < sz; i++) {
        if (fronts[i] == backs[i]) {
            ss.insert(fronts[i]);
        }
    }

    int minv = INT_MAX;
    for (int i = 0; i < sz; i++) {
        if (!ss.count(fronts[i]) && fronts[i] < minv) {
            minv = fronts[i];
        }
        if (!ss.count(backs[i]) && backs[i] < minv) {
            minv = backs[i];
        }
    }

    return minv == INT_MAX ? 0 : minv;
}

int flipgame1(vector<int> fronts, vector<int> backs) {
    // 思路：模拟
    // 如果前面的值和后面的值相同，那么该值一定不是结果
    // 找所有可能结果的最小值
    // 时间 O(nlogn)，空间 O(n)

    set<int> ss;
    int sz = fronts.size();
    ss.insert(fronts.begin(), fronts.end());
    ss.insert(backs.begin(), backs.end());
    for (int i = 0; i < sz; i++) {
        if (fronts[i] == backs[i]) {
            ss.erase(fronts[i]);
        }
    }

    return ss.empty() ? 0 : *ss.begin();
}

int main(int argc, char *argv[]) {
    // 2
    cout << flipgame({1, 2, 4, 4, 7}, {1, 3, 4, 1, 3}) << endl;
    // 0
    cout << flipgame({1}, {1}) << endl;

    return 0;
}
