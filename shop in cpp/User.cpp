//
//  User.cpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#include "User.hpp"

int User::random=10000;

User::User (string em,string pass,string loginstatu,string na,int id,int year,int month,int day){
    email=em;
    password=pass;
    loginstatus=loginstatu;
    name=na;
    userid=id;
    registerDay.setYear(year);
    registerDay.setmonth(month);
    registerDay.setDay(day);

}
User::User (string em,string pass,string loginstatu,string na,Date d1,int id)
{
    email=em;
    password=pass;
    loginstatus=loginstatu;
    name=na;
    registerDay=d1;
    userid=id;
}



void User::label(){
    int option;
cout <<"_--------Welcom to the Login interface_-----------\n";
    cout <<"1.login  \n";
    cout <<"2.forget password \n";
    cout <<"_-----------------------------------------------_\n";
    cout <<"Your opption : ";
    cin>>option;
    switch (option) {
        case 1:
            login();
            break;
        case 2:
            forgetpass();
            break;
        default:
            system("clear");
            cout <<"Invalid option GOING BACK..\n";
            menu();
            break;
    }
};
void User::login(){
    system("clear");
    string s,pass;
    string read;
    bool flage=false;
    cin.ignore();
    cout<<"Email  : ";
    getline(cin,s);
    cout <<"Password : ";
    getline(cin,pass);
        
  
        ifstream input ("Database.txt");
        if (!input){
            throw invalid_argument("Error  cannot open data Base ");
        }else {
            
            int pos=0;
            while (getline(input,read )) {
                string mail="",pass1="";
                if (read.substr(0,4)=="skip") continue;
                else {
                    for (int i=0;i<read.length();i++){
                        if (read[i]!=' ') mail+=read[i];
                        else {
                            pos=i;
                            break;
                        }
                    }
                    pass1+=read.substr(pos+1,read.length()-pos);
                    if (s==mail && pass1==pass){
                        flage=true;
                        break;
                    }
                }
            }
        }
        input.close();
        
        if (flage) {
            cout << name << "\n YOUR LOGGING WAS SUCCESSFUL \n WELCOME BACK \n ";
            this->loginstatus="online";
            cout <<"loginstatus : "<<loginstatus<<endl;
        }
        else {
            cout << "\nLOGIN ERROR ,PLEASE CHECK YOUR USERNAME AND PASSWORD ";
            login();
        }
    }

void User::registeration(){
    int year ,day,month;
    cin.ignore();
    cout <<"_------Welcom to the regestration interface_-----------\n";
    cout <<"Enter your  username : ";
    getline(cin,name);
    if (Userchecker(name)){
        cout <<"invalid Username already utilized\n";
        registeration();
    }else {
        Usernames[length]=name;
        length++;
    }
    cout <<"Enter email  : ";
    getline(cin,email);
    cout <<"Enter password : ";
    getline(cin,password);
    cout <<"enter registration date \\ year : ";
    cin>>year;
    cin.ignore();
    cout <<"month : ";
    cin>>month;
    cout <<"Day : ";
    cin>>day;
    userid=random++;
    registerDay.setYear(year);registerDay.setDay(day);
    registerDay.setmonth(month);
    ofstream output("Database.txt", ios::app);
    output <<"skip"<<' '<< name<< ' ' <<registerDay.getDay()<<' '<<registerDay.getMonth()<<' '<<registerDay.getYear()<<' '<<userid<<endl;
    output <<email<<' '<<password<<endl;
    output.close();
    system("clear");
    cout << "REGISTRATION IS SUCCESSFUL" << endl;
    cout <<"GO to Login\n";
    login();
};
void User::menu(){
    int choice;
    cout <<"\n--------------_WELCOM TO REGISTRATION MENU_------------------\n";
    cout <<"Choose from the menu below : \n";
    cout <<"1.Creat new Account  \n";
    cout <<"2.Login to My account \n";
    cout <<"3.exit from the progrem \n";
   m:
    cout <<"\n enter you choice :  ";
    cin>>choice;
    switch (choice) {
        case 1:
            registeration();
            break;
        case 2:
            label();
            break;
        case 3:
            cout <<"\n Bye Bye !!!!\n";
            exit (0);
            break;
        default:
            cout<<"invalid option please try again \n ";
            goto m;
            break;
    }
}



void User::forgetpass(){
    int option,pos=0;
    bool validOption = false;
    
    while (!validOption) {
        system("clear");
        cout << "\t\tyou have forgotten your password \n";
        cout << "\t\t1) recuperate your password \n";
        cout << "\t\t2) exit \n";
        cout << "\t\tenter your choice : \n";
        cin >> option;
        cin.ignore();
        string s1,s2,pass;
        if (option == 1) {
            bool flag = false;
            string  username,email;
            cout << "enter your email : ";
            getline(cin,email);
            cout <<"enter your full name : ";
            getline(cin,username);
            ifstream in("Database.txt");
            
            while (getline(in,s1)) {
                string s3="",s4="";
               string temp= s1.substr(5,s1.length()-4);
                getline(in,s2);
                
                for (int i=0;i< s1.length();i++)
                    if (temp[i]!=' ')s3+=temp[i];
                    else break;
               
                if (s3==username){
                    for (int i=0;i< s2.length();i++){
                        if (s2[i]!=' ')s4+=s2[i];
                        else {
                            pos=i;
                            break;
                        }
                    }
                    if (s4==email){
                            flag = true;
                            cout << "\t\tYOUR ACCOUNT IS FOUND \n";
cout << "\t\tYOUR PASSWORD IS : " << s2.substr(pos+1,s2.length()-pos) << endl;
                            break;
                        
                    }
                }
                
            }
      
            in.close();
            if (!flag) {
                cout << "YOUR ACCOUNT NOT FOUND PLEASE VERIFY YOUR USERNAME\n";
            }
            validOption = true;
        }
        else if (option == 2) {
            validOption = true;
            menu();
        }
        else {
            cout << "please enter one of the numbers \n";
            forgetpass();
        }
    }
}


void  User::print(){
    cout <<"\n_----------------------------------_\n";
    cout <<"Email : "<<this->email<<"\n";
    cout <<"password : "<<this->password<<"\n";
    cout <<"Full Name : "<<this->name<<"\n";
    cout <<"User id : "<<this->userid<<"\n";
    cout <<registerDay<<endl;
};

void User::setall(string em,string pass,string loginstatu,string na,int id,int year,int month,int day){
    this->email=em;
    this->password=pass;
    this->loginstatus=loginstatu;
    this->name=na;
    this-> userid=id;
    this->registerDay.setYear(year);
    this->registerDay.setmonth(month);
    this->registerDay.setDay(day);
}

bool User::Userchecker(string newUser){
    for (int i=0;i<length;i++){
        if (newUser==Usernames[i])return false;
    }
    return true;
};

int User::length=0;
