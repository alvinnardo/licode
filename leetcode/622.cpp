#include "../template/head.h"
#include <bits/stdc++.h>

class MyCircularQueue {
  public:
    vector<int> vec;
    int front = 0;
    int rear = 0;
    int sz;
    MyCircularQueue(int k) : vec(k + 1), sz(k + 1) {}

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        vec[rear] = value;
        rear = (rear + 1) % sz;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % sz;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return vec[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return vec[(sz + rear - 1) % sz];
    }

    bool isEmpty() { return front == rear; }

    bool isFull() { return (rear + 1) % sz == front; }
};

int main(int argc, char *argv[]) {

    MyCircularQueue circularQueue(3);         // 设置长度为 3
    cout << circularQueue.enQueue(1) << endl; // 返回 true
    cout << circularQueue.enQueue(2) << endl; // 返回 true
    cout << circularQueue.enQueue(3) << endl; // 返回 true
    cout << circularQueue.enQueue(4) << endl; // 返回 false，队列已满
    cout << circularQueue.Rear() << endl;     // 返回 3
    cout << circularQueue.isFull() << endl;   // 返回 true
    cout << circularQueue.deQueue() << endl;  // 返回 true
    cout << circularQueue.enQueue(4) << endl; // 返回 true
    cout << circularQueue.Rear() << endl;     // 返回 4

    return 0;
}
