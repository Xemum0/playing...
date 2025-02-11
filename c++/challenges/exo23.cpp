//program to find the minimum number of characters that must be inserted into a
//given string with no whitespace characters to make it a palindrome.
#include <iostream>
#include <cstring>
using namespace std;


int main() {
    int t, len, i, j=0;
    char str1[] = "abcdefgh";
    int dp[2][10000];
    len = (int)strlen(str1);
    for(i = 0; i <= len; i++) dp[0][i] = dp[1][i] = 0;
    for(i = len - 1; i >= 0; i--) {
        for(j = 1; j <= len; j++) {
            if(str1[i] == str1[j - 1]) dp[1][j] = dp[0][j - 1] + 1;
            else dp[1][j] = max(dp[0][j], dp[1][j - 1]);
        }
        for(j = 0; j <= len; j++) {
            dp[0][j] = dp[1][j];
        }
    }
    cout << len - dp[1][j - 1] <<endl;
    return 0;
}


