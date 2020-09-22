// https://leetcode.com/problems/largest-number/

// Spent so much time writing convoluted code before I finally realised how ridiculously simple the solution was.

class Solution {
public:
    
    static bool compare(string s1, string s2){
                
        if(s1 + s2 > s2 + s1) return true;
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> strs;
        
        for(auto &a : nums){
            strs.emplace_back(to_string(a));
        }
        
        sort(strs.begin(), strs.end(), compare);
        
        string res = "";
        for (auto &a : strs)
            res += a;
        if(res[0] == '0') res = "0";
        return res;
    }
};