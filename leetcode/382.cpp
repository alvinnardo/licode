#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2 {
  public:
    // 水塘抽样，时间换空间
    ListNode *m_head;
    Solution2(ListNode *head) : m_head(head) { srand(time(NULL)); }

    int getRandom() {
        // 每次都要遍历整个数组，最后得到每个数返回的概率是 1/n
        ListNode *p = m_head;
        int res = m_head->val;
        int i = 1;
        while (p) {
            // 第一次肯定能够保证拿到 head 的值, rand() % 1 = 0
            // 返回第 i 次结果的概率 =
            // 第 i 次选中的概率 * 其余次选不中的概率 = 1/n
            if (rand() % i == 0) {
                res = p->val;
            }
            i++;
            p = p->next;
        }
        return res;
    }
};

class Solution {
  public:
    vector<ListNode *> vec;
    Solution(ListNode *head) {
        ListNode *p = head;
        while (p) {
            vec.push_back(p);
            p = p->next;
        }

        srand(time(NULL));
    }

    int getRandom() { return vec[rand() % vec.size()]->val; }
};

int main(void) {
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    Solution solution = Solution(p);
    cout << solution.getRandom() << endl;
    cout << solution.getRandom() << endl;
    cout << solution.getRandom() << endl;
    cout << solution.getRandom() << endl;
    cout << solution.getRandom() << endl;

    return 0;
}
