// https://leetcode.com/problems/remove-element/submissions/

// Can use two pointers and store only if not equal to val, or swap with back and pop (this).

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
                nums.pop_back();
            } else {
                i++;
            }
        }
    return n;
    }
};