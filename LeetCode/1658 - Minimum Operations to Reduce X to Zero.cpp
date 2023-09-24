// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

// Equivalent to finding largest subarray whose sum equals total sum - x.


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pSum(n + 1);
        for (int i = 1; i <= n; ++i) {
            pSum[i] = pSum[i - 1] + nums[i - 1];
        }
        int sum = pSum[n] - x;
        if (sum < 0) return -1;
        int left = 0;
        int maxSubArraySize = -1;
        for (int right = 1; right <= n; ++right) {
            if (pSum[right] - pSum[left] == sum) {
                maxSubArraySize = max(maxSubArraySize, right - left);
            } else if (pSum[right] - pSum[left] > sum) {
                ++left;
                --right;
            }
        }
        if (maxSubArraySize == -1) return -1;
        return n - maxSubArraySize;
    }
};