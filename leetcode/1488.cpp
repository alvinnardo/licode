#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> avoidFlood(vector<int> &&rains) {
    // 思路：贪心 + 哈希表 + 红黑树
    // 时间 O(nlogn)，空间 O(n)

    // 哈希表存放之前下过雨的湖泊
    // 队列存放没下雨的日子
    // 后面遇到再下雨的天，查找中间是否有没下雨的日子

    // 不用队列是考虑到 [2, 0, 0, 2, 0, 2] 的情况，
    // 第 3 个 2 需要填充第 3 个 0
    int sz = rains.size();
    unordered_map<int, int> umap;
    set<int> st;

    vector<int> res;
    for (int i = 0; i < sz; i++) {
        if (rains[i] > 0) {
            if (umap.contains(rains[i])) { // 之前下过雨，要找一天抽
                if (st.empty()) {
                    return {};
                }

                auto it = st.upper_bound(umap[rains[i]]); // 获取下雨那天
                // 如果下雨之后有没下雨的日子，则在那天抽该湖泊
                if (it != st.end()) {
                    res[*it] = rains[i];
                    umap[rains[i]] = i; // 更新下雨的日子
                    st.erase(it);
                    res.push_back(-1);
                } else { // 如果没法抽取，直接返回
                    return {};
                }

            } else { // 之前是空的，记录下来
                umap[rains[i]] = i;
                res.push_back(-1);
            }
        } else {
            // 最后处理也是抽取第一个，中间处理时会覆盖，这里直接放 1 即可
            res.push_back(1);
            st.insert(i); // 记录没下雨的日子
        }
    }

    /*
    // 处理其余待定的日子
    // 因为都安排好了，所以可以在出现的湖泊中随便抽
    // 有无数个湖泊，直接抽第 1 个即可
    for (int i = 0; i < sz; i++) {
        if (res[i] == -2) {
            res[i] = 1;
        }
    }
    */

    return res;
}

int main(int argc, char *argv[]) {
    // {-1,-1,-1,-1}
    cout << avoidFlood({1, 2, 3, 4}) << endl;
    // {-1,-1,2,1,-1,-1}
    cout << avoidFlood({1, 2, 0, 0, 2, 1}) << endl;
    // {}
    cout << avoidFlood({1, 2, 0, 1, 2}) << endl;

    return 0;
}
