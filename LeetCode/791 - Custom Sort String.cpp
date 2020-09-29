// https://leetcode.com/problems/custom-sort-string/

// Was forced to use lambda function here, as I could not pass or access a map
// inside a static compare function.

class Solution {
public:
    
    unordered_map<char, int> m;
    
    string customSortString(string S, string T) {
        int p = 0;
        for(auto &c : S) this->m[c] = p++;
        sort(T.begin(), T.end(), [this](char x, char y){
             return this->m[x] < this->m[y];
        });
        return T;
    }
};