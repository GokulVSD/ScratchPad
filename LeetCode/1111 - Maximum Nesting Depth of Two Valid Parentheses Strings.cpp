// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

// Alternative depths can be assigned to A and B, thereby
// minimising the maximum depth.

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size(), 0);
        int count = 0;
        for(int i = 0; i < seq.size(); ++i){
            if(seq[i] == '(')
                ans[i] = (count++) % 2;
            else
                ans[i] = (1 + count--) % 2;
        }
        return ans;
    }
};