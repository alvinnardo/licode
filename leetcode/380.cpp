#include "../template/head.h"
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
class RandomizedSet {
  private:
    vector<int> vec;
    unordered_map<int, int> umap;

  public:
    // 用变长数组存数字，用哈希表存位置
    RandomizedSet() { srand(time(NULL)); }

    bool insert(int val) {
        if (umap.find(val) != umap.end()) {
            return false;
        }

        vec.push_back(val);
        umap[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (umap.find(val) == umap.end()) {
            return false;
        }

        // 将最后一个元素放到删除数字的位置
        auto pos = umap[val];
        auto last = vec.back();
        vec[pos] = last;
        umap[last] = pos;
        umap.erase(val);

        // 删除最后一个元素
        vec.pop_back();
        return true;
    }

    int getRandom() { return vec[rand() % vec.size()]; }
};

class RandomizedSet_my {
  private:
    int mod = 997;
    vector<list<int>> vec;
    int getMod(int n) {
        int64_t newn = n;
        newn += INT_MAX;
        newn++;
        return newn % mod;
    }
    int hasVal(int n, int val) {
        for (auto t : vec[n]) {
            if (t == val) {
                return true;
            }
        }
        return false;
    }
    list<int> flags;
    int getMs() {
        using std::chrono::duration_cast;
        using std::chrono::nanoseconds;
        // 用纳秒做时间种子
        auto nanoseconds_since_epoch =
            duration_cast<nanoseconds>(
                std::chrono::system_clock::now().time_since_epoch())
                .count();
        // cout << nanoseconds_since_epoch << endl;
        return nanoseconds_since_epoch % 1000;
    }

    int randomVal(int a, int b) {
        std::default_random_engine e;
        e.seed(getMs());
        return (e() % (b - a + 1)) + a;
    }

  public:
    RandomizedSet_my() : vec(mod) {}

    bool insert(int val) {
        int hval = getMod(val);
        if (hasVal(hval, val)) {
            return false;
        }

        if (vec[hval].empty()) {
            flags.push_back(hval);
        }

        vec[hval].push_front(val);
        return true;
    }

    bool remove(int val) {
        int hval = getMod(val);

        if (!hasVal(hval, val)) {
            return false;
        }

        for (auto it = vec[hval].begin(); it != vec[hval].end(); it++) {
            if (*it == val) {
                vec[hval].erase(it);
                break;
            }
        }
        if (vec[hval].empty()) {
            for (auto it = flags.begin(); it != flags.end(); it++) {
                if (*it == hval) {
                    flags.erase(it);
                    break;
                }
            }
        }
        return true;
    }

    int getRandom() {
        int flags_random_val = randomVal(0, flags.size() - 1);
        auto it = flags.begin();
        advance(it, flags_random_val);
        int hval = *it;

        int num_random_val = randomVal(0, vec[hval].size() - 1);
        it = vec[hval].begin();
        advance(it, num_random_val);

        return *it;
    }
};

int main(void) {
    RandomizedSet *rset = new RandomizedSet();
    // printBool(rset->insert(-1));       // true
    // printBool(rset->remove(-2));       // false
    // printBool(rset->insert(-2));       // true
    // cout << rset->getRandom() << endl; // -1 || -2
    // printBool(rset->remove(-1));       // true
    // printBool(rset->insert(-2));       // false
    // cout << rset->getRandom() << endl; // -2
    printBool(rset->insert(1));        // true
    printBool(rset->insert(10));       // true
    printBool(rset->insert(20));       // true
    printBool(rset->insert(30));       // true
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
    cout << rset->getRandom() << endl; // -2
}
