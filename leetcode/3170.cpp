#include "../template/head.h"
#include <bits/stdc++.h>

// 按字典序和位置排序
struct cmp1 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
};

// 按位置排序
struct cmp2 {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

string clearStars(string s) {
    // 思路：贪心 + 优先队列
    // 时间 O(nlogn)，空间 O(n)

    // 去掉 * 的时候，需要找到离自己最近的且字典序最小的字符
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq1;
    int len = s.length();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            pq1.pop();
            cnt++;
        } else {
            pq1.emplace(s[i] - 'a', i);
        }
    }

    if (cnt == 0) { // 没有 * 字符，直接返回
        return s;
    }

    // 将剩下的字符按位置排序(大根堆，最后结果从小到到)
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> pq2;
    while (!pq1.empty()) {
        pq2.emplace(pq1.top().first, pq1.top().second);
        pq1.pop();
    }

    string res;
    while (!pq2.empty()) {
        res += ('a' + pq2.top().first);
        pq2.pop();
    }
    return res;
}

int main(int argc, char *argv[]) {
    // "aab"
    cout << clearStars("aaba*") << endl;
    // "abc"
    cout << clearStars("abc") << endl;

    return 0;
}
