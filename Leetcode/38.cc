#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string prev;
		string ans = "1";
		int i = 1;
		while (i < n) {
			prev = ans;
			ans = "";
			i++;
			int target = -1;
			int count = 0;
			for (auto it = prev.begin(); it != prev.end(); it++) {
				if (*it - 48 == target) count++;
				else {
					if (target != -1) {
						ans.push_back((char)(count + 48));
						ans.push_back((char)(target + 48));
					}
					count = 1;
					target = *it - 48;
				}
			}
			ans.push_back((char)(count + 48));
			ans.push_back((char)(target + 48));
			//cout << i << " " << count << " "<< target << " " << ans << endl;
		}
		return ans;
    }
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.countAndSay(5) << endl;
	return 0;
}

