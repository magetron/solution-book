#include <bits/stdc++.h>
#define si short int

using namespace std;

class Solution {
	public:
		bool dfs (string& s1, int l1, string& s2, int l2, string& s3, vector<vector<si>>& memo) {
			//for (int i = 0; i < l1; i++) cout << s1[i]; cout << endl;
			//for (int i = 0; i < l2; i++) cout << s2[i]; cout << endl;
			//for (int i = 0; i < l3; i++) cout << s3[i]; cout << endl;
			//cout << l1 << " " << l2 << " " << l3 << endl;
			//cout << memo[l1][l2][l3] << endl;  
			//cout << "-----" << endl;
			if (memo[l1][l2] != -1) return memo[l1][l2] == 1;
			if (l1 == s1.length() && l2 == s2.length()) {
				memo[l1][l2] = 1;
				return true;
			}
			if (l1 == s1.length()) {
				bool res;
				if (l2 == s2.length() || s2[l2] != s3[l1 + l2]) res = false; else res = dfs(s1, l1, s2, l2 + 1, s3, memo);
				memo[l1][l2] = res;
				return res;
			}
			if (l2 == s2.length()) {
				bool res;
				if (l1 == s1.length() || s1[l1] != s3[l1 + l2]) res = false; else res = dfs(s1, l1 + 1, s2, l2, s3, memo);
				memo[l1][l2] = res;
				return res;
			}
			bool branch1 = false, branch2 = false; 
			if (s1[l1] == s3[l1 + l2]) branch1 = dfs(s1, l1 + 1, s2, l2, s3, memo);
			memo[l1][l2] = branch1;
			if (branch1) return true;
			if (s2[l2] == s3[l1 + l2]) branch2 = dfs(s1, l1, s2, l2 + 1, s3, memo);
			memo[l1][l2] = branch2;
			if (branch2) return true;
			memo[l1][l2] = 0;
			return false;
		}
		
		bool isInterleave (string s1, string s2, string s3) {
			if (s1.length() + s2.length() != s3.length()) return false;
			vector<vector<si>> memo(s1.length() + 1, vector<si>(s2.length() + 1, -1));
			return dfs(s1, 0, s2, 0, s3, memo);
		}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbbccac");
	Solution s;
	cout << (s.isInterleave(s1, s2, s3) ? "true" : "false") << endl;
	return 0;
}
