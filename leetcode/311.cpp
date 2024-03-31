#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

bool isValidSerialization(string preorder) {
    // 直接走前序遍历
    // 中间出错，或最后没用完都算错误
    vector<string> vec;
    string t;
    for (int i = 0; i <= preorder.length(); i++) {
        if (i == preorder.length() || preorder[i] == ',') {
            vec.emplace_back(t);
            t = "";
        } else {
            t += preorder[i];
        }
    }

    int idx = 0;
    int sz = vec.size();

    function<bool(void)> dfs = [&]() {
        if (idx >= sz)
            return false;

        if (vec[idx] == "#") {
            idx++;
            return true;
        }

        idx++;
        return dfs() && dfs();
    };

    bool res = dfs();
    return res ? idx == sz : false;
}

int main(void) {

    printBool(isValidSerialization("9,3,4,#,#,100,#,#,2,#,6,#,#"));
    printBool(isValidSerialization("1,#"));
    printBool(isValidSerialization("9,#,#,1"));
    printBool(isValidSerialization("#"));
    printBool(isValidSerialization("1,#,#"));

    return 0;
}
