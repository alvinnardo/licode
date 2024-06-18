#include "../template/head.h"
#include <bits/stdc++.h>
#include <math.h>

string discountPrices(string sentence, int discount) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    string res, tmp;
    int len = sentence.length();

    auto getRound = [&](double price) {
        stringstream ss;
        ss << fixed << setprecision(2) << price;
        return ss.str();
    };

    bool mon = false;
    double pri = 0;
    for (int i = 0; i <= len; i++) {
        if (i == len || sentence[i] == ' ') {
            if (!res.empty()) {
                res += " ";
            }

            if (!mon || tmp == "$") {
                res += tmp;
            } else {
                res += string("$") +
                       getRound(pri * ((100 - discount) * 1.0 / 100));
            }

            tmp = "";
            mon = false;
            pri = 0;
        } else {
            if (tmp.empty() && sentence[i] == '$') {
                mon = true;
            } else if (mon) {
                if (sentence[i] >= '0' && sentence[i] <= '9') {
                    pri = pri * 10 + (int)(sentence[i] - '0');
                } else {
                    mon = false;
                }
            }
            tmp += sentence[i];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "there are $0.50 $1.00 and 5$ candies in the shop"
    cout << discountPrices("there are $1 $2 and 5$ candies in the shop", 50)
         << endl;
    // "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
    cout << discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$", 100) << endl;
    cout << discountPrices("$11111-", 10) << endl;
    cout << discountPrices("$9111111111", 10) << endl;
    // "$39577.72 ab $3.12 $"
    cout << discountPrices("$76111 ab $6 $", 48) << endl;
    // "$2$3 $9.50 $95.00 $0.95 200 $31.35 33$ $$ $94.05 $94999.05
    // $9499999999.05"
    cout << discountPrices(
                "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999", 5)
         << endl;

    return 0;
}
