#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string text;
    ofstream file("file.txt", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    cout << "Enter the number of lines to write: ";
    int x;
    cin >> x;
    cin.ignore(); // Ignore the newline character left in the input stream
    for (int i = 0; i < x; i++) {
        cout << "Enter line " << i + 1 << ": ";
        getline(cin, text);
        file << text << endl;
    }
    file.close();

    ifstream infile("file.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    cout << "The content of the file:" << endl;
    while (getline(infile, text)) {
        cout << text << endl;
    }
    infile.close();

    return 0;
}


