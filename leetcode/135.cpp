#include "../template/head.h"
#include <bits/stdc++.h>

int candy(vector<int> ratings) {
    // 思路：分类讨论
    // 时间 O(n)，空间 O(k)
    // 主要讨论相等的情况
    // 第一次遍历保存极小值的位置
    // 第二次遍历所有极小值，依次遍历左右

    vector<int> pos_vec;
    int sz = ratings.size();
    if (sz == 1) {
        return 1;
    }
    for (int i = 0; i < sz; i++) {
        if (i == 0) {
            if (i + 1 < sz && ratings[i + 1] >= ratings[i]) {
                pos_vec.push_back(i);
            }
        } else if (i == sz - 1) {
            if (i - 1 >= 0 && ratings[i - 1] >= ratings[i]) {
                pos_vec.push_back(i);
            }

        } else {
            if (ratings[i + 1] >= ratings[i] && ratings[i - 1] >= ratings[i]) {
                pos_vec.push_back(i);
            }
        }
    }

    int pre = 0, res = 0, tmp = 1;
    for (int i = 0; i < pos_vec.size(); i++) {
        res++;
        // 尝试前面
        tmp = 1;
        int pos = pos_vec[i];
        int pos_pre = i - 1 >= 0 ? pos_vec[i - 1] : -1;

        for (int j = pos - 1; j > pos_pre; j--) {
            if (ratings[j] <= ratings[j + 1]) {
                break;
            }
            res += (++tmp);
        }

        if (tmp != 1) {
            res -= min(pre, tmp);
        }

        // 尝试后面
        tmp = 1;
        int cnt = 0;
        int pos_next = i + 1 < pos_vec.size() ? pos_vec[i + 1] : sz;
        for (int j = pos + 1; j < pos_next; j++) {
            if (ratings[j] < ratings[j - 1]) {
                break;
            } else if (ratings[j] == ratings[j - 1]) { // 处理极大值相邻的时候
                res++;
                tmp = 1;
                cnt++;
                continue;
            }
            cnt++;
            res += (++tmp);
        }

        if (cnt > 0) {
            pre = tmp;
        } else {
            pre = 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 5
    cout << candy({1, 0, 2}) << endl;
    // 4
    cout << candy({1, 2, 2}) << endl;
    // 18
    cout << candy({2, 6, 9, 10, 2, 2, 5, 5, 3, 3}) << endl;
    // 12
    cout << candy({2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}) << endl;
    // 21
    cout << candy({4, 1, 10, 7, 10, 5, 4, 3, 1}) << endl;

    return 0;
}
