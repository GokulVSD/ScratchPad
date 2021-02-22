// https://leetcode.com/problems/prison-cells-after-n-days/

// FSM, only 2^6 (64) possible states, so should be quick, constant time. 

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& res, int n) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while (n--) {
            for (int i = 1; i < 7; i++) {
                tmp[i] = res[i - 1] == res[i + 1];
            }
            if (seen.size() && seen.front() == tmp) return seen[n % seen.size()]; 
            else seen.push_back(tmp);
            res = tmp;
        }
        return res;
    }
};