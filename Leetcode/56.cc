class Solution {
public:
    
    inline bool check (vector<int>& l, vector<int>& r) {
        //cout << l[0] << " " << l[1] << " " << r[0] << " " << r[1] << endl;
        return l[1] >= r[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& l, const vector<int>& r) { return l[0] > r[0]; });
        //for (auto i : intervals) cout << i[0] << " " << i[1] << endl;
        int i = intervals.size() - 1;
        while (i > 0) {
            bool mergable = check(intervals[i], intervals[i - 1]);
            if (mergable) {
                vector<int> new_interval{min(intervals[i][0], intervals[i - 1][0]), max(intervals[i][1], intervals[i - 1][1])};
                intervals.erase(intervals.begin() + i);
                intervals.erase(intervals.begin() + i - 1);
                intervals.insert(intervals.begin() + i - 1, new_interval);
               // cout << "new_interval " << new_interval[0] << " " << new_interval[1] << endl;
            } 
            i--;
        }
        return intervals;
    }
};
