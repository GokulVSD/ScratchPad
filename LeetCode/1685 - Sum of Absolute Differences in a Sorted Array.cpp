// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// Linear time with help of prefix sum, sum of the left reduces, sum of the right increases, the number itself increases left size number of times, and reduces right size number of times.

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> prefsum(nums.size());
        
        prefsum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            prefsum[i] = nums[i] + prefsum[i - 1];

        for(int i = 0; i < nums.size(); ++i){
            res[i] = nums[i]*i - 2*prefsum[i] + prefsum[nums.size() - 1] - nums[i]*(nums.size() - 2 - i);
        }
        
        return res;
    }
};
    