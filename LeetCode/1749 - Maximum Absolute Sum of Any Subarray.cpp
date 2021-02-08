// https://leetcode.com/contest/biweekly-contest-45/problems/maximum-absolute-sum-of-any-subarray/

/*
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        
        if(n == 0) return 0;
        pre[0] = 0;
        
        for(int i = 1; i <= n; ++i){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int l = INT_MAX, h = INT_MIN;
        for(int i = 0; i <= n; ++i){
            h = max(h, pre[i]);
            l = min(l, pre[i]);
        }
            
        return abs(h) + abs(l);
    }
};