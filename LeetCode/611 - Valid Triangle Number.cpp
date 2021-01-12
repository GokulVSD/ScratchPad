// https://leetcode.com/problems/valid-triangle-number/

// Sum of any two sides of a triangle is always greater than the third side. Instead of checking this inequality for the 3 combinations of any triplet, we can sort the numbers, and only check i + j > k, where i <= j <= k in the sorted array. The two other inequality combinations are implicitly satisfied.

// For each i, for each j greater than i, we check for the condition to be true starting from k = i + 2. We find the first k that does not satisfy this inequality. The number of triangles possible for the given i and j will be k - j - 1. For subsequent values of j for the same i, we can resume checking for the inequality from where the previous k ceased to satisfy, as all before that would also satisfy for a higher j.

// On an interesting note, I did not realise the size() function returns an unsigned value, it led to overflow when subtracting 2 from it.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size() - 2; ++i){
            cout<<(nums.size() - 2)<<" ";
            int k = i + 2;
            for(int j = i + 1; j < nums.size() - 1 && nums[i] != 0; ++j){
                while(k < nums.size() && nums[i] + nums[j] > nums[k])
                    ++k;
                count += k - j - 1;
            }
        }
        return count;
    }
};