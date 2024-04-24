#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    unordered_map<int, vector<int>> umap; // 存放数字和索引的映射
  public:
    Solution(vector<int> &nums) {
        srand(time(NULL));
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        if (umap.find(target) != umap.end()) {
            auto t = umap[target];
            return t[rand() % t.size()];
        }

        return -1;
    }
};

int main(void) {

    vector<int> nums{1, 2, 3, 3, 3};
    Solution solution(nums);

    // 2 || 3 || 4
    cout << solution.pick(3) << endl;
    // 0
    cout << solution.pick(1) << endl;
    // 2 || 3 || 4
    cout << solution.pick(3) << endl;

    return 0;
}
