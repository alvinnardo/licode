#include "head.h"
#include <bits/stdc++.h>

using namespace std;

// 树状数组(index tree)，用来快速计算范围和的问题
// 本节为一维模板
/** 前置知识:
    1. 树状数组用来保存数组信息, 并能快速求前缀和，
      如果存原数组，那么可以求前缀和，
      如果存差分数组，那么求的是原数组的某个值
      (即差分数组求前缀和是原始数组)
    2. 差分数组，是原始数组的差分，用来进行范围插入，
      比如，在 [3, 5] 插入 3，则差分数组为 [0, 0, 0, 3, 0, 0, -3]
      idx = 3 的位置 + 3, idx = 6 的位置 -3，表示从 a 开始, b + 1 结束,
      还原为原数组为 [0, 0, 0, 3, 3, 3, 0]
    3. 求某个数最左边的 1, 可以用 i & -i 的方法，
      -i 即 i 取反 + 1，+1 表示还原最左边的 1
    4. 为了计算方便，且在求范围时需要用到 index_tree[0] = 0 的哨兵，
      所以在计算时从 idx = 1 开始计算，注意求值时与原始数组的关系
    5. 使用树状数组，添加和查询的时间复杂度都为 O(logk), k 为数组长度
 */

// 单点插入，范围查询
// 示例：在 idx = 3 处添加值，求得 [1, 5] 和 [3, 5] 的前缀和
class singleInsert {
  private:
    vector<int> index_tree;
    int lowbit(int i) { return i & -i; }

  public:
    singleInsert(const vector<int> &nums) : index_tree(nums.size() + 1) {
        for (int i = 0; i < nums.size(); i++) {
            add(i, nums[i]);
        }
        cout << "init vector: ";
        printVector(index_tree);
    }

    void add(int pos, int val) {
        int n = pos + 1; // 映射
        while (n < index_tree.size()) {
            index_tree[n] += val;
            n += lowbit(n);
        }
    }

    int query(int pos) {
        int n = pos + 1;
        int sum = 0;
        while (n > 0) {
            sum += index_tree[n];
            n -= lowbit(n);
        }
        return sum;
    }

    int queryRange(int a, int b) { return query(b) - query(a - 1); }
};

// 范围插入，单点查询
// 在 [3, 5] 上添加 val, 查询 6 上最后的值
class rangeInsertSingleSearch {
  private:
    vector<int> index_tree;
    int lowbit(int i) { return i & -i; }

    void add(int pos, int val) {
        int n = pos;
        while (n < index_tree.size()) {
            index_tree[n] += val;
            n += lowbit(n);
        }
    }

  public:
    // +2 表示留出 0 的位置，以及最后多的一个位置，方便进行差分处理
    rangeInsertSingleSearch(const vector<int> &nums)
        : index_tree(nums.size() + 2) {
        for (int i = 0; i < nums.size(); i++) {
            addRange(i, i, nums[i]);
        }
        cout << "init vector: ";
        printVector(index_tree);
    }

    // 在这里做差分
    void addRange(int a, int b, int val) {
        int l = a + 1, r = b + 1;
        add(l, val);
        add(r + 1, -val);
    }

    int query(int pos) {
        int n = pos + 1;
        int sum = 0;
        while (n) {
            sum += index_tree[n];
            n -= lowbit(n);
        }

        return sum;
    }
};

// 范围插入，范围查询
// 在 [3, 5] 添加 val, 在 [4, 6] 查询和
/* clang-format off */
/**
  推导公式：
     A1 + A2 + A3 + ... + Ak
  = (D1) + (D1 + D2) + (D1 + D2 + D3) + ... + (D1 + D2 + D3 + ... + Dk)
  = k * D1 + (k - 1) * D2 + (k - 2) * D3 + (k - 3) * D4 + ... + (k - (k - 1)) * Dk
  = k * (D1 + D2 + ... + Dk) - (0 * D1 + 1 * D2 + ... + (k - 1) * Dk)
  = k * sum(Di) (1 <= i <= k) - sum((i - 1) * Di) (1 <= i <= k)

  根据上面的推导公式，可以得出使用两个树状数组，分别存放 Di 和 (i - 1) * Di 的差分数组，
  在做范围插入时，分别对两个数组进行处理，最后求和时使用上面的结果进行求和即可

 */
/* clang-format on */
class rangeInsertRangeSearch {
  private:
    vector<int> index_tree1, index_tree2;
    int lowbit(int i) { return i & -i; }

    void add(vector<int> &index_tree, int pos, int val) {
        int n = pos;
        while (n < index_tree.size()) {
            index_tree[n] += val;
            n += lowbit(n);
        }
    }

    int query(vector<int> index_tree, int pos) {
        int n = pos;
        int sum = 0;
        while (n) {
            sum += index_tree[n];
            n -= lowbit(n);
        }
        return sum;
    }

    // [1, n] 的前缀和
    int querySum(int n) {
        return n * query(index_tree1, n) - query(index_tree2, n);
    }

  public:
    rangeInsertRangeSearch(const vector<int> &nums)
        : index_tree1(nums.size() + 2), index_tree2(nums.size() + 2) {
        for (int i = 0; i < nums.size(); i++) {
            addRange(i, i, nums[i]);
        }

        cout << "init vector: " << endl;
        printVector(index_tree1);
        printVector(index_tree2);
    }

    // 在这里做差分
    void addRange(int a, int b, int val) {
        int l = a + 1, r = b + 1;
        add(index_tree1, l, val);
        add(index_tree1, r + 1, -val);
        add(index_tree2, l, (l - 1) * val);
        add(index_tree2, r + 1, r * (-val));
    }

    // 用两个前缀和求区间和
    int queryRange(int a, int b) {
        int l = a + 1, r = b + 1;
        return querySum(r) - querySum(l - 1);
    }
};

int main(void) {
    cout << "单点插入，范围查询" << endl;
    singleInsert si = singleInsert({0, 1, 2, 3, 4, 5});
    si.add(3, 10);
    for (int i = 0; i < 6; i++) {
        cout << si.query(i) << endl;
    }
    cout << si.queryRange(3, 5) << endl;

    cout << "范围插入，单点查询" << endl;
    rangeInsertSingleSearch riss = rangeInsertSingleSearch({0, 1, 2, 3, 4, 5});
    riss.addRange(3, 5, 4);
    for (int i = 0; i < 6; i++) {
        cout << riss.query(i) << endl;
    }

    cout << "范围插入，范围查询" << endl;
    rangeInsertRangeSearch rirs = rangeInsertRangeSearch({0, 1, 2, 3, 4, 5});
    rirs.addRange(3, 5, 4);
    cout << rirs.queryRange(3, 5) << endl;
    for (int i = 0; i < 6; i++) {
        cout << rirs.queryRange(i, i) << endl;
    }
}
