#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：哈希表 + 红黑树
// 方便修改评分，所以需要哈希表
// 评分需要排序，考虑每次 sort 或 红黑树，红黑树方便插入和查找
// 时间 O(nlogn)，空间 O(n)
class FoodRatings {
  public:
    // <名称，<类型，评分>>
    unordered_map<string, pair<string, int>> foods_map;
    // <类型，<评分, <名称>>>
    // 用于排序，用评分来进行插入、删除
    unordered_map<string, map<int, set<string>>> types_map;
    // 时间 O(nlogn)
    FoodRatings(vector<string> foods, vector<string> cuisines,
                vector<int> ratings) {

        int sz = foods.size();
        for (int i = 0; i < sz; i++) {
            foods_map[foods[i]] = {cuisines[i], ratings[i]};
            types_map[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }

    // 时间 O(logn)
    void changeRating(string food, int newRating) {
        // <类型，评分>
        auto &it = foods_map[food];
        // 删除旧评分
        types_map[it.first][it.second].erase(food);
        if (types_map[it.first][it.second].empty()) {
            types_map[it.first].erase(it.second);
        }

        foods_map[food].second = newRating;
        types_map[it.first][newRating].insert(food);
    }

    // 时间 O(1)
    string highestRated(string cuisine) {
        if (!types_map.count(cuisine)) {
            return "";
        }
        // 类型 最大分数 字典序最小
        return *types_map[cuisine].rbegin()->second.begin();
    }
};

int main(int argc, char *argv[]) {
    FoodRatings foodRatings(
        {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"},
        {"korean", "japanese", "japanese", "greek", "japanese", "korean"},
        {9, 12, 8, 15, 14, 7});
    cout << foodRatings.highestRated("korean") << endl;   // "kimchi"
    cout << foodRatings.highestRated("japanese") << endl; // "ramen"
    foodRatings.changeRating("sushi", 16);
    cout << foodRatings.highestRated("japanese") << endl; // "sushi"
    foodRatings.changeRating("ramen", 16);
    cout << foodRatings.highestRated("japanese") << endl; //  "ramen"

    return 0;
}
