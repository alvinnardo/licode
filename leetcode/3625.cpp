#include "../template/head.h"
#include <bits/stdc++.h>

int countTrapezoids(vector<vector<int>> &&points) {
    // 思路：哈希表
    // 时间 O(n2)，空间 O(k)，k 是不同斜率个数，最多 O(n2)，最少 O(1)

    // 先按斜率区分，再按截距区分

    // 两点式方程转一般式结果 (y1-y2) * x + (x2-x1) * y + (x1*y2-y1*x2) = 0
    // 与 y 轴截距为 (y1*x2 - x1*y2) / (x2-x1)

    // 如果是垂直的线，则转为与 x 轴截距

    // 注意：浮点数的正 0 和 负 0 的二进制位不同，值相同
    int sz = points.size();
    double dx{}, dy{};

    auto getK = [](auto &a, auto &b) -> double {
        double dy = b[1] - a[1], dx = b[0] - a[0];
        double t = dy / dx;
        return t != -INFINITY ? (t == 0 ? 0 : t) : INFINITY;
    };

    auto getD = [](auto &a, auto &b) -> double {
        if (a[0] == b[0]) {
            return a[0];
        }
        double up = a[1] * b[0] - a[0] * b[1], down = b[0] - a[0];
        double t = up / down;
        return t == 0 ? 0 : t;
    };

    auto getLen = [](auto &a, auto &b) -> double {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    };

    // <斜率，截距>
    unordered_map<double, unordered_map<double, int>> umap;
    // <斜率 ^ 长度，截距>
    unordered_map<uint64_t, unordered_map<double, int>> umap2;
    double k{}, d{}, len{};
    uint64_t t{}, uk{}, ulen{};
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < i; j++) {
            k = getK(points[i], points[j]);
            d = getD(points[i], points[j]);
            len = getLen(points[i], points[j]);
            uk = bit_cast<uint64_t>(k);
            ulen = bit_cast<uint64_t>(len);
            ++umap[k][d];
            ++umap2[uk ^ (ulen + 0x9e3779b9 + (uk << 6) + (uk >> 2))][d];
        }
    }

    // 根据截距分组，找到所有矩形
    int res{};
    int pre{};
    for (auto &it : umap) {
        pre = 0;
        for (auto &itt : it.second) {
            res += itt.second * pre;
            pre += itt.second;
        }
    }

    // 找到斜率相同且长度相同的线段，即平行四边形个数
    // 删除重复计算的个数即可
    int cnt{};
    for (auto &it : umap2) {
        pre = 0;
        for (auto &itt : it.second) {
            cnt += itt.second * pre;
            pre += itt.second;
        }
    }

    return res - (cnt >> 1);
}

int main(int argc, char *argv[]) {
    // 2
    cout << countTrapezoids({{3, 2}, {3, 0}, {2, 3}, {-3, 2}, {2, -3}}) << endl;
    // 1
    cout << countTrapezoids({{0, 0}, {1, 0}, {0, 1}, {2, 1}}) << endl;
    // 10
    cout << countTrapezoids({{71, -89},
                             {-75, -89},
                             {-9, 11},
                             {-24, -89},
                             {-51, -89},
                             {-77, -89},
                             {42, 11}})
         << endl;
    // 3
    cout << countTrapezoids(
                {{10, -66}, {-36, 30}, {86, 30}, {83, 19}, {86, 19}, {-39, 19}})
         << endl;
    // 1
    cout << countTrapezoids({{312, 100},
                             {347, 67},
                             {146, -881},
                             {411, -63},
                             {264, 226},
                             {82, -751}})
         << endl;

    return 0;
}
