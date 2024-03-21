#include "../template/head.h"
#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker {

  public:
    // 两个结构：存放每个数的频次，查询频次的哈希表
    static const int sz = 1e5 + 1;
    vector<int> freqs;
    vector<int> freqs_num;
    FrequencyTracker() : freqs(sz), freqs_num(sz) {}

    void add(int number) {
        int f = freqs[number];
        if (hasFrequency(f)) {
            --freqs_num[f];
        }
        ++freqs[number];
        ++freqs_num[++f];
    }

    void deleteOne(int number) {
        int f = freqs[number];
        if (f == 0) {
            return;
        }
        --freqs_num[f];
        --freqs[number];
        ++freqs_num[--f];
    }

    bool hasFrequency(int frequency) { return freqs_num[frequency] != 0; }
};

int main(void) {

    std::shared_ptr<FrequencyTracker> fre_ptr = make_shared<FrequencyTracker>();
    fre_ptr->add(3);
    fre_ptr->add(3);
    fre_ptr->deleteOne(4);
    printBool(fre_ptr->hasFrequency(1));

    return 0;
}
