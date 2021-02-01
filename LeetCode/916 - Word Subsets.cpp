// https://leetcode.com/problems/word-subsets/submissions/

// Calculate bag of required characters from each b in B, and check every a in A.

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> uni;
        vector<int> bag(26);
        // getting bag that every a in A must have, O(B.size)
        for(auto &b: B){
            vector<int> temp(26);
            for(auto &c: b)
                ++temp[c - 'a'];
            for(int i = 0; i < 26; ++i)
                bag[i] = max(bag[i], temp[i]);
        }
        // Checking every a in A has the required bag, O(A.size)
        for(auto &a: A){
            vector<int> temp(26);
            for(auto &c: a)
                ++temp[c - 'a'];
            bool valid = true;
            for(int i = 0; i < 26; ++i)
                if(temp[i] < bag[i]){
                    valid = false;
                    break;
                }
            if(valid) uni.emplace_back(a);
        }
        return uni;
    }
};
