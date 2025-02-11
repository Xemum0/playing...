#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int x;
    string s;
    cout <<"enter the line that you want to remove : ";
    cin>>x;
    fstream file,temp;
    file.open("file.txt",ios::in);
    if(!file)cerr<<"error file cannot open\n";
    else {
        temp.open("temp.txt",ios::app|ios::out);
        int i=0;
        while (getline(file,s)){
            i++;
            if (i==x)
                cout<<"line deleted succefully\n";
            else {
                temp<<s<<endl;
            }
        }
        file.close();
        temp.close();
        remove("file.txt");
        rename("temp.txt", "file.txt");
    }

    return 0;
}
