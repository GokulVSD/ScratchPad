// https://leetcode.com/problems/destination-city/

// Simple enough

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, bool> out(n);
        for(auto &p: paths){
            out[p[0]] = true;
            out[p[1]] &= true;
        }
        for(auto &p: out){
            if(!p.second) return p.first;
        }
        return "";
    }
};