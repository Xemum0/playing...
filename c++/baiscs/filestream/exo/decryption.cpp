#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    string filename;
    int key;

    // Get filename and encryption key from user
    cout << "Enter the name of the file to decrypt: ";
    cin >> filename;
    cout << "Enter the encryption key (a number between 1 and 25): ";
    cin >> key;

    // Open input file and check for errors
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        return 1;
    }

    // Create output filename with .enc extension
    string outputFile = filename + ".txt";

    // Open output file and check for errors
    ofstream outputFileStream(outputFile);
    if (!outputFileStream) {
        cerr << "Error creating encrypted file " << outputFile << endl;
        return 1;
    }

    // Read input file character by character and write encrypted characters to output file
    char ch;
    while (inputFile.get(ch)) {
         ch=ch-key;
        outputFileStream <<ch;
    }

    // Close files
    inputFile.close();
    outputFileStream.close();

    cout << "File " << filename << " decrypted successfully.decrypted file saved as " << outputFile << endl;

    return 0;
}
