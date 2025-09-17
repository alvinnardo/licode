#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：哈希表 + 红黑树
// 时间 O(nlogn)，空间 O(n)
// 哈希表存放<位置，数字>
// 红黑树存放数字位置排序
class NumberContainers {
  public:
    unordered_map<int, int> nums;
    unordered_map<int, set<int>> poss;
    NumberContainers() {}

    void change(int index, int number) {
        if (nums.count(index)) {
            // 清空当前位置的数字
            auto num = nums[index];
            nums.erase(index);

            // 清空数字的位置
            poss[num].erase(index);
        }

        nums[index] = number;
        poss[number].insert(index);
    }

    int find(int number) {
        if (poss[number].empty()) {
            return -1;
        }

        return *poss[number].begin();
    }
};

int main(int argc, char *argv[]) {

    NumberContainers nc;
    cout << nc.find(10) << endl; // -1
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    cout << nc.find(10) << endl; // 1
    nc.change(1, 20);
    cout << nc.find(10) << endl; // 2

    return 0;
}
