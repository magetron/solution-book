#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		bool isValid(string s) {
			stack<char> st;
			st.push('@');
			for (auto it = s.begin(); it != s.end(); it++) 
				switch(*it) {
					case '(':
						st.push('(');
						break;
					case '[':
						st.push('[');
						break;
					case '{':
						st.push('{');
						break;
					case ')':
						if (st.top() != '(') return false;
						st.pop(); break;
					case ']':
						if (st.top() != '[') return false;
						st.pop(); break;
					case '}':
						if (st.top() != '{') return false;
						st.pop(); break;
				}
			return st.top() == '@';
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s("()[]{}");
	Solution ss;
	cout << (ss.isValid(s) ? "true" : "false") << endl;
	return 0;
}
