#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> m_nums;
    Solution(vector<int> &nums) : m_nums(nums) { srand(time(NULL)); }

    vector<int> reset() { return m_nums; }

    vector<int> shuffle() {
        vector<int> res = m_nums;
        for (int i = 0; i < m_nums.size(); i++) {
            int idx = rand() % (i + 1);
            swap(res[i], res[idx]);
        }
        return res;
    }
};

int main(void) {

    vector<int> nums{1, 2, 3};
    Solution solution = Solution(nums);
    printVector(solution.shuffle());
    // printVector(solution.reset());
    printVector(solution.shuffle());
    // printVector(solution.reset());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    printVector(solution.shuffle());
    return 0;
}
