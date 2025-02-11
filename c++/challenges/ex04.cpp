// reverse the digits of a 32-bit signedinteger
#include<iostream>
using namespace std;

int64_t reversed (int num){
    bool negative;
    static int t=0,p=1;
    if (num<0) {
        num=~num+1;
        negative=true;
    }
    if (num)
    { 
        reversed(num/10);
        t=(num%10)*p+t;
        p*=10;
    }
    return negative ? -t :t;
}

int main (){

int num=123;
cout <<reversed(num)<<endl;

    return 0;
}