// https://leetcode.com/problems/gray-code/

// idea is to generate the sequence iteratively. For example, when n=3, we can get the result based on n=2.

// 00,01,11,10 -> (000,001,011,010 ) + (110,111,101,100)
// every increase in i doubles the ans size, append to ans reverse of whats in it, with an added bit of 1 in the front. 

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; ++i){
            int size = ans.size();
            for(int j = size - 1; j >= 0; --j){
                ans.push_back(ans[j] | (1 << i));
            }
        }
        return ans;
    }
};