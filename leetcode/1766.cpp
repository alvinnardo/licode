#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> getCoprimes(vector<int> nums, vector<vector<int>> edges) {
    // 思路：将节点下推，从后往前找到第一个互质的节点
    int n = nums.size();
    vector<int> res(n, -1);
    vector<vector<int>> new_edges(n);
    for (auto &edge : edges) {
        new_edges[edge[0]].push_back(edge[1]);
        new_edges[edge[1]].push_back(edge[0]);
    }

    // 存放质数
    vector<vector<int>> coprimes(51);

    // DFS
    unordered_set<int> seen;
    vector<pair<int, int>> pos(51, {-1, -1}); // 值和{节点，权值}的映射
    function<void(int)> dfs = [&](int node) {
        if (seen.find(node) != seen.end()) {
            return;
        }
        seen.insert(node);

        int val = nums[node];
        if (coprimes[val].empty()) {
            for (int i = 1; i <= 50; i++) {
                if (__gcd(val, i) == 1) {
                    coprimes[val].push_back(i);
                }
            }
        }

        int min_pos = INT_MAX;
        int min_node = -1;
        for (int i : coprimes[val]) {
            if (pos[i].second != -1 && pos[i].second < min_pos) {
                min_pos = pos[i].second;
                min_node = pos[i].first;
            }
        }

        res[node] = min_node;

        auto tmp = pos;
        for (int i = 1; i <= 50; i++) {
            if (i == val) {
                pos[i].first = node;
                pos[i].second = 0;
            } else if (pos[i].second != -1) {
                pos[i].second++;
            }
        }
        for (int e : new_edges[node]) {
            dfs(e);
        }
        pos = tmp;
    };

    dfs(0);
    return res;
}

int main(void) {
    // [-1, 0, 0, 1]
    printVector(getCoprimes({2, 3, 3, 2}, {{0, 1}, {1, 2}, {1, 3}}));
    // [-1, 0, -1, 0, 0, 0, -1]
    printVector(getCoprimes({5, 6, 10, 2, 3, 6, 15},
                            {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2,
                            6}}));

    printVector(getCoprimes(
        {9,  16, 30, 23, 33, 35, 9,  47, 39, 46, 16, 38, 5,  49, 21, 44,
         17, 1,  6,  37, 49, 15, 23, 46, 38, 9,  27, 3,  24, 1,  14, 17,
         12, 23, 43, 38, 12, 4,  8,  17, 11, 18, 26, 22, 49, 14, 9},
        {{17, 0},  {30, 17}, {41, 30}, {10, 30}, {13, 10}, {7, 13},  {6, 7},
         {45, 10}, {2, 10},  {14, 2},  {40, 14}, {28, 40}, {29, 40}, {8, 29},
         {15, 29}, {26, 15}, {23, 40}, {19, 23}, {34, 19}, {18, 23}, {42,
         18}, {5, 42},  {32, 5},  {16, 32}, {35, 14}, {25, 35}, {43, 25}, {3,
         43}, {36, 25}, {38, 36}, {27, 38}, {24, 36}, {31, 24}, {11, 31},
         {39, 24}, {12, 39}, {20, 12}, {22, 12}, {21, 39}, {1, 21},  {33, 1},
         {37, 1}, {44, 37}, {9, 44},  {46, 2},  {4, 46}}));

    return 0;
}
