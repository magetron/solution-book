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
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int iStar = -1, jStar = -1;
        while (i < s.length()) {
            //cout << i << " " << s[i] << " " << j << " " << p[j] << endl;
            if (s[i] == p[j]) {
                i++;
                j++;
            } else if (p[j] == '?') {
                i++;
                j++;
            } else { 
                if (p[j] == '*') {
                    jStar = j;
                    iStar = i;
                }
                if (jStar == -1) return false;
                else {
                    i = iStar;
                    iStar++;
                    j = jStar + 1;
                }
            }
        }
        while (j < p.length() && p[j] == '*') j++;
        return (j == p.length());
    }
};
