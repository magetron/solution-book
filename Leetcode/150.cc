#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
	int convert(string token) {
		int a = 0;
		if (token[0] != '-') for (char c : token) a = a * 10 + c - 48;
		else {
			for (int i = 1; i < token.length(); i++) a = a * 10 + token[i] - 48;
			a = -a;
		}
		return a;
	}

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
		for (string token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				if (token == "+") st.push(b + a);
				else if (token == "-") st.push(b - a);
				else if (token == "*") st.push(b * a);
				else if (token == "/") st.push(b / a);
			} else {
				int a = convert(token);
				st.push(a);
			}
		}
		return st.top();
    }
};
