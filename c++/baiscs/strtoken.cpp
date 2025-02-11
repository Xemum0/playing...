#include <iostream>
#include <cstring> 
using namespace std;

bool fun (){cout <<"f";return false; }
char  fun1(){return 'g';}
char fun2(){cout <<"h";return 'h';} 

int main() {
  char result (fun()?fun1():fun2());
  cout <<result<<endl;
   char sentence[] = "hello hello hello hello ,this is me hello dehello ifhello";
    char *tokenPtr;
    string word ;
    int count =0;
    cout <<"enter the word  : ";
    cin>>word;
    tokenPtr = strtok( sentence, " " );
   while ( tokenPtr != NULL )
 {
 if (word==tokenPtr)count ++;
 tokenPtr = strtok( NULL, " " );
 } 
cout <<"number of occurence is : "<<count<<endl;

   
}