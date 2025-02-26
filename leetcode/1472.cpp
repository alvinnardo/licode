#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 用 vector 模拟即可
// 时间 O(k)，空间 O(k)，k 是调用次数，如果都是 visit，最差空间 O(n)
class BrowserHistory {
  public:
    vector<string> m_mem;
    int m_pos = -1;
    BrowserHistory(string homepage) : m_mem{homepage}, m_pos(0) {}

    void visit(string url) {
        m_mem.resize(m_pos + 1);
        m_mem.emplace_back(url);
        m_pos = m_mem.size() - 1;
    }

    string back(int steps) {
        m_pos -= steps;
        if (m_pos < 0) {
            m_pos = 0;
        }

        return m_mem[m_pos];
    }

    string forward(int steps) {
        m_pos += steps;
        if (m_pos >= m_mem.size()) {
            m_pos = m_mem.size() - 1;
        }
        return m_mem[m_pos];
    }
};

int main(int argc, char *argv[]) {
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    cout << browserHistory.back(1) << endl;    // "facebook.com"
    cout << browserHistory.back(1) << endl;    // "google.com"
    cout << browserHistory.forward(1) << endl; // "facebook.com"
    browserHistory.visit("linkedin.com");
    cout << browserHistory.forward(2) << endl; // "linkedin.com"
    cout << browserHistory.back(2) << endl;    // "google.com"
    cout << browserHistory.back(7) << endl;    // "leetcode.com"

    return 0;
}
