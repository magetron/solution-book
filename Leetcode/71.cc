#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	void go_back (string& ans) {
		if (ans == "/") return;
		int i = ans.length() - 2;
		while (ans[i] != '/') i--;
		ans = ans.substr(0, i + 1);
		return;
	}

    string simplifyPath(string path) {
		string ans = "/";
		string cur = "";
		if (path.back() != '/') path.push_back('/');
    	int i = 0;
		while (path[i] != '/') i++;
		i++;
		while (i < path.length()) {
			if (path[i] == '/') {
				if (cur == "..") go_back(ans);
				else if (cur != "" && cur != ".") ans += cur + "/";
				//cout << cur << " ---- " << ans << endl;
				cur = "";
			} else cur += path[i];
			i++;
		}
		if (ans != "/") ans.pop_back();
		return ans;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
	return 0;
}

