#include "../template/head.h"
#include <bits/stdc++.h>

int distanceBetweenBusStops(vector<int> distance, int start, int destination) {
    // 思路：模拟
    // 时间 O(n)，空间 O(1)
    if (start > destination) {
        int t = start;
        start = destination;
        destination = t;
    }

    int sum = 0, val = 0;
    for (int i = 0; i < distance.size(); i++) {
        sum += distance[i];
        val += i >= start && i < destination ? distance[i] : 0;
    }

    return val < sum - val ? val : sum - val;
}

int main(int argc, char *argv[]) {

    // 1
    cout << distanceBetweenBusStops({1, 2, 3, 4}, 0, 1) << endl;
    // 3
    cout << distanceBetweenBusStops({1, 2, 3, 4}, 0, 2) << endl;
    // 4
    cout << distanceBetweenBusStops({1, 2, 3, 4}, 0, 3) << endl;

    return 0;
}
