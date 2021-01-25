// https://leetcode.com/problems/longest-common-subsequence/submissions/

// Straightforward dp, where dp[i][j] indicates longest common subsequence between text1[0..i-1] and text2[0..j-1]

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (text1[i-1] == text2[j-1]));
            }
        }
        return dp[m][n];
    }
};