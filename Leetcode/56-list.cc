class Solution {
public:
    
    inline bool check (vector<int>& l, vector<int>& r) {
        //cout << l[0] << " " << l[1] << " " << r[0] << " " << r[1] << endl;
        return l[1] >= r[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) { return l[0] > r[0]; });
        list<vector<int>> intv(intervals.begin(), intervals.end());
        auto it = prev(intv.end());
        while (it != intv.begin()) {
            bool mergable = check(*it, *prev(it));
            if (mergable) {
                vector<int> new_interval{min((*it)[0], (*prev(it))[0]), max((*it)[1], (*prev(it))[1])};
                intv.erase(it--);
                intv.insert(it, new_interval);
                intv.erase(it--);
                //cout << "new interval " << new_interval[0] << " " << new_interval[1] << endl;
            } else it--;
        }
        vector<vector<int>> ans(intv.begin(), intv.end());
        return ans;
    }
};
