#include "../template/head.h"
#include <bits/stdc++.h>

bool reorderedPowerOf2(int n) {
    // 思路：哈希表 + 排序
    // 时间 O(logn)，空间 O(k)
    std::unordered_set<std::string> vec{
        "1",         "2",        "4",         "8",         "16",
        "23",        "46",       "128",       "256",       "125",
        "0124",      "0248",     "0469",      "1289",      "13468",
        "23678",     "35566",    "011237",    "122446",    "224588",
        "0145678",   "0122579",  "0134449",   "0368888",   "11266777",
        "23334455",  "01466788", "112234778", "234455668", "012356789",
        "0112344778"};

    std::string tmp = std::to_string(n);
    std::sort(tmp.begin(), tmp.end());

    return vec.count(tmp);
}

int main(int argc, char *argv[]) {
    // std::vector<std::string> vec;
    // std::string tmp;
    // int i = 1, cnt = 31;
    // while (cnt--) {
    //     tmp = std::to_string(i);
    //     std::sort(tmp.begin(), tmp.end());
    //     vec.emplace_back(std::move(tmp));
    //     i <<= 1;
    // }
    // cout << vec << endl;

    // 1
    cout << reorderedPowerOf2(1) << endl;
    // 0
    cout << reorderedPowerOf2(10) << endl;

    return 0;
}
