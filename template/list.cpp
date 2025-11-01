#include "list.h"

ListNode *buildList(const vector<int> &vv) {
    ListNode *head = nullptr, *cur = nullptr;
    for (int v : vv) {
        if (!head) {
            head = new ListNode(v);
            cur = head;
        } else {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
    }

    return head;
}

void printList(ListNode *head) {
    int cnt{};
    for (ListNode *p = head; p != nullptr; p = p->next, cnt++) {
        if (cnt > 0) {
            cout << "->";
        }
        cout << p->val;
    }
    cout << endl;
}
