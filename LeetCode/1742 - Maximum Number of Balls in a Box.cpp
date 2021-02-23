// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

// Alternatively, if you know the upperbound for highLimit, you can calculate the max box number, and keep an array of that size.

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> freq;
        int ans = 0;
        for(int i = lowLimit; i <= highLimit; ++i){
            int sum = 0, n = i;
            while(n != 0){
                sum += n % 10;
                n /= 10;
            }
            ans = max(++freq[sum], ans);
        }
        return ans;
    }
};