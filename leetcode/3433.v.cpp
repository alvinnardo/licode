#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> countMentions(int numberOfUsers, vector<vector<string>> &&events) {
    // 思路：模拟 + 差分数组
    // 时间 O(mn)，空间 O(n)

    // 用一个队列保存恢复时间
    // 如果出现 HERE，先恢复队列中的 ID，然后除去剩余的 ID，加上所有 ID

    // 按时间排序
    sort(events.begin(), events.end(),
         [](const auto &event1, const auto &event2) {
             // 注意这里排序要转成数字排序，因为 "10" < "5"
             // 同一时刻发生的时间，"OFFLINE" 需要优先处理
             int t1 = stoi(event1[1]), t2 = stoi(event2[1]);
             return (t1 == t2 ? event1[0] > event2[0] : t1 < t2);
         });

    vector<int> res(numberOfUsers);
    deque<pair<int, int>> up_queue; // 因为排序过，所以会按照重新上线的时间排序
    int sz = events.size();

    auto addRange = [&](int bng, int end, bool plus = true) {
        // 左闭右开
        res[bng] += (plus ? 1 : -1);
        if (end < res.size()) {
            res[end] += (plus ? -1 : 1);
        }
    };

    auto checkID = [&](const auto &str) {
        int num{};
        for (int i = 0; i < str.size() + 1; i++) {
            if (i == str.size() || str[i] == ' ') {
                addRange(num, num + 1);
                num = 0;
            } else if (str[i] != 'i' && str[i] != 'd') {
                num = num * 10 + (str[i] - '0');
            }
        }
    };

    for (int i = 0; i < sz; i++) {
        const auto &event = events[i];
        if (event[0] == "MESSAGE") {
            if (event[2][0] == 'i') {
                checkID(event[2]);
            } else if (event[2][0] == 'A') {
                addRange(0, res.size());
            } else { // HERE
                int cur_time = stoi(event[1]);
                addRange(0, res.size());
                while (!up_queue.empty() &&
                       up_queue.front().first <= cur_time) { // 恢复
                    up_queue.pop_front();
                }

                for (int i = 0; i < up_queue.size(); i++) { // 除去没有恢复的 ID
                    addRange(up_queue[i].second, up_queue[i].second + 1, false);
                }
            }
        } else {
            // 重新上线的时间
            up_queue.emplace_back(stoi(event[1]) + 60, stoi(event[2]));
        }
    }

    for (int i = 1; i < res.size(); i++) {
        res[i] += res[i - 1];
    }
    return res;
}

int main(int argc, char *argv[]) {
    // {2, 2}
    cout << countMentions(2, {{"MESSAGE", "10", "id1 id0"},
                              {"OFFLINE", "11", "0"},
                              {"MESSAGE", "71", "HERE"}})
         << endl;
    // {2, 2}
    cout << countMentions(2, {{"MESSAGE", "10", "id1 id0"},
                              {"OFFLINE", "11", "0"},
                              {"MESSAGE", "12", "ALL"}})
         << endl;
    // {0,1}
    cout << countMentions(2,
                          {{"OFFLINE", "10", "0"}, {"MESSAGE", "12", "HERE"}})
         << endl;
    // {1, 3, 2}
    cout << countMentions(3, {{"MESSAGE", "5", "HERE"},
                              {"OFFLINE", "10", "0"},
                              {"MESSAGE", "15", "HERE"},
                              {"OFFLINE", "18", "2"},
                              {"MESSAGE", "20", "HERE"}})
         << endl;

    return 0;
}
