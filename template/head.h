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
    for (auto &t : nums) {
        cout << t << ",";
    }
    cout << endl;
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

static vector<int> getNRandom(int a, int b, int n) {
    std::default_random_engine e;
    e.seed(time(0));

    auto getRangeNum = [&]() { return (e() % (b - a + 1)) + a; };

    vector<int> res;
    for (int i = 0; i < n; i++) {
        res.push_back(getRangeNum());
    }
    return res;
}
