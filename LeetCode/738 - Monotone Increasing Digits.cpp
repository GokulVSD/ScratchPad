// https://leetcode.com/problems/monotone-increasing-digits/

// The moment monotone property is not satisfied when scanning right to left, subtract 1 from cur*offset.

class Solution {
    public:
    int monotoneIncreasingDigits(int N) {
        int ans = 0;
        int prev = INT_MAX;
        int offset = 1;
        while(N != 0) {
            int cur = N % 10;
            if(cur > prev) {
                ans = cur * offset - 1;
                prev = cur - 1;
            } else {
                ans += cur * offset;
                prev = cur;
            }
            offset *= 10;
            N /= 10;
        }
        return ans;
    }
};