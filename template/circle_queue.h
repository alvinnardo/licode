#pragma once
#include <bits/stdc++.h>

using namespace std;

template <class T> class CircleQueue {
private:
  using TPtr = shared_ptr<T>;
  vector<T> vv;
  int front = 0;
  int rear = 0;
  int sz = 10;
  std::mutex m_mutex;
  std::condition_variable m_cv;

  bool m_finished = false;

public:
  CircleQueue() { vv.resize(sz); }
  ~CircleQueue() = default;
  bool isEmpty() { return front == rear; }
  bool isFull() { return (rear + 1) % sz == front; }
  bool isFinished() { return m_finished; }
  void setFinished() {
    m_finished = true;
    m_cv.notify_all();
  }

  TPtr pop() {
    std::unique_lock<std::mutex> lock(m_mutex);
    TPtr t = nullptr;
    // 在这里也要判断是否结束，否则空时会一直等待
    while (!(isFinished() && isEmpty())) {

      if (!isEmpty()) {
        t = make_shared<T>(vv[front]);
        front = (front + 1) % sz;
        m_cv.notify_all();
        return t;
      }

      auto now = std::chrono::system_clock::now();
      m_cv.wait_until(lock, now + 100ms);
    }

    return t;
  }

  void push(T &t) {
    std::unique_lock<std::mutex> lock(m_mutex);

    while (isFull()) {
      auto now = std::chrono::system_clock::now();
      m_cv.wait_until(lock, now + 100ms);
    }

    vv[rear] = t;
    rear = (rear + 1) % sz;
    m_cv.notify_all();
  }
};
