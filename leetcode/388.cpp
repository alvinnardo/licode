#include "../template/head.h"
#include <bits/stdc++.h>

int lengthLongestPath(string input) {

    // 前后加上分隔符方便处理，层号分隔符为 \n\t*
    input += "\n";

    int max_len = INT_MIN, len = input.length();
    stack<pair<int, int>> st; // 保存层号和长度

    int level = 0, dir_len = 0, is_file = false;
    for (int i = 0; i < len; i++) {
        if (input[i] == '\n') {
            // 获取层号
            level = 0;
            while (i + 1 < len && input[i + 1] == '\t') {
                level++;
                i++;
            }
        } else if (input[i] == '.') {
            dir_len++;
            is_file = true;
        } else {
            dir_len++;
        }

        if (i + 1 < len && input[i + 1] == '\n') {
            // 处理本次的长度
            while (!st.empty() && st.top().first >= level) { // 层数更低
                st.pop();
            }

            int sub_len = dir_len;
            if (!st.empty()) {
                auto &t = st.top();
                sub_len = t.second + dir_len + 1;
            }

            st.emplace(level, sub_len);
            if (is_file) {
                max_len = max(max_len, sub_len);
            }

            // restore
            level = 0;
            dir_len = 0;
            is_file = false;
        }
    }

    return max_len == INT_MIN ? 0 : max_len;
}

int main(void) {
    // 20
    cout << lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext")
         << endl;
    // 32
    cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1."
                              "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n"
                              "\t\t\tfile2.ext")
         << endl;
    // 0
    cout << lengthLongestPath("a") << endl;
    // 0
    cout << lengthLongestPath("bbb\n\t") << endl;
    // 12
    cout << lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt") << endl;
    // 22
    cout << lengthLongestPath(
                "dir\n\tsubdir1\naaaaa\n\tbbbb.ext\n\tsubdir2\n\t\tfile.ext")
         << endl;
    // 0
    cout << lengthLongestPath("\n\n\n\n\n\n\n\n\n\n\n") << endl;

    return 0;
}
