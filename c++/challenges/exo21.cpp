#include<iostream>
using namespace std;

int main() {
    string digits;
    int digit, product, max_product = 0,x;

   cout << "Enter the 1000-digit number:" << endl;
   cin >> digits;
    cout<<"enter the consuctive num : ";
    cin>>x;
    for (int i = 0; i < 1000-x; i++) {
        product = 1;
        for (int j = i; j < i + x; j++) {
            digit = digits[j] - '0';
            product *= digit;
        }
        if (product > max_product) {
            max_product = product;
        }
    }

    std::cout << "The maximum product of " <<x<<" adjacent digits is: " << max_product << std::endl;

    return 0;
}
