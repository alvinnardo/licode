#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

string maximumBinaryString(string binary) {
    // 提示：贪心，保证每一次操作最多只有一个 0
    // 找规律：诸如 01110 => 10111 (两个 0 之间夹杂多个 1)

    cout << binary << " ";
    int l = -1;
    int len = binary.length();
    for (int i = 0; i < len; i++) {
        if (binary[i] == '0') {
            if (l == -1) {
                l = i;
            } else {
                binary[i] = '1';
                binary[l] = '1';
                binary[l + 1] = '0';
                l++; // l 的下一位肯定是 0
            }
        }
    }

    return binary;
}

int main(void) {
    cout << maximumBinaryString("0") << endl;
    cout << maximumBinaryString("1") << endl;
    cout << maximumBinaryString("00") << endl;
    cout << maximumBinaryString("01") << endl;
    cout << maximumBinaryString("10") << endl;
    cout << maximumBinaryString("11") << endl;
    cout << maximumBinaryString("000") << endl;
    cout << maximumBinaryString("001") << endl;
    cout << maximumBinaryString("010") << endl;
    cout << maximumBinaryString("011") << endl;
    cout << maximumBinaryString("100") << endl;
    cout << maximumBinaryString("101") << endl;
    cout << maximumBinaryString("110") << endl;
    cout << maximumBinaryString("111") << endl;
    cout << maximumBinaryString("0000") << endl;
    cout << maximumBinaryString("0001") << endl;
    cout << maximumBinaryString("0010") << endl;
    cout << maximumBinaryString("0011") << endl;
    cout << maximumBinaryString("0100") << endl;
    cout << maximumBinaryString("0101") << endl;
    cout << maximumBinaryString("0110") << endl;
    cout << maximumBinaryString("0111") << endl;
    cout << maximumBinaryString("1000") << endl;
    cout << maximumBinaryString("1001") << endl;
    cout << maximumBinaryString("1010") << endl;
    cout << maximumBinaryString("1011") << endl;
    cout << maximumBinaryString("1100") << endl;
    cout << maximumBinaryString("1101") << endl;
    cout << maximumBinaryString("1110") << endl;
    cout << maximumBinaryString("1111") << endl;
    cout << maximumBinaryString("00000") << endl;
    cout << maximumBinaryString("00001") << endl;
    cout << maximumBinaryString("00010") << endl;
    cout << maximumBinaryString("00011") << endl;
    cout << maximumBinaryString("00100") << endl;
    cout << maximumBinaryString("00101") << endl;
    cout << maximumBinaryString("00110") << endl;
    cout << maximumBinaryString("00111") << endl;
    cout << maximumBinaryString("01000") << endl;
    cout << maximumBinaryString("01001") << endl;
    cout << maximumBinaryString("01010") << endl;
    cout << maximumBinaryString("01011") << endl;
    cout << maximumBinaryString("01100") << endl;
    cout << maximumBinaryString("01101") << endl;
    cout << maximumBinaryString("01110") << endl;
    cout << maximumBinaryString("01111") << endl;
    cout << maximumBinaryString("10000") << endl;
    cout << maximumBinaryString("10001") << endl;
    cout << maximumBinaryString("10010") << endl;
    cout << maximumBinaryString("10011") << endl;
    cout << maximumBinaryString("10100") << endl;
    cout << maximumBinaryString("10101") << endl;
    cout << maximumBinaryString("10110") << endl;
    cout << maximumBinaryString("10111") << endl;
    cout << maximumBinaryString("11000") << endl;
    cout << maximumBinaryString("11001") << endl;
    cout << maximumBinaryString("11010") << endl;
    cout << maximumBinaryString("11011") << endl;
    cout << maximumBinaryString("11100") << endl;
    cout << maximumBinaryString("11101") << endl;
    cout << maximumBinaryString("11110") << endl;
    cout << maximumBinaryString("11111") << endl;
    cout << maximumBinaryString("10001000") << endl;

    return 0;
}
