// https://leetcode.com/problems/pascals-triangle/

// Simple enough

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p;
        vector<int> row;
        row.push_back(1);
        p.push_back(row);
        while(--numRows){
            int prev = p.size() - 1;
            row.clear();
            row.push_back(1);
            for(int i = 0; i < p[prev].size() - 1; ++i)
                row.push_back(p[prev][i] + p[prev][i + 1]);
            row.push_back(1);
            p.push_back(row);
        }
        return p;
    }
};