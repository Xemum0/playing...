//greatest_lengthofsubstr_without repet
#include <iostream>
#include <string>
using namespace std;

string compare(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        bool is_unique = true;
        for (int j = 0; j < i; j++) {
            if (str[j] == str[i]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            result += str[i];
        }
    }
    return result;
}


void fun(string s, string temp[]) {
    for (int i = 0; i < s.length(); i++) {
        int count = 1;
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j])
                break;
            else
                count++;
        }
        temp[i] = s.substr(i, count);
        temp[i] = compare(temp[i]);
    }
}
    int arr[10];
int final(string temp[], int size) {

    for (int i = 0; i < size; i++) {
        arr[i] =(int) temp[i].length();
    }
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    int size = str.length();
    string temp[size];
  for (int i = 0; i < size; i++) {
        temp[i] ="a";
    }
    fun(str, temp);
    cout << "Length of the longest substring without repeating characters: "
         << final(temp, size) << "\n";

    return 0;
}
/*
#include <iostream>
#include <string>

using namespace std;

int getLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;

    // Create a map to store the last index of each character seen so far
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int start = 0; // Starting index of the current substring
    for (int i = 0; i < n; i++) {
        int ch = s[i];

        // If the current character has been seen before and its last occurrence
        // is within the current substring, update the starting index of the
        // substring to be the next index after the last occurrence of the character
        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }

        // Update the last occurrence index of the character
        lastIndex[ch] = i;

        // Update the maximum length of the substring seen so far
        maxLength = max(maxLength, i - start + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int longestSubstring = getLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << longestSubstring << endl;

    return 0;
}
*/