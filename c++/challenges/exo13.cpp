//addition without + and -
#include <iostream>
using namespace std;
int addition(int a,int b){
  while (b!=0){
    int temp=(a&b)<<1;
    a=a^b;
    b=temp;
  }return a;
}
int main (){
cout <<addition(100,90)<<endl;
}