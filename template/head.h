#pragma once
#include "list.h"
#include "tree.h"
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
    bool is_string = is_same<T, std::string>::value;

    for (auto t : nums) {
        if (is_string) {
            oss << "\"" << t << "\"" << delimiter;
        } else {
            oss << t << delimiter;
        }
    }
    auto res = oss.str();
    if (!res.empty()) {
        res.pop_back();
    }
    cout << "[" << res << "]" << endl;
}

template <class T>
void printVectorVector(const vector<vector<T>> nums_vv,
                       const std::string &delimiter = ",") {
    if (nums_vv.empty()) {
        cout << "[]" << endl;
        return;
    }
    ostringstream oss, oss_line;
    oss << "[";
    for (int i = 0; i < nums_vv.size(); i++) {
        const auto &nums_v = nums_vv[i];
        oss << "[";
        for (int j = 0; j < nums_v.size(); j++) {
            oss << nums_v[j];
            if (j != nums_v.size() - 1) {
                oss << delimiter;
            }
        }
        oss << "]";
        if (i != nums_vv.size() - 1) {
            oss << ",";
        }
    }
    oss << "]";

    cout << oss.str() << endl;
}

static int getRandom(int a, int b) {
    setSrand();
    return (rand() % (b - a + 1)) + a;
}

static vector<int> getNRandom(int a, int b, int n, bool unique = false) {
    setSrand();

    auto getRangeNum = [&]() { return (rand() % (b - a + 1)) + a; };
    if (unique && b - a + 1 < n) {
        cout << "range must be not less than n in unique mode" << endl;
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
