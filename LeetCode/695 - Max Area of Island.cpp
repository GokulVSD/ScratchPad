// https://leetcode.com/problems/max-area-of-island/

// Pretty standard recursion, took a while for me to realise I needed to replace with 0 when I consider an island segment

class Solution {
public:
    
    int scan(vector<vector<int>>& grid, int i, int j){
        
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0) 
            return 0;
        grid[i][j] = 0;
        return 1 + scan(grid, i, j + 1) + scan(grid, i, j - 1) + scan(grid, i + 1, j) + scan(grid, i - 1, j);
         
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                max_size = max(max_size, scan(grid, i, j));
            }
        }
        return max_size;
    }
};