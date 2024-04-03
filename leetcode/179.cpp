#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 优化
string largestNumber(vector<int> nums) {
    // 可以直接一次比较即可
    vector<string> vec;
    int cnt0 = 0;
    for (auto &num : nums) {
        if (num == 0) {
            cnt0++;
        }
        vec.emplace_back(to_string(num));
    }

    if (cnt0 == nums.size()) { // 全是零
        return "0";
    }

    sort(vec.begin(), vec.end(),
         [](const string &a, const string &b) { return a + b > b + a; });

    string res;
    for (auto &str : vec) {
        res += str;
    }

    return res;
}

string largestNumber_my(vector<int> nums) {
    // 1. 将数字转为字符串
    // 2. 配置十个桶，按首字符入桶
    // 3. 按桶顺序取数，取桶内数据时，需要进行排序

    vector<vector<string>> buckets(10);

    int cnt0 = 0;
    int sz = nums.size();
    for (int i = 0; i < sz; i++) {
        string tmp;
        int t = nums[i];
        if (t == 0) {
            buckets[0].emplace_back("0");
            cnt0++;
            continue;
        }

        while (t) {
            tmp += (t % 10 + '0');
            t /= 10;
        }
        reverse(tmp.begin(), tmp.end());

        int head = tmp[0] - '0';
        buckets[head].emplace_back(tmp);
    }

    if (cnt0 == sz) { // 全是零
        return "0";
    }

    // 0 不用管
    for (int i = 1; i < 10; i++) {
        auto &bucket = buckets[i];

        // 排序，比较前后关系
        // 比如 "23" 和 "232" => 23232，而不是 23223
        // 比如 "21" 和 "212" => 21221，而不是 21212
        sort(bucket.begin(), bucket.end(),
             [](const string &a, const string &b) {
                 // a 在前，b 在后，每个 a 和 b 都有如下关系
                 return a + b < b + a;
             });
    }

    string res;
    for (int i = 9; i >= 0; i--) {
        for (int j = buckets[i].size() - 1; j >= 0; j--) {
            res += buckets[i][j];
        }
    }

    return res;
}

int main(void) {
    cout << largestNumber({10, 2}) << endl;
    cout << largestNumber({3, 30, 34, 5, 9}) << endl;
    cout << largestNumber({0,  0,   1,  12,  111, 1113, 31,         33333,
                           37, 21,  22, 23,  212, 232,  1000000000, 34,
                           77, 731, 38, 65,  6,   4,    32,         5,
                           9,  93,  91, 157, 655})
         << endl;
    cout << largestNumber({23, 232}) << endl;
    cout << largestNumber({21, 212}) << endl;
    cout << largestNumber({3221, 322132}) << endl;
    cout << largestNumber({322132, 3221}) << endl;
    cout << largestNumber({0, 0, 0}) << endl;

    return 0;
}
