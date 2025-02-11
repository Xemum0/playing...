#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> lines;
    string line;

    ifstream infile("file.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    while (getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }

    return 0;
}


