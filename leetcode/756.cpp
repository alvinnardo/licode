#include "../template/head.h"
#include <bits/stdc++.h>

bool isValid(const std::string &line,
             unordered_map<string, vector<char>> &umap) {
    if (line.length() == 1) {
        return true;
    }

    vector<string> vec;
    stringstream ss;
    for (int i = 0; i < line.length() - 1; i++) {
        string t = line.substr(i, 2);
        if (!umap.count(t)) {
            return false;
        }

        vector<string> tmp;
        if (i == 0) {
            for (char c : umap[t]) {
                tmp.push_back(string("") + c);
            }
        } else {
            for (auto &s : vec) {
                for (char c : umap[t]) {
                    ss.clear();
                    ss.str("");
                    ss << s.back() << c;
                    if (umap.count(ss.str())) {
                        tmp.push_back(s + c);
                    }
                }
            }
        }
        vec = tmp;
    }

    for (auto &line : vec) {
        if (isValid(line, umap)) {
            return true;
        }
    }

    return false;
}

// 注意：不能使用两两比较的方法
// 如用例 2
// "AAAA", {"AAB", "AAC", "BCD", "BBE", "DEF"}
// 如果两两比较，第二层 B, {B 或 C}，C，中间确定用 B，就不能选 C
bool pyramidTransition(string bottom, vector<string> allowed) {
    // 思路：DFS，判断每一层是否能成立
    // 时间 O(k^n2)，空间 O(nk^n)，k 是能成立的平均个数
    unordered_map<string, vector<char>> umap;
    for (auto &p : allowed) {
        umap[p.substr(0, 2)].emplace_back(p[2]);
    }

    return isValid(bottom, umap);
}

int main(int argc, char *argv[]) {

    // 1
    cout << pyramidTransition("BCD", {"BCC", "CDE", "CEA", "FFF"}) << endl;
    // 0
    cout << pyramidTransition("AAAA", {"AAB", "AAC", "BCD", "BBE", "DEF"})
         << endl;
    // 1
    cout << pyramidTransition("ABCDEF",
                              {"ABA", "ABB", "ABC", "ABD", "ABE", "ABF", "ABG",
                               "BCA", "BCB", "BCC", "BCD", "BCE", "BCF", "BCG",
                               "CDA", "CDB", "CDC", "CDD", "CDE", "CDF", "CDG",
                               "DEA", "DEB", "DEC", "DED", "DEE", "DEF", "DEG",
                               "EFA", "EFB", "EFC", "EFD", "EFE", "EFF", "EFG"})
         << endl;
    // 0
    cout << pyramidTransition("ABBBBA",
                              {"ABA", "ABC", "ABF", "ABE", "ABD", "CBA", "CBC",
                               "CBF", "CBE", "CBD", "FBA", "FBC", "FBF", "FBE",
                               "FBD", "EBA", "EBC", "EBF", "EBE", "EBD", "DBA",
                               "DBC", "DBF", "DBE", "DBD", "BAA", "BAC", "BAF",
                               "BAE", "BAD", "BCA", "BCC", "BCF", "BCE", "BCD",
                               "BFA", "BFC", "BFF", "BFE", "BFD", "BEA", "BEC",
                               "BEF", "BEE", "BED", "BDA", "BDC", "BDF", "BDE",
                               "BDD", "BBA", "BBC", "BBF", "BBE", "BBD", "BBB"})
         << endl;

    return 0;
}
