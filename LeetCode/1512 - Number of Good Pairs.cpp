// https://leetcode.com/problems/number-of-good-pairs/description/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodPairs = 0;
        vector<int> c(101, 0);
        for (const auto& n : nums) {
            ++c[n];
        }
        for (const auto& n : c) {
            goodPairs += n*(n-1)/2;
        }
        return goodPairs;
    }
};