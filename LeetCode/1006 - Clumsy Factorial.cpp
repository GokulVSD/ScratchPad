// https://leetcode.com/problems/clumsy-factorial/submissions/

// Common sense

class Solution {
public:
    int pod(int N){
        return -N*(N-1)/(N-2) + N-3;
    }
    int clumsy(int N) {
        int ans = 0;
        if(N > 3) ans = N*(N-1)/(N-2) + N-3;
        if(N == 3) ans = N*(N-1)/(N-2);
        if(N == 2) ans = N*(N-1);
        if(N == 1) ans = 1;
        N -= 4;
        while(N > 3){
            ans += pod(N);
            N -= 4;
        }
        if(N == 3) ans -= N*(N-1)/(N-2);
        if(N == 2) ans -= N*(N-1);
        if(N == 1) ans -= 1;
        return ans;
    }
};

// However, i * (i-1) / (i-2) = i+1 when i >= 5 (only for floor division)

/*
i * (i-1) / (i-2) + (i-3) - (i-4) * (i-5) / (i-6) + (i-7) - (i-8) * .... + rest elements
=   (i+1) + "(i-3)" - "(i-4) * (i-5) / (i-6)" + "(i-7)" - "(i-8) * " .... + rest elements
=   (i+1) + "(i-3) - (i-3)" + "(i-7) - (i-7)" +  ....  + rest elements
=   (i+1) + rest elements

class Solution:
    def clumsy(self, N: int) -> int:
        magic = [1, 2, 2, -1, 0, 0, 3, 3]
        return N + (magic[N % 4] if N > 4 else magic[N + 3])
*/

