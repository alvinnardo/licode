#include "../template/head.h"
#include <bits/stdc++.h>

int wateringPlants(vector<int> plants, int capacity) {

    // 思路：模拟
    // 时间 O(n), 空间 O(1)
    int t_capacity = capacity;

    int sz = plants.size(), cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (t_capacity >= plants[i]) {
            t_capacity -= plants[i];
            cnt++;
        } else {
            t_capacity = capacity - plants[i];
            cnt += (i << 1) + 1;
        }
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    // 14
    cout << wateringPlants({2, 2, 3, 3}, 5) << endl;
    // 30
    cout << wateringPlants({1, 1, 1, 4, 2, 3}, 4) << endl;
    // 49
    cout << wateringPlants({7, 7, 7, 7, 7, 7, 7}, 8) << endl;
    // 1
    cout << wateringPlants({7}, 8) << endl;

    return 0;
}
