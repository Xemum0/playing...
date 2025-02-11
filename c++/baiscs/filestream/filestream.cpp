#include<iostream>
#include <fstream>
using namespace std;
/*modes
ios::
out :output
in:input
trunc: any existing contents of the file are truncated, or erased, before the first write operation
ate: make the courser at the end  with  the ability to change it  place and it posiible write/read mode
app: make the courser at the end without the ability to change it  place possible just for write 
binary: open a file as binary file

_we have_
istream for input read   
ostream for output write 
these bothe are inherat from fstream class
 



*/
int main (){
// fstream data;//defult mode(flacs) of fstream is ios::in |ios::out an this not creat file

//     data.open("data.txt",ios::out );
//     if (data.is_open()){
//          string x;
//          data>>x;
//         cout <<data.bad()<<endl;
//     }


//     data.close();

char c=cin.peek();//instead of get 
//when you use get 
//use this 
//cin.putback(c);
if (c>='0'&& c<='9'){
    int num;
    cin>>num;
    cout <<"the num is : "<<num<<endl;
}else{
    string s;
    cin>>s;
    cout <<"the string is : "<<s<<endl;
}

    return 0;
}