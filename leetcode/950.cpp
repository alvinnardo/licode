#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> deckRevealedIncreasing(vector<int> deck) {
    // 思路：模拟
    // 时间 O(nlogn)，空间 O(n)
    // 用下标正推，然后再推回来

    int sz = deck.size();
    vector<int> idx_vec;
    queue<int> qu;
    for (int i = 0; i < sz; i++) {
        qu.push(i);
    }

    // 用队列优化一下，比列表节省空间
    while (!qu.empty()) {
        idx_vec.push_back(qu.front());
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    }

    // 最后 res 中保存有序数组的下标
    // deck 中保存有序数组
    // 反着推即可
    sort(deck.begin(), deck.end());
    vector<int> res(sz);

    // res[idx[i]] = deck[i];
    for (int i = 0; i < sz; i++) {
        res[idx_vec[i]] = deck[i];
    }

    return res;
}

int main(int argc, char *argv[]) {
    // {2,13,3,11,5,17,7}
    printVector(deckRevealedIncreasing({17, 13, 11, 2, 3, 5, 7}));

    return 0;
}
