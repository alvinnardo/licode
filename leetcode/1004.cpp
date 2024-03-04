#include <bits/stdc++.h>
using namespace std;

int longestOnes(const vector<int> &nums, int k)
{
    // 当 k > 0 时就移动右边，否则移动左边
    int left = 0, right = 0;
    int sz = nums.size();
    int max_len = INT_MIN;
    int len = 0;
    int t = k;
    while (right < sz) {
        if (nums[right] == 1) {
            len++;
            right++;
        } else if (t > 0) {
            len++;
            right++;
            t--;
        } else {
            if (nums[left] == 1) {
                left++;
                len--;
            } else {
                left++;
                len--;
                t++;
            }
        }
        cout << left << " " << right << ": " << len << endl;
        max_len = max(max_len, len);
    }

    return max_len;
}

int main(void)
{
    cout << longestOnes({1,1,1,0,0,0,1,1,1,1,0}, 2) << endl; // 6
    cout << longestOnes({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3) << endl; // 10
    cout << longestOnes({0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0}, 3) << endl;
    cout << longestOnes({0,0,0,1,1,1,0}, 0) << endl;
    cout << longestOnes({0,0,0,0,0}, 0) << endl;
    cout << longestOnes({0,0,1,1,1,0,0,0,1,1,1,1,1}, 0) << endl;
    cout << longestOnes({0,1}, 0) << endl;
    cout << longestOnes({0,0,0,0,0,0}, 0) << endl;


    return 0;
}
