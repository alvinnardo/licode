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
        for (; j >= 0 && vv[j] > t; j--) {
            vv[j + 1] = vv[j];
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
        // 将相等步长的分为一组，进行插入排序
        for (int i = step; i < sz; i++) {
            int t = vv[i];
            int j = i - step;
            for (; j >= 0 && vv[j] > t; j -= step) {
                vv[j + step] = vv[j];
            }
            vv[j + step] = t;
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
void heap_sort(vector<int> vv) {
    cout << "=== Heap Sort ===" << endl;
    int sz = vv.size();

    function<void(vector<int> &, int, int)> maxHeapify =
        [&](vector<int> &a, int i, int heapSize) {
            int l = i * 2 + 1, r = i * 2 + 2, largest = i;
            if (l < heapSize && a[l] > a[largest]) {
                largest = l;
            }

            if (r < heapSize && a[r] > a[largest]) {
                largest = r;
            }

            if (largest != i) {
                swap(a[i], a[largest]);
                maxHeapify(a, largest, heapSize);
            }
        };

    auto buildMaxHeap = [&](vector<int> &a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        }
    };

    buildMaxHeap(vv, sz);
    for (int i = sz - 1; i >= 0; i--) {
        swap(vv[0], vv[i]);
        --sz;
        maxHeapify(vv, 0, sz);
    }

    printVector(vv);
}

// STL 中的 std::sort() 并不全是快排
// 结合内省排序 + 插入排序
// 内省排序包括快排 + 堆排序(当递归层次太深的时候，退化成 O(n2) 倾向时)

// 将数据进行分段，在每个段上递归调用快排然后插入排序结果归并
// 当分段数据量较少(16)时，使用插入排序，当数据比较有序时，插入排序效率更高
// 然后查看递归层次, 当递归层次太深的时候，退化成 O(n2), 使用堆排序
// 否则使用快排

/* 为什么不直接用堆排序？
   堆排序又不需要递归，最差也是 O(nlogn), 而快排最差是 O(n2)
   1. 快排分块之后有局部性原理，而堆排序会长距离跳跃，访问方式不友好
   2. 在相对有序的数据中，建堆过程中，会打破原有的顺序，
      平均比快排数据交换次数更多，用时更长
*/

void std_sort(vector<int> vv) {
    cout << "=== STL Sort ===" << endl;
    std::sort(vv.begin(), vv.end());
    printVector(vv);
}

// 从后面选择一个最小的
// O(n2)
void selection_sort1(vector<int> vv) {
    cout << "=== Selection Sort ===" << endl;
    int sz = vv.size();
    for (int i = 0; i < sz; i++) {
        int minv = vv[i];
        int min_pos = i;
        int j = i + 1;
        for (; j < sz; j++) {
            if (vv[j] < minv) {
                minv = vv[j];
                min_pos = j;
            }
        }

        vv[min_pos] = vv[i];
        vv[i] = minv;
    }
    printVector(vv);
}

// example from std::iter_swap
template <class ForwardIt> void selection_sort(ForwardIt begin, ForwardIt end) {
    for (ForwardIt it = begin; it != end; ++it) {
        std::iter_swap(it, std::min_element(it, end));
    }
}

void selection_sort(vector<int> vv) {
    cout << "=== Selection Sort ===" << endl;
    selection_sort(vv.begin(), vv.end());
    cout << vv << endl;
}

// 需要有范围
// 最好 O(n + k)
// 最坏 O(n + k)
// 平均 O(n + k)
// 空间 O(n + k)
// 稳定
void counting_sort(vector<int> vv) {
    cout << "=== Counting Sort ===" << endl;
    int minv = INT_MAX, maxv = INT_MIN;
    for (auto i : vv) {
        minv = min(minv, i);
        maxv = max(maxv, i);
    }

    int n = maxv - minv + 1;
    vector<int> tmp(n);
    for (auto i : vv) {
        tmp[i - minv]++;
    }

    int j = 0;
    for (int i = 0; i < tmp.size(); i++) {
        while (tmp[i] > 0) {
            vv[j] = i + minv;
            j++;
            tmp[i]--;
        }
    }
    printVector(vv);
}

// 利用分治思想，是计数排序的升级版
// 设置多个桶，将数字依次放入桶中，并将每个桶中的数字排序
// 在放入桶前计算排序关键字与桶的映射关系，使每个桶中数量尽量均匀
// 能达到线性时间复杂度 O(n)
void bucket_sort(vector<int> vv) {
    cout << "=== Bucket Sort ===" << endl;
    int sz = vv.size();
    int bucket_num = 10; // 这个自定义，根据数组最大值和最小值，尽量做到均匀
    vector<vector<int>> buckets(bucket_num);
    int minv = INT_MAX, maxv = INT_MIN;
    for (auto &num : vv) {
        minv = min(minv, num);
        maxv = max(maxv, num);
    }

    // 得到每个桶中能够放的个数
    // 总数字个数 + 桶大小 即向上取整
    int dur = (maxv - minv + 1 + bucket_num) / bucket_num;

    for (auto &num : vv) {
        int idx = (num - minv) / dur; // 映射关系，左闭右闭
        buckets[idx].push_back(num);
    }

    int idx = 0;
    for (auto &bucket : buckets) {
        for (int i = 1; i < bucket.size(); i++) {
            int t = bucket[i];
            int j = i - 1;
            for (; j >= 0 && bucket[j] > t; j--) {
                bucket[j + 1] = bucket[j];
            }

            bucket[j + 1] = t;
        }
        for (auto &t : bucket) {
            vv[idx++] = t;
        }
    }

    printVector(vv);
}

// 准备十个桶
// 每次按一个数位排序，拿出，再进行下一位排序
void radix_sort(vector<int> vv) {
    cout << "=== Radix Sort ===" << endl;
    vector<queue<int>> vec(10);
    int mod = 10, div = 1;

    // 当 cnt 都是数组大小的时候，就不进行下一次排序了，因为最高位都是 0 了
    int cnt = 0;
    while (cnt != vv.size()) {
        cnt = 0;
        for (auto &i : vv) {
            int t = (i % mod) / div;
            vec[t].push(i);
            if (i / div == 0) { // 除法看最高位
                cnt++;
            }
        }

        mod *= 10;
        div *= 10;

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            while (!vec[i].empty()) {
                int t = vec[i].front();
                vec[i].pop();
                vv[idx++] = t;
            }
        }
    }
    printVector(vv);
}

int main(void) {
    vector<int> vv(
        {1, 10, 3, 3, 2, 3, 98, 16, 22, 14, 31, 1, 1, 87, 3, 2, 14, 22});

    std_sort(vv);
    bubble_sort(vv);
    selection_sort(vv);
    insert_sort(vv);
    heal_sort(vv);
    merge_sort(vv);
    quick_sort(vv);
    heap_sort(vv);

    // 以下三种思想类似，不是两两比较，而是先用一个范围包住
    counting_sort(vv);
    bucket_sort(vv);
    radix_sort(vv);

    return 0;
}
