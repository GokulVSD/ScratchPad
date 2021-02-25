// https://leetcode.com/problems/first-unique-character-in-a-string/submissions/

// Very straightforward. If the goal is to print earliest non repeating string for every position in string, we need to use a queue.

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        for(auto &c : s){
            freq[c - 'a']++;
        }
        for(int i = 0; i < s.size(); ++i){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};