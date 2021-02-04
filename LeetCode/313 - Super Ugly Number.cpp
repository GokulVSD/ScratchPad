// https://leetcode.com/problems/super-ugly-number/

// Heap

// Key insight is that every ugly number is generated as a result of multipying some previous ugly number with one of the primes.

// pos keeps track of index of last ugly number that was multiplied with this prime.

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pos(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < primes.size(); ++j)
                ugly[i] = min(ugly[i], ugly[pos[j]] * primes[j]);
            // duplicate removal
            for(int j = 0; j < primes.size(); ++j)
                pos[j] += (ugly[i] == ugly[pos[j]]*primes[j]);
        }
        return ugly[n-1];
}
};

// Or a using a heap (priority queue) (slower by 30%)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ugly;
        pq.push(1);
        
        for(int i = 0; i < n; ++i){
            ugly = pq.top();
            
            for(auto &p: primes){
                long long temp = (long long int)p * ugly;
                if(temp >= INT_MAX) break;
                pq.push(temp);
            }
            while(pq.top() == ugly)
                pq.pop();
        }
        
        return ugly;
    }
};