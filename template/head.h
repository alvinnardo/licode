#pragma once
#include "tree.h"
#include <bits/stdc++.h>
#include <random>
using namespace std;

inline void printBool(bool t) {
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

template <class T> void printVector(const vector<T> &nums) {
    ostringstream oss;
    for (auto &t : nums) {
        oss << t << ",";
    }
    auto res = oss.str();
    if (!res.empty()) {
        res.pop_back();
    }
    cout << res << endl;
}

template <class T> void printVectorVector(const vector<vector<T>> &nums) {
    for (auto &t : nums) {
        printVector(t);
    }
}

static int getRandom(int a, int b) {
    std::default_random_engine e;
    e.seed(time(0));

    return (e() % (b - a + 1)) + a;
}

static vector<int> getNRandom(int a, int b, int n, bool unique = false) {
    std::default_random_engine e;
    e.seed(time(0));

    auto getRangeNum = [&]() { return (e() % (b - a + 1)) + a; };
    if (unique && b - a + 1 <= n) {
        cout << "range larger than n in unique mode" << endl;
        return {};
    }

    vector<int> res;
    unordered_set<int> uset;
    for (int i = 0; i < n; i++) {
        int t = getRangeNum();
        if (unique) {
            while (uset.find(t) != uset.end()) {
                t = getRangeNum();
            }
            uset.insert(t);
        }

        res.push_back(t);
    }
    return res;
}
