#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;

    vector<int> tmp;

    function<void(int, int, int)> dfs = [&](int num, int k, int n) {
        if (k == 0 && n == 0) {
            res.emplace_back(tmp);
            return;
        }

        if (k <= 0 || n <= 0 || num > 9) {
            return;
        }

        dfs(num + 1, k, n);
        tmp.push_back(num);
        dfs(num + 1, k - 1, n - num);
        tmp.pop_back();
    };

    dfs(1, k, n);
    return res;
}

int main(void) {
    cout << "1" << endl;
    printVectorVector(combinationSum3(3, 7));
    cout << "2" << endl;
    printVectorVector(combinationSum3(3, 9));
    cout << "3" << endl;
    printVectorVector(combinationSum3(4, 1));
    cout << "4" << endl;
    printVectorVector(combinationSum3(9, 45));
    cout << "5" << endl;
    printVectorVector(combinationSum3(1, 3));

    return 0;
}
