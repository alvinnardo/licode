#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

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
