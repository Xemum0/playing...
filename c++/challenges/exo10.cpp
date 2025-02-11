//remove all instances of a given value from a given array
// of integers and return the length of the updated array
#include <iostream>
using namespace std;


void remove (int arr[],int value,int &length){
    int j=0;
    for (int i=0;i<length;i++){
        if (arr[i]!=value){
            arr[j]=arr[i];
            j++;
        }
    }
    length =j;
}

int main (){
    int nums[] = {1,1,2,3,4,4,5,6,4,6};    
    int length =sizeof (nums)/sizeof(nums[0]);
    remove(nums,4,length);
    cout <<"the length of the new array : "<<length<<endl;


    return 0;
}
