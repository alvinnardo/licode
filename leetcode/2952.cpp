#include <bits/stdc++.h>
using namespace std;

int minimumAddedCoins(vector<int> coins, int target) {

    // 思路: 一个变量存放能够到达的最大数字
    // 子序列，所以可以排序
    // 排序后，对每个数字进行遍历，每个数字是下一次的基础
    // 如果到不了这个基础，就需要添加数字
    // 直到最后最大数字等于或超过 target
    sort(coins.begin(), coins.end());
    int reach = 0;

    int sum = 0;
    int idx = 0;
    while (reach < target) {
        if (idx < coins.size()) { // 有硬币
            int c = coins[idx];
            if (c <= reach + 1) { // 能放
                reach += c;
                idx++;
            } else {
                sum++;
                reach += reach + 1;
            }
        } else {
            sum++;
            reach += reach + 1;
        }
    }

    return sum;
}

int main(void) {
    cout << minimumAddedCoins({1, 4, 10}, 19) << endl;
    cout << minimumAddedCoins({1, 4, 10, 5, 7, 19}, 19) << endl;
    cout << minimumAddedCoins({1, 1, 1}, 20) << endl;
    cout << minimumAddedCoins({2}, 2) << endl;
    cout << minimumAddedCoins({2}, 100) << endl;
    cout << minimumAddedCoins({2}, 10000) << endl;
    cout << minimumAddedCoins({2, 1000}, 100000) << endl;

    return 0;
}
