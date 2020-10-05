// https://leetcode.com/problems/subarray-sum-equals-k/

// A variation of maximum length of subarray summing to k, where you
// keep a map of <sum, no_of_occurences>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        int count = 0, acc = 0;
        
        m[0] = 1;
        
        for(int i = 0; i < nums.size(); ++i){
            
            acc += nums[i];
            
            if(!(m.find(acc - k) == m.end()))
                count += m[acc - k];
            
            if(m.find(acc) == m.end())
                m[acc] = 1;
            else
                ++m[acc];
            
        }
        return count;
    }
};