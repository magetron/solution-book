#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('@');
        for (auto& c : s) {
            if (c == '(') st.push('(');
            else if (c == '[') st.push('[');
            else if (c == '{') st.push('{');
            else {
                char tmp_c = st.top();
                if (c == ')' && tmp_c != '(') return false;
                else if (c == ']' && tmp_c != '[') return false;
                else if (c == '}' && tmp_c != '{') return false;
                st.pop();
            }
        }
        return st.top() == '@';
    
    }
};
