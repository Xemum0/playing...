#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void MainMenu();

class Managment {
    public :
    Managment(){
        MainMenu();
    }
};

//................details.....................
class Details
{
    public:
   static string name ,gender;
   string adress;
    int phone,age;
    static int costumer_id;
    char arr[100];

    void information (){
                system("clear");
                cout << "\n______________________________________________________\n" ;
                cout <<"             WELCOME TO INFORMATION MENU " ;
                cout << "\n______________________________________________________\n" ;
                cout <<"enter the costumer id : ";
                cin>>costumer_id;
                cin.ignore();
                cout <<"enter the name : ";
                getline(cin,name);
                cout <<"enter the gender : ";
                cin>>gender;
                cout <<"enter the age : ";
                cin>>age;
                cin.ignore();
                cout <<"enter the address : ";
               getline(cin,adress);
               cin.ignore();
        cout <<"THE OPERATION  END SUCCEFULLY\n\n";
               
    }
};
//................register....................
int Details::costumer_id;
string Details ::name;
string Details::gender;
class Register {
public:
      static int choice;
      int choice1;
      int back;
      static float charges;
    void  flights(){
     system("clear");
    string flightN[]={"Dubai","USA","UK","canada","algeria"};
     cout << "\n______________________________________________________\n" ;
     cout <<"             WELCOME TO REGISTRATION BOARED " ;
     cout << "\n______________________________________________________\n" ;

     for (int i=0;i<5;i++){
        cout <<i+1<<"."<<flightN[i]<<endl;
     }
     m:
     cout <<"\nenter your destination :";
     cin>>choice;
  
switch (choice)
{
case 1:
     cout <<"\n_____________WELCOME TO EMIRATES FLIGHTS________________\n";
     cout<< "Your comfort is our priority. Enjoy the journey!"<<endl;
     cout<<"Following are the flights \n"<<endl;
     cout<<"1. DUB - 498"<<endl;
     cout<<"\te8-01-2022 8:00AM 10hrs Rs. 14000"<<endl; 
     cout<<"2. DUB - 658"<<endl;
     cout<<"\t89-01-2022 4:00AM 12hrs Rs. 10000"<<endl; 
     cout<<"3. DUB- 599"<<endl;
     cout<<"\t11-01-2022 11:00AM 11hrs. Rs. 9000"<<endl;
     cout<<"Select the flight you want to book : ";
     cin>>choice1;
     if (choice1 ==1){
        charges=14000;
       cout<<"You have successfully booked the flight DUB - 498"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;
     }else if (choice1==2){

        charges=10000;
       cout<<"\nYou have successfully booked the flight DUB - 658"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else if (choice1==3){

          charges=9000;
       cout<<"\nYou have successfully booked the flight DUB - 599"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else {
        cout <<"\ninvalud choice ,shifting the previous menu ";
        flights();
     }
     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
    break;

    case 2:
     cout <<"\n_____________WELCOME TO USA FLIGHTS________________\n";
     cout<< "Your comfort is our priority. Enjoy the journey!"<<endl;
     cout<<"Following are the flights \n"<<endl;
     cout<<"1. USA - 033"<<endl;
     cout<<"\te8-01-2022 9:00AM 10hrs Rs. 20000"<<endl; 
     cout<<"2. USA - 789"<<endl;
     cout<<"\t89-01-2022 4:00AM 12hrs Rs. 23000"<<endl; 
     cout<<"3. USA- 599"<<endl;
     cout<<"\t11-01-2022 11:00AM 11hrs. Rs. 19000"<<endl;
     cout<<"Select the flight you want to book : ";
     cin>>choice1;
     if (choice1 ==1){
        charges=20000;
       cout<<"You have successfully booked the flight USA - 033"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;
     }else if (choice1==2){

        charges=23000;
       cout<<"\nYou have successfully booked the flight USA - 789"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else if (choice1==3){

          charges=19000;
       cout<<"\nYou have successfully booked the flight USA - 599"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else {
        cout <<"\ninvalud choice ,shifting the previous menu ";
        flights();
     }
     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
    break;

        case 3:
     cout <<"\n_____________WELCOME TO UK FLIGHTS________________\n";
     cout<< "Your comfort is our priority. Enjoy the journey!"<<endl;
     cout<<"Following are the flights \n"<<endl;
     cout<<"1. UK -002"<<endl;
     cout<<"\te8-01-2022 9:00AM 10hrs Rs. 13000"<<endl; 
     cout<<"2. UK - 543"<<endl;
     cout<<"\t89-01-2022 4:00AM 12hrs Rs. 23000"<<endl; 
     cout<<"Select the flight you want to book : ";
     cin>>choice1;
     if (choice1 ==1){
        charges=13000;
       cout<<"You have successfully booked the flight UK - 002"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;
     }else if (choice1==2){

        charges=23000;
       cout<<"\nYou have successfully booked the flight UK - 543"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else {
        cout <<"\ninvalud choice ,shifting the previous menu ";
        flights();
     }
     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
    break;

        case 4:
     cout <<"\n_____________WELCOME TO CANADA FLIGHTS________________\n";
     cout<< "Your comfort is our priority. Enjoy the journey!"<<endl;
     cout<<"Following are the flights \n"<<endl;
     cout<<"1. CA - 001"<<endl;
     cout<<"\te8-01-2022 9:00AM 10hrs Rs. 24000"<<endl; 
     cout<<"2. CA - 002"<<endl;
     cout<<"\t89-01-2022 4:00AM 12hrs Rs. 15000"<<endl; 
     cout<<"3. CA- 003"<<endl;
     cout<<"\t11-01-2022 11:00AM 11hrs. Rs. 13000"<<endl;
     cout<<"Select the flight you want to book : ";
     cin>>choice1;
     if (choice1 ==1){
        charges=24000;
       cout<<"You have successfully booked the flight CA - 001"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;
     }else if (choice1==2){

        charges=15000;
       cout<<"\nYou have successfully booked the flight CA - 002"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else if (choice1==3){

          charges=13000;
       cout<<"\nYou have successfully booked the flight CA - 003"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else {
        cout <<"\ninvalud choice ,shifting the previous menu ";
        flights();
     }
     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
    break;

    case 5:
     cout <<"\n_____________WELCOME TO ALGERIA FLIGHTS________________\n";
     cout<< "Your comfort is our priority. Enjoy the journey!"<<endl;
     cout<<"Following are the flights \n"<<endl;
     cout<<"1. ALG - 022"<<endl;
     cout<<"\te8-01-2022 9:00AM 10hrs Rs. 7000"<<endl; 
     cout<<"2. ALG - 033"<<endl;
     cout<<"\t89-01-2022 4:00AM 12hrs Rs. 6700"<<endl; 
     cout<<"3. ALG- 044"<<endl;
     cout<<"\t11-01-2022 11:00AM 11hrs. Rs. 5000"<<endl;
     cout<<"Select the flight you want to book : ";
     cin>>choice1;
     
     if (choice1 ==1){
        charges=7000;
       cout<<"You have successfully booked the flight ALG - 022"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;
     }else if (choice1==2){

        charges=6700;
       cout<<"\nYou have successfully booked the flight ALG - 033"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else if (choice1==3){

          charges=5000;
       cout<<"\nYou have successfully booked the flight ALG - 044"<<endl;
       cout<<"You can go back to menu and take the ticket"<<endl;

     }else {
        cout <<"\ninvalud choice ,shifting the previous menu ";
        flights();
     }
     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
    break;
default:
cout <<"\ninvalid choice please try again \n";
goto m;
    break;
}
    }
};
//................tiket.......................
float Register ::charges;
int Register::choice;
class Tiket :public Register,Details {
    public:
    void Bill(){
        system("clear");
        string destination="";
        ofstream outf("tiket.txt");
        {
            cout <<"_________________XYZ AIRLINES____________________"<<endl;
            cout <<"_____________________TIKET_______________________"<<endl;
            cout <<"_________________________________________________"<<endl;
            outf<<"COSTUMER ID : "<<Details::costumer_id<<endl;
            outf<<"COSTUMER NAME : "<<Details::name<<endl;
            outf<<"COSTUMER GENDER : "<<Details::gender<<endl;
            outf<<"COSTUMER ADRESS : "<<Details::adress<<endl;
            outf<<"\nDESCRIPTION : "<<endl;

            if (Register::choice==1)destination="Dubai";
            else if (Register::choice==2)destination="USA";
            else if (Register::choice==3)destination="UK";
            else if (Register::choice==4)destination="CANADA";
            else if (Register::choice==5)destination="ALGERIA";

            outf<<"DESTINATION : "<<destination<<endl;
            outf<<"FLIGHT COST  : "<<Register::charges<<endl;
        }
        outf.close();
        }
    void display(){
        system("clear");
        cout <<"\n-----------------------------------------------\n";
        ifstream file ("tiket.txt");
        {
            if (!file )cout <<"\nerror file emoty !!\n";
            while (!file.eof()){
                file.getline(arr,100);
                cout <<arr<<endl;
            }
        }
       cout <<"\n-----------------------------------------------\n";
        file.close();
    }
    
};
//............................................
void  MainMenu(){
    int Ichoice,Schoice,back;
        cout << "---------------------------------------" << endl;
        cout << "|         AIRLINE RESERVATION          |" << endl;
        cout << "|                                      |" << endl;
        cout << "| 1. Add costumer details              |" << endl;
        cout << "| 2. Flight regestration               |" << endl;
        cout << "| 3. Tiket and charges                 |" << endl;
        cout << "| 4. Exit                              |" << endl;
        cout << "|                                      |" << endl;
        cout << "---------------------------------------" << endl;
m:
        cout << "Enter your choice: ";
        cin >> Ichoice; 

    Details d;
    Register r;
    Tiket t;

      switch (Ichoice) {
            case 1:
                 cout <<"\n______________________INFORMATIONS______________________\n";
                 d.information();
                 cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
                break;
            case 2:
                cout << "\n______________________________________________________\n" ;
                cout <<"             BOOK YOUR TIKET USING THIS SYSTEM ";
                cout << "\n______________________________________________________\n" ;
                r.flights();
                break;
            case 3:
                cout << "\n______________________________________________________\n" ;
                cout <<"                         GET YOUR TIKET  ";
                cout << "\n______________________________________________________\n" ;
                 t.Bill();
                 cout<<"\nYour ticket is printed, you can collect it In"<<endl;
                  cout<<"Press 1 to display your ticket \n";
                  cin>>back;
                  if (back==1){
                    t.display();
                     cout <<"\nPRESS ANY KEY TO GO BACK TO THE MAIN MENU \n";
                 cin>>back;
                 back==1?MainMenu():MainMenu();
                  }else MainMenu();
                break;
            case 4:
            cout <<"\nTHANK YOU FOR USING OUR SERVICES \n GOOD BYE\n";
            exit(0);
            default:
                cout << endl << "Invalid choice. Please select a valid option." << endl;
                goto m;
                break;
        }
}

int main (){
Managment moj;

    return 0;
}
