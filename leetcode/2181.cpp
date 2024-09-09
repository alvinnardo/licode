#include "../template/head.h"
#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeNodes(ListNode *head) {
        // 思路：模拟
        // 时间 O(n)，空间 O(1)
        ListNode *p = head;
        int cur = 0;
        while (p->next) {
            if (p->next->val == 0) {
                p->next->val = cur;
                p = p->next;
                cur = 0;
            } else {
                cur += p->next->val;
                p->next = p->next->next;
            }
        }

        return head->next;
    }
};

ListNode *makeList(vector<int> vec) {
    if (vec.empty()) {
        return nullptr;
    }

    ListNode *head = nullptr, *tail = nullptr;

    for (int i : vec) {
        if (!head) {
            head = new ListNode(i);
            tail = head;
        } else {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
    }

    return head;
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    shared_ptr<Solution> solution_ptr = make_shared<Solution>();
    // {4, 11}
    ListNode *head = makeList({0, 3, 1, 0, 4, 5, 2, 0});
    printList(solution_ptr->mergeNodes(head));
    // {1, 3, 4}
    head = makeList({0, 1, 0, 3, 0, 2, 2, 0});
    printList(solution_ptr->mergeNodes(head));

    return 0;
}
