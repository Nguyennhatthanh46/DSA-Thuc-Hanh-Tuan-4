#include <iostream>
#include <stack>
using namespace std;

bool Match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string s;
    cin >> s;
    stack<char> st;

 for (char x : s) {
        if (x == '(' || x == '[' || x == '{') {
            st.push(x);
        }
        else if (x == ')' || x == ']' || x == '}') {
            if (st.empty() || !Match(st.top(), x)) {
                cout << "0";
                return 0;
            }
            st.pop();
        }
    }
if(st.empty()) cout<<"1";
else cout<<"0";
}
