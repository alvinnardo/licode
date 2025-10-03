#include "../template/head.h"
#include <bits/stdc++.h>

int trap(vector<int> &&height) {
    // 思路：单调栈
    // 时间 O(n)，空间 O(n)

    // 从左向右遍历，单调栈中存放左边板的长度
    // 添加右板时，如果左边有更小的且左边的左边还有长板
    // 即能把中间的包住，那么两边板的最小值减去中间的高度就是能存的水
    // 最后整理单调栈中左边板的长度

    // 单调栈中存放 pos 值，可以求得左右两板之间的间隔
    vector<int> st;
    int res{}, sz = height.size();
    for (int i = 0; i < sz; i++) {
        if (st.empty() || height[i] < height[st.back()]) {
            st.push_back(i);
            continue;
        }

        // 找左右板，求积水量
        // 相同的板要存放最右边的，如 [2,2,1,2]，要保存 pos = 1 的 2
        while (!st.empty() && height[i] >= height[st.back()]) {
            int pos = st.back();
            st.pop_back();
            if (st.size() == 0) {
                break;
            }

            // 左边板到右边板中间能存放的水
            res += (min(height[i], height[st.back()]) - height[pos]) *
                   (i - st.back() - 1);
        }

        // 放置右板
        st.push_back(i);
    }

    return res;
}

int trap1(vector<int> &&height) {
    // 思路：DP + 水桶
    // 时间 O(n)，空间 O(n)

    // 学习灵神的想法，把每块当成一个水桶
    // 求每个水桶左边最长板和右边最长板
    // 能够积累的水就是左右最长板的最小值 - 当前位置高度
    vector<pair<int, int>> vec(height.size());
    int sz = height.size(), right{};
    for (auto i = 0; i < sz; i++) {
        if (i == 0) {
            vec[i].first = height[i];
            right = sz - i - 1;
            vec[right].second = height[right];
        } else {
            vec[i].first = max(vec[i - 1].first, height[i]);
            vec[right - 1].second = max(vec[right].second, height[right - 1]);
            right--;
        }
    }

    int res{};
    for (int i = 0; i < sz; i++) {
        res += min(vec[i].first, vec[i].second) - height[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << endl;
    // 9
    cout << trap({4, 2, 0, 3, 2, 5}) << endl;
    // 16
    cout << trap({5, 2, 1, 2, 1, 5}) << endl;

    return 0;
}
