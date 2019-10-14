# include <iostream>
# include <queue>
using namespace std;

int main(void)
{
    queue<string> qu;
    qu.push("aaa");
    qu.push("bbb");
    qu.push("ccc");
    cout<<qu.front()<<endl; // 第一个元素，结果是 aaa
    cout<<qu.back()<<endl; // 最后一个元素，结果是 ccc
    //-------------------------------------------
    cout<<qu.empty()<<endl; // 结果是 0
    cout<<qu.size()<<endl; // 结果是 3
    //-------------------------------------------
    qu.push("ddd");
    cout<<qu.back()<<endl; // 结果是 ddd
    qu.pop();
    cout<<qu.front()<<endl; // 结果是 bbb

    return 0;
}
