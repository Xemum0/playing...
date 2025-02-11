#include <iostream>  
#include<stdlib.h>
#include<cmath>
using namespace std;

int compar (const void *c,const void *d){
    int a=*((int*)c);
    int b=*((int*)d);
    return a-b;
}

int compare (int a,int b){
    if(abs(a)>abs(b))return -1;
    else return 1;
}
void bubble (int arr[],int size ){
  for (int i=0 ;i<size-1 ;i++){
      for (int j=0; j<size ;j++){

          if (compare(arr[j],arr[j+1])>0){
              swap(arr[j],arr[j+1]);
          }
      }
  }
}


 int main (){
int arr[6]={1,9,2,8,6,5};
//qsort(arr,4,sizeof(int),compar);
bubble(arr,6);
for (int i=0;i<6;i++)cout <<arr[i]<<" ";

     return 0;
 }