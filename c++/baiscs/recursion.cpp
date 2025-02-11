#include <iostream>
#include<cmath>
using namespace std;

//.................................................

void reversestring (string s){
    if (s.length()==0){
        return ;
    }
        string ros=s.substr(1);
    reversestring(ros);
        cout <<s[0];
}
//.................................................

void replacepi(string s){
    if (s.length()==0){
        return ;
    }
    if(s[0]=='p'&&s[1]=='i'){
        cout <<"3.14";
        replacepi(s.substr(2));
    }
    else{
        cout <<s[0];
        replacepi(s.substr(1));
    }
}
//.................................................

void towerofhanoi(int n,char start,char dest,char help){
    if (n==1){
        cout <<" move "<<n<<" from "<<start<<" to "<<dest<<endl;
    }
    else {
        towerofhanoi(n-1, start, help, dest);
        cout <<" move "<<n<<" from "<<start<<" to "<<dest<<endl;
        towerofhanoi(n-1, help, dest, start);
    }
}
//.................................................

string removeduplicat (string s){
    if(s.length()==0)//sorted string brk
        return "";
    char c=s[0];
    string ans=removeduplicat(s.substr(1));
    if(c==ans[0]){
        return ans;
    }else return (c+ans);
        
        }
//.................................................

string movextotheend (string s){
    if(s.length()==0)
        return "";
    char c=s[0];
    string help= movextotheend(s.substr(1));
    if(c=='x'){
        return (help+c);
    }return c+help;
        
        }
//.................................................

void substringgen(string s,string re){
    if(s.length()==0){
        cout <<re<<endl;
    return ;}
    char c=s[0];
    string help=s.substr(1);
    substringgen(help, re);
    substringgen(help, re+c);
    
}
//.................................................

void asscisub(string s,string re){
    if(s.length()==0){
        cout <<re<<endl;
        return ;}
    char c=s[0];
    int code=c;
    string help=s.substr(1);
    asscisub(help, re);
    asscisub(help, re+c);
    asscisub(help, re+to_string(code));
}
//.................................................

string phonepad[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string re){
    if(s.length()==0){
        cout <<re<<endl;
        return ;}
    char c=s[0];
    string code=phonepad[c-'0'];
    string ros=s.substr(1);
    for (int i=0;i<code.length();i++){
        keypad(ros,re+code[i]);
    }
    
}
//.................................................
int staires (int n){
    if (n==1||n==2)return n;
    else return staires(n-1)+staires (n-2);
    
}
//.................................................

int sumofnuminasentenc(string s){
    int sum=0,num=0;
    for (int i=0;i<s.length();i++){
        if (s[i]<='9' && s[i]>='1'){
            num=num*10+(s[i]-'0');
        }else {
            sum+=num;
            num=0;
            
        }
    }
    return sum+num;
}
//.................................................

int count_partition (int n,int m){
    if (n==0)
        return 1;
    else if (m==0 ||n<0)
        return 0;
    else {
        return count_partition(n,m-1)+count_partition(n-m,m );
    }
}
//.................................................

int grid (int m,int n){
    
    if (n==1 || m==1){
        return 1;
    }
    else {
        return grid(m, n-1)+grid (m-1,n);
        
    }
}
//.................................................

int combinatorial (int n,int k){
    if (n==k ||k==0)return 1;
    else return combinatorial(n-1,k-1)+combinatorial(n-1,k);
}

//.................................................
/*
Put n items with given weight and value in a knapsack of capacity W to get the maximum total value in the knapsack
capcityof_bag=c
number_ofitems=n
*/
int knapsack (int val[],int weight[],int n,int c){
    if (n==0||c==0)return 0 ;
    if (weight[n-1]>c) return knapsack(val,weight,n-1,c);
return max ((knapsack(val,weight,n-1,c-weight[n-1])+val[n-1]),knapsack(val,weight,n-1,c));

}

//.................................................

void permutation (string s,string ans){
    if (s.length()==0)
    {
        cout <<ans<<endl;
        return;
    }
    else for (int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutation(ros,ans+ch);
    }
}
//.................................................
int main() {
int wt[]={10,20,30};
int val[]={100,50,150};
int w=50;

cout << knapsack(wt,val,3,w)<<endl;

    return 0;
}
