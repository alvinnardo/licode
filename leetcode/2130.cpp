#include "../template/head.h"
#include <bits/stdc++.h>

int pairSum(ListNode *head) {
    // 思路：两次遍历
    // 翻转链表
    // 时间 O(n)，空间 O(1)
    // 第一次遍历，获取个数
    // 第二次遍历，前半段翻转，后半段求和

    int cnt = 0;
    ListNode *p = head;
    // 这里可以用快慢指针优化
    while (p) {
        cnt++;
        p = p->next;
    }

    cnt >>= 1;
    p = head;
    ListNode *q = p->next, *tmp = nullptr;
    if (cnt == 1) { // 不用翻转
        return p->val + q->val;
    }

    // 翻转 n / 2 - 1 次
    for (int i = 0; i < cnt - 1; i++) {
        tmp = q->next;
        q->next = p;
        if (p == head) {
            head->next = nullptr;
        }

        p = q;
        q = tmp;
    }

    // 现在 p 和 q 都在中间，且都指向自己的一半链表
    int res = INT_MIN;
    while (p) {
        res = max(res, p->val + q->val);
        p = p->next;
        q = q->next;
    }

    return res;
}

int main(int argc, char *argv[]) {
    // 6
    cout << pairSum(buildList({5, 4, 2, 1})) << endl;
    // 7
    cout << pairSum(buildList({4, 2, 2, 3})) << endl;
    // 100001
    cout << pairSum(buildList({1, 100000})) << endl;

    return 0;
}
