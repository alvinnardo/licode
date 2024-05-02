#include "../template/head.h"
#include <bits/stdc++.h>

double average(vector<int> salary) {
    int minv = INT_MAX, maxv = INT_MIN, tot = 0;
    for (auto s : salary) {
        if (s > maxv) {
            maxv = s;
        }
        if (s < minv) {
            minv = s;
        }

        tot += s;
    }

    return (tot - minv - maxv) * 1.0 / (salary.size() - 2);
}

int main(int argc, char *argv[]) {
    // 2500
    cout << average({4000, 3000, 1000, 2000}) << endl;
    // 2000
    cout << average({1000, 2000, 3000}) << endl;
    // 3500
    cout << average({6000, 5000, 4000, 3000, 2000, 1000}) << endl;
    // 4750
    cout << average({8000, 9000, 2000, 3000, 6000, 1000}) << endl;

    return 0;
}
