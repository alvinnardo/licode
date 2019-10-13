# include <iostream>
# include <vector>
using namespace std;

int main(void){

    vector<int> v, v2;

    /*
    operator=
    */
    v = {1, 2, 3, 4, 5}; // 赋值
//---------------------------------
    /*
    assign()函数原型:
    1:void assign(const_iterator first, const_iterator last);
    将first到last之间的值赋值给调用者
    2:void assign(size_type n, const T& x = T());
    把n个x赋值给调用者
    */
    v2.assign(v.begin(), v.begin()+3);
    for(int n : v2){
        cout<<n<<' ';
    }
    cout<<endl; // 结果是 1 2 3

    v2.assign(5, 8);
    for(int n : v2){
        cout<<n<<' ';
    }
    cout<<endl; // 结果是 8 8 8 8 8

//---------------------------------
    cout<< v.at(0) <<endl; // 访问指定的元素，结果是 2
    //cout<< v.at(5) <<endl; // 进行越界检查，结果是 out_of_range
    cout<< v.front() <<endl; // 访问第一个元素，结果是 1
    cout<< v.back() <<endl; // 访问最后一个元素，结果是 5
    cout<< v.data() <<endl; // 访问指向内存中数组第一个元素的指针

    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int>::iterator iter; // 正向迭代器
    vector<int>::reverse_iterator riter; // 逆向迭代器
    for(iter=v3.begin(); iter!=v3.end(); ++iter){
        cout<<*iter<<' ';
    } // 结果是 1 2 3 4 5
    cout<<endl;
    riter = v3.rbegin();
    for(riter=v3.rbegin(); riter!=v3.rend(); ++riter){
        cout<<*riter<<' ';
    } // 结果是 5 4 3 2 1
    cout<<endl;

//---------------------------------
    vector<int> v4 = {2, 4, 6, 8, 10};
    cout<<v4.empty()<<endl; // 结果是 0，非空
    cout<<v4.size()<<endl; // 结果是 5
    cout<<v4.max_size()<<endl; // 结果是 1073741823，取决于计算机
    v4.reserve(8); // 预留8个存储空间
    cout<<v4.size()<<endl; // 结果是 5，大小不变
    cout<<v4.capacity()<<endl; // 结果是 8，预留空间改变
    for(iter=v4.begin(); iter!=v4.end(); ++iter){
        cout<<*iter<<' ';
    } // 结果是 2 4 6 8 10
    cout<<endl;

//---------------------------------
    /*
        insert()函数原型：
        void insert( iterator pos, size_type count, const T& value );
    */
    vector<int> v5 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    v5.insert(v5.begin()+2, 3, 5); // 在pos处插入count个value, count可以省略代表一个
    for(int n:v5) { cout<<n<<' '; } cout<<endl; // 结果是 1 2 5 5 5 2 3 3 3 4 4 4 4

    /*
        erase()函数原型：
        1.iterator erase( iterator pos );
        擦除pos上的元素
        2.iterator erase( iterator first, iterator last );
        擦除[first, last)范围的元素
    */
    v5.erase(v5.begin()+3); // 移除第4个位置上的元素
    for(int n:v5) { cout<<n<<' '; } cout<<endl; // 结果是 1 2 5 5 2 3 3 3 4 4 4 4
    v5.erase(v5.begin()+3, v5.begin()+5); // 移除[4, 6]位置上的元素
    for(int n:v5) { cout<<n<<' '; } cout<<endl; // 结果是 1 2 5 3 3 3 4 4 4 4

    v5.push_back(6); // 添加到容器末尾
    for(int n:v5) { cout<<n<<' '; } cout<<endl; // 结果是 1 2 5 3 3 3 4 4 4 4 6
    v5.pop_back(); // 移除末尾元素
    for(int n:v5) { cout<<n<<' '; } cout<<endl; // 结果是 1 2 5 3 3 3 4 4 4 4


    return 0;
}
