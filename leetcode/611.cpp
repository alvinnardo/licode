#include <bits/stdc++.h>
using namespace std;


int cntTri(const vector<int> &tnums)
{
    auto nums = tnums;
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    int cnt = 0;
    for (int i = sz - 1; i >= 2; i--)
    {
        int target = nums[i];
        for (int a = 0; a < i; a++) {
            int rem = target - nums[a];
            // 这里的 end 位置，要在允许的下标后 +1，比如 end() 是 最后一个下标 + 1
            auto pos = upper_bound(nums.begin() + a + 1, nums.begin() + i, rem) - nums.begin();
            int span = i - pos;
            if (span > 0)
                cnt += span;
        }
    }

    return cnt;
}


int main(void)
{
    // 最小的两边之和大于第三边
    cout << cntTri({{2,2,3,4}}) << endl;
    cout << cntTri({{4,2,3,4}}) << endl;
    cout << cntTri({{1,1,3,4}}) << endl;

    return 0;
}
