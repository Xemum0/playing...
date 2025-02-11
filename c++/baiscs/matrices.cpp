#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    return 0;
}

/*
 #include<iostream>
 using namespace std;
 #define MAX 10
 void multiplyMatrix(int [MAX][MAX],int [MAX][MAX]);
 int rone,cone,rtwo,ctwo;
 int crm[MAX][MAX];
 int sum,i=0,j=0,k=0;
 int main()
 {
     int arm[MAX][MAX],brm[MAX][MAX],i,j,k;
     
        cout<<"\n\n Multiplication of two Matrices :\n";
        cout<<"----------------------------------\n";
     cout <<" Input number of rows for the first matrix : ";
     cin>>rone;
     cout <<" Input number of columns for the first matrix : ";
     cin>>cone;
     
     cout <<" Input number of rows for the second matrix : ";
     cin>>rtwo;
     cout <<" Input number of columns for the second matrix : ";
     cin>>ctwo;
     if(cone!=rtwo)
     {
          cout <<"\n Check col. of first and row of second matrix.";
          cout <<"\n They are different. Try again.\n";
     }
     else
     {
       cout <<"\n Input elements in the first matrix :\n";
       for(i=0;i<rone;i++){
       for(j=0;j<cone;j++){
              cout <<" element - "<<"["<<i<<"]"<<",["<<j<<"] : ";
           cin>>arm[i][j];}}
       cout <<" Input elements in the second matrix :\n";
       for(i=0;i<rtwo;i++){
       for(j=0;j<ctwo;j++){
            cout <<" element - "<<"["<<i<<"]"<<",["<<j<<"] :  ";
            cin>>brm[i][j];}}
       cout <<"\n Here is the elements of First matrix : \n";
       for(i=0;i<rone;i++)
       {
       cout <<"\n";
       for(j=0;j<cone;j++)
       {
            cout <<" "<<arm[i][j]<<" ";
       }
       }
       cout <<"\n Here is the elements of Second matrix : \n";
       for(i=0;i<rtwo;i++)
       {
       cout <<"\n";
       for(j=0;j<ctwo;j++)
       {
            cout <<" "<<brm[i][j]<<" ";
       }
       }
         
       multiplyMatrix(arm,brm);//multiplying
   }
   cout <<"\n The multiplication of two matrix is : \n";
   for(i=0;i<rone;i++)
   {
       cout <<"\n";
       for(j=0;j<ctwo;j++)
       {
            cout <<" "<<crm[i][j]<<" ";
       }
   }
   cout <<"\n\n";
   return 0;
 }
 void multiplyMatrix(int arm[MAX][MAX],int brm[MAX][MAX])
 {
     if(i<rone)
     { //row of first matrix
     if(j<ctwo)
     {  //column of second matrix
          if(k<cone)
          {
              sum=sum+arm[i][k]*brm[k][j];
              k++;
              multiplyMatrix(arm,brm);
          }
          crm[i][j]=sum;
              sum=0;
              k=0;
              j++;
              multiplyMatrix(arm,brm);
     }
     j=0;
     i++;
     multiplyMatrix(arm,brm);
     }
 }
 //....................................
 for (int i=0;i<4;i++){
     mtr[i][0]=1;
     mtr[i][i]=1;              / /pascal triangle
     for (int j=1;j<i;j++){
         mtr[i][j]=mtr[i-1][j]+mtr[i-1][j-1];
     }
 }
*/

