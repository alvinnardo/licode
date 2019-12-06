# include <iostream>
using namespace std;

int main(void)
{
    int a[100] = {6, -12, 8, -4}, sum=a[0];
    for(int i=0; i<4 ;i++)
    {
        sum = a[i];
        for(int j=i+1; j<4; j++)
        {
            if(sum+a[j]>sum) sum = sum+a[j];
            else break;
            cout<<a[j]<<endl;
        }

        //cout<<a[i]<<endl;
    }


    return 0;
}
