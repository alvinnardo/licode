#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

// 可以直接用哈希表存，不需要另加结构
class ThroneInheritance {
  public:
    unordered_map<string, vector<string>> inherit_umap;
    unordered_set<string> death_uset;
    string king;

    ThroneInheritance(string kingName) : king(std::move(kingName)) {}
    void birth(string parentName, string childName) {
        inherit_umap[parentName].emplace_back(childName);
    }

    void death(string name) { death_uset.insert(name); }

    // 前序遍历
    vector<string> getInheritanceOrder() {
        vector<string> res;
        stack<string> st;
        st.push(king);

        while (!st.empty()) {
            auto pa = st.top();
            st.pop();
            // not death
            if (death_uset.find(pa) == death_uset.end()) {
                res.emplace_back(pa);
            }
            for (int i = inherit_umap[pa].size() - 1; i >= 0; i--) {
                st.emplace(inherit_umap[pa][i]);
            }
        }

        return res;
    }
};

struct ThroneTreeNode {
    bool is_dead = false;
    string m_name;
    vector<ThroneTreeNode *> m_children;
    ThroneTreeNode(string name) : m_name(name){};

    void setDeath() { is_dead = true; }
    void push_child(ThroneTreeNode *child) { m_children.push_back(child); }
};

class ThroneInheritance_my {
  public:
    ThroneTreeNode *root;
    unordered_map<string, ThroneTreeNode *> name_tree;
    ThroneInheritance_my(string kingName) {
        root = new ThroneTreeNode(kingName);
        name_tree[kingName] = root;
    }

    void birth(string parentName, string childName) {
        ThroneTreeNode *pa = name_tree[parentName];
        ThroneTreeNode *t = new ThroneTreeNode(childName);
        pa->push_child(t);
        name_tree[childName] = t;
    }

    void death(string name) {
        ThroneTreeNode *t = name_tree[name];
        t->setDeath();
    }

    // 前序遍历
    vector<string> getInheritanceOrder() {

        vector<string> res;

        stack<ThroneTreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            ThroneTreeNode *t = st.top();
            if (!t->is_dead) {
                res.push_back(t->m_name);
            }

            st.pop();
            for (int i = t->m_children.size() - 1; i >= 0; i--) {
                st.push(t->m_children[i]);
            }
        }

        return res;
    }
};

int main(void) {
    // king
    ThroneInheritance t = ThroneInheritance("king");
    printVector(t.getInheritanceOrder());

    // king > andy
    t.birth("king", "andy");
    printVector(t.getInheritanceOrder());

    // king > andy > bob
    t.birth("king", "bob");
    printVector(t.getInheritanceOrder());

    // king > andy > bob > catherine
    t.birth("king", "catherine");
    printVector(t.getInheritanceOrder());

    // king > andy > matthew > bob > catherine
    t.birth("andy", "matthew");
    printVector(t.getInheritanceOrder());

    // king > andy > matthew > bob > alex > catherine
    t.birth("bob", "alex");
    printVector(t.getInheritanceOrder());

    // king > andy > matthew > bob > alex > asha > catherine
    t.birth("bob", "asha");
    printVector(t.getInheritanceOrder());

    // king > andy > matthew > bob（已经去世）> alex > asha > catherine
    t.death("bob");
    printVector(t.getInheritanceOrder());
    return 0;
}
