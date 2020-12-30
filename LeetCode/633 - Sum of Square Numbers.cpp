// https://leetcode.com/problems/sum-of-square-numbers/

// can be brute forced by checking if sqrt(c - a**2) is an integer. Similarly, binary
// search can be used from the range [0, c - a**2], such that mid*mid = c - a**2

// the best solution is using fermat's theorem. Any positive number n is expressible as a sum of two squares if and only if the prime factorization of n, every prime of the form (4k+3)(4k+3) occurs an even number of times.

// first we find all prime factors of c in the range [2, sqrt(c)] along with the count of these factors by repeated division. if any prime factor of the form (4k+3) occurs odd number of times, we can return false. Incase c itself is a prime, it wont have any prime factors, hence we must check if c can be expressed as (4k+3), and if it is, return false.

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; ++i) {
            int count = 0;
            // since we keep dividing when we find a factor, the factors are prime
            if (c % i == 0) {
                while (c % i == 0) {
                    ++count;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};