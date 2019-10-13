# include <iostream>
# include <map>
# include <string>
# include <algorithm>
using namespace std;

int main(void)
{
    string s, str[1005];
    int i=0;
    while(cin>>s){
        str[i++] = s;
        if(i==12) break;
    }
    sort(str, str+i);
    for(int j=0; j<i; j++){
        cout<<str[j]<<endl;
    }


    return 0;
}
