#include "../template/head.h"
#include <bits/stdc++.h>

string validIPAddress(string queryIP) {
    // 思路：要把所有可能都考虑到才行
    // 时间 O(n), 空间 O(1)
    int dot_cnt = 0, colon_cnt = 0, digit_cnt = 0, alpha_cnt = 0;
    int len = queryIP.length();
    for (auto c : queryIP) { // 先单字符检查
        if (c == '.') {
            dot_cnt++;
        } else if (c == ':') {
            colon_cnt++;
        } else if (c >= '0' && c <= '9') {
            digit_cnt++;
        } else if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F') {
            alpha_cnt++;
        } else {
            return "Neither";
        }
    }

    // 互斥检查
    if (dot_cnt > 0 && colon_cnt > 0) {
        return "Neither";
    } else if (dot_cnt > 0) { // IPv4 检查
        if (dot_cnt != 3 || alpha_cnt > 0) {
            return "Neither";
        }
        // 检查数字是否合法
        string tmp;
        for (int i = 0; i <= len; i++) {
            if (i == len || queryIP[i] == '.') {
                if (tmp.empty() || tmp.length() > 3 ||
                    (tmp.length() > 1 && tmp[0] == '0') ||
                    atoi(tmp.c_str()) > 255) {
                    return "Neither";
                }

                tmp = "";
            } else {
                tmp += queryIP[i];
            }
        }
        return "IPv4";
    } else { // IPv6 检查
        if (colon_cnt != 7) {
            return "Neither";
        }

        string tmp;
        for (int i = 0; i <= len; i++) {
            if (i == len || queryIP[i] == ':') {
                if (tmp.empty() || tmp.length() > 4) {
                    return "Neither";
                }

                tmp = "";
            } else {
                tmp += queryIP[i];
            }
        }
        return "IPv6";
    }

    return "Neither";
}

int main(int argc, char *argv[]) {
    // "IPv4"
    cout << validIPAddress("172.16.254.1") << endl;
    // "IPv6"
    cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
    // "Neither"
    cout << validIPAddress("256.256.256.256") << endl;

    return 0;
}
