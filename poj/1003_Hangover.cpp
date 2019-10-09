# include<iostream>
using namespace std;

double digit(int n)
{
    return 1.0/n;
}

int main(void)
{
    double test, sum=0;
    cin>>test;
    while(test!=0.00){
        for(int i=2; i<100000; i++)
        {
            sum = sum+digit(i);
            if(sum>=test){
                cout<<i-1<<" card(s)"<<endl;
                break;
            }
        }
        //cout<<sum<<endl;
        sum=0;
        cin>>test;
    }
    return 0;
}
