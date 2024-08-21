#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {

    int x = 5;
    long long res = 0;
    long long mask = 1;
    int cnt = 1;
    string s;
    while (mask < 1e15) {
        if (cnt % x == 0) {
            res = res + mask;
        }

        mask <<= 1;
        cnt++;
    }

    auto printBit = [](int res) {
        long long t = res;
        string tss;
        while (t) {
            if (t & 1) {
                tss += "1";
            } else {
                tss += "0";
            }
            t >>= 1;
        }
        int ret = 16 - tss.length();
        if (ret > 0) {
            while (ret--) {
                tss += "0";
            }
        }
        reverse(tss.begin(), tss.end());
        // cout << tss << endl;
        return tss;
    };

    map<int, int> ss;
    int sum = 0;
    for (int i = 0; i < 30000; i++) {
        int t = __builtin_popcount(i & res);
        sum += t;
        ss[t]++;
        printf("%3d %s: %3d, %3d   ", i, printBit(i).c_str(), t, sum);
        for (auto &it : ss) {
            cout << it.first << ", " << it.second << "; ";
        }
        cout << endl;
    }

    return 0;
}
