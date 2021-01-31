// https://leetcode.com/problems/counting-bits/

// i&(i-1) removes the lowest set bit. So since we've previously calculated the answer for a smaller number, we can remove a bit, look up its set bits, and add one to it.

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};