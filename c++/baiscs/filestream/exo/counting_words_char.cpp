#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int word_count = 0;
    int char_count = 0;

    string txt;
    ifstream file("file.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
    } else {
        while (file >> txt) {
            word_count++;
        }
        file.clear();
        file.seekg(0, ios::beg);
        while (!file.eof()) {
           char c= file.get() ;
            if (c!=' ')char_count++;
        }
        cout << "Number of words: " << word_count << endl;
        cout << "Number of characters: " << char_count << endl;
        file.close();
    }

    return 0;
}

