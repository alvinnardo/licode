#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> removeSubfolders(vector<string> &&folder) {
    // 思路：排序 + 模拟
    // 时间 O(nlogn)，空间 O(logn)
    int sz = folder.size();
    // 如 /a 和 /ac，加上后缀后方便排序
    for (int i = 0; i < sz; i++) {
        folder[i].push_back('/');
    }

    // 按字典序排序
    sort(folder.begin(), folder.end());
    vector<string> res;
    int last = 0;
    for (int i = 0; i < sz; i++) {
        if (res.empty()) {
            last = 0;
            res.emplace_back(folder[i]);
            res.back().pop_back();
            continue;
        }

        if (folder[last] != folder[i].substr(0, folder[last].size())) {
            last = i;
            res.emplace_back(folder[i]);
            res.back().pop_back();
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"/a","/c/d","/c/f"}
    printVector(removeSubfolders({"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}));
    // {"/a"}
    printVector(removeSubfolders({"/a", "/a/b/c", "/a/b/d"}));
    // {"/a/b/c","/a/b/ca","/a/b/d"}
    printVector(removeSubfolders({"/a/b/c", "/a/b/ca", "/a/b/d"}));

    return 0;
}
