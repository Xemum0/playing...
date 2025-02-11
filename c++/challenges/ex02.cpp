//median of two sorted_arr
#include <iostream>
#include<iomanip>
using namespace std;

void selctionsort(int arr[],int size1){
    for (int i=0;i<size1;i++){
        for (int j=i+1;j<size1;j++){
            if (arr[i]>=arr[j])swap (arr[i],arr[j]);
        }
    }
}

float find_median_sorted_arrays(int arr1[],int size1,int arr2[],int size2,bool sorted){

  if (!sorted){
    selctionsort(arr1,size1);
    selctionsort(arr2,size2);
  }
      float median;
      int tmp= (size1+size2)/2;
      if (((size1+size2)& 1)==1){//check if its odd
           if (tmp>=size1) median=(float)arr2[tmp-size1];
           else median =(float)arr1[tmp];
      }else {
        median=(float)(arr1[tmp-1]+arr2[tmp-size1])/2;
      }
      return median;
}
int main (){
    int num1[] = {1, 2, 5, 6, 7 };
    int num2[] = {14, 19, 35, 45, 50};
   int s1 = sizeof(num1)/sizeof(num1[0]);
    int s2 = sizeof(num2)/sizeof(num2[0]);
    float temp=find_median_sorted_arrays(num1, s1, num2, s2,true);
    cout<<"Median of the above two sorted arrays is: "<< setprecision(5)<<fixed<<temp<<"\n";  

    return 0;
}


