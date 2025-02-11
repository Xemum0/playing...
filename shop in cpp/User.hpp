//
//  User.hpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#ifndef User_hpp
#define User_hpp

#include "Date.hpp"
#include<iostream>
using namespace std;
#include <fstream>
class User {
public:
    static int random;
    User (string em,string pass,string loginstatu,string na,int id,int,int,int);
    User (string em,string pass,string loginstatu,string na,Date d1,int id);
    User(){
        for (int i=0;i<1000;i++)Usernames[i]="";
    };
    void menu();
    void login();
    void label();
    void registeration();
    void forgetpass();
    void print();
    void setall(string em,string pass,string loginstatu,string na,int id,int year,int month,int day);
    bool Userchecker(string);
private:
    string email,password,loginstatus,name;
    Date registerDay;
    int userid;
    static int length;
    string Usernames[1000];

    
};
#endif /* User_hpp */
