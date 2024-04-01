#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

struct listnode {
    int key;
    int val;
    listnode *pre = nullptr;
    listnode *next = nullptr;
    listnode(int k, int v) : key(k), val(v) {}
};

struct mylist {
    int m_size = 0;
    listnode *head = nullptr;
    listnode *tail = nullptr;

    void pop_front() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            // free(head);
            head = tail = nullptr;
        } else {
            head->next->pre = nullptr;
            listnode *t = head;
            head = head->next;
            // free(t);
        }
        m_size--;
    }

    void pop_back() {
        if (tail == nullptr) {
            return;
        }
        if (head == tail) {
            // free(tail);
            head = tail = nullptr;
        } else {
            tail->pre->next = nullptr;
            listnode *t = tail;
            tail = tail->pre;
            // free(t);
        }
        m_size--;
    }

    void push_back(int key, int value) {
        listnode *t = new listnode(key, value);

        if (head == nullptr) {
            head = t;
            tail = head;
        } else {
            tail->next = t;
            t->pre = tail;
            tail = t;
        }

        m_size++;
    }

    void remove_node(listnode *t) {
        if (t == head) {
            pop_front();
        } else if (t == tail) {
            pop_back();
        } else {
            t->pre->next = t->next;
            t->next->pre = t->pre;
            // free(t);
            m_size--;
        }
    }

    listnode *back() { return tail; }
    listnode *front() { return head; }
    int size() { return m_size; }
};

class LRUCache {
  public:
    // 双向链表和哈希表
    // 哈希表找键，时间复杂度 O(1)
    int m_capacity = 0;
    unordered_map<int, listnode *> umap;
    mylist ll;
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(int key) {
        if (umap.find(key) != umap.end()) {
            listnode *t = umap[key];
            int value = t->val;

            umap.erase(key);
            ll.remove_node(t);

            ll.push_back(key, value);
            umap[key] = ll.back();
            return ll.back()->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if (umap.find(key) != umap.end()) {
            listnode *t = umap[key];
            umap.erase(key);
            ll.remove_node(t);

            ll.push_back(key, value);
            umap[key] = ll.back();
        } else {
            ll.push_back(key, value);
            umap[key] = ll.back();

            if (ll.size() > m_capacity) {
                umap.erase(ll.head->key);
                ll.pop_front();
            }
        }
    }
};

int main(void) {
    LRUCache ca = LRUCache(2);
    ca.put(1, 1);
    ca.put(2, 2);
    cout << ca.get(1) << endl;
    ca.put(3, 3);
    cout << ca.get(2) << endl;
    ca.put(4, 4);
    cout << ca.get(1) << endl;
    cout << ca.get(3) << endl;
    cout << ca.get(4) << endl;

    return 0;
}
