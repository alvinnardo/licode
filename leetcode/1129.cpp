#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> redEdges,
                                     vector<vector<int>> blueEdges) {
    // 思路：Dijkstra
    // 时间 O(m + n)，空间 O(m + n)，m 是边数，n 是点数

    // 单源有向最短路径
    vector<vector<int>> red_nei_edges(n), blue_nei_edges(n);
    auto putEdges = [](auto &edges, auto &nei_edges) {
        for (const auto &e : edges) {
            nei_edges[e[0]].push_back(e[1]);
        }
    };
    putEdges(redEdges, red_nei_edges);
    putEdges(blueEdges, blue_nei_edges);

    // 是否从红色边开始
    auto getDis = [&](auto &dis_vec, bool begin_red) {
        dis_vec[0] = {0, 0};

        // {是否红色出去过，是否蓝色出去过}
        vector<vector<int>> visited(n, {0, 0});
        queue<int> qu;
        qu.push(0);
        while (!qu.empty()) {

            int cnt = qu.size();
            while (cnt--) {
                auto t = qu.front();
                qu.pop();

                if ((begin_red && visited[t][0]) ||
                    (!begin_red && visited[t][1])) {
                    continue;
                }

                auto &edges = begin_red ? red_nei_edges : blue_nei_edges;
                int new_dis = (begin_red ? dis_vec[t][1] : dis_vec[t][0]) + 1;

                for (int n : edges[t]) {
                    if (begin_red) {
                        if (dis_vec[n][0] < 0) {
                            dis_vec[n][0] = new_dis;
                        } else {
                            dis_vec[n][0] = min(dis_vec[n][0], new_dis);
                        }
                    } else {
                        if (dis_vec[n][1] < 0) {
                            dis_vec[n][1] = new_dis;
                        } else {
                            dis_vec[n][1] = min(dis_vec[n][1], new_dis);
                        }
                    }
                    qu.push(n);
                }

                if (begin_red) {
                    visited[t][0] = 1;
                } else {
                    visited[t][1] = 1;
                }
            }
            begin_red = !begin_red;
        }
    };

    vector<vector<int>> red_dis_vec(n, {-1, -1}), blue_dis_vec(n, {-1, -1});
    getDis(red_dis_vec, true);   // 从 red 开始
    getDis(blue_dis_vec, false); // 从 blue 开始

    // 四个里面选最短路径
    vector<int> res(n, INT_MAX);
    res[0] = 0;
    for (int i = 0; i < n; i++) {
        if (red_dis_vec[i][0] > 0) {
            res[i] = min(res[i], red_dis_vec[i][0]);
        }
        if (red_dis_vec[i][1] > 0) {
            res[i] = min(res[i], red_dis_vec[i][1]);
        }
        if (blue_dis_vec[i][0] > 0) {
            res[i] = min(res[i], blue_dis_vec[i][0]);
        }
        if (blue_dis_vec[i][1] > 0) {
            res[i] = min(res[i], blue_dis_vec[i][1]);
        }
        if (res[i] == INT_MAX) {
            res[i] = -1;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {0,1,-1}
    printVector(shortestAlternatingPaths(3, {{0, 1}, {1, 2}}, {}));
    // {0,1,-1}
    printVector(shortestAlternatingPaths(3, {{0, 1}}, {{2, 1}}));
    // {0, 1, 2, 3, 5}
    printVector(shortestAlternatingPaths(5, {{0, 1}, {2, 3}, {1, 4}},
                                         {{1, 2}, {3, 1}}));
    // {0,5,6,-1,-1,3,2,4,4,1,-1,7,6,-1,3,4,4,3,7,6,-1,-1,-1,5,-1,-1}
    printVector(shortestAlternatingPaths(
        26, {{19, 11}, {21, 4},  {17, 14}, {18, 16}, {3, 20},  {1, 10},
             {5, 4},   {7, 1},   {22, 19}, {9, 5},   {3, 13},  {14, 17},
             {2, 16},  {15, 23}, {5, 12},  {1, 24},  {23, 22}, {6, 17},
             {11, 1},  {9, 14},  {21, 12}, {1, 4},   {18, 8},  {5, 15},
             {5, 16},  {20, 8},  {5, 9},   {0, 9},   {2, 18},  {7, 8}},
        {{5, 8},   {9, 6},   {7, 15},  {23, 19}, {16, 9},  {10, 15},
         {23, 12}, {19, 16}, {22, 1},  {8, 2},   {19, 6},  {13, 1},
         {17, 15}, {10, 20}, {8, 19},  {5, 16},  {2, 14},  {22, 12},
         {7, 22},  {6, 0},   {7, 18},  {15, 5},  {7, 11},  {24, 7},
         {14, 7},  {9, 9},   {13, 22}, {10, 8},  {13, 23}, {3, 23}}));

    return 0;
}
