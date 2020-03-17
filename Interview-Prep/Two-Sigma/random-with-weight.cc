#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

class BIT {
public: 
    vector<int> b;
    int cap;
   
	BIT () { }

    BIT (int n) : b(vector<int>(n + 1, 0)), cap(n) { }
    
    int get (int i) {
        i++;
        int s = 0;
        while (i > 0) {
            s += b[i];
            i -= i & (-i);
        }
        return s;
    }
    
    void update (int diff, int i) {
        i++;
        while (i <= cap) {
            b[i] += diff;
            i += i & (-i);
        }
    }    
    
};

class Solution {
public:
    
    BIT bit;
    int maxima;
    
    Solution(vector<int>& w) {
        bit = BIT(w.size());
        for (int i = 0; i < w.size(); i++) bit.update(w[i], i);
        maxima = bit.get(w.size() - 1);
        srand(time(NULL));
    }
    
    void updateIndex (int diff, int i) {
        bit.update(diff, i);
	}
    
    int pickIndex() {
        int ran = rand() % maxima;
        //cout << ran << " " << maxima << endl;
        int l = 0;
        int r = bit.cap;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int val = bit.get(mid);
            int pval = (mid > 0 ? bit.get(mid - 1) : -1);
            if (val >= ran && pval < ran) return mid;
            else if (val > ran) r = mid;
            else l = mid + 1;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

