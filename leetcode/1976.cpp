#include <bits/stdc++.h>
#include "../template/head.h"
using namespace std;

// 最短时间路径数
int countPaths(int n, const vector<vector<int>> &roads)
{
    if (n == 1) return 0;

    vector<vector<pair<int,int>>> nei(n);
    for (auto &road : roads)
    {
        nei[road[0]].emplace_back(road[1], road[2]);
        nei[road[1]].emplace_back(road[0], road[2]);
    }

    vector<int> seen(n);
    priority_queue<

    function<void(int, int64_t)> dfs = [&] (int x, int64_t len) {
        if (x == n - 1) {
            umap[len] = (umap[len] + 1) % 1000000007;
            return;
        }

        seen[x] = 1;
        for (auto &t : nei[x]) {
            if (seen[t.first] == 0) {
                dfs(t.first, len + t.second);
            }
        }
        seen[x] = 0;
    };

    dfs(0, 0);

    return umap.begin()->second;
}

int main(void)
{
    // 4
    // cout << countPaths(7, {{0,6,7}, {0,1,2}, {1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}}) << endl;
    // cout << countPaths(2, {{1,0,10}}) << endl; // 2
    // cout << countPaths(1, {{}}) << endl; // 0

    vector<vector<int>> in;
    ifstream iss("res.dat");
    std::string line;
    while (iss >> line)
    {
        vector<int> line_vec;
        // cout << line << endl;
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ',') continue;
            if (pos1 == 0) {
                pos1 = i;
            } else {
                pos2 = i;
            }
        }

        line_vec.push_back(atoi(line.substr(0, pos1).data()));
        line_vec.push_back(atoi(line.substr(pos1 + 1, pos2 - pos1).data()));
        line_vec.push_back(atoi(line.substr(pos2 + 1).data()));
        // printVector(line_vec);
        // break;
        in.emplace_back(line_vec);
    }

    cout << "begin" << endl;
    cout << countPaths(200, in);



    return 0;
}
