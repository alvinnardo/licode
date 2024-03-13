#include "../template/head.h"
#include <bits/stdc++.h>

using namespace std;

// 归并排序
// 常用于外排，数据量大，不能一次完全读入内存
void merge_sort(vector<int> vv) {
    cout << "=== Merge Sort ===" << endl;
    int sz = vv.size();

    function<void(int, int)> dfs = [&](int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        dfs(left, mid);
        dfs(mid + 1, right);

        vector<int> tmp(right - left + 1);
        int p = left, q = mid + 1, i = 0;
        while (p <= mid || q <= right) {
            if (p <= mid && q <= right) {
                if (vv[p] < vv[q]) {
                    tmp[i++] = vv[p++];
                } else {
                    tmp[i++] = vv[q++];
                }
            } else if (p <= mid) {
                tmp[i++] = vv[p++];
            } else {
                tmp[i++] = vv[q++];
            }
        }

        for (int t = 0; t < tmp.size(); t++) {
            vv[left + t] = tmp[t];
        }
    };

    dfs(0, sz - 1);
    printVector(vv);
}

// 挖坑快排
// 每次定位中间位置
// 最差 O(n2)
// 平均 O(nlogn)
// STL 中的快排与挖坑快排不太一样，
// 挖坑快排每次将 pivot 放在中间，STL 快排每次将 pivot 放在第一个
void quick_sort(vector<int> vv) {
    cout << "=== Quick sort ===" << endl;
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

// 插入排序
// 扑克牌整理顺序
// 最好比较 (n - 1) 次
// 最差比较 n(n-1)/2 次, O(n2)
// 平均 O(n2)
// 空间 O(1)
// 稳定
// 原地排序

// 改进：
// 1. 二分查找 O(nlogn)
// 2. 插入排序对几乎排好序的数据操作时，效率很高，能到 O(n)
//    可以分割成若干子序列，对每个子序列进行排序，然后缩减增量再进行排序
//    实现希尔排序
void insert_sort(vector<int> vv) {
    cout << "=== Insert Sort ===" << endl;
    int sz = vv.size();
    for (int i = 1; i < sz; i++) {
        int t = vv[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (vv[j] > t) {
                vv[j + 1] = vv[j];
            } else {
                break;
            }
        }

        vv[j + 1] = t;
    }
    printVector(vv);
}

// 希尔排序
// 本质是分组插入排序, 又称递减增量排序算法
// 非稳定
// O(nlogn) ~ O(n2)

// 1. 收敛：步长从 x .. 1，最后到 1 的时候肯定能实现一次插入排序
//    当选用更小的步长时，较大的步长也是有序的，能够保证更快完成排序
// 2. 步长序列：较好的步长序列能对减少平均时间
void heal_sort(vector<int> vv) {
    cout << "=== Heal Sort ===" << endl;
    int sz = vv.size();
    for (int step = sz >> 1; step > 0; step >>= 1) {
        for (int i = step; i < sz; i++) {
            int temp = vv[i];
            int j;
            for (j = i - step; j >= 0 && vv[j] > temp; j -= step) {
                vv[j + step] = vv[j];
            }
            vv[j + step] = temp;
        }
    }

    printVector(vv);
}

// 冒泡
// 每次冒出一个最小的
void bubble_sort(vector<int> ori) {
    cout << "=== Bubble Sort ===" << endl;
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

// 堆排序
// 最坏 O(nlogn)
// 平均 O(nlogn)
void heap_sort(vector<int> vv) { cout << "=== Heap Sort ===" << endl; }

// STL 中的 std::sort() 并不全是快排
// 结合内省排序 + 插入排序
// 内省排序包括快排 + 堆排序(当递归层次太深的时候，退化成 O(n2) 倾向时)

// 将数据进行分段，在每个段上递归调用快排然后插入排序结果归并
// 当分段数据量较少(16)时，使用插入排序，当数据比较有序时，插入排序效率更高
// 然后查看递归层次, 当递归层次太深的时候，退化成 O(n2), 使用堆排序
// 否则使用快排
void std_sort(vector<int> vv) {
    cout << "=== STL Sort ===" << endl;
    std::sort(vv.begin(), vv.end());
    printVector(vv);
}

int main(void) {
    vector<int> vv(
        {1, 10, 3, 3, 2, 3, 98, 16, 22, 14, 31, 1, 1, 87, 3, 2, 14, 22});
    vector<int> svv(vv);

    std_sort(vv);
    bubble_sort(vv);
    insert_sort(vv);
    quick_sort(vv);
    merge_sort(vv);
    heap_sort(vv);
    heal_sort(vv);

    return 0;
}
