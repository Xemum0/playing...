//program to generate all combinations of well-forme
// parentheses from n given pairs of parentheses
#include <iostream>
#include <string>

using namespace std;

void generateParentheses(string str, int open, int close, int n) {
    if (open == n && close == n) {
        cout << str << endl;
        return;
    }
    if (open < n) {
        generateParentheses(str + "(", open + 1, close, n);
    }
    if (close < open) {
        generateParentheses(str + ")", open, close + 1, n);
    }
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    cout << "All possible combinations of well-formed parentheses:" << endl;
    generateParentheses("", 0, 0, n);

    return 0;
}

