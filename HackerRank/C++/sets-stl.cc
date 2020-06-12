#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();


int main() {
    unordered_set<int> dict;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        switch (a) {
            case 1: dict.insert(b); break;
            case 2: dict.erase(b); break;
            case 3: if (dict.find(b) != dict.end()) cout << "Yes" << endl; else cout << "No" << endl;
        }
    }
    return 0;
}
