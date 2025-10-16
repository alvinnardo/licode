#include "../template/head.h"
#include <bits/stdc++.h>

// 跳表
// 多级链表，最底层是最完整的链表，上层是对下层的抽样
// 时间：查找、添加、删除平均时间复杂度 O(logn)
// 空间: O(n)

// 跳表和红黑树的效率差不多
// 但胜在实现简单且支持顺序遍历
// 红黑树的顺序遍历复杂度太高

// 记法：长节点
const static int LEVEL = 32; // 合理的层数即可
static double thred = 0.25;
struct Node {
    int m_val{};
    std::vector<std::shared_ptr<Node>> next_vec;
    Node(int val) : m_val(val), next_vec(LEVEL) {}
};

class Skiplist {

    std::shared_ptr<Node> m_lst;
    vector<shared_ptr<Node>> vec;
    std::uniform_real_distribution<double> dist;
    std::mt19937 gen{std::random_device{}()};

  public:
    Skiplist() : vec(LEVEL), dist(0, 1) {
        m_lst = std::make_shared<Node>(INT_MIN);
    }

    // 不管是查询、添加、还是删除都需要找到节点的前一个点
    void find(int t) {
        // 从顶到底
        // 因为有哨兵，所以 vec[i] 肯定不是 nullptr
        std::shared_ptr<Node> cur = m_lst;
        for (int i = LEVEL - 1; i >= 0; i--) {
            while (cur->next_vec[i] && cur->next_vec[i]->m_val < t) {
                cur = cur->next_vec[i];
            }
            vec[i] = cur;
        }
    }

    bool check() { return dist(gen) > thred; }

    bool search(int target) {
        find(target);
        return vec[0]->next_vec[0] && vec[0]->next_vec[0]->m_val == target;
    }

    void add(int num) {
        find(num);
        std::shared_ptr<Node> ptr = std::make_shared<Node>(num);
        for (int i = 0; i < LEVEL; i++) {
            if (i == 0 || check()) {
                ptr->next_vec[i] = vec[i]->next_vec[i];
                vec[i]->next_vec[i] = ptr;
            } else {
                break;
            }
        }
    }

    bool erase(int num) {
        if (!search(num)) {
            return false;
        }

        for (int i = 0; i < LEVEL; i++) {
            if (vec[i]->next_vec[i] && vec[i]->next_vec[i]->m_val == num) {
                vec[i]->next_vec[i] = vec[i]->next_vec[i]->next_vec[i];
            } else {
                break;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Skiplist skiplist;
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);
    cout << skiplist.search(0) << endl; //  false
    skiplist.add(4);
    cout << skiplist.search(1) << endl; //  true
    cout << skiplist.erase(0) << endl;  //  false
    cout << skiplist.erase(1) << endl;  //  true
    cout << skiplist.search(1) << endl; //  false

    return 0;
}
