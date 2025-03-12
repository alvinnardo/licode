#include "../template/head.h"
#include <bits/stdc++.h>

// 看了题解，觉得题解的思路挺好的
// 因为是恰好等于 k 个，不好滑动右边界
// 所以题解给出先求 >= k 个的所有字符串，那么中间成立外面一定成立
// 然后再求出 >= k + 1 个的所有字符串，使用相同的逻辑
// 前者 - 后者 = 恰好等于 k 个的所有字符串

long long countOfSubstrings(string word, int k) {
    // 思路：双指针 + 哈希表
    // 时间 O(n)，空间 O(1)

    // 双指针使用条件，中间成立则外面都成立
    // 这道题有两个限制条件，中间成立外面不一定成立
    // 成立后到下一个辅音之前是成立的
    // 所以需要一个能够快速找到下一个辅音字符的方法
    // 用数组存辅音字符位置，找当前成立位置下一个位置即可
    int len = word.length();
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> umap;
    int cnt = 0;      // 保存辅音字符的个数
    int next_fu = -1; // 下一个辅音字符位置
    int j = 0;
    long long res = 0;
    for (int i = 0; i < len; i++) {

        char c = word[i];
        if (uset.count(c)) {
            umap[c]++;
        } else {
            cnt++;
        }

        while (cnt >= k && umap.size() == uset.size()) {
            while (next_fu <= i) { // 找下一个辅音字符位置
                do {
                    next_fu++;
                } while (next_fu < len && uset.count(word[next_fu]));
            }

            // 如果成立，加上结果
            if (cnt == k) {
                res += next_fu - i;
            }

            // 移动左边
            c = word[j++];
            if (uset.count(c)) {
                if (--umap[c] == 0) {
                    umap.erase(c);
                }
            } else {
                cnt--;
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 0
    cout << countOfSubstrings("aeioqq", 1) << endl;
    // 1
    cout << countOfSubstrings("aeiou", 0) << endl;
    // 3
    cout << countOfSubstrings("ieaouqqieaouqq", 1) << endl;

    return 0;
}
