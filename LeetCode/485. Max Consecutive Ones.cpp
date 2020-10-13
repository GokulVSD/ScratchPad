// https://leetcode.com/problems/max-consecutive-ones/submissions/

// Similar to Kadane's

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_so_far = 0, till_here = 0;
        for(int i = 0; i < nums.size(); ++i){
            ++till_here;
            if(nums[i] == 0) till_here = 0;
            max_so_far = max(max_so_far, till_here);
        }
        return max_so_far;
    }
};