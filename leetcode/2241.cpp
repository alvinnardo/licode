#include "../template/head.h"
#include <bits/stdc++.h>

class ATM {
  public:
    // 思路：模拟
    // 时间 O(n)，空间 O(n)
    vector<pair<int, int>> vv{{20, 0}, {50, 0}, {100, 0}, {200, 0}, {500, 0}};
    ATM() {}

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < banknotesCount.size(); i++) {
            vv[i].second += banknotesCount[i];
        }
    }

    // 优先取最大的，如果剩余的不够则取下一个
    vector<int> withdraw(int amount) {
        int pos = vv.size() - 1;
        vector<int> res(vv.size(), 0);
        while (pos >= 0) {
            if (amount < vv[pos].first) {
                pos--;
                continue;
            }
            int t = min(vv[pos].second, amount / vv[pos].first);
            res[pos] = t;
            amount -= t * vv[pos].first;
            pos--;
        }

        if (amount != 0) {
            return {-1};
        }

        for (int i = 0; i < res.size(); i++) {
            vv[i].second -= res[i];
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    ATM atm;
    atm.deposit({0, 0, 1, 2, 1});
    printVector(atm.withdraw(600)); // {0,0,1,0,1}
    atm.deposit({0, 1, 0, 1, 1});
    printVector(atm.withdraw(600)); // {-1}
    printVector(atm.withdraw(550)); // {0,1,0,0,1}

    return 0;
}
