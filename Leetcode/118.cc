#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		if (numRows == 0) return vector<vector<int>>();
		vector<vector<int>> ans;
		ans.push_back(vector<int>{1});
		if (numRows == 1) return ans;
		for (int i = 2; i <= numRows; i++) {
			vector<int> line;
			for (int j = 0; j < (i + 1) / 2; j++) 
				if (j == 0) line.push_back(1);
				else line.push_back(ans.back()[j - 1] + ans.back()[j]);
			for (int j = (i + 1) / 2; j < i; j++) line.push_back(line[i - 1 - j]);
			ans.push_back(line);
		}
		return ans;
    }
};
