#include<iostream>
using namespace std;

char *c[]={"hello,","this","is","jay"};
char **p[]={c+3,c+2,c+1,c};
char ***r=p;


//.................................





int main(){ 
        cout << **++r  <<" ";
     cout <<  *--*++r+2 <<" ";
     cout <<   *r[-2]+1<<" ";
     cout << r[-1][-1]+1  <<" ";
/*
//2 dimensional

        int b[2][3]={{1,2,3},{4,5,6}};
        int (*P)[3]=b;
    cout <<**(P+1)<<endl;//derefrence 
    cout << b <<" "<< &b[0]<<"\n";//adress of the first array
    cout << *b <<" "<<b[0]<<" "<<&b[0][0]<<"\n";//adress of the first int elem 
    cout <<b+1<<" "<< *b[1]<<"\n";//it pass to the next array of 1d and print the adress
    cout << *(b+1)<<" "<< b[1]<<" "<<&b[1][0]<<"\n"; //the addres of the first elem in 2nd array
    cout << *(b+1)+2<<" "<<b[1]+2<<" "<<&b[1][2]<<"\n";//adress of the sec elem of the 2nd array
    cout << *(*b+1)<<"\n";//second elem in the 1st array
    //b[i][j]==*(*(b+i)+j)==*(b[i]+j) they are same 
    cout <<endl;    
    cout <<b[1][2]<<" "<<*(*(b+1)+2)<<" "<<*(b[1]+2)<<endl;

//multi  dimensions
int mlti [3][2][2]={{{1,2},{3,4}},{{5,6},{7,8}},{{9,10},{11,12}}};
//multi[i][j][k]==*(multi[i][j]+k)==*(*(multi[i])+j)+k)==*(*(*(multi+i)+j)+k)
int (*ptr)[2][2]=mlti;





//.................................

//char c1[6]={"hello"};//string get stored in the space for array 
//char *c="hello ";//string get stored as compile time constant "you cant modify"
//c[0]='a';//gives an error

//.................................

     cout <<endl;
    char c[]="hello";
    char *c1=c;
    cout <<*c1+1<<endl;
    cout <<*(c1+1)<<endl;
    cout <<c1+1<<endl;//substr
    cout <<c+1<<endl;//same sbstr 
    char **c2=&c1;
    *(*c2+3)='p';
    cout <<*c2<<" "<<c<<" "<<c1<<endl;
*/


    return 0;
}