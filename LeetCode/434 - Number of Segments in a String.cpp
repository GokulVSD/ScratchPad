// https://leetcode.com/problems/number-of-segments-in-a-string/submissions/

// Simple enough

class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        int count = 0;
        bool prevNotWS = false;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' ') prevNotWS = true;
            else if(prevNotWS){
                ++count;
                prevNotWS = false;
            }
        }
        if(s[s.size() - 1] != ' ') ++count;
        return count;
    }
};