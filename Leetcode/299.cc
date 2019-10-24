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
    string getHint(string secret, string guess) {
		int bulls = 0;
		unordered_map<char, int> left;
		string nguess;
		for (int i = 0; i < secret.length(); i++) 
			if (secret[i] == guess[i]) bulls++; else {
				nguess.push_back(guess[i]);
				if (left.find(secret[i]) == left.end()) left.insert({secret[i], 1});
				else left[secret[i]]++;
			}
		//cout << nguess << endl;
		int cows = 0;
		for (int i = 0; i < nguess.length(); i++) 
			if (left.find(nguess[i]) != left.end()) {
				cows++;
				left[nguess[i]]--;
				if (left[nguess[i]] == 0) left.erase(nguess[i]);
			}
		//cout << bulls << " " << cows << endl;
    	string ans;
		ans += to_string(bulls) + "A" + to_string(cows) + "B";
		return ans;
	}
};

int main () {
	Solution s;
	cout << s.getHint("11", "10") << endl;
	return 0;
}
