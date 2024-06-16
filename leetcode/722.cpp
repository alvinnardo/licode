#include "../template/head.h"
#include <bits/stdc++.h>

vector<string> removeComments(vector<string> source) {
    // 思路：模拟
    // 时间 O(l)，空间 O(l)
    bool lq = false;
    vector<string> res;
    string tmp;
    for (int l = 0; l < source.size(); l++) {
        string &s = source[l];
        for (int i = 0; i < s.length(); i++) {
            if (!lq && s[i] == '/') {
                if (i + 1 < s.length()) {
                    if (s[i + 1] == '/') {
                        break;
                    } else if (s[i + 1] == '*') {
                        i++;
                        lq = true;
                    }
                }
            } else if (lq && s[i] == '*') {
                if (i + 1 < s.length()) {
                    if (s[i + 1] == '/') {
                        i++;
                        lq = false;
                        continue;
                    }
                }
            }
            if (!lq && i < s.length()) {
                tmp += s[i];
            }
        }
        if (!lq && !tmp.empty()) {
            res.push_back(tmp);
            tmp = "";
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    printVector(removeComments({"e/*/eabeea/*///*c*////*dc*//bcadcde/*/acbe//"
                                "*d/*/*//ae//*dc//*cc//*//*eaebb*//"}),
                "\n");
    printVector(
        removeComments({"/*Test program */", "int main()", "{ ",
                        "  // variable declaration ", "int a, b, c;",
                        "/* This is a test", "   multiline  ",
                        "   comment for ", "   testing */", "a = b + c;", "}"}),
        "\n");
    printVector(
        removeComments({"a/*comment", "line", "more_comment*/b; c = 4; /*",
                        "aaa///////a*/ bbbb // cccc"}),
        "\n");

    return 0;
}
