#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 总体空间 O(1)，字符串只保存当前结果
class TextEditor {
  public:
    int m_pos = 0; // 表示左边有几个字符
    string m_str;
    TextEditor() {}

    // 时间 O(n)
    void addText(string text) {
        // 在当前位置插入
        m_str.insert(m_str.begin() + m_pos, text.begin(), text.end());
        m_pos += text.length();
    }

    // 时间 O(k)
    int deleteText(int k) {
        // 左边的字符都要删除
        if (m_pos < k) {
            m_str.erase(0, m_pos);
            int cnt = m_pos;
            m_pos = 0;
            return cnt;
        }

        m_str.erase(m_pos - k, k);
        m_pos -= k;
        return k;
    }

    string output_10() {
        int bng = m_pos < 10 ? 0 : m_pos - 10;
        return m_str.substr(bng, m_pos - bng);
    }

    // 时间 O(k)
    string cursorLeft(int k) {
        m_pos = m_pos < k ? 0 : m_pos - k;
        return output_10();
    }

    // 时间 O(k)
    string cursorRight(int k) {
        int right_cnt = m_str.length() - m_pos; // 右边剩余的个数
        m_pos = right_cnt < k ? m_str.length() : m_pos + k;
        return output_10();
    }
};

int main(int argc, char *argv[]) {
    TextEditor textEditor;
    textEditor.addText("leetcode");
    cout << textEditor.deleteText(4) << endl; //  4
    textEditor.addText("practice");
    cout << textEditor.cursorRight(3) << endl; // "etpractice"
    cout << textEditor.cursorLeft(8) << endl;  // "leet"
    cout << textEditor.deleteText(10) << endl; // 4
    cout << textEditor.cursorLeft(2) << endl;  // ""
    cout << textEditor.cursorRight(6) << endl; // "practi"

    return 0;
}
