#include <bits/stdc++.h>
using namespace std;

// 有环的链表，找环的入口
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    // 第一次相遇
    // 快指针走了 f = 2s(步数是二倍)
    // f = s + nd(比慢指针多走了 n 倍的环长)
    // 那么可以得出 s = nd
    do {
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    // 环的入口是长度是 a + nd
    // 且已得出慢指针走了 nd，则再走 a 就能到达环的入口
    // 那么令快指针指向头部，跟慢指针一起走，第二次相遇就是环的入口了
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
