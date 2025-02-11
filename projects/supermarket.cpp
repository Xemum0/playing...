
#include<iostream>
#include<fstream>
using namespace std;

class Shopping { // capitalize the first letter of class name
    private:
        int product_code;
        float price, discount;
        string name;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void Delete();
        void list();
        void receipt();
};

void Shopping::menu() {
    int choice;
    string email, password;
a:
    cout << "------------------------------" << endl;
    cout << "        SUPERMARKET MENU      " << endl;
    cout << "------------------------------" << endl;
    cout << " 1. Administrator" << endl;
    cout << " 2. Buyer" << endl;
    cout << " 3. Exit" << endl;
    cout << "-------------------------" << endl;
    cout << "\nPlease select: ";
    cin >> choice;
    switch (choice) {
        case 1:
        n:
            static int count = 0;
            cout << "\nEnter your information: ";
            cout << "\nEMAIL: ";
            cin >> email;
            cout << "\nPASSWORD: ";
            cin >> password;
        m:
            count++;
            if (email == "youcef@gmail.com" && password == "qwerty12") {
                cout << "\nWELCOME MR \"YOUCEF\"\n\n" << endl;
                administrator();
            } else if (email == "youcef@gmail.com" && password != "qwerty12") {
                cout << "Invalid password. Please try again: ";
                cout << "\nPASSWORD: ";
                cin >> password;
                goto m;
            } else if (email != "youcef@gmail.com" && password == "qwerty12") {
                cout << "Invalid email. Please try again.\n";
                cout << "\nEMAIL: ";
                cin >> email;
                goto m;
            } else {
                cout << "Invalid information. Please try again: ";
                goto n;
            }
            if (count == 5) {
                cout << "You are suspended. Please go out.\n";
                exit(0);
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            cout << "Goodbye.\n";
            exit(0);
        default:
            cout << "Please enter a valid number.\n";
            goto a;
            break;
    }
}

void Shopping::administrator() {
    m:
    int choice;
    cout << "\n---------------------------------" << endl;
    cout << "        ADMINISTRATOR MENU         " << endl;
    cout << "-----------------------------------" << endl;
    cout << " 1. Add product" << endl;
    cout << " 2. Modify product" << endl;
    cout << " 3. Delete a product" << endl;
    cout << " 4. List all products" << endl;
    cout << " 5. Back to the main menu" << endl;
    cout << "---------------------------------\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            Delete();
            break;
        case 4:
            list();
            break;
        case 5:
            menu();
            break;
        default:
            cout << "Invalid choice.\n";
            goto m;
            break;
    }
}

void Shopping::buyer() {
    int choice;
    cout << "\n---------------------------------" << endl;
    cout << " BUYER MENU " << endl;
    cout << "-----------------------------------" << endl;
    cout << " 1. Buy product" << endl;
    cout << " 2. Back to the main menu" << endl;
    cout << "---------------------------------\n" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid choice.\n";
            buyer();
            break;
    }
}


