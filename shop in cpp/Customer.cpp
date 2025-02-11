//
//  Customer.cpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#include "Customer.hpp"
#include <cstring>
void Costumer:: Menu(){

    int option;
    cout <<"\n------------------_Welcome backe MR "<<username<<"_------------------\n";
    cout <<"Please Choose from the Menu : \n";
    cout <<"1.Go to store \n";
    cout <<"2.Show my info\n";
    cout <<"3.Update profile\n";
    cout <<"3.exit from the Store\n";
    cout <<"OPtion : ";
    cin>>option;
    switch (option) {
        case 1:
            gotostore();
            break;
        case 2:
            printinfo();
            break;
        case 3:
            cout <<"Bye Bye....\n";
            exit(0);
            break;

        default:
            cout <<"invalid option choose again \n";
            Menu();
            break;
    }
};

void Costumer::setinfo(string username){
    this->username=username;
    int count =0;
    cout <<"please enter your info \n";
    cout <<"adress : ";
    getline(cin,adress);
m:
     if (count==3){
        cerr<<"Error your card is blocked\n";
        exit(-1);
    }
    cout <<"Credit card info : \n";
    cout <<"Enter Card type : ";
    getline(cin,card.cardcompany);
    cout <<"Enter card number : ";
    getline(cin,card.pan);
    cout<<"Enter pin : ";
    getline(cin,card.pin);
    cout <<"Enter date of expire : ";
    getline(cin,card.expiredon);

    if (!Cardchecker(card.cardcompany,card.pan,card.expiredon,card.pin)){
        cout <<"invalid card check again ";
        count ++;
        goto m;
    }else {
        ofstream input("Costumer.txt",ios::app);
        if(!input){
            cout <<"File not opened "<<endl;
            return;
        }else {
            input <<username<<' '<<adress<<' '<<card.accountbalance<<endl;
        }
    }
    Menu();
}

void Costumer::printinfo(){
    User::print();
    ifstream read("Costumer.txt");
    if (!read.is_open()){
        cerr<<"error file not opened\n";
        return;
    }else {
        string line,name="",balance="";
        int pos=0;
        while (getline(read,line)){
            for (int i=0;i<line.length();i++){
                if (line[i]!=' ')name+=line[i];
                else break;
            }
            if (name==username){
                for (int i=(int)username.length();i<line.length();i++){
                    if(line[i]==' ')break;
                    pos=i;
                }
                balance=line.substr(pos+1,line.length()-pos);
            }
        }

//.........print

        cout <<"Adress : "<<adress<<endl;
        cout <<"Card type : "<<card.cardcompany<<endl;
        cout <<"Card code : "<<card.pan<<endl;
        cout <<"Card pin : "<<card.pin<<endl;
        cout <<"Expired date : "<<card.expiredon<<endl;
        cout <<"Account balance : "<<card.accountbalance<<endl;
    }
    Menu();
};

bool Costumer::Cardchecker(string company,string cardnum,string date,string pin){
    ifstream read("Card.txt");
    string line;
    if (!read) {
        cerr <<"error file not opened\n";
        return  false;
    }else {
        while (getline(read,line)){
            char* token = std::strtok(&line[0], " ");
            string arr[6];
            int i=0;
            while (token != NULL) {
                arr[i]=string (token);
                token = std::strtok(NULL, " ");
                i++;
                }
            if (arr[0]==username &&arr[1]==company && arr[2]==cardnum && arr[3]==date && (arr[4])==pin){
                card.accountbalance=stof(arr[5]);
                return true;
            }
    }
}
    return false;

};


void Costumer::setUserinfo(string User){
    ifstream in ("Database.txt");
    if (!in){
        cerr<<"error file not opened\n";
        return;
    }else{
        string line,line2 ;
        while (getline(in,line)){
            getline(in,line2);
            char* token = strtok(&line[0], " ");
            token = strtok(NULL," ");
            if (string (token)==User){
                int i=0;
                string arr[5];
                string email ,pass;
                while (token != NULL) {
                    arr[i]=string (token);
                    token = strtok(NULL, " ");
                    i++;
                }
                char *token2=strtok(&line2[0], " ");
                email=string (token2);
                token2 = strtok(NULL, " ");
                pass=string (token2);
                
               this->setall(email, pass, "online", arr[0], stoi(arr[4]),stoi(arr[3]),stoi(arr[2]), stoi(arr[1]));

            }
        }
        }
};



void Costumer::Order(){};
void Costumer::buy(){};
void Costumer::gotostore(){};

void Costumer::updateprofile (){
    cout <<"\n-----------_Welcome to profile Mr "<<username<<"_----------\n";
    cout <<"1.Update email\n";
    cout <<"2.Update Username\n";
    cout <<"3.Update password\n";
    cout <<"4.Update email\n";
    cout <<"1.Update email\n";

};
