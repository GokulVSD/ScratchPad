// https://leetcode.com/problems/prime-arrangements/submissions/

// Using Sieve of Eratosthenes O(n loglog n) to find all primes less than n

class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> prime(n + 1, true);
 
        for (int p = 2; p * p <= n; p++)
            if (prime[p] == true)
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
        
        int primes = 0, mod = pow(10, 9) + 7;
        for(int i = 2; i <= n; ++i)
            if(prime[i]) ++primes;
        
        long comp_perms = 1, prime_perms = 1;
        for(int i = 2; i <= n - primes; ++i){
            comp_perms *= i;
            comp_perms = comp_perms % mod;
        }
        for(int i = 2; i <= primes; ++i){
            prime_perms *= i;
            prime_perms = prime_perms % mod;
        }
        
        return (comp_perms*prime_perms) % mod;
    }
};