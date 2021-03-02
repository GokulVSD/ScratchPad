// https://leetcode.com/problems/map-of-highest-peak/

// BFS, as BFS traverses layer by layer

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        
        vector<vector<int>> height(m, vector<int>(n));
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<tuple<int, int, int>> q;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(isWater[i][j]){
                    height[i][j] = 0;
                    q.push(make_tuple(i, j, 0));
                    visited[i][j] = true;
                } else
                    visited[i][j] = false;
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = get<0>(p), j = get<1>(p), h = get<2>(p);
            if(i > 0){
                if(!visited[i - 1][j]){
                    height[i - 1][j] = h + 1;
                    visited[i - 1][j] = true;
                    q.push(make_tuple(i - 1, j, h + 1));
                }
            }
            if(j > 0){
                if(!visited[i][j - 1]){
                    height[i][j - 1] = h + 1;
                    visited[i][j - 1] = true;
                    q.push(make_tuple(i, j - 1, h + 1));
                }
            }
            if(i < m - 1){
                if(!visited[i + 1][j]){
                    height[i + 1][j] = h + 1;
                    visited[i + 1][j] = true;
                    q.push(make_tuple(i + 1, j, h + 1));
                }
            }
            if(j < n - 1){
                if(!visited[i][j + 1]){
                    height[i][j + 1] = h + 1;
                    visited[i][j + 1] = true;
                    q.push(make_tuple(i, j + 1, h + 1));
                }
            }
        }
        
        return height;
    }
};