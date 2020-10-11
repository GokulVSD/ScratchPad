// https://leetcode.com/problems/out-of-boundary-paths/solution/

// memo[i][j][k] is used to store the number of possible moves leading to a path out of the boundary if the current position is given by the indices (i, j) and number of moves left is k.

class Solution {
    public:
    
    int M = 1000000007;

    int paths(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& memo) {
    
        // out of bounds
        if (i == m || j == n || i < 0 || j < 0) return 1;
        // no more moves
        if (N == 0) return 0;
        // if previously calculated
        if (memo[i][j][N] >= 0) return memo[i][j][N];
        // all 4 movement directions, modulo after every addition
        memo[i][j][N] = (
            (paths(m, n, N - 1, i - 1, j, memo) + paths(m, n, N - 1, i + 1, j, memo)) % M +
            (paths(m, n, N - 1, i, j - 1, memo) + paths(m, n, N - 1, i, j + 1, memo)) % M
        ) % M;

        return memo[i][j][N];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
      
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(N + 1, -1)));
      
        return paths(m, n, N, i, j, memo);
    }
};