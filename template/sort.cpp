#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

// 归并排序
void merge_sort(const vector<int> &ori) {
    vector<int> vv(ori);
    int sz = vv.size();


}

// 挖坑快排
// 每次定位中间位置
void quick_sort(const vector<int> &ori) {
    vector<int> vv(ori);
    int sz = vv.size();

    function<void(int, int)> dfs = [&](int begin, int end) {
        if (begin >= end)
            return;

        int p = begin, q = end;
        int pivot = vv[begin]; // 最左边是坑

        while (p < q) {
            while (p < q && vv[q] >= pivot) { // 从右往左
                --q;
            }
            if (p < q) {
                vv[p] = vv[q]; // 填坑, 右边成为下一个坑
            }

            while (p < q && vv[p] <= pivot) { // 从左到右
                p++;
            }

            if (p < q) { // 填坑
                vv[q] = vv[p];
            }
        }

        vv[p] = pivot; // 填中间

        dfs(begin, p - 1);
        dfs(p + 1, end);
    };

    dfs(0, sz - 1);
    printVector(vv);
}

// 冒泡
// 每次冒出一个最小的
void bubble_sort(const vector<int> &ori) {
    vector<int> vv(ori);
    int sz = vv.size();

    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (vv[i] > vv[j]) {
                int t = vv[i];
                vv[i] = vv[j];
                vv[j] = t;
            }
        }
    }
    printVector(vv);
}

int main(void) {
    vector<int> vv(
        {1, 10, 3, 3, 2, 3, 98, 16, 22, 14, 31, 1, 1, 87, 3, 2, 14, 22});
    bubble_sort(vv);
    quick_sort(vv);
    merge_sort(vv);

    return 0;
}
