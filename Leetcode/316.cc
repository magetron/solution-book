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
    string removeDuplicateLetters(string s) {
		vector<int> dict(26, 0);
		for (char c : s) dict[c - 97]++;
		stack<char> st;
		vector<bool> st_check(26, false);
		for (int i = 0; i < s.length(); i++) {
			if (!st_check[s[i] - 97]) {
				while (!st.empty() && s[i] < st.top() && dict[st.top() - 97] != 0) {
					char c = st.top(); st.pop();
					st_check[c - 97] = false;
				}
                st.push(s[i]);
			    st_check[s[i] - 97] = true;
			}
            dict[s[i] - 97]--;
		}
		string ans = "";
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
        reverse(ans.begin(), ans.end());
		return ans;
    }
};

