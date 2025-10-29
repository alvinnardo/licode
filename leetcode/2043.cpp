#include "../template/head.h"
#include <bits/stdc++.h>

class Bank {
  public:
    // 思路: 模拟
    // 时间 O(k)， 空间 O(n)
    vector<long long> m_balance;
    Bank(vector<long long> &balance) : m_balance(balance) {}

    bool isValid(int account) {
        return account >= 1 && account <= m_balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) {
            return false;
        }

        if (!withdraw(account1, money)) {
            return false;
        }

        deposit(account2, money);
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account)) {
            return false;
        }

        m_balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account)) {
            return false;
        }

        if (money > m_balance[account - 1]) {
            return false;
        }

        m_balance[account - 1] -= money;
        return true;
    }
};

int main(int argc, char *argv[]) {
    vector<long long> vec = {10, 100, 20, 50, 30};

    Bank bank(vec);

    cout << bank.withdraw(3, 10) << endl;    // true
    cout << bank.transfer(5, 1, 20) << endl; // true
    cout << bank.deposit(5, 20) << endl;     // true
    cout << bank.transfer(3, 4, 15) << endl; // false
    cout << bank.withdraw(10, 50) << endl;   // false

    return 0;
}
