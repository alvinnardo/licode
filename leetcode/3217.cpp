#include "../template/head.h"
#include <bits/stdc++.h>

ListNode *modifiedList(vector<int> &&nums, ListNode *head) {
    // 思路：哈希表
    // 时间 O(m + n)，空间 O(m)
    int maxv = *max_element(nums.begin(), nums.end());
    vector<int> vec(maxv + 1);

    for (int i = 0; i < nums.size(); i++) {
        vec[nums[i]]++;
    }

    // 先把头节点保证了，题目给出至少一个有效节点
    while (head->val <= maxv && vec[head->val]) {
        head = head->next;
    }

    ListNode *p = head;
    while (p->next) {
        if (p->next->val <= maxv && vec[p->next->val]) {
            p->next = p->next->next;
        } else {
            p = p->next;
        }
    }

    return head;
}

int main(int argc, char *argv[]) {
    // {4,5}
    printList(modifiedList({1, 2, 3}, buildList({1, 2, 3, 4, 5})));
    // {2,2,2}
    printList(modifiedList({1}, buildList({1, 2, 1, 2, 1, 2})));

    return 0;
}
