// https://leetcode.com/problems/sort-integers-by-the-power-value/submissions/

// Memoization

class Solution {
public:
    int buildPower(int x, unordered_map<int, int> &memo){
        if(memo[x] > 0) return memo[x];
        if(x == 0 || x == 1) return 0;
        if(x % 2){
            memo[x] = 1 + buildPower(3*x + 1, memo);
        } else {
            memo[x] = 1 + buildPower(x/2, memo);
        }
        return memo[x];
    }
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> memo;
        vector<int> res(hi - lo + 1);
        for(int i = 0; i < res.size(); ++i){
            res[i] = i + lo;
        }
        
        for(int i = 2; i <= hi; ++i){
            buildPower(i, memo);
        }
        sort(res.begin(), res.end(), [&memo](int x, int y){
            if(memo[x] == memo[y])
                return x < y;
                return memo[x] < memo[y];
        });
        return res[k-1];
    }
};