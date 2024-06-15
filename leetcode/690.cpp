#include "../template/head.h"
#include <bits/stdc++.h>
class Employee {
  public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee> employees, int id) {
    // 思路：哈希表 + BFS
    // 时间: O(nm)，n 是 employees 数组大小，m 是领导为 id 的下属个数
    // 空间: O(n)
    unordered_map<int, Employee> umap;

    int pos = 0;
    for (int i = 0; i < employees.size(); i++) {
        umap[employees[i].id] = employees[i];
        if (employees[i].id == id) {
            pos = i;
        }
    }

    int sum = 0;
    queue<int> qu;
    qu.emplace(employees[pos].id);

    while (!qu.empty()) {
        int t = qu.front();
        sum += umap[t].importance;
        qu.pop();

        for (int i : umap[t].subordinates) {
            qu.emplace(i);
        }
    }

    return sum;
}

int main(int argc, char *argv[]) {
    // 11
    cout << getImportance({{1, 5, {2, 3}}, {2, 3, {}}, {3, 3, {}}}, 1) << endl;
    // 13
    cout << getImportance({{1, 5, {2, 3}}, {2, 3, {4}}, {3, 3, {}}, {4, 2, {}}},
                          1)
         << endl;
    // -3
    cout << getImportance({{1, 2, {5}}, {5, -3, {}}}, 5) << endl;
    // 1
    cout << getImportance({{1, 2, {5}},
                           {5, -3, {2, 4}},
                           {2, 1, {}},
                           {4, 2, {6}},
                           {6, 1, {}}},
                          5)
         << endl;

    return 0;
}
