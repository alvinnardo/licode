#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

string finalString(string s) {

    string res;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'i') {
            res += s[i];
        } else {
            int cnt = 1;
            while (i + 1 < s.length() && s[i + 1] == 'i') {
                i++;
                cnt++;
            }
            if (cnt & 1) {
                reverse(res.begin(), res.end());
            }
        }
    }
    return res;
}

int main(void) {
    cout << finalString("string") << endl;
    cout << finalString("poiinter") << endl;

    return 0;
}
