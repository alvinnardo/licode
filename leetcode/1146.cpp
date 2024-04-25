#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
  private:
    // 思路：用列表表示位置，内部列表表示快照
    // 使用二分查找小于等于当前快照的值
    int snap_id = 0;
    vector<vector<pair<int, int>>> vec;

  public:
    SnapshotArray(int length)
        : vec(length, vector<pair<int, int>>(1, {snap_id, 0})) {}

    void set(int index, int val) {
        auto &t = vec[index].back();
        if (snap_id == t.first) {
            t.second = val;
        } else {
            vec[index].emplace_back(snap_id, val);
        }
    }

    int snap() { return snap_id++; }

    int get(int index, int snap_id) {
        auto &t = vec[index];

        int l = 0, r = t.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (t[mid].first < snap_id) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (l < t.size() && t[l].first == snap_id) {
            return t[l].second;
        }
        return t[r].second;
    }
};

int main(void) {
    SnapshotArray snapshotArr(3);
    snapshotArr.set(0, 5);
    cout << snapshotArr.snap() << endl;
    snapshotArr.set(0, 6);
    cout << snapshotArr.get(0, 0) << endl; // 5

    return 0;
}
