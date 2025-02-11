#include<iostream>
using namespace std;

//....................................

int **get_2d_array(int r, int c) {
      int **res = new int *[r];
       
      for(int i=0; i<r; i++)
      res[i] = new int[c];
       return res;
}

//....................................

template <typename T>
T most_common(T *A, int size) {
T winner=A[0];
int freq=0;
int i,j, tmp; 
    for(i=0;i<size;i++){
    for(tmp=j=0;j<size;j++)
        if(A[i]==A[j]) tmp++; 
    if(tmp>freq){
        freq = tmp;
        winner = A[i];
}
}
return winner; 
}
//....................................

int main (){
/*
int a[5] = { 1,2,3,4,5} ;
int *p = a+2;
int *q = new int[3];
 int i;
for(i=0;i<3;i++) 
*q++ = *p++;
cout << "Loop 1" << endl; 
while(p!=a){
p--;
cout << p[0] << endl;
 }
cout << "Loop 2" << endl; 
for(i=1;i<=3;i++)
cout << q[-i] << endl;
delete [ ] (q-3);
 q=a+1;
cout << "Loop 3" << endl; 
for(i=0;i<4;i++)
cout << q[i] << endl;

cout <<endl;

*/
 int **p=get_2d_array(2,4);

     for (int i=0;i<8;i++)
{
    cin>>*(*p+i);
}
     for (int i=0;i<8;i++)
{
    cout <<*(*p+i)<<" ";
}
delete []p;

    return 0;
}