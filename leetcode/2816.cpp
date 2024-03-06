#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next = nullptr;
    ListNode(int x) { val = x; }
    ListNode(int x, ListNode *next) {
        val = x;
        next = next;
    }
};

// 链表翻倍
ListNode *doubleIt(ListNode *head) {
    vector<int> carry;
    for (ListNode *p = head; p; p = p->next) {
        p->val <<= 1;
        if (p->val >= 10) {
            p->val %= 10;
            carry.push_back(1);
        } else {
            carry.push_back(0);
        }
    }

    auto t = 1;
    for (ListNode *p = head; p; p = p->next, t++) {
        p->val += carry[t];
    }

    if (carry[0] == 1) {
        ListNode *p = new ListNode(1, head);
        head = p;
    }

    printVector(carry);

    return head;
}

int main(void) { return 0; }
