#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {

    // vector 做缓存
    string tmp;
    vector<string> vec;
    for (int i = 0; i <= path.length(); i++) {
        if (i < path.length() && path[i] == '/' || i == path.length()) {
            if (!tmp.empty()) {
                if (tmp == "..") {
                    if (!vec.empty()) {
                        vec.pop_back();
                    }
                } else if (tmp == ".") {
                    // do nothing
                } else {
                    vec.emplace_back(tmp);
                }

                tmp = "";
            }
        } else {
            tmp += path[i];
        }
    }

    string res;
    if (vec.empty()) {
        res = "/";
    }

    for (auto &s : vec) {
        res += "/" + s;
    }
    return res;
}

int main(void) {
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo///////") << endl;
    cout << simplifyPath("/home/aaa") << endl;
    cout << simplifyPath("/home/...////./aaa/b/./..//") << endl;

    return 0;
}
