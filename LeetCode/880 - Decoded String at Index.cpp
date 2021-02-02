// https://leetcode.com/problems/decoded-string-at-index/

// Key insight is to keep track of i, a position in the string, and forward or backward.

// Go forth in the string till the decoded string length (N) exceeds K, then go backward.
// If a digit is found, divide N by it (reverse process). After than, modulo K with N. This is because as you reverse "simulate" looping over a string of size N, K will land on K % N

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};