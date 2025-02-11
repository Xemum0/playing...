//give the Length of longest (valid)parentheses 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int res = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                res = max(res, i - st.top());
            }
        }
    }

    return res;
}


int main() {
    string main_str = "(()))";
    cout << "Original Parentheses string: " << main_str << endl;
    cout << "Length of longest parentheses: " << longestValidParentheses(main_str) << endl;
    return 0;
}
