// https://leetcode.com/problems/regular-expression-matching/submissions/

// Can be sped up using DP

class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p.size() == 0) return !s.size();
        bool first = s.size() > 0 && (s[0] == p[0] || p[0] == '.');
        
        if(p.size() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (first && isMatch(s.substr(1), p));
        else
            return first && isMatch(s.substr(1), p.substr(1));
    }
};