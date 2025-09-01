#include "../template/head.h"
#include <bits/stdc++.h>

/**
  最开始的想法是：对于结果来说，分母是个数不变，分子越大越好
  分子是由一个一个平均数组成的，一个平均数也是一个分式，分子和分母都增加分式增加
  用贪心将增量加到最大的分式上即可

  但仔细想是不对的，分式最大加上增量后不一定会增加，比如 {2, 2}，之前之后都是 1
  要的是加上一个增量后，选取平均数增加量最多的
  */

// 暴力模拟，对拍用
double maxAverageRatio1(vector<vector<int>> &&classes, int extraStudents) {
    // 思路：模拟
    // 时间 O(mn)，空间 O(1)

    for (int i = 0; i < extraStudents; i++) {
        // 选出增量最大的那个班级
        double e = 0, t = 0;
        int pos = 0;
        for (int j = 0; j < classes.size(); j++) {
            t = (classes[j][0] + 1) * 1.0 / (classes[j][1] + 1) -
                classes[j][0] * 1.0 / classes[j][1];
            if (t > e) {
                e = t;
                pos = j;
            }
        }

        classes[pos][0]++;
        classes[pos][1]++;
    }

    double res = 0;
    for (auto &c : classes) {
        res += c[0] * 1.0 / c[1];
    }

    return res / classes.size();
}

// 求分数增加量
auto getDiff(const auto &t) -> double {
    return (t[0] + 1) * 1.0 / (t[1] + 1) - t[0] * 1.0 / t[1];
};

struct cmp {
    // 大根堆，less
    bool operator()(const auto &a, const auto &b) {
        return getDiff(a) < getDiff(b);
    };
};

double maxAverageRatio2(vector<vector<int>> &&classes, int extraStudents) {
    // 思路：优先队列
    // 时间 O(mlogn)，空间 O(n)

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq(classes.begin(),
                                                             classes.end());

    // 每次选取一个增加量最大的分式
    for (int i = 0; i < extraStudents; i++) {
        int a = pq.top()[0] + 1, b = pq.top()[1] + 1;
        pq.pop();
        pq.push({a, b});
    }

    // 计算所有平均数的和
    double res = 0;
    while (!pq.empty()) {
        res += pq.top()[0] * 1.0 / pq.top()[1];
        pq.pop();
    }

    return res / classes.size();
}

double maxAverageRatio3(vector<vector<int>> &&classes, int extraStudents) {
    // 思路：优先队列
    // 时间 O(mlogn)，空间 O(n)
    // 优化常数时间

    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    double res = 0;
    for (auto &c : classes) {
        pq.emplace(c);
        res += c[0] * 1.0 / c[1];
    }

    // 每次选取一个增加量最大的分式
    vector<int> t;
    for (int i = 0; i < extraStudents; i++) {
        t = std::move(pq.top());
        res += getDiff(t);
        t[0]++;
        t[1]++;

        pq.pop();
        pq.emplace(t);
    }

    return res / classes.size();
}

double maxAverageRatio(vector<vector<int>> &&classes, int extraStudents) {
    // 思路：优先队列
    // 时间 O(mlogn)，空间 O(n)
    // 优化常数时间
    // 自定义结构，比 vector 快点(参考灵神的代码)

    struct Pair {
        int a, b;
    };
    auto cmp = [](const Pair &a, const Pair &b) {
        return (a.a + 1) * 1.0 / (a.b + 1) - a.a * 1.0 / a.b <
               (b.a + 1 * 1.0) / (b.b + 1) - (b.a) * 1.0 / b.b;
    };

    priority_queue<Pair, vector<Pair>, decltype(cmp)> pq;

    double res = 0;
    for (auto &c : classes) {
        pq.emplace(c[0], c[1]);
        res += c[0] * 1.0 / c[1];
    }

    // 每次选取一个增加量最大的分式
    vector<int> t;
    for (int i = 0; i < extraStudents; i++) {
        auto [a, b] = pq.top();
        res += (a + 1) * 1.0 / (b + 1) - a * 1.0 / b;

        pq.pop();
        pq.emplace(a + 1, b + 1);
    }

    return res / classes.size();
}

int main(int argc, char *argv[]) {
    // 0.78333
    cout << maxAverageRatio({{1, 2}, {3, 5}, {2, 2}}, 2) << endl;
    // 0.53485
    cout << maxAverageRatio({{2, 4}, {3, 9}, {4, 5}, {2, 10}}, 4) << endl;

    return 0;
}
