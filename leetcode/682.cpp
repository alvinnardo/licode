#include "../template/head.h"
#include <bits/stdc++.h>

int calPoints(vector<string> operations) {
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    vector<int> vec;
    for (const string &s : operations) {
        if (s == "C") {
            vec.pop_back();
        } else if (s == "D") {
            vec.push_back(vec.back() << 1);
        } else if (s == "+") {
            vec.push_back(vec[vec.size() - 1] + vec[vec.size() - 2]);
        } else {
            vec.push_back(atoi(s.c_str()));
        }
    }

    return accumulate(vec.begin(), vec.end(), 0);
}

int main(int argc, char *argv[]) {
    // 30
    cout << calPoints({"5", "2", "C", "D", "+"}) << endl;
    // 27
    cout << calPoints({"5", "-2", "4", "C", "D", "9", "+", "+"}) << endl;
    // 1
    cout << calPoints({"1"}) << endl;

    return 0;
}
