// https://leetcode.com/problems/count-numbers-with-unique-digits/

// Let k=number of digits, f(1) = 10, f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0]

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> dp(n + 1, 9);
        dp[1] = 10;
        for(int i = 2; i <= n; ++i){
            for(int j = 9; j > 9 - i + 1; --j)
                dp[i] *= j;
            dp[i] += dp[i - 1];
        }
        return dp[n];   
    }
};