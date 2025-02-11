#include<iostream>
#include <fstream>
using namespace std;
int main (){

    fstream data;
    data.open ("data.txt",ios::out|ios::binary);
    if (data.is_open()){
        char sample []={"hello this is me \ni cant play game"};
        data.write(sample,(int)strlen (sample));

    }else cout <<"couldnot open the file "<<endl;
    data.close();
      char c[250];
      data.open("data.txt",ios::in);
    while (!data.eof()){
          data.getline(c,250);
          cout <<c<<" "<<data.gcount()<<endl;
    }
data.close();

}