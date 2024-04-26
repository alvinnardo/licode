#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> reconstructQueue(vector<vector<int>> people) {
    // 思路：高度从大到小依次遍历，使用链表保存结果，判断前面有几个大于等于的位置
    // 优化，不需要使用额外的链表，直接使用数组即可
    // 链表查找是 O(n), 数组插入也是 O(n), 是一样的
    // 时间: O(n2), 空间 O(logn) 排序的栈使用的空间
    sort(people.begin(), people.end(),
         [&](const vector<int> &a, const vector<int> &b) {
             return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
         });

    vector<vector<int>> res;
    for (auto &t : people) {
        res.insert(res.begin() + t[1], t);
    }

    return res;
}

vector<vector<int>> reconstructQueue_my(vector<vector<int>> people) {
    // 思路：高度从大到小依次遍历，使用链表保存结果，判断前面有几个大于等于的位置
    // 时间: O(n2), 空间 O(n)
    sort(people.begin(), people.end(),
         [&](const vector<int> &a, const vector<int> &b) {
             return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
         });

    list<vector<int>> ll;
    for (auto &t : people) {
        if (t[1] == 0) {
            ll.push_front(t);
        } else {
            auto it = ll.begin();
            advance(it, t[1]);
            ll.insert(it, t);
        }
    }

    return vector<vector<int>>(ll.begin(), ll.end());
}

int main(void) {
    // {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}}
    printVectorVector(
        reconstructQueue({{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}));

    // {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}}
    printVectorVector(
        reconstructQueue({{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}}));
}
