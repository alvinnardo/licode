#include "../template/head.h"
#include <bits/stdc++.h>

double soupServings(int n) {
    // 思路：枚举法
    // 时间 O(1)，空间 O(k)
    // 最开始就是想用枚举法，但是暴力法太慢了，
    // 所以先用记忆化搜索写出来了，现在用枚举法优化一下

    // 从 4801 开始后面都是 1
    if (n > 4800) {
        return 1;
    }

    // 0 -> 24 -> 0 * 25
    // 1-25 -> 26-49 -> 1 * 25
    // 26-50 -> 51-74 -> 2 * 25
    // 51-75 -> 75-99 -> 3 * 25
    n = (n + 24) / 25 * 25;

    unordered_map<int, double> umap{
        {0, 0.5},         {25, 0.625},      {50, 0.625},      {75, 0.65625},
        {100, 0.71875},   {125, 0.742188},  {150, 0.757812},  {175, 0.785156},
        {200, 0.796875},  {225, 0.817871},  {250, 0.827637},  {275, 0.844849},
        {300, 0.852173},  {325, 0.866699},  {350, 0.872559},  {375, 0.884827},
        {400, 0.889633},  {425, 0.900076},  {450, 0.904058},  {475, 0.913005},
        {500, 0.916344},  {525, 0.924045},  {550, 0.92687},   {575, 0.933526},
        {600, 0.93593},   {625, 0.941703},  {650, 0.943762},  {675, 0.948783},
        {700, 0.950555},  {725, 0.954934},  {750, 0.956464},  {775, 0.960291},
        {800, 0.961618},  {825, 0.964968},  {850, 0.966121},  {875, 0.969061},
        {900, 0.970066},  {925, 0.972648},  {950, 0.973525},  {975, 0.975797},
        {1000, 0.976565}, {1025, 0.978566}, {1050, 0.979239}, {1075, 0.981004},
        {1100, 0.981595}, {1125, 0.983153}, {1150, 0.983673}, {1175, 0.985049},
        {1200, 0.985506}, {1225, 0.986724}, {1250, 0.987127}, {1275, 0.988204},
        {1300, 0.98856},  {1325, 0.989515}, {1350, 0.989829}, {1375, 0.990675},
        {1400, 0.990953}, {1425, 0.991703}, {1450, 0.991949}, {1475, 0.992614},
        {1500, 0.992832}, {1525, 0.993423}, {1550, 0.993616}, {1575, 0.994141},
        {1600, 0.994312}, {1625, 0.994779}, {1650, 0.99493},  {1675, 0.995346},
        {1700, 0.99548},  {1725, 0.99585},  {1750, 0.995969}, {1775, 0.996298},
        {1800, 0.996404}, {1825, 0.996697}, {1850, 0.996791}, {1875, 0.997052},
        {1900, 0.997136}, {1925, 0.997368}, {1950, 0.997443}, {1975, 0.99765},
        {2000, 0.997716}, {2025, 0.997901}, {2050, 0.99796},  {2075, 0.998125},
        {2100, 0.998177}, {2125, 0.998324}, {2150, 0.998371}, {2175, 0.998502},
        {2200, 0.998544}, {2225, 0.998661}, {2250, 0.998699}, {2275, 0.998803},
        {2300, 0.998836}, {2325, 0.99893},  {2350, 0.998959}, {2375, 0.999043},
        {2400, 0.999069}, {2425, 0.999144}, {2450, 0.999167}, {2475, 0.999234},
        {2500, 0.999255}, {2525, 0.999314}, {2550, 0.999333}, {2575, 0.999386},
        {2600, 0.999403}, {2625, 0.999451}, {2650, 0.999466}, {2675, 0.999508},
        {2700, 0.999522}, {2725, 0.99956},  {2750, 0.999572}, {2775, 0.999606},
        {2800, 0.999616}, {2825, 0.999647}, {2850, 0.999656}, {2875, 0.999684},
        {2900, 0.999692}, {2925, 0.999717}, {2950, 0.999724}, {2975, 0.999746},
        {3000, 0.999753}, {3025, 0.999772}, {3050, 0.999779}, {3075, 0.999796},
        {3100, 0.999802}, {3125, 0.999817}, {3150, 0.999822}, {3175, 0.999836},
        {3200, 0.999841}, {3225, 0.999853}, {3250, 0.999857}, {3275, 0.999868},
        {3300, 0.999872}, {3325, 0.999882}, {3350, 0.999885}, {3375, 0.999894},
        {3400, 0.999897}, {3425, 0.999905}, {3450, 0.999908}, {3475, 0.999915},
        {3500, 0.999917}, {3525, 0.999924}, {3550, 0.999926}, {3575, 0.999932},
        {3600, 0.999933}, {3625, 0.999939}, {3650, 0.99994},  {3675, 0.999945},
        {3700, 0.999946}, {3725, 0.999951}, {3750, 0.999952}, {3775, 0.999956},
        {3800, 0.999957}, {3825, 0.99996},  {3850, 0.999961}, {3875, 0.999964},
        {3900, 0.999965}, {3925, 0.999968}, {3950, 0.999969}, {3975, 0.999971},
        {4000, 0.999972}, {4025, 0.999974}, {4050, 0.999975}, {4075, 0.999977},
        {4100, 0.999977}, {4125, 0.999979}, {4150, 0.99998},  {4175, 0.999981},
        {4200, 0.999982}, {4225, 0.999983}, {4250, 0.999984}, {4275, 0.999985},
        {4300, 0.999985}, {4325, 0.999986}, {4350, 0.999987}, {4375, 0.999988},
        {4400, 0.999988}, {4425, 0.999989}, {4450, 0.999989}, {4475, 0.99999},
        {4500, 0.99999},  {4525, 0.999991}, {4550, 0.999991}, {4575, 0.999992},
        {4600, 0.999992}, {4625, 0.999993}, {4650, 0.999993}, {4675, 0.999994},
        {4700, 0.999994}, {4725, 0.999994}, {4750, 0.999994}, {4775, 0.999995},
        {4800, 0.999995}};

    return umap[n];
}

