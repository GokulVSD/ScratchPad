// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/

// Similar to problem 1685, requires sorting as diff of left cannot interfere with diff of right, check how many moves to make all elements to equal current element.

// Alternatively, you can use quickselect to find median, and just compute moves for getting all elements to be be the median.
// That would be O(n) average.

// Annoying problem does not give proper bounds, causing me to not use long long int initially.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int ans = LLONG_MAX;
        int n = nums.size();
        
        if(n == 0 || n == 1) return 0;
        
        sort(nums.begin(), nums.end());
        
        vector<int> pre(n + 1);
        pre[0] = 0;
        for(int i = 1; i <= n; ++i)
            pre[i] = nums[i - 1] + pre[i - 1];
        
        for(int i = 1; i < n; ++i){
            ans = min(ans, abs((long long int)i*nums[i] - pre[i]) + abs((long long int)(n - i - 1)*nums[i] - (pre[n] - pre[i + 1])));
        }
        return ans;
    }
};