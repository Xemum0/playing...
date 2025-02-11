//from decimal to roman
#include <iostream>
#include <string>
using namespace std;

void to_roman(int num, string& result) {
    static const int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    static const string numerals[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
for (int i=0;i<13;i++){
    while (num>=values[i]){
        num-=values[i];
        result+=numerals[i];
    }
}
}

int main() {
    int num =987;
    string roman_numeral;
    to_roman(num, roman_numeral);
    cout << "The Roman numeral representation of " << num << " is: " << roman_numeral << endl;
    return 0;
}
