#include "../template/head.h"
#include <bits/stdc++.h>
long long maximumSubsequenceCount(string text, string pattern) {
    // 题解：遍历 + 统计
    // 关键点：从前往后 和 从后往前生成的个数是相同的，只计算从前往后一次即可
    // 比如 aaabb，a 有 3 个，b 有 2 个，从前往后 3 * 2 = 从后往前 2 * 3
    // 时间 O(n)，空间 O(1)
    long long res = 0;
    int cnt1 = 0, cnt2 = 0;
    for (char c : text) {
        if (c == pattern[1]) {
            res += cnt1;
            cnt2++;
        }
        if (c == pattern[0]) {
            cnt1++;
        }
    }

    // 最后添加时，选择最多的一个即可
    return res + max(cnt1, cnt2);
}

long long maximumSubsequenceCount_my(string text, string pattern) {
    // 思路：模拟
    // pattern[0] 放在头，pattern[1] 放在尾肯定结果最大
    // 时间 O(n)，空间 O(1)
    long long head = 0, tail = 0; // 保存结果
    int len = text.size(), last = -1;
    int p0 = 0, p1 = 0; // 用于统计个数
    for (int i = 0; i < len; i++) {
        last = len - i - 1;

        // pattern 中的两个字符可能会相同
        // 所以在累加次数和全局的时候都需要进行判断
        // 先累加全局，再统计次数
        if (text[i] == pattern[1]) {
            head += p0;
        }
        if (text[i] == pattern[0]) {
            p0++;
        }

        if (text[last] == pattern[0]) {
            tail += p1;
        }
        if (text[last] == pattern[1]) {
            p1++;
        }
    }

    // 附加字母后的结果
    head += p0;
    tail += p1;
    return head > tail ? head : tail;
}

int main(int argc, char *argv[]) {
    // 6
    cout << maximumSubsequenceCount("aaa", "aa") << endl;
    // 4
    cout << maximumSubsequenceCount("abdcdbc", "ac") << endl;
    // 6
    cout << maximumSubsequenceCount("aabb", "ab") << endl;
    // 12
    cout << maximumSubsequenceCount("cccccccccccc", "ac") << endl;
    // 78
    cout << maximumSubsequenceCount("cccccccccccc", "cc") << endl;

    // 496
    cout
        << maximumSubsequenceCount(
               "vnedkpkkyxelxqptfwuzcjhqmwagvrglkeivowvbjdoyydnjrqrqejoyptzokla"
               "xcjxbrrfmpdxckfjzahparhpanwqfjrpbslsyiwbldnpjqishlsuagevjmiyktg"
               "ofvnyncizswldwnngnkifmaxbmospdeslxirofgqouaapfgltgqxdhurxljcepd"
               "pndqqgfwkfiqrwuwxfamciyweehktaegynfumwnhrgrhcluenpnoieqdivznrjl"
               "jcotysnlylyswvdlkgsvrotavnkifwmnvgagjykxgwaimavqsxuitknmbxppgzf"
               "wtjdvegapcplreokicxcsbdrsyfpustpxxssnouifkypwqrywprjlyddrggkcgl"
               "bgcrbihgpxxosmejchmzkydhquevpschkpyulqxgduqkqgwnsowxrmgqbmltrlt"
               "zqmmpjilpfxocflpkwithsjlljxdygfvstvwqsyxlkknmgpppupgjvfgmxnwmvr"
               "fuwcrsadomyddazlonjyjdeswwznkaeaasyvurpgyvjsiltiykwquesfjmuswjl"
               "rphsdthmuqkrhynmqnfqdlwnwesdmiiqvcpingbcgcsvqmsmskesrajqwmgtdok"
               "treqssutpudfykriqhblntfabspbeddpdkownehqszbmddizdgtqmobirwbopmo"
               "qzwydnpqnvkwadajbecmajilzkfwjnpfyamudpppuxhlcngkign",
               "rr")
        << endl;
    return 0;
}
