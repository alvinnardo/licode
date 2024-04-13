#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a
    // nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a
    // single integer The result is undefined if this NestedInteger holds a
    // nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a
    // nested list The result is undefined if this NestedInteger holds a single
    // integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {

  public:
    // 使用迭代器，不用存数据或指针
    stack<
        pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>>
        st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        st.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        int t = st.top().first->getInteger();
        st.top().first++;

        return t;
    }

    bool hasNext() {
        while (!st.empty()) {
            auto &t = st.top();
            if (t.first == t.second) {
                st.pop();
                if (!st.empty()) {
                    st.top().first++;
                }
                continue;
            }

            if (t.first->isInteger()) {
                return true;
            }

            auto &l = t.first->getList();
            st.emplace(l.begin(), l.end());
        }
        return false;
    }
};

class NestedIterator1 {

  public:
    vector<int> res;
    int idx = 0;
    NestedIterator1(vector<NestedInteger> &nestedList) {
        function<void(const vector<NestedInteger> &)> dfs =
            [&](const vector<NestedInteger> &list) {
                for (const auto &nested : list) {
                    if (nested.isInteger()) {
                        res.push_back(nested.getInteger());
                    } else {
                        dfs(nested.getList());
                    }
                }
            };
        dfs(nestedList);
    }

    int next() { return res[idx++]; }

    bool hasNext() { return idx < res.size(); }
};

int main(void) { return 0; }
