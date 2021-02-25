// https://leetcode.com/problems/coin-change-2/

// 0/1 Knapsack, dp[i][j] indiciates upto index i of coins, number of ways to make amount j, optimal substructure is number of ways to make amount j with upto index i-1 of coins + number of ways to make amount j - coins[i - 1] with utpo index i coins.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= amount; ++j){
                dp[i][j] = dp[i - 1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[n][amount];
    }
};

// Can be simplified down to:
 public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;        
        for (int i = 0; i < coins.length; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i];
                }
            }
        }
        return dp[amount];
    }