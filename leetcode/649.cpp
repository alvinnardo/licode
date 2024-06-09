#include "../template/head.h"
#include <bits/stdc++.h>

string predictPartyVictory(string senate) {
    // 题解：贪心
    // 时间 O(n)，空间 O(n)
    // 两个队列
    int len = senate.length();
    queue<int> rq, dq;

    for (int i = 0; i < len; i++) {
        if (senate[i] == 'R') {
            rq.push(i);
        } else {
            dq.push(i);
        }
    }

    while (!rq.empty() && !dq.empty()) {
        // 小的先投票
        // 投完票加一个长度，参加下一轮投票
        if (dq.front() < rq.front()) {
            dq.push(dq.front() + len);
        } else {
            rq.push(rq.front() + len);
        }
        dq.pop();
        rq.pop();
    }

    return rq.size() ? "Radiant" : "Dire";
}

string predictPartyVictory_my(string senate) {
    // 思路：模拟，可以禁止任何一个对方的人
    // 贪心，禁止下一个阵营最近的人
    // 时间 O(n)，空间 O(n)
    int r_cnt = 0, d_cnt = 0;
    vector<bool> valid_vec(senate.length(), true);
    for (int i = 0; i < senate.length(); i++) {
        if (senate[i] == 'R') {
            r_cnt++;
        }
        if (senate[i] == 'D') {
            d_cnt++;
        }
    }

    int bid_r = 0, bid_d = 0;
    while (r_cnt && d_cnt) {
        for (int i = 0; i < senate.length(); i++) {
            if (valid_vec[i] == false) {
                continue;
            }

            if (bid_r && senate[i] == 'R') {
                bid_r--;
                valid_vec[i] = false;
                continue;
            }
            if (bid_d && senate[i] == 'D') {
                bid_d--;
                valid_vec[i] = false;
                continue;
            }

            if (senate[i] == 'R') {
                bid_d++;
                d_cnt--;
            } else {
                bid_r++;
                r_cnt--;
            }

            if (r_cnt == 0 || d_cnt == 0) {
                break;
            }
        }
    }

    return r_cnt ? "Radiant" : "Dire";
}

int main(int argc, char *argv[]) {
    // "Radiant"
    cout << predictPartyVictory("RD") << endl;
    // "Dire"
    cout << predictPartyVictory("RDD") << endl;
    // "Dire"
    cout << predictPartyVictory("DDRRR") << endl;
    // "Dire"
    cout << predictPartyVictory("DRDRR") << endl;
    // "Radiant"
    cout << predictPartyVictory("DRRDRDRDRDDRDRDR") << endl;

    return 0;
}
