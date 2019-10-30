#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    
    void dfs (string& num, int pos, string& path, ll cur, ll prev, int& target, vector<string>& ans) {
        if (pos == num.length()) {
            if (cur == target) {
                ans.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.length(); i++) {
            if (pos == 0) {
                string ns = num.substr(pos, i - pos + 1);
                ll val = stol(ns);
                path += ns;
                dfs(num, i + 1, path, val, val, target, ans);
                path.erase(path.length() - ns.length(), ns.length());
            } else {
                string ns = num.substr(pos, i - pos + 1);
                ll val = stol(ns);
                path += "+" + ns;
                dfs(num, i + 1, path, cur + val, val, target, ans);
                path.erase(path.length() - ns.length() - 1, ns.length() + 1);
                path += "-" + ns;
                dfs(num, i + 1, path, cur - val, -val, target, ans);
                path.erase(path.length() - ns.length() - 1, ns.length() + 1);
                path += "*" + ns;
                dfs(num, i + 1, path, prev * val + cur - prev, prev * val, target, ans);
                path.erase(path.length() - ns.length() - 1, ns.length() + 1);
            }
            if (num[pos] == '0') break;
        }
    }
    
    vector<string> addOperators(string num, int target) {
        if (!num.length()) return {};
        string path{};
        vector<string> ans;
        dfs(num, 0, path, 0, 0, target, ans);
        return ans;
    }
};
