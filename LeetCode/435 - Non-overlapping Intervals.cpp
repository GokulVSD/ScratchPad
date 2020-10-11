// https://leetcode.com/problems/non-overlapping-intervals/

// Simple enough

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y){
            return x[0] < y[0];
        });
        
        int res = 0, prev = 0;
        
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < intervals[prev][1]){
                ++res;
                if(intervals[i][1] < intervals[prev][1])
                    prev = i;
            }
            else prev = i;
        }
        
        return res;
    }
};