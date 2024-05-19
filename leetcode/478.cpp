#include "../template/head.h"
#include <bits/stdc++.h>

class Solution {
  public:
    double m_radius = 0;
    double m_x_center = 0;
    double m_y_center = 0;
    // mt19937 是梅森旋转算法，用于生成随机数
    // 循环节为 2^19937 - 1，是一个梅森素数
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    Solution(double radius, double x_center, double y_center)
        : dis(-radius, radius), m_radius(radius), m_x_center(x_center),
          m_y_center(y_center) {
        srand(time(NULL));
        srand48(time(NULL));
    }

    vector<double> randPoint() {
        // 学习题解算法
        // 时间 O(1)，期望是 圆的面积 / 正方形面积
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= m_radius * m_radius) {
                return {m_x_center + x, m_y_center + y};
            }
        }
    }

    vector<double> randPoint_my() {
        // 思路：拒绝采样
        // 先随机整数点，再随机小数点

        auto getRandDouble = [&]() -> double {
            double d = m_radius * 2;
            while (true) {
                int x_int = rand() % ((int)d + 1);
                double x_double = x_int * 1.0 + drand48();
                if (x_double <= d) {
                    return x_double;
                }
            }
        };

        while (true) {
            double x_double = getRandDouble() - m_radius,
                   y_double = getRandDouble() - m_radius;
            if (x_double * x_double + y_double * y_double <=
                m_radius * m_radius) {
                // cout << x_double << " " << y_double << endl;
                cout << x_double * x_double + y_double * y_double << endl;
                return {x_double + m_x_center, y_double + m_y_center};
            }
        }

        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution solution(1.0, 0.0, 0.0);
    solution.randPoint();
    solution.randPoint();
    solution.randPoint();

    return 0;
}
