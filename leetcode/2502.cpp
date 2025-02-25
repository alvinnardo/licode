#include "../template/head.h"
#include <bits/stdc++.h>

struct MemSlot {
    int m_begin = 0;
    int m_len = 0;
    int m_note = 0;
    bool m_alloted = false;
    MemSlot(int begin, int len, int note, bool allocated = true)
        : m_begin(begin), m_len(len), m_note(note), m_alloted(allocated) {}
};

class Allocator {
  public:
    // 思路：模拟 + 链表法
    // 时间 O(km)，空间 O(m)，k 是调用次数，m 是链表中最多个数
    list<MemSlot> m_lst;
    // 保存标记和个数的关系
    unordered_map<int, int> m_note_map;

    Allocator(int n) { m_lst.emplace_back(0, n, -1, false); }

    int allocate(int size, int mID) {
        for (auto it = m_lst.begin(); it != m_lst.end(); it++) {
            if (!it->m_alloted) {
                if (it->m_len == size) { // 全分配，长度不变
                    it->m_note = mID;
                    it->m_alloted = true;
                    m_note_map[mID]++;
                    return it->m_begin;
                } else if (it->m_len > size) {
                    int begin_bak = it->m_begin;
                    it->m_begin += size;
                    it->m_len -= size; // 剩下的

                    // 重载当前的迭代器，所以插入已分配的
                    m_lst.insert(it, {begin_bak, size, mID});

                    m_note_map[mID]++;
                    return begin_bak;
                }
            }
        }

        return -1;
    }

    int freeMemory(int mID) {
        if (!m_note_map.count(mID)) {
            return 0;
        }

        int res = 0;
        for (auto it = m_lst.begin(); it != m_lst.end(); it++) {
            if (it->m_alloted && it->m_note == mID) {
                res += it->m_len;

                // free, meanwhile, free prev and next
                if (it != m_lst.begin()) {
                    auto pre = std::prev(it);
                    // 如果前面是空闲的
                    if (!pre->m_alloted) {
                        pre->m_len += it->m_len;
                        it = std::prev(m_lst.erase(it));
                    }
                }

                it->m_note = -1;
                it->m_alloted = false;

                auto nst = std::next(it);
                if (nst != m_lst.end() && !nst->m_alloted) {
                    it->m_len += nst->m_len;
                    m_lst.erase(nst);
                }

                // 都清空了
                if (--m_note_map[mID] == 0) {
                    break;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    Allocator loc(10);
    cout << loc.allocate(1, 1) << endl; // [1, , , , , , , , , ]。返回 0 。
    cout << loc.allocate(1, 2) << endl; // [1,2, , , , , , , , ]。返回 1 。
    cout << loc.allocate(1, 3) << endl; // [1,2,3, , , , , , , ]。返回 2 。
    cout << loc.freeMemory(2) << endl;  // [1, ,3, , , , , , , ] 。返回 1 。
    cout << loc.allocate(3, 4) << endl; // [1, ,3,4,4,4, , , , ]。返回 3 。
    cout << loc.allocate(1, 1) << endl; // [1,1,3,4,4,4, , , , ]。返回 1 。
    cout << loc.allocate(1, 1) << endl; // [1,1,3,4,4,4,1, , , ]。返回 6 。
    cout << loc.freeMemory(1) << endl; //  [ , ,3,4,4,4, , , , ] 。返回 3 。
    cout << loc.allocate(10, 2) << endl; // -1 。
    cout << loc.freeMemory(7) << endl;   // 返回 0 。

    return 0;
}
