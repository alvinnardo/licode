#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

int getMoneyAmount_dp(int n) {
    // DP
    // 思路类似，算法更佳
    // f(i, j) 为范围 (i, j) 的最少金额
    // f(i, j) = min(k + max(f(i, k - 1), f(k + 1, j)))
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = j + dp[i][j - 1];
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
    }

    return dp[1][n];
}
int getMoneyAmount(int n) {
    // 优化的 DFS，依旧比 DP 慢不少
    vector<vector<int>> vv(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> dfs = [&](int a, int b) {
        if (a >= b) {
            return 0;
        }

        if (vv[a][b] != -1) {
            return vv[a][b];
        }

        int t = INT_MAX;
        for (int i = a; i <= b; i++) {
            t = min(t, i + max(dfs(a, i - 1), dfs(i + 1, b)));
        }

        vv[a][b] = t;
        return t;
    };

    return dfs(1, n);
}

// n 范围 [1, 200]
int getMoneyAmount_enum(int n) {
    // 记忆化搜索的时间复杂度也降不下来，先打个表
    vector<int> vec{
        0,   0,   1,   2,   4,   6,   8,   10,  12,  14,  16,  18,  21,  24,
        27,  30,  34,  38,  42,  46,  49,  52,  55,  58,  61,  64,  67,  70,
        73,  76,  79,  82,  86,  90,  94,  98,  102, 106, 110, 114, 119, 124,
        129, 134, 139, 144, 149, 154, 160, 166, 172, 178, 182, 186, 190, 194,
        198, 202, 206, 210, 214, 218, 222, 226, 230, 234, 238, 242, 246, 250,
        254, 258, 262, 266, 270, 274, 278, 282, 286, 290, 295, 300, 305, 310,
        315, 320, 325, 330, 335, 340, 345, 350, 355, 360, 365, 370, 376, 382,
        388, 394, 400, 406, 412, 418, 424, 430, 436, 442, 448, 454, 460, 466,
        473, 480, 487, 494, 501, 508, 515, 522, 529, 536, 543, 550, 555, 560,
        565, 570, 575, 580, 585, 590, 595, 600, 605, 610, 615, 620, 625, 630,
        635, 640, 645, 650, 655, 660, 666, 674, 680, 686, 692, 698, 703, 708,
        713, 718, 723, 728, 733, 738, 743, 748, 753, 758, 763, 768, 773, 778,
        783, 788, 793, 798, 803, 808, 813, 818, 823, 828, 833, 838, 843, 848,
        853, 858, 863, 868, 873, 878, 883, 888, 893, 898, 904, 910, 916, 922,
        928, 934, 940, 946, 952};
    return vec[n];
}

int getMoneyAmount_my(int n) {
    // 思路: DFS，求每个节点左子树和右子树的最大值，再加上根节点
    int minv = INT_MAX;

    if (n == 1)
        return 1;

    auto getNum = [&](int64_t a, int64_t b, int64_t c, int64_t d,
                      int64_t e) -> int64_t {
        return a * 1e12 + b * 1e9 + c * 1e6 + d * 1000 + e;
    };

    unordered_map<int64_t, int> umap;
    function<int(int, int, int, int, int)> dfs = [&](int root, int ll, int lr,
                                                     int rl, int rr) {
        int a = ll, b = lr, c = rl, d = rr;
        if (ll > lr) {
            a = b = 0;
        }
        if (rl > rr) {
            c = d = 0;
        }
        int64_t t = getNum(root, a, b, c, d);
        if (umap.find(t) != umap.end()) {
            return umap[t];
        }

        int lval = INT_MAX, rval = INT_MAX;
        if (lr > ll) {
            for (int i = ll; i <= lr; i++) {
                int t = dfs(i, ll, i - 1, i + 1, lr);
                lval = min(t, lval);
            }
        } else {
            lval = 0;
        }

        if (rr > rl) {
            for (int i = rl; i <= rr; i++) {
                int t = dfs(i, rl, i - 1, i + 1, rr);
                rval = min(t, rval);
            }
        } else {
            rval = 0;
        }

        int ans = root + max(lval, rval);
        umap[t] = ans;
        return ans;
    };

    for (int i = 1 + (n / 6); i <= n; i++) {
        minv = min(dfs(i, 1, i - 1, i + 1, n), minv);
    }

    return minv;
}

int main(void) {
    // // 1
    // cout << getMoneyAmount(1) << endl;
    // // 1
    // cout << getMoneyAmount(2) << endl;
    // // 2
    // cout << getMoneyAmount(3) << endl;
    // // 4
    // cout << getMoneyAmount(4) << endl;
    // 6
    // cout << getMoneyAmount(5) << endl;
    // // 8
    // cout << getMoneyAmount(6) << endl;
    // // 10
    // cout << getMoneyAmount(7) << endl;
    // [1,1,2,4,6,8,10,12,14,16,18,21,24,27,30,34,38,42,46,49,52,55,58,61,64,67,70,73,76,79,82,86,90,94,98,102,106,110,114,119,124,129,134,139,144,149,154,160,166,172,178,182,186,190,194,198,202,206,210,214,218,222,226,230,234,238,242,246,250,254,258,262,266,270,274,278,282,286,290,295,300,305,310,315,320,325,330,335,340,345,350,355,360,365,370,376,382,388,394,400,406,412,418,424,430,436,442,448,454,460,466,473,480,487,494,501,508,515,522,529,536,543,550,555,560,565,570,575,580,585,590,595,600,605,610,615,620,625,630,635,640,645,650,655,660,666,674,680,686,692,698,703,708,713,718,723,728,733,738,743,748,753,758,763,768,773,778,783,788,793,798,803,808,813,818,823,828,833,838,843,848,853,858,863,868,873,878,883,888,893,898,904,910,916,922,928,934,940,946,952,
    for (int i = 1; i <= 200; i++) {
        cout << i << ": " << getMoneyAmount(i) << endl;
    }

    return 0;
}
