
 #include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

char **tokinizeztring (char str[],const int size){
    char *copy=new char [strlen(str)+1];
    strcpy(copy, str);
    char **arr = new char *[size];
    int i=0;
    char *token=strtok(copy," ");
    while (token !=NULL){
        arr[i]=token;
       token =strtok(NULL," ");
       i++;
    }
    return arr;
}


int main (){
    char c[]={"hello world this is me playing foot omee"};
    char **ptr=tokinizeztring(c,8);
    for (int i=0;i<8;i++){
        cout <<ptr[i]<<" ";
    }
    cout <<"\n";
    cout <<c<<endl;
  return 0;
}

