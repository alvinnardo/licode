#include "../template/head.h"
#include <bits/stdc++.h>

vector<int> distributeCandies(int candies, int num_people) {
    // 思路：模拟
    // 时间 O(log(candies))，空间 O(1)
    vector<int> res(num_people);

    int bng = 1, pos = 0;
    while (candies) {
        int t = candies >= bng ? bng : candies;
        bng++;
        res[pos] += t;
        candies -= t;

        pos = (pos + 1) % num_people;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // [1,2,3,1]
    printVector(distributeCandies(7, 4));
    // [5,2,3]
    printVector(distributeCandies(10, 3));

    return 0;
}
