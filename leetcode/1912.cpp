#include "../template/head.h"
#include <bits/stdc++.h>

/**
  分析：
  1. search 需要按照 movie 查找，首先想到用哈希表存放
  2. rent 和 drop 要快速插入和删除，movie 哈希表可以快速查找，
     shop 也需要快速查找，可以再准备一个哈希表
  3. 还要解决排序的问题，要么随时 sort，要么用自动排序的容器，
     比如红黑树和优先队列
     同时考虑到插入和删除，所以先定红黑树，价格和商店排序，把这两个拼起来
  4. 对于借出的电影存放，可以和上面一样的结构
     但是对于排序，需要整体电影排序，考虑排序顺序，按照价格、商店、电影拼起来
*/
// 思路：哈希表 + 红黑树
// 时间 O(klogn)，空间 O(k)
class MovieRentingSystem {
  public:
    // <电影，<商店，价格>>
    unordered_map<int, unordered_map<int, int>> m_movie_umap;
    // <电影，<价格商店>>
    unordered_map<int, set<long long>> m_movie_sort;
    unordered_map<int, unordered_map<int, int>> m_rented_umap;
    // 根据各值的范围，拼接后是 3e15，没有超过 LLONG_MAX
    // <价格商店电影>
    set<long long> m_rented_sort;

    const int e5 = 1e5;
    const int e6 = 1e6;
    MovieRentingSystem(int n, vector<vector<int>> &entries) {
        // 时间 O(logn)
        // 顺序是 0商店，1电影，2价格
        long long t{};
        for (auto &entry : entries) {
            m_movie_umap[entry[1]][entry[0]] = entry[2];
            t = (long long)entry[2] * 1e6 + entry[0];
            m_movie_sort[entry[1]].insert(t);
        }
    }

    vector<int> search(int movie) {
        if (m_movie_umap[movie].empty()) {
            return {};
        }

        auto &info = m_movie_sort[movie];
        // vector<long long> vec;
        vector<int> res;
        auto it = info.begin();

        for (int i = 0; i < 5; i++) {
            res.push_back((*it) % e6);
            if (++it == info.end()) {
                break;
            }
        }

        return res;
    }

    void rent(int shop, int movie) {
        int price = m_movie_umap[movie][shop];
        long long t = (long long)price * 1e6 + shop;

        // 从 movies 哈希表中删除
        m_movie_umap[movie].erase(shop);
        m_movie_sort[movie].erase(t);

        // 添加到 rented 哈希表中
        t = t * 1e5 + movie;
        m_rented_umap[movie][shop] = price;
        m_rented_sort.insert(t);
    }

    void drop(int shop, int movie) {
        int price = m_rented_umap[movie][shop];
        long long t = (long long)price * e6 + shop;
        t = t * e5 + movie;

        // 从 rented 哈希表中删除
        m_rented_umap[movie].erase(shop);
        m_rented_sort.erase(t);

        // 添加到 movies 哈希表中
        t = t / e5;
        m_movie_umap[movie][shop] = price;
        m_movie_sort[movie].insert(t);
    }

    vector<vector<int>> report() {
        if (m_rented_sort.empty()) {
            return {};
        }

        vector<vector<int>> res;
        auto it = m_rented_sort.begin();
        int price{}, shop{}, movie{};
        for (int i = 0; i < 5; i++) {
            long long t = *it;

            // 只需要 shop 和 movie
            movie = t % e5;
            t /= e5;
            shop = t % e6;

            res.push_back({shop, movie});

            if (++it == m_rented_sort.end()) {
                break;
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> vec{{0, 1, 5}, {0, 2, 6}, {0, 3, 7},
                            {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
    MovieRentingSystem movieRentingSystem(3, vec);

    cout << movieRentingSystem.search(1) << endl; // {1, 0, 2}
    movieRentingSystem.rent(0, 1);
    movieRentingSystem.rent(1, 2);
    cout << movieRentingSystem.report() << endl; // {{0, 1}, {1, 2}}
    movieRentingSystem.drop(1, 2);
    cout << movieRentingSystem.search(2) << endl; // {0, 1}

    return 0;
}
