#include "../template/head.h"
#include <bits/stdc++.h>

int maxmiumScore(vector<int> cards, int cnt) {
    // 思路：贪心
    // 时间 O(nlogn)，空间 O(1)
    // 有点小窍门，先贪心加前个大值，
    // 如果是偶数可以直接返回，
    // 如果是奇数，可以将前面的最小偶数和后面的最大奇数替换
    // 也可以将前面的最小奇数和后面的最大偶数替换
    sort(cards.begin(), cards.end(), greater<int>());
    int sz = cards.size();
    int sum = 0;
    int odd_pos = -1, even_pos = -1;
    for (int i = 0; i < cnt; i++) {
        sum += cards[i];
        if (cards[i] & 1) {
            odd_pos = i;
        } else {
            even_pos = i;
        }
    }

    if (!(sum & 1)) {
        return sum;
    }

    int res = 0;
    if (odd_pos != -1) {
        // 有最小的奇数，找最大的偶数
        for (int i = cnt; i < sz; i++) {
            if (!(cards[i] & 1)) {
                res = max(res, sum - cards[odd_pos] + cards[i]);
                break;
            }
        }
    }
    if (even_pos != -1) {
        // 有最小的偶数，找最大的奇数
        for (int i = cnt; i < sz; i++) {
            if (cards[i] & 1) {
                res = max(res, sum - cards[even_pos] + cards[i]);
                break;
            }
        }
    }

    return res;
}

int maxmiumScore_my(vector<int> cards, int cnt) {
    // 思路：贪心
    // 时间 O(nlogn)，空间 O(n)
    int sz = cards.size();
    vector<int> odd, even;
    for (int i : cards) {
        if (i & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }

    int rem = 0;
    if (cnt > even.size()) {
        rem = cnt - even.size();
        if (rem & 1) {
            rem++;
        }

        if (rem > cnt) {
            return 0;
        }

        // 奇数个数不够
        if (odd.size() < rem) {
            return 0;
        }
    }

    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());

    int sum_odd = 0, sum_even = 0;
    int i = 0, j = 0;
    for (; i < rem; i++) {
        sum_odd += odd[i];
    }

    int cnt_even = cnt - rem;
    for (; j < cnt_even; j++) {
        sum_even += even[j];
    }

    int res = sum_odd + sum_even;
    int cur = res;
    while (i < odd.size() && i + 1 < odd.size() && j - 1 >= 0 && j - 2 >= 0) {
        cur += odd[i++];
        cur += odd[i++];
        cur -= even[--j];
        cur -= even[--j];
        res = max(res, cur);
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 18
    cout << maxmiumScore({1, 2, 8, 9}, 3) << endl;
    // 0
    cout << maxmiumScore({3, 3, 1}, 2) << endl;
    // 10
    cout << maxmiumScore({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2},
    5)
         << endl;
    // 444
    cout << maxmiumScore({84, 38, 69, 19, 57, 57, 73, 74, 58, 48,
                          43, 59, 7,  85, 84, 95, 70, 3,  96, 24},
                         5)
         << endl;
    cout << maxmiumScore({2, 2, 2, 2}, 3) << endl;
    cout << maxmiumScore({4, 8, 3}, 2) << endl;
    // vector<int> tmp = getNRandom(1, 100, 200);
    // printVector(tmp);
    // cout << maxmiumScore(tmp, 77);

    return 0;
}
