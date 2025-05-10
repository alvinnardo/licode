#include "../template/head.h"
#include <bits/stdc++.h>

// 根据题解进行优化
// 思路和时空复杂度相同，对一些小细节进行优化
struct DisPoint2 {
    int dis = 0;
    int posx = 0;
    int posy = 0;
    DisPoint2(int a, int b, int c) : dis(a), posx(b), posy(c) {}
    // 比较直接写在类中
    bool operator<(const DisPoint2 &p) const { return dis > p.dis; }
};

int minTimeToReach(vector<vector<int>> moveTime) {
    // 思路：Dijkstra
    // 时间 O(mnlogmn)，空间 O(mn)

    int m = moveTime.size(), n = moveTime[0].size();
    // 保存起点到该点的距离
    // 由于每次只移动一步，x 和 y 只改变一个，可根据位置推出来
    // 题解给出用一个 visited 表示是否处理过，根据距离是否处理过可以直接判断

    // 根据测试结果，题解中的 visited 数组使用来减少时间的
    // 如果处理过，则直接跳过
    vector<vector<int>> vec(m, vector<int>(n, INT_MAX));
    vec[0][0] = 0;

    vector<pair<int, int>> direct{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    priority_queue<DisPoint2> pq; // 比较函数已经写在类中了，会自动调用

    pq.emplace(0, 0, 0);
    int dis{}, posx{}, posy{};
    while (!pq.empty()) {
        dis = pq.top().dis;
        posx = pq.top().posx;
        posy = pq.top().posy;
        pq.pop();

        int next_x{}, next_y{};
        for (int i = 0; i < 4; i++) {
            next_x = posx + direct[i].first;
            next_y = posy + direct[i].second;
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
                if (vec[next_x][next_y] != INT_MAX) {
                    continue;
                }

                vec[next_x][next_y] =
                    max(dis, moveTime[next_x][next_y]) + (posx + posy) % 2 + 1;
                pq.emplace(vec[next_x][next_y], next_x, next_y);
            }
        }
    }

    return vec[m - 1][n - 1];
}

struct DisPoint {
    int dis = 0;
    int posx = 0;
    int posy = 0;
    DisPoint(int a, int b, int c) : dis(a), posx(b), posy(c) {}
};

struct cmp {
    bool operator()(const DisPoint &a, const DisPoint &b) {
        return a.dis > b.dis;
    }
};

int minTimeToReach1(vector<vector<int>> moveTime) {
    // 思路：Dijkstra
    // 时间 O(mnlogmn)，空间 O(mn)
    int m = moveTime.size(), n = moveTime[0].size();
    // 保存起点到该点的距离 和 附加移动时间
    vector<vector<pair<int, int>>> vec(m,
                                       vector<pair<int, int>>(n, {INT_MAX, 0}));
    vec[0][0] = {0, 2};

    vector<pair<int, int>> direct{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    priority_queue<DisPoint, vector<DisPoint>, cmp> pq;

    pq.emplace(0, 0, 0);
    int dis{}, posx{}, posy{};
    while (!pq.empty()) {
        dis = pq.top().dis;
        posx = pq.top().posx;
        posy = pq.top().posy;
        pq.pop();

        int next_x{}, next_y{};
        for (int i = 0; i < 4; i++) {
            next_x = posx + direct[i].first;
            next_y = posy + direct[i].second;
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n) {
                if (vec[next_x][next_y].first != INT_MAX) {
                    continue;
                }

                int add = vec[posx][posy].second == 1 ? 2 : 1;
                vec[next_x][next_y].first =
                    dis > moveTime[next_x][next_y]
                        ? dis + add
                        : moveTime[next_x][next_y] + add;
                vec[next_x][next_y].second = add;
                pq.emplace(vec[next_x][next_y].first, next_x, next_y);
            }
        }
    }

    return vec[m - 1][n - 1].first;
}

int main(int argc, char *argv[]) {
    // 7
    cout << minTimeToReach({{0, 4}, {4, 4}}) << endl;
    // 6
    cout << minTimeToReach({{0, 0, 0, 0}, {0, 0, 0, 0}}) << endl;
    // 4
    cout << minTimeToReach({{0, 1}, {1, 2}}) << endl;

    return 0;
}
