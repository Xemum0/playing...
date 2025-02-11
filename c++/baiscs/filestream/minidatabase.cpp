#include <iostream>
#include<fstream>
using namespace std;

class person {
    public:
    string fname,lname;
    short age,phone;
};
struct node {
person elem;
node *next;
};
static int numberofper=0;
node *head;
//..............................
    void append (string a,string b,short c,short d ){
        numberofper++;
        node *temp=new node ;
        temp->elem.fname=a;
        temp->elem.lname=b;
        temp->elem.age=c;
        temp->elem.phone=d;

        if (head ==NULL){
            head =temp;
            temp->next=NULL;
            return ;
        }else {
            node *ptr=head;
            while (ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->next=NULL;
        }
    }
    void deltelist(node* head){
while (head!=NULL){
    node*temp=head;
    head=head->next;
    delete temp;
    temp=nullptr;
}
}

//..........................................................
void addperson ();
void displayall();
void addtofile ();
void load();
void searchforperson();
void removeperson();
    int main (){
        head=NULL;
        int choice;
        do{
            cout <<endl;
            cout <<"number of people in data base : "<<numberofper<<endl;
            cout <<"\n\t\t_MENU_\n";
            cout <<"1.Add a Person\n";
            cout <<"2.show all persones\n";
            cout <<"3.save in a file \n";
            cout <<"4.load people on data base\n";
            cout <<"5.search for person \n";
            cout <<"6.remove a person from the data base\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
               addperson ();
                break;
             case 2:
                displayall();
                break;
                 case 3:
                addtofile();
                break;
                 case 4:
                load();
                break;
                case 5:
                searchforperson();
                break;
                case 6:
                removeperson();
                break;
            default:
                cin.clear();
                cin.ignore();
                cout <<"\ninvalid option please try again \n";
                break;
            }
            cout <<"\nif you want to stop enter 1 else 0 : \n";
            cin>>choice;
        }while (choice !=1);
        deltelist(head);
        return 0;
    }

void addperson() {
    string a, b;
    short c, d;
    cout << "enter the first name : ";
    cin>>a;
    cout << "enter the last name : ";
    cin.ignore(); // ignore the newline character from the previous input
    getline(cin, b);
    cout << "enter the age : ";
    cin >> c;
    cout << "enter the phone number : ";
    cin >> d;
    append(a, b, c, d);
}


void displayall(){
    if (head==NULL)cout <<"the data base is empty \n";
     node *temp=head;
     while (temp!=NULL){
        cout <<"_______________person : "<<numberofper<<" info______________\n";
        cout <<"FIRST NAME : "<<temp->elem.fname<<endl;
        cout <<"LAST NAME : "<<temp->elem.lname<<endl;
        cout <<"AGE : "<<temp->elem.age<<endl;
        cout <<"PHONE NUMBER  : "<<temp->elem.phone<<endl;
        temp=temp->next;
     }
}
void addtofile (){
    ofstream data("data.txt",ios::app);
    node *temp=head;
   if (numberofper==0)cout <<"no persones to add\n";
   else {
    for (int i=0;i<numberofper;i++){
        while (temp!=NULL){
        data<<temp->elem.fname<<endl;
        data<<temp->elem.lname<<endl;
        data<<temp->elem.age<<endl;
        data<<temp->elem.phone<<endl;
        temp=temp->next;
        }
    }
    cout <<"data added properly\n";
   }
}


void load() {
    ifstream data("data.txt");
    if (!data) {
        cout << "The database is empty.\n";
    } else {
        string a, b;
        short c, d;
        while (data >> a >> b >> c >> d) {
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
            cout << d << endl;
            cout <<endl;
        }
        if (data.eof()) {
            cout << "\nData loaded properly.\n";
        } else {
            cout << "\nError while reading data.\n";
        }
    }
}
void searchforperson(){
      string name;
         cout <<"enter person s name : ";
         cin >>name;
      ifstream data("data.txt");
    if (!data) {
        cout << "The database is empty.\n";
    } else {
        string a, b;
        short c, d;
        while (data >> a >> b >> c >> d) {
            if (a==name){
             cout <<"PERSON  FOUND HERE IS HIS INFO : \n";
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
            cout << d << endl;
            cout <<endl;
                return ;
            }
        }
        cout <<"person not found"<<endl;
}
}
void removeperson(){
        string name;
         cout <<"enter person s name : ";
         cin >>name;
    fstream data,data1;
    data.open("data.txt",ios::in);
     if (!data) {
        cout << "The database is empty.\n";
    } else {
       data1.open("temp.txt",ios::app|ios::out);
        string a, b;
        short c, d;
        int token=0;
        while (data >> a >> b >> c >> d) {
            if (a==name){
                token ++;
             cout <<"PERSON  REMOVED PROPERLY \n";
            }   else {
                data1<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
            }
        }
        if (token ==0)cout <<"person not found \n";
        data.close();
        data1.close();
        remove("data.txt");
        rename("temp.txt","data.txt");

}

}
