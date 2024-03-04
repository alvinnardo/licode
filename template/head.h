#pragma once
#include <bits/stdc++.h>
using namespace std;

void printBool(bool t) {
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

template <class T>
void printVector(const vector<T> &nums)
{
    for (auto &t : nums) {
        cout << t << " ";
    }
    cout << endl;
}

template <class T>
void printVectorVector(const vector<vector<T>> &nums) {
    for (auto &t : nums) {
        printVector(t);
    }
}
