#include<bits/stdc++.h>
#pragma GCC optimise ("Ofast")

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return 0;
} ();

int main () {
	//freopen("p1320.in", "r", stdin);
	string s;
	cin >> s;
	string tot("");
	cout << s.length() << " ";
	tot += s;
	s.clear();
	cin.clear();
	while (cin >> s) {
		tot += s;
		cin.clear();
		s.clear();
	}
	//cout << tot << "#" << endl;
	if (tot[0] == '1') cout << "0 ";
	int c = 1;
	for (int i = 1; i < tot.length(); i++) 
		if (tot[i] != tot[i - 1]) {
			cout << c << " "; 
			c = 1;
		} else c++;
	cout << c << endl;
	//fclose(stdin);
	return 0;
}
