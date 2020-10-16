// https://leetcode.com/problems/reverse-string-ii/submissions/

// Use of the reverse function really shortens the code.

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while(++i*k < s.size())
            if(i%2) reverse(s.begin() + (i - 1)*k, s.begin() + i*k);
        if(i%2) reverse(s.begin() + (i - 1)*k, s.end());
        return s;
    }
};