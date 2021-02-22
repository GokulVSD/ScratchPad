// https://leetcode.com/problems/product-of-array-except-self/solution/

// Uses left and right arrays to keep track of products to the left and to the right.
// Can be made constant space by using ans array as right, and calculating left while iterating

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), ans(n);
        left[0] = 1;
        right[n - 1] = 1;
        
        for(int i = 1; i < n; ++i)
            left[i] = left[i - 1] * nums[i - 1];
        for(int i = n - 2; i >= 0; --i)
            right[i] = right[i + 1] * nums[i + 1];
        
        for(int i = 0; i < n; ++i)
            ans[i] = left[i] * right[i];
        
        return ans;
    }
};