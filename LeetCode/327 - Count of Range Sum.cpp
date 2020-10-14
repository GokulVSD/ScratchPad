// https://leetcode.com/problems/count-of-range-sum/

// j is the first index satisfy first[j] - first[i] > upper and
// k is the first index satisfy first[k] - first[i] >= lower.

class Solution {
public:
    
    int mergeSort(vector<long>& first, int lower, int upper, int low, int high)
    {
        if(high - low <= 1) return 0;
        int mid = (low + high)/2,
            k = mid,
            j = mid,
            count = 0;
        count = mergeSort(first,lower,upper,low,mid) + mergeSort(first,lower,upper,mid,high);
        for(int i = low; i < mid; ++i){
            while(k < high && first[k] - first[i] < lower) k++;
            while(j < high && first[j] - first[i] <= upper) j++;
            count += j - k;
        }
        inplace_merge(first.begin() + low, first.begin() + mid, first.begin() + high);
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // prefix sum vector
        vector<long> first(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); ++i)
            first[i] = first[i - 1] + nums[i - 1];
        
        return mergeSort(first, lower, upper, 0, nums.size() + 1);
    }
};


// Below is a DP solution, O((n^2)/2), not as good as the previous one

class Solution {
public:
    // void printDP(vector<vector<pair<long, long>>>& dp){
    //     for(auto &a : dp){
    //         for(auto &b : a){
    //             cout<<b.first<<":"<<b.second<<"\t";
    //         }
    //         cout<<"\n";
    //     } cout<<"\n";
    // }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0] >= lower && nums[0] <= upper;
        
        vector<vector<pair<long, long>>> dp(n + 1, vector<pair<long, long>>(n + 1, make_pair(0, 0)));
        
        for(int i = 0; i < n; ++i)
            dp[i + 1][i + 1] = make_pair(nums[i] >= lower && nums[i] <= upper, nums[i]);   

        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <= n; ++j){
                auto l = dp[j - i][j - 1];
                auto r = dp[j - i + 1][j];
                auto d = dp[j - i + 1][j - 1];
                bool c = l.second + r.second - d.second >= lower &&
                         l.second + r.second - d.second <= upper;
                dp[j - i][j] = make_pair(l.first + r.first - d.first + c,
                                         l.second + r.second - d.second);
            }
        }

        return dp[1][n].first;
    }
};