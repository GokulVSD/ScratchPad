// https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/

// keep dp array as best sum upto position
// From the current position, check k positions back, and try to find a better sum
// curMax keeps track of largest in the last k, best keeps track of best combination  

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                curMax = max(curMax, A[i - k]);
                best = max(best, dp[i - k] + curMax * k);
            }
            dp[i] = best; 
        }
        return dp[N];
    }
};