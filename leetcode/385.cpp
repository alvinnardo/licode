#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to
    // it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

NestedInteger deserialize(string s) {
    // 如果是数字，就调用 setInteger，如果是列表，就调用 add

    int i = 0, len = s.length();

    auto getNum = [](bool is_neg, int a) { return is_neg ? -a : a; };

    function<NestedInteger()> dfs = [&]() {
        bool is_list = false;

        int tmp = INT_MAX;
        bool is_neg = false;
        NestedInteger ni;
        while (i <= len) {
            if (i == len) {
                if (tmp != INT_MAX) {
                    if (is_list) {
                        ni.add(NestedInteger(getNum(is_neg, tmp)));
                    } else {
                        ni.setInteger(getNum(is_neg, tmp));
                    }
                }
                break;
            }

            if (s[i] == '[') {
                if (!is_list) {
                    is_list = true;
                } else {
                    ni.add(dfs());
                }
            } else if (s[i] == ']') {
                if (tmp != INT_MAX) {
                    ni.add(NestedInteger(getNum(is_neg, tmp)));
                }
                break;
            } else if (s[i] == ',') {
                if (tmp != INT_MAX) {
                    if (is_list) {
                        ni.add(NestedInteger(getNum(is_neg, tmp)));
                    } else {
                        ni.setInteger(getNum(is_neg, tmp));
                    }
                    tmp = INT_MAX;
                    is_neg = false;
                }
            } else if (s[i] == '-') {
                is_neg = true;
            } else {
                if (tmp == INT_MAX) {
                    tmp = 0;
                }
                tmp = tmp * 10 + (int)(s[i] - '0');
            }
            i++;
        }

        return ni;
    };

    return dfs();
}

int main(void) {
    deserialize("343");
    deserialize("[123,[456,[789]]]");
    deserialize("[123,[456,789],[111,222]]");
    deserialize("[[111],[456,789],[111,222]]");

    return 0;
}
