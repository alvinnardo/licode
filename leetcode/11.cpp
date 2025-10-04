#include "../template/head.h"
#include <bits/stdc++.h>

/**
   查看了历史提交记录，这道题是 2021.06.04 提交了第一次，
   本次是时隔 4 年零 4 个月再次提交，
   以前历史最少用时 90-100ms，算法思路不明确且复杂
   经过多年的做题经验，现在可以使用更优的算法思路，
   这需要归因于个人思考和学习他人经验(学且思)

   当初做不出题会想一天，一周，甚至一个月，尝试各种方法解题，直到解不出来放弃
   这种精神在现在来看是值得的，工程中解决问题也是这样
   因人而异，不一定能想出最优的解法，但能用能解决就可以，思考过程提升了个人能力
   中间会不断学习他人经验，不断成长，再次遇到会想出更好的算法

   当思考不出来时，一定要看题解模仿学习，这样能力才能有提升
*/
int maxArea(vector<int> &&height) {
    // 思路：贪心 + 双指针
    // 时间 O(n)，空间 O(1)
    // 往中心移动，要对面板子 >= 自己

    int p = 0, q = height.size() - 1;
    int res = 0;
    while (p < q) {
        res = max(res, min(height[p], height[q]) * (q - p));
        if (height[p] == height[q]) {
            p++;
            q--;
        } else if (height[p] < height[q]) { // 把小边拉起来
            p++;
        } else {
            q--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 49
    cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << endl;
    // 1
    cout << maxArea({1, 1}) << endl;

    return 0;
}
