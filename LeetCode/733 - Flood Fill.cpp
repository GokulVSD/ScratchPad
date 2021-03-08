// https://leetcode.com/problems/flood-fill/submissions/

// BFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m));
        q.push(make_pair(sr, sc));
        visited[sr][sc] = true;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i < n - 1 && !visited[i + 1][j] && image[i + 1][j] == image[i][j]){
                visited[i + 1][j] = true;
                q.push(make_pair(i + 1, j));
            }
            if(i > 0 && !visited[i - 1][j] && image[i - 1][j] == image[i][j]){
                visited[i - 1][j] = true;
                q.push(make_pair(i - 1, j));
            }
            if(j < m - 1 && !visited[i][j + 1] && image[i][j + 1] == image[i][j]){
                visited[i][j + 1] = true;
                q.push(make_pair(i, j + 1));
            }
            if(j > 0 && !visited[i][j - 1] && image[i][j - 1] == image[i][j]){
                visited[i][j - 1] = true;
                q.push(make_pair(i, j - 1));
            }
            
            image[i][j] = newColor;
        }
        return image;
    }
};