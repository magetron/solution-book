#include <bits/stdc++.h>

using namespace std;

int find (vector<int>& pre, int x) {
	int y = x;
	while (pre[y] != y) y = pre[y];
	while (pre[x] != x) {
		int pre_x = pre[x];
		pre[x] = y;
		x = pre_x;
	}
	return y;
}

int unite (vector<int>& pre, int x, int y, vector<int>& ppl) {
	int pre_x = find(pre, x);
	int pre_y = find(pre, y);
	if (pre_x != pre_y) {
		pre[pre_y] = pre_x;
		ppl[pre_x] += ppl[pre_y];
		return ppl[pre_x];
	} else return ppl[pre_x];
}

void do_work () {
	int n;
	cin >> n;
	vector<int> pre(2 * n);
	vector<int> ppl(2 * n, 1);
	for (int i = 0; i < 2 * n; i++) pre[i] = i;
	unordered_map<string, int> dict;
	string useless;
	getline(cin, useless);
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		int split_pos = -1;
		for (int i = 0; i < str.length(); i++) if (str[i] == ' ') { split_pos = i; break; }
		if (split_pos == -1) break;
		string name_a = str.substr(0, split_pos);
		string name_b = str.substr(split_pos + 1, str.length() - split_pos - 1);
		auto found_a = dict.find(name_a);
		auto found_b = dict.find(name_b);
		if (found_a == dict.end()) dict.insert({name_a, dict.size()});
		if (found_b == dict.end()) dict.insert({name_b, dict.size()});
		cout << unite(pre, dict[name_a], dict[name_b], ppl) << endl;
	}
}


int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) do_work();
	return 0;
}

