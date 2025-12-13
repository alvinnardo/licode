#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> validateCoupons(vector<string> &&code,
                               vector<string> &&businessLine,
                               vector<bool> &&isActive) {
    // 思路：排序
    // 时间 O(nlogn)，空间 O(logn)
    vector<int> vv;
    int sz = code.size();

    for (int i = 0; i < sz; i++) {
        if (isActive[i]) {
            if (businessLine[i] == "electronics" ||
                businessLine[i] == "grocery" || businessLine[i] == "pharmacy" ||
                businessLine[i] == "restaurant") {
                if (code[i].size() > 0) {
                    int pos = 0;
                    for (; pos < code[i].size(); ++pos) {
                        if (!(code[i][pos] >= 'a' && code[i][pos] <= 'z' ||
                              code[i][pos] >= 'A' && code[i][pos] <= 'Z' ||
                              code[i][pos] >= '0' && code[i][pos] <= '9' ||
                              code[i][pos] == '_')) {
                            break;
                        }
                    }

                    if (pos == code[i].size()) {
                        vv.push_back(i);
                    }
                }
            }
        }
    }

    std::function<bool(int, int)> cmp = [&](int a, int b) {
        return businessLine[a] == businessLine[b]
                   ? code[a] < code[b]
                   : businessLine[a] < businessLine[b];
    };

    std::ranges::sort(vv, cmp);
    vector<string> res;
    for (int i = 0; i < vv.size(); i++) {
        res.emplace_back(code[vv[i]]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {"PHARMA5","SAVE20"}
    cout << validateCoupons({"SAVE20", "", "PHARMA5", "SAVE@20"},
                            {"restaurant", "grocery", "pharmacy", "restaurant"},
                            {true, true, true, true})
         << endl;

    // {"ELECTRONICS_50"}
    cout << validateCoupons({"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"},
                            {"grocery", "electronics", "invalid"},
                            {false, true, true})
         << endl;

    return 0;
}
