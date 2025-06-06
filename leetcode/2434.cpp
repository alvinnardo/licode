#include "../template/head.h"
#include <bits/stdc++.h>

string robotWithString(string s) {
    // 根据题解优化
    // 时间 O(n + k)，空间 O(n + k)

    // 和剩下的最小的比就行
    string st, res;
    vector<int> vec(26);
    for (int i = 0; i < s.length(); i++) {
        vec[s[i] - 'a']++;
    }

    int min_pos = 0;

    // 看剩下的最小值是否在自己后面
    // 如果在自己后面，自己就是当前最小的
    auto check = [&](int pos) { return min_pos >= pos; };
    while (min_pos < vec.size() && vec[min_pos] == 0) {
        min_pos++;
    }

    for (int i = 0; i < s.length(); i++) {
        while (!st.empty() && check(st.back() - 'a')) {
            res += st.back();
            st.pop_back();
        }

        if (check(s[i] - 'a')) {
            res += s[i];
        } else {
            st += s[i];
        }

        vec[s[i] - 'a']--;
        while (min_pos < vec.size() && vec[min_pos] == 0) {
            min_pos++;
        }
    }

    while (!st.empty()) {
        res += st.back();
        st.pop_back();
    }

    return res;
}

string robotWithString1(string s) {
    // 思路：栈 + 哈希表
    // 时间 O(nk)，空间 O(n + k)

    // 需要知道后面有几个比自己小的
    // 如果自己是当前最小的，则可以输出
    // 用一个统计数组，能判断自己是否是最小的

    // 因为处理完一个字符之后，可以处理缓存栈的栈顶的字符
    // 所以需要知道栈顶字符后面还有几个比自己小的
    string st, res;
    vector<int> vec(26);
    for (int i = 0; i < s.length(); i++) {
        vec[s[i] - 'a']++;
    }

    auto check = [&](int pos) {
        for (int i = 0; i < pos; i++) {
            if (vec[i] != 0) {
                return false;
            }
        }
        return true;
    };

    // 遍历一个删除一个，剩下的就是剩余字符串的所有字符统计
    // 判断时扫描一遍哈希表
    for (int i = 0; i < s.length(); i++) {
        while (!st.empty() && check(st.back() - 'a')) {
            res += st.back();
            st.pop_back();
        }

        if (check(s[i] - 'a')) {
            res += s[i];
        } else {
            st += s[i];
        }
        // 不管是结果还是缓存起来，剩下的串都要减去该字符
        vec[s[i] - 'a']--;
    }

    while (!st.empty()) {
        res += st.back();
        st.pop_back();
    }

    return res;
}

int main(int argc, char *argv[]) {
    // "azz"
    cout << robotWithString("zza") << endl;
    // "abc"
    cout << robotWithString("bac") << endl;
    // "addb"
    cout << robotWithString("bdda") << endl;

    return 0;
}
