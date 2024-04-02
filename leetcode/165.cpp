#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    // 思路：拆分，并比较 vector
    vector<int> vec1, vec2;
    auto getVec = [](const string &str, vector<int> &vec) {
        int len = str.length();

        int tmp = 0;
        for (int i = 0; i <= len; i++) {
            if (i == len || str[i] == '.') {
                vec.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp * 10 + (int)(str[i] - '0');
            }
        }
    };

    getVec(version1, vec1);
    getVec(version2, vec2);
    int sz1 = vec1.size(), sz2 = vec2.size();
    if (sz1 > sz2) {
        for (int i = 0; i < sz1 - sz2; i++) {
            vec2.push_back(0);
        }
    } else {
        for (int i = 0; i < sz2 - sz1; i++) {
            vec1.push_back(0);
        }
    }

    // printVector(vec1);
    // printVector(vec2);
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] > vec2[i]) {
            return 1;
        } else if (vec1[i] < vec2[i]) {
            return -1;
        }
    }
    return 0;
}

int main(void) {
    cout << compareVersion("1.01", "1.001") << endl;
    cout << compareVersion("1.0", "1.0.0") << endl;
    cout << compareVersion("0.1", "1.1") << endl;

    return 0;
}
