#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 时间 O(n)，空间 O(1)，结果不算空间
class OrderedStream {
  public:
    vector<string> vec;
    int pos = 1;
    OrderedStream(int n) : vec(n + 1) {}

    vector<string> insert(int idKey, string value) {
        vec[idKey] = value;
        if (pos != idKey) {
            return {};
        }

        int cur = pos, cur2 = pos;
        while (cur < vec.size() && !vec[cur].empty()) {
            cur++;
        }
        pos = cur;
        return vector<string>(vec.begin() + cur2, vec.begin() + cur);
    }
};

int main(int argc, char *argv[]) {
    OrderedStream os(5);
    printVector(os.insert(3, "ccccc")); // []
    printVector(os.insert(1, "aaaaa")); // ["aaaaa"]
    printVector(os.insert(2, "bbbbb")); // ["bbbbb", "ccccc"]
    printVector(os.insert(5, "eeeee")); // []
    printVector(os.insert(4, "ddddd")); // ["ddddd", "eeeee"]

    return 0;
}
