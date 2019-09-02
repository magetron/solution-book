#include <bits/stdc++.h>

using namespace std;

void do_work () {
    int n;
    cin >> n;
    list<int> arr;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int new_element;
        cin >> new_element;
		if (i == 0) {
			arr.push_back(new_element);
			continue;
		}
        int dist = 0;
		bool found = false;
        for (auto it = arr.begin(); it != arr.end(); it++) {
            dist++;
            if (*it > new_element) {
                ans += ((i + 1) - dist);
                arr.insert(it, new_element);
				found = true;
                break;
            }
        }
		if (!found) arr.push_back(new_element);
		//for (auto it : arr) cout << it << " ";
		//cout << endl;
    }
    cout << ans << endl;
}

int main () {
    freopen("INVCNT.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) do_work();
    fclose(stdin);
    return 0;
}

