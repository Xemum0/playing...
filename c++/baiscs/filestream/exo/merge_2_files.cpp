#include <iostream>
#include <fstream>

using namespace std;

int main() {
string txt;
     
    fstream file1,file2,file;
    file1.open("file.txt",ios::in);
    file2.open("file1.txt",ios::in);
    file.open("result.txt",ios::app|ios::out);
    if (!file1||!file2)cerr<<"error file cannot be opend\n";
    else {
        while (getline(file1,txt)) {
            file <<txt<<endl;
        }
        while (getline(file2,txt)) {
            file <<txt<<endl;
        }
    }
    cout <<"operation end succefully\n";
    return 0;
}

