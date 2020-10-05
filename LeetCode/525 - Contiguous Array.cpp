// https://leetcode.com/problems/contiguous-array/

// It's basically longest continuous subarray that sums to k, where k=0, if 0 is replaced with -1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        replace(nums.begin(), nums.end(), 0, -1);
        
        unordered_map<int, int> m;
        
        int maxlen = 0, acc = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            
            acc += nums[i];
            
            if(acc == 0) maxlen = i + 1;
            
            if(m.find(acc) == m.end())
                m[acc] = i;
            else
                maxlen = max(maxlen, i - m[acc]);
            
        }
        
        return maxlen;
        
    }
};
