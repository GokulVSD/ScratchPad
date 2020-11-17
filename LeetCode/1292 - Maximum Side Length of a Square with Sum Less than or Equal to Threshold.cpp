// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

// Prefix sum 2D array allows you to quickly find sum of a sub-matrix.

class Solution {
public:
    int squareSum(vector<vector<int>>& sums, int x1, int y1, int x2, int y2) {
        return sums[x2][y2] - sums[x1][y2] - sums[x2][y1] + sums[x1][y1];
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sums(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                sums[i][j] = mat[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                int len = ans + 1;
                while(i+len <= m && j+len <= n && squareSum(sums, i, j, i+len, j+len) <= threshold){
                    ans = len++;
                }
            }
        }
        return ans;
    }
};