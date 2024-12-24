#include "in.h"

void test_regex() {
    string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    // C++ 将 \ 认为字符串的转义符，所以需要将其转义
    std::regex txt_regex("[a-z]+\\.txt");

    for (const auto &fname : fnames) {
        cout << fname << ": " << regex_match(fname, txt_regex) << endl;
    }

    // regex_match 可以一次匹配，获取正则中匹配的过程字符串
    std::regex txt_regex2("([a-z]+)\\.txt");
    // 定义为 std::match_results<std::string::const_iterator>，即匹配结果迭代器
    std::smatch base_match;
    for (const auto &fname : fnames) {
        if (std::regex_match(fname, base_match, txt_regex2)) {
            if (base_match.size() == 2) {
                // 0 匹配所有，1 匹配第一个括号表达式
                cout << "sub-match[0]: " << base_match[0].str() << endl;
                cout << "sub-match[1]: " << base_match[1].str() << endl;
            }
        }
    }
}
