# include <iostream>
# include <stdlib.h>
# include <math.h>
using namespace std;

int fibonacci(int a){
    if(a<3){
        return 1; // n=1»òn=2Ê±
    }
    return fibonacci(a-1) + fibonacci(a-2); // n>2Ê±
}

int64_t fibonacci_dp(int a){
    int n = 10000;
    int64_t f[n];
    f[1] = 1;
    f[2] = 1;
    for(int i=3; i<=a; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[a];
}

int64_t fibonacci_dp_simplify(int a){
    int64_t m = 1, n = 1, r = 1;
    for(int i=3; i<=a; i++){
        r = m + n;
        m = n;
        n = r;
    }
    return r;
}

double fibonacci_math(int a){ // 返回值类型为double
    return (pow((1+sqrt(5))/2, a) - pow((1-sqrt(5))/2, a))/sqrt(5);
}

int main(void)
{
    //cout<<fibonacci(5);
    for(int i=1; i<100; i++){
        cout<<i<<" "<<fibonacci_math(i)<<endl;
    }



    return 0;
}
