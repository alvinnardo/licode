#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class Iterator {
    struct Data;
    Data *data;

  public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// 也可以先一步保存下一个值
class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        // 用当前的对象创建一个临时变量，用完即销毁
        PeekingIterator iter = PeekingIterator(*this);
        return iter.next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() { return Iterator::next(); }

    bool hasNext() const { return Iterator::hasNext(); }
};
