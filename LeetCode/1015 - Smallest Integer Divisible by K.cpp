// https://leetcode.com/problems/smallest-integer-divisible-by-k/submissions/

// Either use a set to keep track of seen remainders, and return -1 if seen before, or return -1 after K iterations, since due to pidgeon hole principle, a remainder will repeat.

// We can module n with K after every *10 + 1 because all we care about is if we get a 0 remainder, not the order of the remainders we get. %K will still eventually get us the same set of remainders.

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int n = 1, len = 1;
        while(len <= K){
            if(n % K == 0)
                return len;
            ++len;
            n = n*10 + 1;
            n = n % K;
        }
        return -1;
    }
};