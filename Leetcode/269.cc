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
	
	bool top_sort (int i, vector<vector<int>>& g, vector<bool>& v, vector<bool>& f, string& ans) {
		if (f[i]) return true;
		else if (v[i]) return false;
		else v[i] = true;
		for (int ch : g[i]) {
			if (!top_sort(ch, g, v, f, ans)) return false;
		}
		ans.push_back(i + 97);
		f[i] = true;
		return true;
	}

    string alienOrder(vector<string>& words) {
		set<pair<char, char>> pred;
		unordered_set<char> dict;
		//vector<int> in(26, 0);
		for (auto w : words) 
			for (auto c : w) dict.insert(c);
		for (int i = 1; i < words.size(); i++) {
			int p1 = 0;
			int p2 = 0;
			while (p1 < words[i].length() && p2 < words[i].length() && words[i][p1] == words[i - 1][p2]) {
				p1++;
				p2++;
			}
			for (int j = p1 + 1; j < words[i].length(); j++) dict.insert(words[i][j]);
			if (p1 == words[i].length() && p2 == words[i - 1].length()) continue;
			if (p1 != words[i].length() && p2 != words[i - 1].length())
				pred.insert({words[i - 1][p2] - 97, words[i][p1] - 97});
		}
		vector<vector<int>> g(26, vector<int>());
		for (auto p : pred) {
			g[p.first].push_back(p.second);
			//in[p.second]++;
		}
		
		/*for (int i = 0; i < 26; i++) if (g[i].size()) {
			cout << (char)(i + 97) << ": ";
			for (auto c : g[i]) cout << (char)(c + 97) << " ";
			cout << endl;
		}*/

		string ans;
    	vector<bool> v(26, false);
		vector<bool> f(26, false);
		bool exist = false;
		for (int i = 0; i < g.size(); i++) if (g[i].size() > 0) {
			exist = true;
			if (!top_sort(i, g, v, f, ans)) return "";
		}
		reverse(ans.begin(), ans.end());

		bool none = true;
		for (int i = 0; i < g.size(); i++) if (g[i].size() > 0) none = false;
		if (!exist && !none) return "";
		for (char a : ans) dict.erase(a);
		for (auto ch : dict) ans.push_back(ch);
		return ans;
	}
};

int main () {
	Solution s;
	vector<string> words{"sobdtfqmkx","touaona","adt","sjlz","pofhlg","jwi","g","hnhe","acrciuu","axhchsi","axz"};
	cout << s.alienOrder(words) << endl;
	return 0;
}

