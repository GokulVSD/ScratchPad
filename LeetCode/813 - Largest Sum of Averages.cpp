// https://leetcode.com/problems/largest-sum-of-averages/

// dp creation, don't need to represent as 2D, since only previous iteration affects current iteration.
// dp[i, k] represents best score for array A[i:] partitoned at most k times.
        
// dp(i, k) = max(average(i, N), max_{j > i}(average(i, j) + dp(j, k-1)))
// first term in max is if its better not to partition.

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        // prefix sum, double so as to force floating point division
        vector<double> prefix(A.size() + 1);
        for(int i = 0; i < A.size(); ++i){
            prefix[i+1] = prefix[i] + A[i];
        }
        
        vector<double> dp(A.size());
        
        // initialise assuming no partition (k=0)
        for(int i = 0; i < A.size(); ++i){
            dp[i] = (prefix[A.size()] - prefix[i]) / (A.size() - i);
        }
        
        for(int k = 0; k < K-1; ++k){
            for(int i = 0; i < A.size(); ++i){
                for(int j = i+1; j < A.size(); ++j){
                    dp[i] = max(dp[i], ((prefix[j] - prefix[i]) / (j - i)) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};