double soupServings1(int n) {
    // 思路：记忆化搜索
    // 时间 O(min(4800*4800, n2))，空间 O(min(4800*4800, n2))

    // 从 4801 开始后面都是 1
    if (n > 4800) {
        return 1;
    }

    // 0 -> 24 -> 0 * 25
    // 1-25 -> 26-49 -> 1 * 25
    // 26-50 -> 51-74 -> 2 * 25
    // 51-75 -> 75-99 -> 3 * 25
    n = (n + 24) / 25 * 25;

    vector<vector<double>> vv(n + 1, vector<double>(n + 1));
    vector<pair<int, int>> vec{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    function<double(int, int)> dfs = [&](int a, int b) -> double {
        if (vv[a][b]) {
            return vv[a][b];
        }
        if (a == 0 && b == 0) {
            return 0.5;
        } else if (a == 0) {
            return 1;
        } else if (b == 0) {
            return 0;
        }

        double res = 0;
        for (int i = 0; i < 4; i++) {
            int new_a = max(0, a - vec[i].first);
            int new_b = max(0, b - vec[i].second);
            res += 0.25 * dfs(new_a, new_b);
        }

        vv[a][b] = res;
        return res;
    };

    return dfs(n, n);
}

vector<pair<int, int>> vv;

int main(int argc, char *argv[]) {

    // 0.62500
    cout << soupServings(50) << endl;
    // 0.71875
    cout << soupServings(100) << endl;
    vector<double> res;
    for (int i = 0; i <= 4800; i += 25) {
        cout << "{" << i << ", " << soupServings(i) << "}," << endl;
    }

    return 0;
}
