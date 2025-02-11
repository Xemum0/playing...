 //program to find the largest palindrome 
 //made from the product of two 3-digit numbers.
#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int rev = 0, num = n;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return (rev == n);
}

int main() {
    int maxPalindrome = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int prod = i * j;
            if (isPalindrome(prod)) {
                maxPalindrome = max(maxPalindrome, prod);
            }
        }
    }
    cout << maxPalindrome << endl;
    return 0;
}
