#include "head.h"
#include <bits/stdc++.h>
using namespace std;

void subsets(const vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    int sz = nums.size();
    function<void(int)> dfs = [&](int i) {
        if (i == sz) {
            res.emplace_back(tmp);
            return;
        }

        dfs(i + 1);
        tmp.push_back(nums[i]);
        dfs(i + 1);
        tmp.pop_back();
    };

    // 按照答案的角度，每次填入 j+1 .. j+n
    function<void(int)> dfs2 = [&](int i) {
        res.emplace_back(tmp);
        if (i == sz) {
            return;
        }

        for (int p = i; p < sz; p++) {
            tmp.push_back(nums[p]); // 放一个
            dfs2(p + 1);            // 继续后面的
            tmp.pop_back();         // 把放的那个拿出来
        }
    };

    dfs2(0);
    printVectorVector(res);
}

int main(void) {
    subsets({1, 2, 3});

    return 0;
}
