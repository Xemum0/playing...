//Sieve of eratosthenes to find the nth prime
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char *s;
    size_t i;
    unsigned ctr = 0;
    size_t n = 1000000;
    const unsigned target_val = 1001;
    s = new char[n]();
    for (i = 2; i < n; i++) {//till sqrt (n)if you want to print
        if (!s[i]) {
            size_t j;
            ctr++;
            if (ctr == target_val) {
                cout << i << endl;
                break;
            }
            for (j = i*2; j < n; j += i) {//you can optimise it starting with i*i
                s[j] = 1;
            }
        }
    }
    delete [] s;
    return 0;
}
