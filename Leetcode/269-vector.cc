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
    
    bool top_sort (int pos, vector<vector<int>>& graph, vector<int>& order, vector<bool>& v, vector<bool>& f) {
        if (f[pos]) return true;
        else if (v[pos]) return false;
        else v[pos] = true;
        for (int i = 0; i < graph[pos].size(); i++) {
            if (!top_sort(graph[pos][i], graph, order, v, f)) return false;
        }
        order.push_back(pos);
        f[pos] = true;
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        if (!words.size()) return {};
        vector<vector<int>> graph(26, vector<int>());
        vector<bool> nodes(26, false);
        for (int i = 0; i < words[0].length(); i++) nodes[words[0][i] - 97] = true;
        for (int i = 1; i < words.size(); i++) {
            int p1 = 0, p2 = 0;
            while (p1 < words[i - 1].length() && p2 < words[i].length() && words[i - 1][p1] == words[i][p2]) {
                p1++; p2++;
            }
            if (p1 < words[i - 1].length() && p2 < words[i].length()) {
                //cout << words[i - 1][p1] << " " << words[i][p2] << endl;
                graph[words[i - 1][p1] - 97].push_back(words[i][p2] - 97);
            }
            for (int j = 0; j < words[i].size(); j++) nodes[words[i][j] - 97] = true;
        }
        /*for (int i = 0; i < 26; i++) {
            cout << (char)(i + 97) << " - ";
            for (auto n : graph[i]) cout << (char)(n + 97) << " ";
            cout << endl;
        }*/
        vector<bool> v(26, false);
        vector<bool> f(26, false);
        vector<int> order;
        for (int i = 0; i < 26; i++) if (graph[i].size() > 0) {
            if (top_sort(i, graph, order, v, f) == false) return {};
        }
        for (int i = 0; i < order.size(); i++) nodes[order[i]] = false;
        for (int i = 0; i < 26; i++) if (nodes[i]) order.push_back(i);
        reverse(order.begin(), order.end());
        string ans;
        for (auto chi : order) ans.push_back((char)(chi + 97));
        return ans;
    }
};
