//program to find the index of the first occurrence of a given string 
//within another given string. If not found return -1
#include <iostream>
using namespace std;

int found (string main,string key){
    for (int i=0;i<main.length()-key.length()+1;i++){
          if (main[i]==key[0]){
                 if (main.substr(i,key.length())==key)return i;
                 else continue;
          }
    }
    return -1;
}

int main (){
     string str,str1 ;
     cout <<"enter the two string : \n";
     cin>>str>>str1;
     cout <<"the string found in the index : "<<found(str,str1)<<endl;


    return 0;
}