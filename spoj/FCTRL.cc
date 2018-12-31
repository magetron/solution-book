#include <bits/stdc++.h>

using namespace std;

void do_work () {
	int n;
	cin >> n;
	int zeros = 0;
	int fives = n / 5;
	while (fives > 0) {
		zeros += fives;
		fives /= 5;
	}
	cout << zeros << endl;
}	

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) do_work();
	return 0;
}
