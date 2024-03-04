#include "head.h"
#include <bits/stdc++.h>
using namespace std;
// 单源最短路径

// 无权图最短路径(队列)
// 有向边和无向边都行
void unweightedGraphs() {
    // BFS
    // 先到的地方，先遍历, 后面再遍历到它肯定比之前遍历的要大
    int n = 6;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 2},
                              {2, 4}, {3, 4}, {3, 5}, {4, 5}};

    vector<vector<int>> nei(n);
    for (auto &edge : edges) {
        nei[edge[0]].push_back(edge[1]);
    }

    queue<int> qu;
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> path(n, -1);

    // init
    visited[0] = 1;
    dist[0] = 0;
    qu.push(0);

    // start
    while (!qu.empty()) {
        int t = qu.front();
        qu.pop();

        for (auto &c : nei[t]) {
            if (visited[c] == true) {
                continue;
            }

            dist[c] = min(dist[c], dist[t] + 1);
            visited[c] = true;
            path[c] = t;
            qu.push(c);
        }
    }

    printVector(dist);
}

// 模板中的比较器
class less {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
};

class greater {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

// 有权图最短路径(优先队列)
// 有向边和无向边都行
void dijkstra() {
    // 这里使用有向边做示例
    int n = 6;
    vector<vector<int>> edges{{0, 1, 1},  {0, 2, 1},  {1, 2, 9},
                              {1, 3, 3},  {3, 2, 4},  {2, 4, 5},
                              {3, 4, 13}, {3, 5, 15}, {4, 5, 4}};
    vector<vector<int>> nei(n, vector<int>(n, INT_MAX));

    for (auto &edge : edges) {
        nei[edge[0]][edge[1]] = edge[2];
    }

    // 这里的 less 和 greater 表示排好序后第一个数和下一个数的比较关系
    // 比如正常的数组，less 表示从小到大，greater 表示从大到小

    // 大根堆排序完是从小到大的(less)，这需要结合图例理解，每次把大根堆的堆顶放在当前大小数组的末尾
    // 比如 10 7 8，数组大小是3，10 是堆顶，那么把 10 放在最后，变成 8 7 10
    // 数组大小变为 2，再排列 8 7，最后得到 7 8，结果是 7 8 10

    // 优先队列就是用的堆，每次出堆要把堆顶元素放到当前数组长度的末尾，然后数组长度减一
    // 比如大根堆，每次出堆出最大的，但是它本身排好序后是从小到大的

    std::priority_queue<pair<int, int>, vector<pair<int, int>>,
                        std::greater<pair<int, int>>>
        pq;

    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> path(n, -1);

    // init
    visited[0] = true;
    dist[0] = 0;
    pq.emplace(0, 0);

    // start
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int node = t.first;
        int d = t.second;

        for (int i = 0; i < n; i++) {
            if (nei[node][i] != INT_MAX) {
                if (visited[i] == true) {
                    continue;
                }

                dist[i] = min(dist[i], dist[node] + nei[node][i]);
                visited[i] = true;
                path[i] = node;
                pq.emplace(i, dist[i]); // 放入的是从源到本节点的总路径长度
            }
        }
    }

    printVector(dist);
}

int main(void) {
    // unweightedGraphs();
    dijkstra();
    return 0;
}
