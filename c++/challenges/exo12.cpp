//program to divide two given integers without
//using the multiplication, division and mod operator
#include <iostream>
#include <limits>
using namespace std;
//................................................................
int division(int dividend ,int divisor){
     int count =0;
     while (dividend>=divisor){
        dividend-=divisor;
        count ++;
     }
return count ;
}
//................................................................
int division_withbitwise(int div,int diviso){
    bool sign=(div>0)^(diviso>0);
int a=abs(div);
int b=abs(diviso);
int result=0;
    while (a-b>=0){
        int count=0;
        while (a-(b<<1<<count)>=0){
        count++;
    }
           result+=1<<count;
            a-=b<<count;
}
return sign ? -result:result;
}
 //................................................................

int main (){
     int dev=division_withbitwise(15,3);
     cout <<dev<<endl;

    return 0;
}