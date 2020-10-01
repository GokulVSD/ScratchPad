// https://leetcode.com/problems/maximum-subarray/

// Kadane's

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum_so_far = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum_so_far += nums[i];
            max_sum = max(max_sum, sum_so_far);
            sum_so_far = max(sum_so_far, 0);
        }
        return max_sum;
    }
};