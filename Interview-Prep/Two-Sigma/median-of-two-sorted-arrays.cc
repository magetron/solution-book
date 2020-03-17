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
    
    inline double findMed(vector<int>& n) {
        if (n.size() % 2 == 0) {
            return (n[n.size() / 2 - 1] * 1.0 + n[n.size() / 2] * 1.0) / 2;
        } else {
            return (n[n.size() / 2]);
        }
    }
    
    inline double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = nums1.size();
        if (r == 0) {
            return findMed(nums2);    
        }
        
        int totl = (nums1.size() + nums2.size()) / 2;
        int lpos = -1, rpos = -1;
        while (l <= r) {
            int cnt1 = l + (r - l) / 2;
            int cnt2 = totl - cnt1;
            //cout << "l and r : " << l << " " << r << endl;
            //cout << cnt1 << " " << cnt2 << endl;
            if ((cnt1 == 0 || nums1[cnt1 - 1] <= nums2[cnt2]) && (cnt2 == 0 || nums2[cnt2 - 1] <= (cnt1 < nums1.size() ? nums1[cnt1] : INT_MAX))) {
                lpos = cnt1;
                rpos = cnt2;
                break;
            } else if (cnt1 > 0 && nums1[cnt1 - 1] > nums2[cnt2]) r = cnt1;
            else l = cnt1 + 1;
        }
        
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            double s = min(lpos < nums1.size() ? nums1[lpos] : INT_MAX, rpos < nums2.size() ? nums2[rpos] : INT_MAX)
                + max(lpos > 0 ? nums1[lpos - 1] : INT_MIN, rpos > 0 ? nums2[rpos - 1] : INT_MIN);
            return s / 2;
        } else {
            return min(lpos < nums1.size() ? nums1[lpos] : INT_MAX, rpos < nums2.size() ? nums2[rpos] : INT_MAX);
        }
        
        return 0;
    }
};
