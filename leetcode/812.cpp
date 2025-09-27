#include "../template/head.h"
#include <bits/stdc++.h>

double largestTriangleArea(vector<vector<int>> &&points) {
    // 思路：数学
    // 时间 O(n3)，空间 O(1)

    // S = 1/2 * ab * sin
    // cos = (a2 + b2 - c2) / 2ab
    int sz = points.size();

    double a2{}, b2{}, c2{}, a{}, b{};
    double res = 0, cos = 0, sin = 0;
    auto get2 = [](const auto &p1, const auto &p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
               (p1[1] - p2[1]) * (p1[1] - p2[1]);
    };
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            for (int k = j + 1; k < sz; k++) {
                a2 = get2(points[i], points[j]);
                b2 = get2(points[i], points[k]);
                c2 = get2(points[j], points[k]);
                a = sqrt(a2), b = sqrt(b2);
                cos = (a2 + b2 - c2) / (2 * a * b);
                sin = sqrt(1 - cos * cos);
                res = max(res, a * b * 0.5 * sin);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 2.00000
    cout << largestTriangleArea({{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}})
         << endl;
    // 0.50000
    cout << largestTriangleArea({{1, 0}, {0, 0}, {0, 1}}) << endl;

    return 0;
}
