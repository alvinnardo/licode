# include <iostream>
# include <vector>
using namespace std;

int main(void){

    vector<int> v, v2;

    /*
    operator=
    */
    v = {1, 2, 3, 4, 5}; // 赋值

    /*
    assign原型:
    */

    cout<< v.at(0) <<endl; // 访问指定的元素，结果是 2
    cout<< v.at(5); // 进行越界检查，结果是 out_of_range



    return 0;
}
