#include "../template/head.h"
#include <bits/stdc++.h>

class MyLinkedList {
  private:
    int length = 0;

    struct ListNode {
        int val;
        ListNode *next = nullptr;

        ListNode() : val(0) {}
        ListNode(int v) : val(v) {}
        ListNode(int v, ListNode *n) : val(v), next(n) {}
    };

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

  public:
    MyLinkedList() {
        head = new ListNode();
        tail = head;
    }
    void print() {
        cout << length << ": " << endl;
        for (ListNode *p = head; p->next; p = p->next) {
            cout << p->next->val << " ";
        }
    }

    int get(int index) {
        if (index >= length) {
            return -1;
        }

        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->next->val;
    }

    void addAtHead(int val) {
        ListNode *t = new ListNode(val, head->next);
        head->next = t;
        length++;
        if (tail == head) {
            tail = head->next;
        }
    }

    void addAtTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index > length) {
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }

        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }

        ListNode *t = new ListNode(val, p->next);
        p->next = t;
        length++;
    }

    void deleteAtIndex(int index) {
        if (index >= length) {
            return;
        }

        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }

        p->next = p->next->next;
        length--;

        if (index == length) {
            tail = p;
        }
    }
};

int main(int argc, char *argv[]) {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);       // 链表变为 1->2->3
    cout << myLinkedList.get(1) << endl; // 返回 2
    myLinkedList.deleteAtIndex(1);       // 现在，链表变为 1->3
    cout << myLinkedList.get(1) << endl; // 返回 3

    return 0;
}
