#include "../template/head.h"
#include <bits/stdc++.h>

struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

int maximizeWin(vector<int> prizePositions, int k) {
    // 思路：前缀和 + 双指针 + 优先队列
    // 先判断最大的，如果个数相同，则靠右的优先

    // 尽可能多选，如果有交集就少选了
    // 如果范围太小，只能有交集了
    if (prizePositions.back() - prizePositions[0] + 1 <= ((k + 1) << 1)) {
        return prizePositions.size();
    }

    vector<pair<int, int>> vec{{0, 0}};
    for (int i = 0; i < prizePositions.size(); i++) {
        if (prizePositions[i] == vec.back().first) {
            vec.back().second++;
        } else {
            vec.emplace_back(prizePositions[i], vec.back().second + 1);
        }
    }

    int pos = 0, cnt = 0;
    vector<vector<int>> pos_val;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (int i = 0; i < vec.size(); i++) {
        while (vec[i].first - vec[pos].first > k + 1) {
            pos++;
        }

        int t = vec[i].second - vec[pos].second;
        pos_val.push_back({vec[i].first - k, vec[i].first, t});
        pq.emplace(t, vec[i].first);
    }

    int res = INT_MIN;
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        for (int i = 0; i < pos_val.size(); i++) {
            if (pos_val[i][1] < t.second - k || pos_val[i][0] > t.second) {
                res = max(res, t.first + pos_val[i][2]);
            }
        }

        if (res != INT_MIN) {
            break;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 7
    cout << maximizeWin({1, 1, 2, 2, 3, 3, 5}, 2) << endl;
    // 2
    cout << maximizeWin({1, 2, 3, 4}, 0) << endl;
    // 5
    cout << maximizeWin({1, 2, 3, 4, 5}, 1) << endl;

    return 0;
}
