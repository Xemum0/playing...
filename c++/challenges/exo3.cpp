//longest palindromic_substring
#include <iostream>
using namespace std;

bool palindrom (string s){
    if (s.length()==1||s.length()==0)return true;
    else {
        for (int i=0;i<s.length()/2;i++){
        if (s[i]!=s[s.length()-i-1]) return false;
    }
    return true;
    }
}

string final (string s){
      string temp=s.substr(0,1);
    for (int i=0;i<s.length();i++){
        for (int j=0;j<s.length();j++){
            if (palindrom(s.substr(i,j))){
                 if (s.substr(i,j).length()>=temp.length())temp=s.substr(i,j);
            }
        }
        }
        return temp;
    }

int main (){
  string s="boolloolsoolking";
  cout <<final(s)<<endl;

    return 0;
}