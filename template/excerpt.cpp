#include <bits/stdc++.h>

// from std::rotate
template <class ForwardIt>
constexpr // since C++20
    ForwardIt
    rotate(ForwardIt first, ForwardIt middle, ForwardIt last) {
    if (first == middle)
        return last;

    if (middle == last)
        return first;

    ForwardIt write = first;
    ForwardIt next_read = first; // read position for when “read” hits “last”

    for (ForwardIt read = middle; read != last; ++write, ++read) {
        // 当 first 将要被移动时，记录 first 要去的位置
        // 以保证 next_read 一直指向 first 的位置
        if (write == next_read)
            next_read = read; // track where “first” went
        std::iter_swap(write, read);
    }

    // rotate the remaining sequence into place
    rotate(write, next_read, last);
    return write;
}
