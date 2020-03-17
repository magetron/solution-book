#include<bits/stdc++.h>

using namespace std;

int main () {
	vector<int> tree{2,2,-1,0,0};
	int index = 2;
	vector<bool> visited(tree.size(), false);
	for (int i = 0; i < tree.size(); i++)
		if (!visited[i]) {
			int n = tree[i];
			while (n != -1 && n != index) {
				n = tree[n];
			}
			if (n == index) {
				int rn = i;
				while (rn != n) {
					if (!visited[rn]) cout << rn << " ";
					visited[rn] = true;
					rn = tree[rn];
				}
			}
			visited[i] = true;
		}
	return 0;
}
