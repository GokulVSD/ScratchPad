// https://leetcode.com/problems/minimum-size-subarray-sum/solution/

// two pointers, left and i, keep track of current contiguous subarray, increment left if condition is met, as smallest subarray starting from left already found.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, ans = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i - left + 1);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};