#pragma once
#include "tree.h"
#include "list.h"
#include <bits/stdc++.h>
#include <random>
using namespace std;

static bool has_srand = false;

static void setSrand() {
    if (!has_srand) {
        has_srand = true;
        srand(time(NULL));
    }
}

inline void printBool(bool t) {
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

template <class T>
void printVector(const vector<T> nums, string delimiter = ",") {
    ostringstream oss;
    for (auto t : nums) {
        oss << t << delimiter;
    }
    auto res = oss.str();
    if (!res.empty()) {
        res.pop_back();
    }
    cout << res << endl;
}

template <class T> void printVectorVector(const vector<vector<T>> nums) {
    for (auto t : nums) {
        printVector(t);
    }
}

static int getRandom(int a, int b) {
    setSrand();
    return (rand() % (b - a + 1)) + a;
}

static vector<int> getNRandom(int a, int b, int n, bool unique = false) {
    setSrand();

    auto getRangeNum = [&]() { return (rand() % (b - a + 1)) + a; };
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
