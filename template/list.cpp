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
