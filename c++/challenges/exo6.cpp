//sum of three nums in array equal to zero
#include <iostream>
#include <stdlib.h>
using namespace std;

void triples (int arr[],int size){
   cout <<"triplets of the said array whose sum equal to zero : ";
       for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            for (int k=j+1;k<size;k++){
                 
                 if (arr[i]+arr[j]+arr[k]==0){
                    cout <<"["<<arr[i]<<"] ,"<<"["<<arr[j]<<"] ,"<<"["<<arr[k]<<"]"<<"  ";
                 }
}}}
cout <<endl;
}
int compar (const void *c,const void *d){
    int a=*((int*)c);
    int b=*((int*)d);
    return a-b;
}
class solution {
public:
    bool findtriple(int arr[], int size) {
        qsort(arr,size,sizeof(int),compar) ;// Sort the input array in ascending order
        for (int i = 0; i < size - 2; i++) {
            int j = i + 1;
            int k = size - 1;
            while (k > j) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0) {
                    return true; // Found a triplet whose sum is zero
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return false; // No triplet whose sum is zero found
    }
    bool findquadriple (int tergetsum,int arr[],int size){
        qsort(arr,size,sizeof(int),compar) ;
        for (int i = 0; i < size - 3; i++) {
             for (int j = i+1; j < size -2; j++) {
                int sum=tergetsum-(arr[i]+arr[j]);
            int start = j + 1;
            int end = size - 1;
            while (end > start) {
                int t = arr[start] + arr[end] ;
                if (sum == t) {

                    return true;
                }
                else if (t < sum) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
    }
    return false;
    }
};

int main (){
            int arr[]={-2,1,3,0,};
            int size =sizeof(arr)/sizeof (arr[0]);
            solution t;
            
           cout <<boolalpha<< t.findquadriple(0,arr,size)<<endl;
    return 0;
}

