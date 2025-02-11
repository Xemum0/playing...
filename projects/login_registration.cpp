#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


// Function prototypes
void login();
void registration();
void forgetpass();

int main() {
    int choice;

    cout << "\t________________________________________________\n\n";
    cout << "\t           Welcome to the login page\n";
    cout << "\t___________________ Menu _______________________\n\n";
    cout << "\t| 1) \"login\" \n";
    cout << "\t| 2) \"register\" \n";
    cout << "\t| 3) \"forget password\"\n";
    cout << "\t| 4) \"exit\"\n";
    cout << "\t________________________________________________\n\n";
    cout << "\t\nenter your choice : ";

    try {
        cin >> choice;
        if (cin.fail()) {
            throw std::runtime_error("Invalid input. Please enter a valid integer.");
        }
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
        return 1;
    }

    switch (choice) {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgetpass();
        break;
    case 4:
        cout << "Good bye !! ";
        exit(0);
        break;
    default:
        system("cls");
        cout << " please enter one of the numbers above : \n";
        main();
        break;
    }
    return 0;
}

// Function to handle login
void login() {
    bool flag = false;
    string user_id, pass, id, password;

    system("clear");
    cout << "\t\tenter the Username and password : \n";
    cout << "\t\tUSERNAME : ";
    cin >> user_id;
    cout << "\t\tPASSWORD : ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id.compare(user_id) == 0 && pass.compare(password) == 0) {
            flag = true;
            system("clear");
        }
    }

    input.close();

    if (flag) {
        cout << user_id << "\n YOUR LOGGING WAS SUCCESSFUL \n WELCOME BACK \n ";
        main();
    }
    else {
        cout << "\nLOGIN ERROR ,PLEASE CHECK YOUR USERNAME AND PASSWORD ";
        main();
    }
}

// Function to handle registration
void registration() {
    string ruser, rpassword, rpass, rid;

    system("clear");
    cout << "\tto create an account fill the gaps below : \n";
    cout << "\t\tUSERNAME : ";
    cin >> ruser;
    cout << "\t\tPASSWORD : ";
    cin >> rpassword;

    ofstream output("records.txt", std::ios::app);
    output << ruser << ' ' << rpassword << endl;
    output.close();

    system("clear");
    cout << "REGISTRATION IS SUCCESSFUL" << endl;
    main();
}

void forgetpass() {
    int option;
    bool validOption = false;
    
    while (!validOption) {
        system("clear");
        cout << "\t\tyou have forgotten your password \n";
        cout << "\t\t1) recuperate your password \n";
        cout << "\t\t2) exit \n";
        cout << "\t\tenter your choice : \n";
        cin >> option;

        if (option == 1) {
            bool flag = false;
            string current, username, password;
            cout << "enter your username : ";
            cin >> current;
            ifstream in("records.txt");
            while (in >> username >> password) {
                if (current == username) {
                    flag = true;
                    cout << "\t\tYOUR ACCOUNT IS FOUND \n";
                    cout << "\t\tYOUR PASSWORD IS : " << password << endl;
                    break;
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
            main();
        }
        else {
            cout << "please enter one of the numbers \n";
            forgetpass();
        }
    }
}
