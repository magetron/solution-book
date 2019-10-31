#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

static int fast_io = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if (lq.empty()) lq.emplace(num);
        else {
            if (num <= lq.top()) lq.emplace(num); else rq.emplace(num);
            if (lq.size() >= rq.size() + 2) {
                int val = lq.top();
                lq.pop();
                rq.emplace(val);
            } else if (rq.size() >= lq.size() + 2) {
                int val = rq.top();
                rq.pop();
                lq.emplace(val);
            }
        }
    }
    
    double findMedian() {
        if ((lq.size() + rq.size()) % 2 == 0) return (lq.top() * 1.0 + rq.top() * 1.0) / 2;
        else return (lq.size() > rq.size() ? lq.top() : rq.top());
    }
};

