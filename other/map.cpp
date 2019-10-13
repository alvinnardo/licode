# include <iostream>
# include <map>
# include <list>
using namespace std;

int main(void)
{
    map<string, int> m;
    m = {{"aaa", 1}, {"bbb", 2}, {"ccc", 3}}; // 赋值
    // 时间复杂度通常为O(nlogn)，如果已排序则为O(n)

    cout<<m["aaa"]<<endl;  // 结果是 1
    m["aaa"] = 4; // 更新值
    m["ddd"] = 5; // 插入值

    for(auto &pair : m) // 输出结果
    {
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
    //----------------------------------------
    // 不重复计数器
    list<string> word = {"hello", "world", "c", "hello", "c++",
                        "world", "hello", "hello"}; // 单词列表
    map<string, size_t> word_map;
    for(auto &n : word){ // 统计
        ++word_map[n];
    }

    for(auto &pair : word_map){ // 输出统计结果
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

    //----------------------------------------

    map<string, int> m2 = m;
    map<string, int>::iterator iter; // 正向迭代器
    map<string, int>::reverse_iterator riter; // 逆向迭代器

    for(iter=m2.begin(); iter!=m2.end(); iter++){
        cout<<iter->first<<" : "<<iter->second<<endl;
    } // 正向迭代器输出结果, 这里iter是指针变量

    for(riter=m2.rbegin(); riter!=m2.rend(); riter++){
        cout<<riter->first<<" : "<<riter->second<<endl;
    } // 逆向迭代器输出结果, 这里riter是指针变量

    //-----------------------------------------
    cout<<m2.empty()<<endl; // 结果是 0
    cout<<m2.size()<<endl;  // 结果是4
    cout<<m2.max_size()<<endl; // 可容纳的最大元素数，不同计算机结果可能不同

    //-----------------------------------------
    m2["ddd"] = 5; // 直接增加
    m2["aaa"] = 10; // 直接更新
    for(auto &pair : m2){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

    m2.erase("ddd"); // 擦除"ddd"
    for(auto &pair : m2){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }

    //------------------------------------------
    cout<<m2.count("aaa")<<endl; // 因为容器不允许键重复，所以结果为1或0

    map<string, int>::iterator sear;
    sear = m2.find("aaa");

    if(sear != m2.end()){
        cout<< "Found. "<< sear->first<<" : "<< sear->second<<endl;
    }else{
        cout<<"Not found."<<endl;
    }


    return 0;
}
