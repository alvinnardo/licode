#include "../template/head.h"
#include <bits/stdc++.h>

int nextGreaterElement(int n) {
    // 思路：看了之前自己的解法，用两次遍历即可
    // 第一次遍历，判断某个元素后面是否还有大于它的元素
    // 第二次遍历，找到大于它的最小值
    // 时间 O(logn)，空间 O(logn)

    vector<int> vec;
    while (n) {
        vec.push_back(n % 10);
        n /= 10;
    }

    int i = 0, maxv = -1;
    for (; i < vec.size(); i++) {
        if (maxv > vec[i]) {
            break;
        }

        maxv = max(maxv, vec[i]);
    }

    if (i == vec.size()) {
        return -1;
    }

    int j = 0, min_pos = -1, minv = INT_MAX;
    for (; j < i; j++) {
        if (vec[j] > vec[i]) {
            if (vec[j] < minv) {
                minv = vec[j];
                min_pos = j;
            }
        }
    }

    swap(vec[i], vec[min_pos]);
    sort(vec.begin(), vec.begin() + i, greater<int>());
    long long res = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        res = res * 10 + vec[i];
    }

    // 注意题目中给出如果大于 INT_MAX，需要返回 -1
    return res > INT_MAX ? -1 : res;
}

int nextGreaterElement1(int n) {
    // 思路：从后往前找比它大的最小数(第一个比它大的值)，替换它，后面排序
    // 时间 O(logn * logn)，空间 O(logn)

    vector<int> vec; // 这里获取的顺序和数字是反序的
    while (n) {
        vec.push_back(n % 10);
        n /= 10;
    }

    set<int> ss;
    unordered_map<int, int> umap;
    int i = 0, maxp = 0;
    for (i = 0; i < vec.size(); i++) {
        if (ss.empty()) {
            ss.insert(vec[i]);
            umap[vec[i]] = 0;
        } else {
            auto p = ss.upper_bound(vec[i]);
            if (p == ss.end()) {
                ss.insert(vec[i]);
                umap[vec[i]] = i;
            } else {
                maxp = umap[*p];
                break;
            }
        }
    }

    if (i == vec.size()) {
        return -1;
    }

    // 剩余的排序
    swap(vec[i], vec[maxp]);
    sort(vec.begin(), vec.begin() + i, greater<int>());
    long long res = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        res = res * 10 + vec[i];
    }

    // 注意题目中给出如果大于 INT_MAX，需要返回 -1
    return res > INT_MAX ? -1 : res;
}

int main(int argc, char *argv[]) {
    // 21
    cout << nextGreaterElement(12) << endl;
    // -1
    cout << nextGreaterElement(21) << endl;
    // 12354
    cout << nextGreaterElement(12345) << endl;
    // -1
    cout << nextGreaterElement(2144444444) << endl;
    // 2147483647
    cout << nextGreaterElement(2147483476) << endl;
    // 230412
    cout << nextGreaterElement(230241) << endl;
    cout << nextGreaterElement(230677766) << endl;

    return 0;
}
