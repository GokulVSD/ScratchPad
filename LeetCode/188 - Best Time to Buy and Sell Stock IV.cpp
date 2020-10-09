
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// Best possible logic is at the bottom

// traditional DP
// putting large dimensions in inner array (like how i've done) better uses cpu cache

// best profit  = dp[currently holding][how many transactions used][after which day]
// on any given day, you can:
// 1. keep the stock (if you own it)
// 2. don't buy the stock (if you don't own it)
// 3. buy the stock (if you don't own it)
// 4. sell the stock (if you own it)

// since we're applying dp, we consider that all these options are possible,
// and fill out the array.

// special case if 2k > days (no of transactions is not a constraint)

class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        
        int days = p.size();
        int sum = 0;
        
        if(days <= 0 || k <= 0)
            return 0;
        
        if(2*k > days){
            for(int i = 0; i < days - 1; ++i)
                sum += max(0, p[i + 1] - p[i]);
            return sum;
        }
        // Have to initialise to -1e9 to ignore impossible situations like
        // on first day, haven't bought, but holding stock
        // usually, initialising to 0 in DP problems is fine
        // can't initialise to INT_MIN incase you'll be buying,
        // possible integer overflow
        vector< vector< vector<int> > > dp(2, vector< vector<int> >(k + 1, vector<int>(days, -1000000000)));
        
        // initial conditions
        dp[0][0][0] = 0;
        dp[1][1][0] = -p[0];
        
        for(int i = 1; i < days; ++i){
            for(int j = 0; j <= k; ++j){
                // after i'th day, if you're not holding
                // max of don't buy and sell
                dp[0][j][i] = max(dp[0][j][i - 1], dp[1][j][i - 1] + p[i]);
                
                // after i'th day, if you're holding
                // max of buy and don't sell
                if(j > 0) // you can only hold if you've previously bought
                    dp[1][j][i] = max(dp[0][j - 1][i - 1] - p[i], dp[1][j][i - 1]);
            }
        }
        
        // best profit is after the final day, you should not be holding,
        // and you could have used upto k transactions
        for(int j = 0; j <= k; ++j)
            sum = max(sum, dp[0][j][days - 1]);
        
        return sum;
        // you can optimise space by keeping track of only prev and cur day.
    }
};


// here's a way better solution

class Solution {
    public:
        int maxProfit(int k, vector<int> &prices) {
            int len = prices.size();
            if (len<2) return 0;
            if (k>len/2){ // simple case
                int ans = 0;
                for (int i=1; i<len; ++i){
                    ans += max(prices[i] - prices[i-1],0);
                }
                return ans;
            }
            int hold[k+1];
            int rele[k+1];
            for (int i=0;i<=k;++i){
                hold[i] = INT_MIN;
                rele[i] = 0;
            }
            int cur;
            for (int i=0; i<len; ++i){
                cur = prices[i];
                for(int j=k; j>0; --j){
                    rele[j] = max(rele[j],hold[j] + cur);
                    hold[j] = max(hold[j],rele[j-1] - cur);
                }
            }
            return rele[k];
        }
}

// logic:

// Follows:
// 1. keep the stock (if you own it)
// 2. don't buy the stock (if you don't own it)
// 3. buy the stock (if you don't own it)
// 4. sell the stock (if you own it)
// minmax accordingly

public int MaxProfitDpCompactFinal(int[] prices)  {
    int buy1 = int.MaxValue, buy2 = int.MaxValue;
    int sell1 = 0, sell2 = 0;

    for (int i = 0; i < prices.Length; i++) {
        buy1 = Math.Min(buy1, prices[i]);
        sell1 = Math.Max(sell1, prices[i] - buy1);
        buy2 = Math.Min(buy2, prices[i] - sell1);
        sell2 = Math.Max(sell2, prices[i] - buy2);
    }

    return sell2;
}