#include "../template/head.h"
#include <bits/stdc++.h>

int maxChunksToSorted(vector<int> arr) {
    // 题解：直接比较当前块的最大值
    // 时间 O(n)，空间(1)
    int maxv = -1, cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxv = max(maxv, arr[i]);
        cnt += maxv == i;
    }
    return cnt;
}

int maxChunksToSorted2(vector<int> arr) {
    // 思路：这道题没有重复数字，可以直接用前缀和
    // 时间 O(n)，空间 O(1)
    int sum = 0, sum2 = 0;
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        sum2 += i;
        if (sum == sum2) {
            res++;
            sum = sum2 = 0;
        }
    }

    return res;
}

int maxChunksToSorted_my(vector<int> arr) {
    // 思路：模拟
    // 时间 O(n2logn)，空间 O(n)
    vector<int> arr2 = arr;
    vector<int> tmp, tmp2;

    sort(arr2.begin(), arr2.end());
    int sz = arr.size();
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        tmp.push_back(arr[i]);
        tmp2.push_back(arr2[i]);
        sort(tmp.begin(), tmp.end());
        if (tmp == tmp2) {
            cnt++;
            tmp.clear();
            tmp2.clear();
        }
    }

    return cnt;
}

int main(int argc, char *argv[]) {

    // 1
    cout << maxChunksToSorted({4, 3, 2, 1, 0}) << endl;
    // 4
    cout << maxChunksToSorted({1, 0, 2, 3, 4}) << endl;

    return 0;
}
