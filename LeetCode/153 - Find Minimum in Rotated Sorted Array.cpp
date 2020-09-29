// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Explained within code. The core insight is that when comparing any two elements,
// the first will always be smaller than the second if the pivot isn't between
// them. This condiditon holds true because the array consists of unique elements.

class Solution {
public:
    
    // int mod(int a, int b){
    //     return (a % b + b) % b;
    // }
    
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, ans = INT_MAX, mid;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[low] <= nums[mid]){ // true if pivot isn't b/w low and mid
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high]){ // true if pivot isn't b/w mid and high
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};