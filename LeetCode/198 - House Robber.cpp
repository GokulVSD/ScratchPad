// https://leetcode.com/problems/house-robber/submissions/

// Keep track of two numbers, including last element, and excluding last element, and build your current best sum based on that, and update for the next iteration.

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int inc, exc, cur_inc, cur_exc;
        inc = nums[0]; exc = 0;
        for(int i = 1; i < nums.size(); ++i){
            cur_exc = max(inc, exc);
            cur_inc = exc + nums[i];
            exc = cur_exc;
            inc = cur_inc;
        }
        return max(exc, inc);
    }
};