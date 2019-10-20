#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class Solution {
public:
    bool confusingNumber(int n) {
        string s = to_string(n);
        string cpy = s;
        reverse(cpy.begin(), cpy.end());
        for (char& c : cpy) {
            if (c == '6') c = '9';
            else if (c == '9') c = '6';
            else if (c == '2' || c == '3' || c == '4' || c == '5' || c == '7') return false;
        }
        //cout << cpy << " " << s << endl;
        return !(cpy == s);
    }
};
