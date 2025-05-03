#include "../template/head.h"
#include <bits/stdc++.h>
int minDominoRotations(vector<int> tops, vector<int> bottoms) {
    // 思路：遍历
    // 时间 O(n)，空间 O(1)

    // 可选数字肯定是来自 pos 0 的
    // 拿 pos 0 的两个数字遍历即可
    int a = tops[0], a_up = 1, a_down = 0;
    int b = bottoms[0], b_up = 0, b_down = 1;
    if (a == b) { // 考虑相同
        a_down = 1;
        b_up = 1;
    }

    int sz = tops.size();
    bool fa = true, fb = true;
    for (int i = 1; i < sz; i++) {
        if (fa) {
            if (tops[i] != a && bottoms[i] != a) {
                fa = false;
            }
            if (tops[i] == a) {
                a_up++;
            }
            if (bottoms[i] == a) {
                a_down++;
            }
        }

        if (fb) {
            if (tops[i] != b && bottoms[i] != b) {
                fb = false;
            }
            if (tops[i] == b) {
                b_up++;
            }
            if (bottoms[i] == b) {
                b_down++;
            }
        }

        if (!fa && !fb) {
            return -1;
        }
    }

    // 如果都成立，那么互斥，选 a 和 b 都行
    if (fa) {
        return min(sz - a_up, sz - a_down);
    }
    return min(sz - b_up, sz - b_down);
}

// 这个太复杂了
int minDominoRotations1(vector<int> tops, vector<int> bottoms) {
    // 思路：分类讨论 + 哈希表
    // 时间 O(n)，空间 O(1)

    int sz = tops.size();

    struct Info {
        int up = 0;
        int down = 0;
    };

    // 前两个位置能够确定需要找的数字
    // 出现至少两次，且不能在同一个位置
    unordered_map<int, int> umap;
    unordered_map<int, Info> uinfo;
    umap[tops[0]]++;
    umap[tops[1]]++;
    umap[bottoms[0]]++;
    umap[bottoms[1]]++;
    if (umap.size() == 4) {
        return -1;
    } else if (umap.size() == 3) {
        if (tops[0] == bottoms[0] || tops[1] == bottoms[1]) {
            return -1;
        }
        for (auto &p : umap) {
            if (p.second == 2) {
                for (int i = 0; i < 2; i++) {
                    if (tops[i] == p.first) {
                        uinfo[p.first].up++;
                    }
                    if (bottoms[i] == p.first) {
                        uinfo[p.first].down++;
                    }
                }
                break;
            }
        }
    } else if (umap.size() == 2) {
        if (umap.begin()->second == 2) {
            if (tops[0] == bottoms[0] || tops[1] == bottoms[1]) {
                return -1;
            }
            for (auto &p : umap) {
                for (int i = 0; i < 2; i++) {
                    if (tops[i] == p.first) {
                        uinfo[p.first].up++;
                    }
                    if (bottoms[i] == p.first) {
                        uinfo[p.first].down++;
                    }
                }
            }
        } else {
            int t = 0;
            for (auto &p : umap) {
                if (p.second == 3) {
                    t = p.first;
                }
            }
            for (int i = 0; i < 2; i++) {
                if (tops[i] == t) {
                    uinfo[t].up++;
                }
                if (bottoms[i] == t) {
                    uinfo[t].down++;
                }
            }
        }
    } else {
        int t = umap.begin()->first;
        for (int i = 0; i < 2; i++) {
            if (tops[i] == t) {
                uinfo[t].up++;
            }
            if (bottoms[i] == t) {
                uinfo[t].down++;
            }
        }
    }

    for (int i = 2; i < sz; i++) {
        auto it1 = uinfo.find(tops[i]);
        auto it2 = uinfo.find(bottoms[i]);
        // 之前都没出现过
        if (it1 == uinfo.end() && it2 == uinfo.end()) {
            return -1;
        }

        // 两个数一样
        if (it1 != uinfo.end() && it2 != uinfo.end()) {
            if (it1 == it2) {
                it1->second.up++;
                it1->second.down++;
                if (uinfo.size() == 2) { // 把没出现的删掉
                    for (auto &p : uinfo) {
                        if (p.first != tops[i]) {
                            uinfo.erase(p.first);
                            break;
                        }
                    }
                }

            } else {
                it1->second.up++;
                it2->second.down++;
            }
        } else if (it1 != uinfo.end()) {
            it1->second.up++;
            for (auto &p : uinfo) {
                if (p.first != tops[i]) {
                    uinfo.erase(p.first);
                    break;
                }
            }
        } else if (it2 != uinfo.end()) {
            it2->second.down++;
            for (auto &p : uinfo) {
                if (p.first != bottoms[i]) {
                    uinfo.erase(p.first);
                    break;
                }
            }
        }
    }

    // 如果是 2 个，则是互斥的，选一个就行
    return min(sz - uinfo.begin()->second.up, sz - uinfo.begin()->second.down);
}

int main(int argc, char *argv[]) {
    // 2
    cout << minDominoRotations({2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}) << endl;
    // -1
    cout << minDominoRotations({3, 5, 1, 2, 3}, {3, 6, 3, 3, 4}) << endl;
    // 6
    cout << minDominoRotations(
                {1, 1, 2, 1, 4, 1, 3, 6, 1, 1, 6, 6, 6, 5, 1, 5, 1, 2, 2, 6, 2},
                {1, 5, 1, 2, 1, 2, 1, 1, 1, 6, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1})
         << endl;

    return 0;
}
