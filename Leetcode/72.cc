#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	inline int min3 (int a, int b, int c) {
		return min(min(a, b), c);
	}

    int minDistance(string word1, string word2) {
 		int w1_len = word1.length();
		int w2_len = word2.length();
		vector<vector<int>> dp(w1_len + 1, vector<int>(w2_len + 1, 0));
		
		for (int i = 0; i <= w1_len; i++) dp[i][0] = i;
		for (int j = 0; j <= w2_len; j++) dp[0][j] = j;

		for (int i = 0; i < w1_len; i++)
			for (int j = 0; j < w2_len; j++) 
				if (word1[i] == word2[j]) dp[i + 1][j + 1] = dp[i][j];
				else dp[i + 1][j + 1] = min3(dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1);

		return dp[w1_len][w2_len];
    }
};


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	cout << s.minDistance("", "") << endl;
	return 0;
}
