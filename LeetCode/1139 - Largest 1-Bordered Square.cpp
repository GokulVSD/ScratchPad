// https://leetcode.com/problems/largest-1-bordered-square/submissions/

// https://leetcode.com/problems/largest-1-bordered-square/discuss/345265/c%2B%2B-beats-100-(both-time-and-memory)-concise-with-algorithm-and-image

// create a hor and ver copy, where keeps track of max sequential at a position

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor(m, vector<int>(n));
        vector<vector<int>> ver(m, vector<int>(n));
        for(int i = 0; i < m; i++) { 
            for(int j = 0; j < n; j++){ 
                if(grid[i][j] == 1){ 
                    hor[i][j] = (j==0)? 1: hor[i][j-1] + 1;
                    ver[i][j] = (i==0)? 1: ver[i-1][j] + 1;
                } 
            } 
        }
        int res = 0;
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                int small = min(ver[i][j], hor[i][j]);
                while(small > res){
                    if(ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small){
                        res = small;
                    }
                    --small;
                }
            }
        }
        return res*res;
    }
};