#include "bits/stdc++.h"
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
    
    bool dfs (string& pattern, int pos, string& str, int spos, unordered_map<char, string>& dict, unordered_set<string>& diff) {
        if (pos == pattern.length() && spos == str.length()) return true;
        if (pos == pattern.length() || spos == str.length()) return false;
        char pc = pattern[pos];
        if (dict.find(pc) != dict.end()) {
            string ss = dict[pc];
            int j = spos, i = 0;
            while (i < ss.length()) {
                if (str[j] != ss[i]) return false;
                i++; j++;
            }
            return dfs(pattern, pos + 1, str, j, dict, diff);
        }
        for (int i = spos; i < str.length(); i++) {
            string ss = str.substr(spos, i - spos + 1);
            if (diff.find(ss) != diff.end()) continue; else diff.insert(ss);
            dict.insert({pc, ss});
            auto res = dfs(pattern, pos + 1, str, spos + ss.length(), dict, diff);
            if (res) return true;
            else {
                dict.erase(pc);
                diff.erase(ss);
            }
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> dict;
        unordered_set<string> diff;
        return dfs(pattern, 0, str, 0, dict, diff);
    }
};
