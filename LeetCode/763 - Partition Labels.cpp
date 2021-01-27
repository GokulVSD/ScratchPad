// https://leetcode.com/problems/partition-labels/

// Greedy solution, keeping track of last occurence of a character.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); ++i){
            m[s[i]] = i;
        }
        int p;
        for(int i = 0; i < s.size(); ++i){
            p = m[s[i]];
            for(int j = i + 1; j < p; ++j){
                p = max(p, m[s[j]]);
            }
            ans.emplace_back(p - i + 1);
            i = p;
        }
        return ans;
    }
};