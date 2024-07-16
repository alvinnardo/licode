#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> findIntersectionValues(vector<int> nums1, vector<int> nums2) {
    // 思路：哈希表
    // 时间 O(m + n)，空间 O(m + n)
    unordered_set<int> uset1, uset2;
    int answer1 = 0, answer2 = 0;
    for (int n : nums1) {
        uset1.insert(n);
    }

    for (int n : nums2) {
        if (uset1.count(n)) {
            answer2++;
        }
        uset2.insert(n);
    }

    for (int n : nums1) {
        if (uset2.count(n)) {
            answer1++;
        }
    }

    return {answer1, answer2};
}

int main(int argc, char *argv[]) {

    // {2, 1}
    printVector(findIntersectionValues({2, 3, 2}, {1, 2}));
    // {3, 4}
    printVector(findIntersectionValues({4, 3, 2, 3, 1}, {2, 2, 5, 2, 3, 6}));
    // {0, 0}
    printVector(findIntersectionValues({3, 4, 2, 3}, {1, 5}));

    return 0;
}
