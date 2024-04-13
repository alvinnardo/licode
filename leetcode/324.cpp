#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int> nums) {
    // 排序 + 贪心
    vector<int> res = nums;
    sort(res.begin(), res.end(), std::greater<int>());
    int idx = 0;
    for (int i = 1; i < res.size(); i += 2) {
        nums[i] = res[idx++];
    }
    for (int i = 0; i < res.size(); i += 2) {
        nums[i] = res[idx++];
    }

    printVector(nums);
}

int main(void) {
    wiggleSort({1, 5, 1, 1, 6, 4});
    wiggleSort({1, 3, 2, 2, 3, 1});
    wiggleSort({1, 2, 3, 4, 5});
    return 0;
}
