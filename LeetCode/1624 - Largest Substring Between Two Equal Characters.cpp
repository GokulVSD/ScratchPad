// https://leetcode.com/problems/largest-substring-between-two-equal-characters/submissions/

// find leftmost and rightmost position of each character

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        vector<int> left(26), right(26);
        for(int i = n - 1; i >= 0; --i){
            int c = s[i] - 'a';
            left[c] = i;
            right[c] = max(right[c], i);
        }
        int big = -1;
        for(int i = 0; i < 26; ++i)
            big = max(big, right[i] - left[i] - 1);
        return big;
    }
};