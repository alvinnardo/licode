# include <iostream>
# include <stack>
using namespace std;

int main(void)
{
    stack<string> st;
    st.push("aaa");
    st.push("bbb");
    st.push("ccc");
    cout<<st.top()<<endl; // 结果是 ccc
    //---------------------------------
    cout<<st.empty()<<endl; // 结果是 0
    cout<<st.size()<<endl; // 结果是 3
    st.push("ddd");
    cout<<st.top()<<endl; // 结果是 ddd
    st.pop();
    cout<<st.top()<<endl; // 结果是 ccc

    return 0;
}
