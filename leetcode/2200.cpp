#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findKDistantIndices(vector<int> &&nums, int key, int k) {
    // 思路：模拟
    // 时间 O(n)，空间 O(k)
    // 遍历两次，第一次保存 key 的位置，第二次产出结果

    vector<int> pos_vec;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        if (nums[i] == key) {
            pos_vec.push_back(i);
        }
    }

    int pos = 0;
    vector<int> res;
    for (int i = 0; i < sz; i++) {
        bool put = false;
        if (pos > 0) {
            if (i <= pos_vec[pos - 1] + k) {
                res.push_back(i);
                put = true;
            }
        }
        if (!put && pos < pos_vec.size() && i >= pos_vec[pos] - k) {
            res.push_back(i);
        }

        if (pos < pos_vec.size() && pos_vec[pos] == i) {
            pos++;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {1,2,3,4,5,6}
    printVector(findKDistantIndices({3, 4, 9, 1, 3, 9, 5}, 9, 1));
    // {0,1,2,3,4}
    printVector(findKDistantIndices({2, 2, 2, 2, 2}, 2, 2));

    return 0;
}
