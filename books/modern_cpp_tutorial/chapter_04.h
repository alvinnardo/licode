#include "in.h"

// 4.1
void test_vector() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    vec.push_back(4);
    vec.push_back(5);
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    vec.shrink_to_fit();
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    // 内存不会主动释放
    vec.clear();
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    vec.shrink_to_fit();
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
}

// c 函数，使用 array 时需要进行兼容
void foo(int *p, int len) { return; }

void test_array() {
    array<int, 3> arr{1, 2, 3};
    // foo(arr, arr.size()); // 无法进行隐式转换
    foo(&arr[0], arr.size());
    foo(arr.data(), arr.size());
}

// 4.3
auto get_student(int id) {
    // 创建元组
    if (id == 0) {
        // 如果是 double，第一个不能写整数，类型推导会报错
        return make_tuple(78.0, 'B', "张三");
    }
    return make_tuple(90.5, 'A', "李四");
}

void test_tuple() {
    auto student = get_student(0);
    // 获取元素
    cout << std::get<0>(student) << endl;
    cout << std::get<1>(student) << endl;
    cout << std::get<2>(student) << endl;

    // 元组解包
    double grade;
    char level;
    std::string name;
    std::tie(grade, level, name) = student;
    cout << grade << endl;
    cout << level << endl;
    cout << name << endl;
}

void test_tuple_type() {
    std::tuple<int, double, double, string> t(10, 1.1, 2.2, "aaa");
    cout << get<string>(t) << endl;
    // cout << get<double>(t) << endl; // 编译时报错
}

// 4.3.2
void test_variant_index() {
    // TODO
}
