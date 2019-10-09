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

    int calculate_simple(string s) {
		int i = 0, ans = 0, n = 0, sign = 1;
		stack<int> op, res;
		while (i < s.length()) {
			if (isdigit(s[i])) n = n * 10 + (s[i] - 48);
			else {
				ans += n * sign;
				n = 0;
				if (s[i] == '+') sign = 1;
				else if (s[i] == '-') sign = -1;
			}
			i++;
		}
		ans += n * sign;
		return ans;
    }

    int calculate(string S) {
		string s;
		for (auto ch : S) if (ch != ' ') s.push_back(ch);
		int i = 0;
		while (i < s.length()) {
			if (s[i] == '*' || s[i] == '/') {
    			int l = i - 1;
				while (l >= 0 && isdigit(s[l])) l--;
				int r = i + 1;
				while (r < s.length() && s[r] != '+' && s[r] != '-') r++;
				int j = l + 1;
				int res = 1;
				int n = 0;
				char sign = '*';
				while (j < r) {
					if (isdigit(s[j])) n = n * 10 + (s[j] - 48);
					else {
						if (sign == '*') res *= n; else res /= n;
						n = 0;
						sign = s[j];
					}
					j++;
				}
				if (sign == '*') res *= n; else res /= n;
				string r_str = to_string(res);
				s.replace(l + 1, r - l - 1, r_str);
				i = l + 1 + r_str.length();
			}
			i++;
		}
		return calculate_simple(s);
	}
		
};

int main () {
	Solution s;
	cout << s.calculate("1 * 2 + 3 * 4 + 5 * 6   * 7") << endl;
	return 0;
}
