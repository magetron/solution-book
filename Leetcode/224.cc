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
    int calculate(string s) {
		int i = 0, ans = 0, n = 0, sign = 1;
		stack<int> op, res;
		while (i < s.length()) {
			if (isdigit(s[i])) n = n * 10 + (s[i] - 48);
			else {
				ans += n * sign;
				n = 0;
				if (s[i] == '+') sign = 1;
				else if (s[i] == '-') sign = -1;
				else if (s[i] == '(') {
					res.push(ans);
					op.push(sign);
					ans = 0;
					sign = 1;
				} else if (s[i] == ')' && !op.empty()) {
					ans = res.top() + ans * op.top();
					res.pop();
					op.pop();
					sign = 1;
				}
			}
			i++;
		}
		ans += n * sign;
		return ans;
    }
};

int main () {
	Solution s;
	cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
	return 0;
}


