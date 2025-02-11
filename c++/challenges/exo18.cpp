//program to find the smallest positive number 
//that is evenly divisible by all of the numbers from 1 to 20
#include <iostream>
#include <cmath>
using namespace std;

const int N = 20;

int main() {
    int factors[N + 1][N + 1] = {}; // initialize all elements to 0
    for (int i = 2; i <= N; i++) {
        int n = i;
        for (int j = 2; j <= n; j++) {
            while (n % j == 0) {
                factors[i][j]++;
                n /= j;
            }
        }
    }
    int lcm[N + 1] = {};
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            lcm[j] = max(lcm[j], factors[i][j]);
        }
    }
    long long ans = 1;
    for (int i = 2; i <= N; i++) {
        ans *= pow(i, lcm[i]);
    }
    cout << ans << endl;
    return 0;
}

