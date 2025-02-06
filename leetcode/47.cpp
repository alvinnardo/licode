#include "../template/head.h"
#include <bits/stdc++.h>
vector<vector<int>> permuteUnique(vector<int> nums) {
    // 测试使用每层哈希表的时间
    vector<vector<int>> res;
    vector<int> tmp;
    int sz = nums.size();
    vector<int> visited(sz); // 优化

    // 不排序
    function<void(void)> dfs = [&]() {
        if (tmp.size() == sz) {
            res.emplace_back(tmp);
            return;
        }

        unordered_set<int> same;
        for (int i = 0; i < sz; i++) {
            if (visited[i] || same.count(nums[i])) {
                continue;
            }

            tmp.emplace_back(nums[i]);
            same.insert(nums[i]);
            visited[i] = 1;
            dfs();
            tmp.pop_back();
            visited[i] = 0;
        }
    };

    dfs();
    return res;
}

vector<vector<int>> permuteUnique2(vector<int> nums) {
    // 思路: 回溯
    // 时间 O(n^n)，空间 O(n)
    // 枚举选哪个：1. 排序 2.每层选一个，重复的不选
    vector<vector<int>> res;
    vector<int> tmp;
    int sz = nums.size();
    vector<int> visited(sz); // 优化

    sort(nums.begin(), nums.end());
    function<void(void)> dfs = [&]() {
        if (tmp.size() == sz) {
            res.emplace_back(tmp);
            return;
        }

        for (int i = 0; i < sz; i++) {
            if (visited[i]) {
                continue;
            }

            // 这个地方比较难理解：本质上就是前面没选的后面也不应该选
            // 1. 对于同一层，如果选了，那么选的是第一次出现的数字，
            //    后面重复的数字由于前面没选，则后面的也不应该选
            // 2. 对于不同层，比如第 2 层，选的是第 2 次出现的数字
            //    如果前面选了，则后面紧跟的也能选，即第 2 个
            // 这个逻辑不好处理的话，还是不排序 + 一个哈希表保存每层的即可
            if (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) {
                continue;
            }

            tmp.emplace_back(nums[i]);
            visited[i] = 1;
            dfs();
            tmp.pop_back();
            visited[i] = 0;
        }
    };

    dfs();
    return res;
}

vector<vector<int>> permuteUnique1(vector<int> nums) {
    // 思路：回溯
    // 枚举选哪个
    //     每层选一个，重复的不选
    // 时间 O(n^n)，空间 O(n)
    // 个数范围上限是 8，最多 8^8，大约 1.67e7

    vector<vector<int>> res;
    vector<int> tmp;
    // 用于判断该下标是否使用过
    unordered_set<int> visited;
    int sz = nums.size();

    function<void()> dfs = [&]() {
        if (tmp.size() == sz) {
            res.emplace_back(tmp);
            return;
        }

        // 每层不能选重复的
        unordered_set<int> same;
        for (int i = 0; i < sz; i++) {
            if (visited.count(i)) {
                continue;
            }
            if (same.count(nums[i])) {
                continue;
            }

            same.insert(nums[i]);
            tmp.emplace_back(nums[i]);
            visited.insert(i);
            dfs();
            tmp.pop_back();
            visited.erase(i);
        }
    };

    dfs();
    return res;
}

int main(int argc, char *argv[]) {
    // {{1,1,2},{1,2,1},{2,1,1}}
    printVectorVector(permuteUnique({1, 1, 2}));
    // {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}
    printVectorVector(permuteUnique({1, 2, 3}));
    printVectorVector(permuteUnique({1, 2, 3, 4, 5, 6, 7, 8}));

    return 0;
}
