#include "../template/head.h"
#include <bits/stdc++.h>

// 一开始理解的是，根据好友关系生成一群群的好友关系
// 然后让每一群都能有一门共同理解的语言
// 其实是好友关系，但是语言不通

// 这个是理解错了的解法
int minimumTeachings1(int n, vector<vector<int>> &&languages,
                      vector<vector<int>> &&friendships) {
    // 思路：哈希表 + BFS
    // 时间 O(m + kn)，空间 O(p)
    // m 是 friendships 所有元素个数, p = 501，k 是组数，最多 250

    // 记录每个组会语言的个数
    // 如果组中个数和最大语言个数相同，则不需要学新语言
    // 否则需要放在整体数组中，选择语言最大的值
    n++;                            // 语言从 1 开始
    vector<int> total(n), group(n); // 存放语言
    vector<vector<int>> fri_vv(501);
    for (auto &friendship : friendships) {
        fri_vv[friendship[0]].push_back(friendship[1]);
        fri_vv[friendship[1]].push_back(friendship[0]);
    }

    unordered_set<int> uset;
    int total_max{INT_MIN};
    for (int i = 0; i < fri_vv.size(); i++) {
        if (fri_vv[i].empty()) {
            continue;
        }
        group.clear();
        group.assign(n, 0);

        queue<int> qu;
        int num{}, maxv{INT_MIN};
        if (!uset.count(i)) { // 处理一组
            qu.push(i);
            int t{};
            while (!qu.empty()) {
                t = qu.front();
                qu.pop();
                if (uset.count(t)) {
                    continue;
                }

                for (auto p : fri_vv[t]) {
                    if (uset.count(p)) {
                        continue;
                    }
                    qu.push(p);
                }

                for (auto p : languages[t - 1]) {
                    maxv = max(maxv, ++group[p]);
                }

                uset.insert(t);
                num++;
            }

            // 如果这组人数和会的语言个数相同，那么就不用学新语言
            // 否则加入到全局中
            if (num != maxv) {
                for (int i = 0; i < n; i++) {
                    total[i] += group[i];
                    total_max = max(total_max, total[i]);
                }
            }
        }
    }

    return total_max < 0 ? 0 : uset.size() - total_max;
}

// 这个是通过的解法
int minimumTeachings(int n, vector<vector<int>> &&languages,
                     vector<vector<int>> &&friendships) {
    // 之前的解法题意理解貌似有问题
    // 重新理解为 已经是好友关系，但语言不通
    // 遍历朋友关系时，如果语言通则不统计，不通则统计
    // 最后学一门语言，找会语言多的个数

    // 思路：哈希表
    // 时间 O(mk + mn + kn)，空间 O(kn + k + n)，k 是人数
    unordered_set<int> uset;
    int k = languages.size() + 1;
    n++;
    vector<vector<int>> language_vv(n, vector<int>(k));
    languages.push_back({}); // 从 1 开始，加个占位
    for (int i = 1; i <= k; i++) {
        for (int l : languages[i - 1]) {
            language_vv[l][i] = 1;
        }
    }

    vector<int> total(n);
    int maxv{INT_MIN};
    for (auto &f : friendships) {
        // 在所有语言中，找到他俩是否都会的一种语言
        bool find = false;
        for (int i = 0; i < language_vv.size(); i++) {
            if (language_vv[i][f[0]] && language_vv[i][f[1]]) {
                find = true;
                break;
            }
        }

        if (!find) { // 统计语言个数
            if (!uset.count(f[0])) {
                for (int t : languages[f[0] - 1]) {
                    maxv = max(maxv, ++total[t]);
                }
                uset.insert(f[0]);
            }
            if (!uset.count(f[1])) {
                for (int t : languages[f[1] - 1]) {
                    maxv = max(maxv, ++total[t]);
                }
                uset.insert(f[1]);
            }
        }
    }

    return maxv < 0 ? 0 : uset.size() - maxv;
}

int main(int argc, char *argv[]) {
    // 1
    cout << minimumTeachings(2, {{1}, {2}, {1, 2}}, {{1, 2}, {1, 3}, {2, 3}})
         << endl;
    // 2
    cout << minimumTeachings(3, {{2}, {1, 3}, {1, 2}, {3}},
                             {{1, 4}, {1, 2}, {3, 4}, {2, 3}})
         << endl;
    // 0
    cout << minimumTeachings(11,
                             {{3, 11, 5, 10, 1, 4, 9, 7, 2, 8, 6},
                              {5, 10, 6, 4, 8, 7},
                              {6, 11, 7, 9},
                              {11, 10, 4},
                              {6, 2, 8, 4, 3},
                              {9, 2, 8, 4, 6, 1, 5, 7, 3, 10},
                              {7, 5, 11, 1, 3, 4},
                              {3, 4, 11, 10, 6, 2, 1, 7, 5, 8, 9},
                              {8, 6, 10, 2, 3, 1, 11, 5},
                              {5, 11, 6, 4, 2}},
                             {{7, 9}, {3, 7}, {3, 4}, {2, 9}, {1, 8}, {5, 9},
                              {8, 9}, {6, 9}, {3, 5}, {4, 5}, {4, 9}, {3, 6},
                              {1, 7}, {1, 3}, {2, 8}, {2, 6}, {5, 7}, {4, 6},
                              {5, 8}, {5, 6}, {2, 7}, {4, 8}, {3, 8}, {6, 8},
                              {2, 5}, {1, 4}, {1, 9}, {1, 6}, {6, 7}})
         << endl;

    return 0;
}
