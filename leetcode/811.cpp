#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> subdomainVisits(vector<string> cpdomains) {
    // 思路：哈希表
    // 时间 O(nk2)，空间 O(mk)，n 是元素个数，k 是平均长度，m 是域名格式
    unordered_map<string, int> umap;
    for (const auto &domain : cpdomains) {
        int num = 0;
        bool blank = false, dot = true;
        for (int i = 0; i < domain.size(); i++) {
            if (!blank) {
                if (domain[i] == ' ') {
                    blank = true;
                } else {
                    num = num * 10 + (int)(domain[i] - '0');
                }
            } else {
                if (dot) {
                    dot = false;
                    umap[domain.substr(i)] += num;
                } else if (domain[i] == '.') {
                    umap[domain.substr(i + 1)] += num;
                }
            }
        }
    }

    vector<string> res;
    for (auto &it : umap) {
        res.emplace_back(to_string(it.second) + " " + it.first);
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {"9001 leetcode.com","9001 discuss.leetcode.com","9001 com"}
    printVector(subdomainVisits({"9001 discuss.leetcode.com"}));
    // {"901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5
    // org","1 intel.mail.com","951 com"}
    printVector(subdomainVisits({"900 google.mail.com", "50 yahoo.com",
                                 "1 intel.mail.com", "5 wiki.org"}));

    return 0;
}
