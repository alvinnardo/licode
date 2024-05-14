#include "head.h"
#include <bits/stdc++.h>
using namespace std;

/**
 水塘抽样：
   一种随机算法，常见场景为在大数据流中随机选取一个或多个数据，通常内存无法一次性装入
   只遍历一次，要求选取每一个元素的概率是相等的
 */

/* clang-format off */
// 在 N 个数中随机选取 1 个数字
// 在遍历到第 i 个数字时，所有数字的概率为 1/i
// 当 i = n 时，每个数字被选中的概率为 1/n
// 推导公式的逻辑：元素最终被选中的概率 = 之前被选中的概率 * 后面没有被替换的概率
// 选中下一个元素的概率 = 之前元素被替换的概率
/**
  i = 1 时，第 1 个元素的概率为 1
  i = 2 时，第 1 个元素的概率为 1 * (1 - 1/2) = 1/2, 第 2 个元素的概率为 1/2
  i = 3 时，第 1 个元素的概率为 1 * (1 - 1/2) * (1 - 1/3) = 1/3, 第 2 个元素的概率为 1/2 * (1 - 1/3) = 1/3, 第 3 个元素的概率为 1/3
  ...
  i = n 时，... 第 j 个元素的概率为 1/j * (1 - 1/(j + 1)) * (1 - 1/(j + 2)) *...* (1 - 1/n) = 1/n
 */
/* clang-format on */
int sampleOne(const vector<int> &nums) {
    // 这里用 i 表示已经读到的元素个数
    // 不能直接用 nums 数组的大小，模拟大数据流的场景
    int i = 0, res = 0;
    for (auto num : nums) {
        i++;
        if (rand() % i == 0) { // 1/i 的概率
            res = num;
        }
    }

    return res;
}

/* clang-format off */
// 在 N 个数中随机选取 k 个数字
// 在遍历到第 i 个数字时，所有数字被选中的概率为 k/i
// 当 i = n 时，每个数字被选中的概率为 k/n
// 注意：每一次选取的概率总和不是 1，而是 k，要选取的是 k 个元素
// 每个元素选中概率为 k/j * (1 - k/(j + 1) * 1/k) * ... * (1 - k/n * 1/k) = k/n
// 推导公式的逻辑：元素最终被选中的概率 = 之前被选中的概率 * 后面没有被替换的概率
// 选中后面元素的概率为 k/(j + 1)，表示要替换之前的元素了，但是要替换 k 个中的哪个元素是不确定的，概率为 1/k
/* clang-format on */
vector<int> sampleK(const vector<int> &nums, int k) {
    vector<int> res;
    int i = 0;
    for (auto num : nums) {
        i++;
        if (res.size() < k) {
            res.push_back(num);
            continue;
        }

        // k/i 的概率
        int t = rand() % i;
        if (t < k) { // 选中该数
            res[t] = num;
        }
    }

    return res;
}

int main(void) {
    srand(time(NULL));

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> res(11);
    for (int i = 0; i < 100000; i++) {
        res[sampleOne(vec)]++;
    }
    printVector(res);
    printVector(sampleK(vec, 3));

    return 0;
}
