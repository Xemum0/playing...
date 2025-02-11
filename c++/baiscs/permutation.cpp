#include <iostream>
#include <string>
using namespace std;
bool check(string s){
   
   for (int i=0; i < (s.length()-1); i++ ){
    if((s[i]=='1' && s[i+1]=='2')||(s[i]=='2' && s[i+1]=='1'))return true;
   }

}
void generate_permutations(string str, int left, int right) {
    if (left == right) {
        if (check(str)){
            static int po=1;
        cout <<po++<<" "<< str << endl;

        }
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            generate_permutations(str, left + 1, right);
            swap(str[left], str[i]);
        }
    }
}
//.....................................................
int mtr [2][10]={0};
//.....................................................
void checker(int arr[10],int start,int end){
  static  int p =0;
    if (p<10)
    mtr[0][p]=start;
    
    int l=0;
    for (int i=start;i<end;i++ ){
        if (arr[i]>arr[i+1]){
            break;
        }else
            l++;
    }
    mtr[1][p]=l;
    p++;
}
//......................................


int main() {
//   int pos=0;
//     int arr[10]={4,5,0,0,3,4,5,2,7,8};
//     for(int i=0;i<10;i++){
//     checker(arr, i , 10);
//     }
//     int max=mtr[1][0];
    
//    for (int i=1;i<10;i++){
//         if (mtr[1][i]>max){
//             pos=i;
//             max=mtr[1][i];
//         }
//     }

//     for (int i=mtr[0][pos];i<=mtr[0][pos]+mtr[1][pos];i++){
//         cout <<arr[i]<<" ";
        
//     }
//     cout <<endl;
     generate_permutations("12345",0,4);
    


    
    return 0;
}



 
