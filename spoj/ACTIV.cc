#include <bits/stdc++.h>
#define modulo 100000000
#define max_n 100005
#define max_e 1000000005

using namespace std;

bool cmp (pair <int, int> a, pair <int, int> b) {
	return b.second > a.second;
}

void do_work (int n) {
	pair <int, int> time_node[max_n];
	for (int i = 0; i < n; i++) cin >> time_node[i].first >> time_node[i].second;
	sort(time_node, time_node + n, cmp);
	int choice[max_n];
	choice[0] = 1;
	for (int i = 1; i <= n; i++) {
		choice[i] = choice[i - 1];
		choice[i] += choice[upper_bound(time_node, time_node + n, make_pair(0, time_node[i - 1].first), cmp) - time_node];
		if (choice[i] >= modulo) choice[i] -= modulo;
	}
	choice[n] += modulo - 1;
	if (choice[n] >= modulo) choice[n] -= modulo;
	cout << setfill('0') << setw(8) << choice[n] << endl;
}


int main () {
	//freopen("ACTIV.in", "r", stdin);
	//freopen("ACTIV.ans", "w", stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	while (n != -1) {
		cin >> n;
		if (n != -1) do_work(n);
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}


