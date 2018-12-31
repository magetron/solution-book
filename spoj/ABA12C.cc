#include <bits/stdc++.h>

using namespace std;

int max (int a, int b) {
	if (a > b) return a;
	else return b;
}

void do_work () {
	int n, k;
	cin >> n >> k;
	int price[k + 1];
	memset(price, 0, sizeof(price));
	for (int i = 1; i <= k; i++) cin >> price[i];
	int money[k + 1];
	memset(money, 0, sizeof(money));
	money[0] = 0;
	for (int i = 1; i <= k; i++) {
		int min_cost = INT_MAX;
		for (int j = 1; j <= i; j++) if ( (price[j] != -1) && (money[i - j] != INT_MAX) ) {
			int cost = money[i - j] + price[j];
			if (cost < min_cost) min_cost = cost;
		}
		money[i] = min_cost;
	}
	//for (int i = 0; i <= k; i++) cout << "money [ " << i << " ] = " << money[i] << endl; 
	if (money[k] == INT_MAX) cout << -1 << endl;
	else cout << money[k] << endl;

}

int main () {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("ABA12C.in", "r", stdin);

	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; i++) do_work();
	
	//fclose(stdin);

	return 0;
}
