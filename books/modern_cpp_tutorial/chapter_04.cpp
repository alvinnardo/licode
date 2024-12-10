#include "chapter_04.h"

// 第 4 章：容器
int main(int argc, char *argv[]) {
    Paragraph("4.1 线性容器");
    Paragraph("4.1.1 array");
    // array 是固定大小的，vector 是自动扩充的
    // array 扩展了传统数组
    test_vector();

    Paragraph("4.1.2 forward_list");
    // 单向链表，比 list 更高的内存利用率
    // 是标准库中唯一一个不提供 size() 方法的容器

    Paragraph("4.2 无序容器");
    // C++11 引入两组无序容器，使用哈希表实现
    // std::unordered_map / std::unordered_multimap
    // std::unordered_set / std::unordered_multiset

    Paragraph("4.3 元组");
    Paragraph("4.3.1 元组基本操作");
    // 存放不同类型数据的容器 (通常会自己定义结构)
    // pair 只能保存两个元素
    // 引入 tuple 容器
    test_tuple();

    // C++14 引入使用类型获取元素
    test_tuple_type();

    Paragraph("4.3.2 运行期索引");
    // 在获取位置时，需要一个编译期常量
    // C++17 引入 variant 动态类型
    test_variant_index();

    return 0;
}
