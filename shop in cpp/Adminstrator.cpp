//
//  Adminstrator.cpp
//  shop
//
//  Created by macbook m1 on 11/5/2023.
//

#include "Adminstrator.hpp"




void Admin::Menu(){
    system("clear");
    int option;
    cout <<"\n ----------_ Welcom to  proucts menu admin MR Youcef_-------------\n";
    cout<<"1.add product\n";
    cout <<"2.remove product\n";
    cout <<"3.change products lables \n";
    cout <<"4.Show my information\n";
    cout <<"5.ban a user\n";
    cout <<"6.Exit \n";
    cout <<"Your choice :";
    cin>>option;
    switch (option) {
        case 1:
            addproducts();
            break;
        case 2:
            removeproducts();
            break;
        case 3:
            Editproduct();
            break;
        case 4:
            User::print();
            break;
        case 5:
            BanUser();
            break;
        case 6:
            cout <<"Bye Bye ....\n";
            exit(0);
            break;
        default:
            system("clear");
            cout <<"invalid option try again \n";
            Menu();
            break;
    }
    
}

void Admin::addproducts(){
    ofstream write("productbase.txt",ios::app);
    if (!write)throw invalid_argument("file not operned");
    else{
        string name;
        float price;
        int id,capacity;
        bool flage=true;
        while (flage){
            cout <<"Enter Product name : ";
            cin>>name;
            cout <<"Enter Price : ";
            cin>>price;
            cout <<"Enter Id : ";
            cin>>id;
            cout <<"Enter Capacity : ";
            cin>>capacity;
            cout <<"Do you want to stop 0 if yes : ";
            cin>>flage;
            write<<name<<' '<<price<<' '<<id<<' '<<capacity<<endl;
        }
        write.close();
        cout <<"Operation done correctly\n";
    }
    write.close();
    Menu();
};


void Admin::removeproducts(){
    int id;
    cout <<"----------_ welcom to the deletion menu _-----------\n";
    cout <<"Enter product id : ";
    cin>>id;
    fstream data,data1;
bool token=false ;
data.open("productbase.txt",ios::in);
if (!data){
  cout <<"file does not exist !!\n";
}else {
    string name;
    float price;
    int ID,capacity;
 data1.open ("Productbasetemp.txt",ios::app|ios::out);
// data>>name>>price>>ID>>capacity;
    while (data>>name>>price>>ID>>capacity) {
      if (ID == id) {
          cout << "record Deleted successfully !!\n";
          token = true;
      } else {
          data1 <<name<<' '<<price<<' '<<ID<<' '<<capacity<<endl;
      }
  }
              data.close();
              data1.close();
              remove("productbase.txt");
              rename("Productbasetemp.txt","productbase.txt");
              if (!token) cout <<"item not found"<<endl;
      }
Menu();
};
void Admin::Editproduct(){
    fstream data1,data2;
    bool token=false ;
    int pkey;
    string name ,tempname;
    float price,tempprice;
    int id ,tempid,capacity,tempcapacity;
    cout <<"\t\nmodify the Product : \n";
    cout <<"\t product Id : ";
    cin>>pkey;
    data1.open("productbase.txt",ios::in);
    if (!data1){
        cout <<"file does not exist !!\n";
    }else {
       data2.open ("Productbasetemp.txt",ios::app|ios::out);
        data1>>name>>price>>id>>capacity;

        while (data1>>name>>price>>id>>capacity){
                    if (pkey==id){
                        token=true;
                        cout <<"Product new code : ";
                        cin>>tempid;
                        cout <<"Product new name : ";
                        cin>>tempname;
                        cout <<"Product new price : ";
                        cin>>tempprice;
                        cout <<"Product new Capacity : ";
                        cin>>tempcapacity;
                        data2<<tempname<<' '<<tempprice<<' '<<tempid<<' '<<tempcapacity<<endl;
                        cout <<"Product edited !! \n";
                    }
                    else data2<<name<<' '<<price<<' '<<id<<' '<<capacity<<endl;
                    
            }
                    data1.close();
                    data2.close();
                    remove("productbase.txt");
                    rename("Productbasetemp.txt","productbase.txt");
                    if (!token)cout <<"item not found"<<endl;
            }
Menu();
};
void Admin:: BanUser(){
    system("clear");
    string username;
    cout <<"\n------------------_ban Pannel_------------------\n";
    k:
    cout <<"Enter Username : ";
    cin>>username;
    if (!User::Userchecker(username)){
        cout <<"invalid username doesnot exist\n";
        BanUser();
    }else {
        ifstream read("Database.txt");
        ofstream copy("Data.txt",ios::app);
        if (!read ||!copy){
            cout <<"Error cannot open the file \n";
            return ;
        }else {
            bool flage =false,skipline2=false;
            string line;
            while (getline(read,line)){
                string temp="";
                for (int i=0;i<username.length();i++){
                    temp+=line[i+5];
                }
                if(temp==username){
                    cout <<"User banned succefully\n";
                    flage=true;
                    skipline2=true;
                }else {
                    if (skipline2){
                        skipline2=false;
                    }
                    else copy<<line<<endl;
                }
            }
            if (!flage){
                cout <<"cannot find User Please reenter username\n";
                goto k;
            }
            read.close();copy.close();
            remove("Database.txt");
            rename("Data.txt", "Database.txt");
        }
    }
    Menu();
};
