// https://leetcode.com/problems/xor-operation-in-an-array/

/*
The core principle used is that x ^ (x + 1) = 1 if x is even.
First, we also simplify by changing the problem from being:
start ^ (start + 2) ^ (start + 4) ^ ... (start + 2*i)
to:
start/2 ^(start/2 + 1)^...^(start + i)

We can do this by remembering the first bit of start, and then right shifting it. At the end, we can left shift our answer and add back the first bit where necessary.

We can derive for the even scenario by considering that start^(start+1)^(start+2)^(start+3) cancels out to 0 when start is even after right shifting. We can use a Switch block to return the answer, which we can figure out by considering n in chunks of 4.

The solution in the odd scenario when start is odd after right shifting can again be derived by using a Switch block, taking into consideration that (start+1)^(start+2)^(start+3)^(start+4) cancels out to 0. (start+1 is even, hence subsequent series is the same as the even scenario). We simply XOR a start to compensate for not considering the first start in the odd scenario.

Similarly, the first bit only has an effect when n is an odd number, as an even number of 1s XOR'd will cancel out to 0.
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int first = start & 1;
        start = start >> 1;
        if(start % 2 == 0){
            switch(n % 4){
                case 0: return 0;
                case 1: return ((start + n - 1) << 1) + first;
                case 2: return 2;
                case 3: return ((1 ^ (start + n - 1)) << 1) + first;
            } 
        } else {
            switch(n % 4){
                case 0: return (start ^ 1 ^ (start + n - 1)) << 1;
                case 1: return (start << 1) + first;
                case 2: return (start ^ (start + n - 1)) << 1;
                case 3: return ((start ^ 1) << 1) + first;
            } 
        }
        return 0; //unreachable
    }
};