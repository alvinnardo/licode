#include <bits/stdc++.h>
using namespace std;

long long maxArrayValue_my(vector<int> ori) {
    // 从某个位置往前推，逐渐累加，并统计最大值，直至遇到一个特别大的数字
    // 然后从该数字开始继续

    vector<long long> nums(ori.begin(), ori.end());
    int sz = nums.size();
    long long maxv = INT_MIN;
    bool start = true;
    long long sum = 0;
    for (int i = sz - 1; i >= 0; --i) {
        if (start) {
            sum += nums[i];
            maxv = max(maxv, sum);
            start = false;
        } else if (nums[i] <= nums[i + 1]) {
            sum += nums[i];
            nums[i] += nums[i + 1];
            maxv = max(maxv, sum);
        } else {
            ++i; // 抵消 --i
            start = true;
            sum = 0;
        }
    }

    return maxv;
}

long long maxArrayValue(const vector<int> &nums) {
    int sz = nums.size();
    long long sum = nums.back();
    for (int i = sz - 2; i >= 0; i--) {
        // 从后往前逐渐累加，当碰到比累加值更大的值，就累加值就等于该值
        sum = nums[i] <= sum ? nums[i] + sum : nums[i];
    }

    return sum;
}

int main(void) {
    cout << maxArrayValue({2, 3, 7, 9, 3}) << endl;
    cout << maxArrayValue({5, 3, 3}) << endl;
    cout << maxArrayValue({4, 5, 3, 6}) << endl;
    cout << maxArrayValue({5, 6, 4, 6}) << endl;

    return 0;
}
