#include "../template/head.h"
#include <bits/stdc++.h>

vector<vector<string>> findDuplicate(vector<string> paths) {
    // 思路：哈希表
    // 时间 O(n)，空间 O(n)
    unordered_map<string, vector<pair<int, int>>> umap;
    vector<vector<string>> dir_map(paths.size());
    for (int i = 0; i < paths.size(); i++) {
        string tmp, dir;
        int cnt = 0;
        bool left = 0;
        for (int j = 0; j < paths[i].length(); j++) {
            if (paths[i][j] == '(') {
                left = true;
            } else if (paths[i][j] == ')') {
                umap[tmp].emplace_back(i, cnt);
                left = false;
                tmp = "";
            } else if (paths[i][j] == ' ') {
                cnt++;
                dir_map[i].emplace_back(dir);
                dir = "";
            } else if (left) {
                tmp += paths[i][j];
            } else {
                dir += paths[i][j];
            }
            if (j == paths[i].length() - 1) {
                dir_map[i].emplace_back(dir);
                dir = "";
            }
        }
    }

    vector<vector<string>> res;
    for (auto &it : umap) {
        if (it.second.size() > 1) {
            vector<string> tmp;
            for (auto &p : it.second) {
                tmp.emplace_back(dir_map[p.first][0] + "/" +
                                 dir_map[p.first][p.second]);
            }
            res.push_back(tmp);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    printVectorVector(
        findDuplicate({"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
                       "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"}));
    printVectorVector(
        findDuplicate({"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)",
                       "root/c/d 4.txt(efgh)"}));

    return 0;
}
