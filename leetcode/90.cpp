#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetsWithDup_review_1(vector<int> nums) {
    // 思路：回溯
    // 选或不选:
    //     1. 先排序
    //     2. 如果当前数字和上一个数字一样，且上一个数字没有选，则当前数字不能选
    //        因为有一种上一个数字选中的情况
    // 时间 O(2^n)，空间 O(n)，栈的空间，保存结果的不算

    vector<vector<int>> res;
    vector<int> tmp;

    sort(nums.begin(), nums.end());
    function<void(int, bool)> dfs = [&](int pos, bool choose) {
        if (pos == nums.size()) {
            res.emplace_back(tmp);
            return;
        }

        dfs(pos + 1, false);
        if (!(pos > 0 && !choose && nums[pos] == nums[pos - 1])) {
            tmp.emplace_back(nums[pos]);
            dfs(pos + 1, true);
            tmp.pop_back();
        }
    };

    dfs(0, false);
    return res;
}

vector<vector<int>> subsetsWithDup_review_2(vector<int> nums) {
    // 思路：回溯
    // 枚举选哪一个，见 40 题解法
    //     1. 排序
    //     2. 每一层选一个数字，如果当前层后续数字重复则不选
    //        主要是判断每一层(pos > i), 重复的数字 (后 == 前)
    // 时间 O(2^n)，空间 O(n)，栈的空间，保存结果的不算

    vector<vector<int>> res;
    vector<int> tmp;

    sort(nums.begin(), nums.end());
    function<void(int)> dfs = [&](int pos) {
        res.emplace_back(tmp);

        // 每次进入循环就是一层
        for (int i = pos; i < nums.size(); i++) {
            // 每一层选一个数，如果重复就不选
            // 在每一层中，判断是否重复从 pos >= i + 1 开始
            if (i > pos && nums[i] == nums[i - 1]) {
                continue;
            }

            tmp.push_back(nums[i]);
            dfs(i + 1);
            tmp.pop_back();
        }
    };

    dfs(0);
    return res;
}

vector<vector<int>> subsetsWithDup(vector<int> nums) {
    // 如果当前的数字和之前的数字相同，且前面的数字没有被选择时，
    // 再选择当前的数字就会重复
    // 比如 [2,2]，第一个 2 选或不选，选的时候，就是 [2 ..], 不选的时候就是 [
    // ..] 第一个 2 选，第二个 2 选或不选，选的时候 [2, 2]，不选的时候 [2]
    // 第一个 2 不选，第二个 2 选或不选，选的时候 [2]，不选的时候 []
    // 所以第一个 2 不选，第二个 2 也不能选
    sort(nums.begin(), nums.end()); // O(nlogn)
    vector<vector<int>> res;

    // 2^n 次方的状态，每个状态构造答案 O(n)，总的是 O(n2^n) 大于 O(nlogn)
    vector<int> each;
    function<void(int)> dfs = [&](int pos) {
        if (pos == nums.size()) {
            res.emplace_back(each);
            return;
        }

        each.push_back(nums[pos]);
        dfs(pos + 1);
        each.pop_back();

        // 一旦不选，则相同的数字都不选
        while (pos + 1 < nums.size() && nums[pos + 1] == nums[pos]) {
            pos++;
        }
        dfs(pos + 1);
    };

    dfs(0);
    return res;
}
vector<vector<int>> subsetsWithDup_my(vector<int> nums) {
    vector<vector<int>> res;
    // 用一个哈希表来存放重复的值

    vector<int> each;
    unordered_set<string> uset;
    function<void(int)> dfs = [&](int pos) {
        if (pos == nums.size()) {
            vector<int> vec(21);
            for (auto &i : each) {
                vec[i + 10]++;
            }
            std::string tstr;
            for (int i = 0; i < 21; i++) {
                tstr += (char)('a' + i) + to_string(vec[i]);
            }
            if (uset.find(tstr) == uset.end()) {
                uset.insert(tstr);
                res.emplace_back(each);
            }
            return;
        }

        dfs(pos + 1);
        each.push_back(nums[pos]);
        dfs(pos + 1);
        each.pop_back();
    };

    dfs(0);
    return res;
}

int main(void) {
    printVectorVector(subsetsWithDup({1, 2, -10, 3, 0, 1, -10, 10, 9, 7}));

    return 0;
}
