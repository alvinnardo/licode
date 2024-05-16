#include "../template/head.h"
#include <bits/stdc++.h>

// 评论中给出的一个解释比较好理解：插空法
// 只要任务没用完，就继续插空，空越来越多
// 先把最大的数展开，然后用其它的数去插空
// 如果其它的能把所有的空都插满，那么所有的数都能排列好并处理完
// 如果不能插满，那么最后的结果就是 插空的数 * 2 + 1
// 插的空 能和展开的数凑成一对，这里的 1 是刚开始的那个数
long long numberOfWeeks(vector<int> milestones) {
    // 思路：贪心，只剩一个数时，才不会继续下去，找最大值，然后用其它数之和与其比较
    // 如果其它的和大于等于，则这个最大值可以直接消费掉
    // 注意：最后剩余的 1 个也可以再执行一次
    // 时间 O(n)，空间 O(1)
    long long sum = 0;
    int maxv = INT_MIN;
    for (auto num : milestones) {
        sum += num;
        if (num > maxv) {
            maxv = num;
        }
    }

    if (sum - maxv + 1 < maxv) {
        sum -= maxv - (sum - maxv + 1);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    // 6
    cout << numberOfWeeks({1, 2, 3}) << endl;
    // 7
    cout << numberOfWeeks({5, 2, 1}) << endl;

    return 0;
}
