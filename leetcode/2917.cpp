#include <bits/stdc++.h>
using namespace std;


int findKOr(const vector<int> &nums, int k)
{
    int res = 0;
    int mask = 1;

    for (int i = 0; i < 32; i++)
    {
        int cnt = 0;
        for (auto &num : nums) {
            if (num & mask) {
                cnt++;
                if (cnt == k) break;
            }
        }

        // cout << cnt << endl;
        if (cnt >= k) {
            res ^= mask;
        }

        mask <<= 1;
    }

    return res;
}

int main(void)
{

    cout << findKOr({7,12,9,8,9,15}, 4) << endl; // 9
    cout << findKOr({2,12,1,11,4,5}, 6) << endl; // 0
    cout << findKOr({10,8,5,9,11,6,8}, 1) << endl; // 15
    cout << findKOr({INT_MAX}, 1) << endl;
    cout << findKOr({INT_MAX, INT_MAX}, 2) << endl;


    return 0;
}