void Shopping::add() {
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;
    cout << "\n---------------------------------" << endl;
    cout << " ADDING MENU " << endl;
    cout << "-----------------------------------" << endl;
    cout << "\nEnter the product code: ";
    cin >> product_code;
    cout << "\nEnter the name of product: ";
    cin >> name;
    cout << "\nEnter the price of product: ";
    cin >> price;
    cout << "\nEnter the discount: ";
    cin >> discount;
    data.open("shoppingdata.txt", ios::in);

    if (data.is_open() && data.peek() != ifstream::traits_type::eof()) {
   while (data >> c >> n >> p >> d) {
            if (c == product_code) {
                token++;
                break;
            }
        }
        data.close();

    } else {
        data.open("shoppingdata.txt", ios::app | ios::out);
        data << product_code << " " << name << " " << price << " " << discount << endl;
        data.close();
    }

    if (token==1) {
        cout << "\nProduct code already exists. Please try again.\n";
        add();
    } else {
        data.open("shoppingdata.txt", ios::app | ios::out);
        data << product_code << " " << name << " " << price << " " << discount << endl;
        data.close();
        cout << "\nRecord inserted successfully.\n";
    }
    administrator();
}
void Shopping ::edit(){
    fstream data1,data2;
    bool token=false ;
    int pkey,c;
    float p,d;
    string n;
    cout <<"\t\nmodify the record : \n";
    cout <<"\t product code : ";
    cin>>pkey;
    data1.open("shoppingdata.txt",ios::in);
    if (!data1){
        cout <<"file does not exist !!\n";
    }else {
       data2.open ("shoppingdatatemp.txt",ios::app|ios::out);
       data1>>product_code>>name>>price>>discount;

            while (data1>>product_code>>name>>price>>discount){
                    if (pkey==product_code){
                        token=true;
                        cout <<"Product new code : ";
                        cin>>c;
                        cout <<"Product new name : ";
                        cin>>n;
                        cout <<"Product new price : ";
                        cin>>p;
                        cout <<"Product new discount : ";
                        cin>>d;
                        data2<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                        cout <<"record edited !! \n";
                    }
                    else data2<<" "<<product_code<<" "<<name<<" "<<price<<" "<<discount<<endl;
                    
            }
                    data1.close();
                    data2.close();
                    remove("shoppingdata.txt");
                    rename("shoppingdatatemp.txt","shoppingdata.txt");
                    if (!token)cout <<"item not found"<<endl;
            }
administrator();

}
void Shopping ::Delete(){
          fstream data,data1;
    bool token=false ;
    int pkey;
    cout <<"\t\tDelete the record : \n";
    cout <<"\t product code : ";
    cin>>pkey;
    data.open("shoppingdata.txt",ios::in);
    if (!data){
        cout <<"file does not exist !!\n";
    }else {
       data1.open ("shoppingdatatemp.txt",ios::app|ios::out);
       data>>product_code>>name>>price>>discount;

        while (data >> product_code >> name >> price >> discount) {
            if (pkey == product_code) {
                cout << "record Deleted successfully !!\n";
                token = true;
            } else {
                data1 << product_code << " " << name << " " << price << " " << discount << endl;
            }
        }
                data1>>product_code>>name>>price>>discount;
                    data.close();
                    data1.close();
                    remove("shoppingdata.txt");
                    rename("shoppingdatatemp.txt","shoppingdata.txt");
                    if (!token) cout <<"item not found"<<endl;
            }
administrator();
}

void Shopping::list() {
fstream data;
data.open("shoppingdata.txt",ios::in);
if (!data) {
cout << "File not found.\n";
} else {
int c;
float p,d;
string n;
cout << "\n-----------------------------------------------------------------------" << endl;
cout << " Product List " << endl;
cout << "-----------------------------------------------------------------------" << endl;
cout << "Code\tProduct\t\tPrice\tDiscount\n";
cout << "-----------------------------------------------------------------------\n";
data >> c >> n >> p >> d;
while (!data.eof()) {
cout << c << "\t" << n << "\t\t" << p << "\t" << d << endl;
data >> c >> n >> p >> d;
}
data.close();
}
administrator();
}

void Shopping::receipt () {
     fstream data;
     float Total=0.0;
      int arr_ofquan[100]={0},arr_ofcodes[100]={0};
      char choice;

      int c=0;
      data.open("shoppingdata.txt",ios::in);
      if (!data) {
      cout << "File not found.\n";
      } else {

         data.close();
      cout << "\n-----------------------------------------------------------------------" << endl;
      cout << "                       PLACE THE ORDER                                  \n" << endl;
      cout << "-----------------------------------------------------------------------" << endl;
     do{
        m:
     cout <<"\n\tenter the product code :";
        cin>>arr_ofcodes[c];
        cout <<"\tenter the product quantity : ";
        cin>>arr_ofquan[c];

        for (int i=0;i<c;i++){
            if (arr_ofcodes[c]==arr_ofcodes[i]){
                cout <<"\tDUPLICATE PRODUCT .PLEASE TRY AGAIN \n";
                goto m;
            }
        }
        c++;
        cout <<"\n\tDo you want to buy another product? if yes then press y else no :";
        cin>>choice;

        }while (tolower(choice)=='y');
            system("clear");
        cout <<"\n___________________RECEIPT___________________\n";
        cout << "\nPRODUCT CODE\tPRODUCT NAME\tPRODUCT QUANTITY\tPRICE\tAMOUNT\tAMOUNT WITHDISCOUNT \n";
        
        for (int i=0;i<c;i++){
         float dis=0.0,amount=0.0;
        data.open("shoppingdata.txt",ios::in);
        while (data>>product_code>>name>>price>>discount){
            if (product_code==arr_ofcodes[i]){
                amount=price*arr_ofquan[i];
                dis=amount-(amount*discount/100);
                Total=Total+dis;
                cout<<"\n"<<product_code<<"\t\t"<<name<<"\t\t"<<arr_ofquan[i]<<"        \t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
            }
        }
              data.close();
      }
      }
      cout <<"\n\n___________________________________________________\n";
      cout <<"\nTOTAL AMOUNT : "<<Total<<endl;
}
int main() {
Shopping s;
s.menu();
return 0;
}
