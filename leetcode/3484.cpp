#include "../template/head.h"
#include <bits/stdc++.h>

// 思路：模拟
// 时间 O(k)，空间 O(26n)，k 是调用次数，n 是行数
class Spreadsheet {
  public:
    vector<vector<int>> vv;
    Spreadsheet(int rows) { vv.assign(rows, vector<int>(26)); }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        vv[row][col] = value;
    }

    void resetCell(string cell) { setCell(cell, 0); }

    // 正则超时了
    /*
    int getValue(string formula) {
        std::regex re("=([A-Z]?\\d+)\\+([A-Z]?\\d+)"); // 加号要转义
        std::smatch m;
        std::regex_match(formula, m, re);
        string a = m[1].str(), b = m[2].str(); // 0 是整个的，子串从 1 开始

        auto get = [&](const auto &str) {
            if (str[0] >= 'A' && str[0] <= 'Z') {
                int col = str[0] - 'A';
                int row = stoi(str.substr(1)) - 1;
                return vv[row][col];
            }
            return stoi(str);
        };

        return get(a) + get(b);
    }
    */

    int getValue(string formula) {
        string a, b;
        bool plus_flag = false;
        auto get = [&](const auto &str) {
            if (str[0] >= 'A' && str[0] <= 'Z') {
                int col = str[0] - 'A';
                int row = stoi(str.substr(1)) - 1;
                return vv[row][col];
            }
            return stoi(str);
        };

        for (char c : formula) {
            if (c == '=') {
                continue;
            } else if (c == '+') {
                plus_flag = true;
            } else if (plus_flag) {
                b += c;
            } else {
                a += c;
            }
        }

        return get(a) + get(b);
    }
};

int main(int argc, char *argv[]) {
    Spreadsheet spreadsheet(3);
    // 12
    cout << spreadsheet.getValue("=5+7") << endl;
    spreadsheet.setCell("A1", 10);
    // 16
    cout << spreadsheet.getValue("=A1+6") << endl;
    spreadsheet.setCell("B2", 15);
    // 25
    cout << spreadsheet.getValue("=A1+B2") << endl;
    spreadsheet.resetCell("A1");
    // 15
    cout << spreadsheet.getValue("=A1+B2") << endl;

    return 0;
}
