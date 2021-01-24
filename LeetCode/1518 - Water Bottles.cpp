// https://leetcode.com/problems/water-bottles/submissions/

// Log(n), simple

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0, leftovers = 0;
        while(numBottles > 0){
            total += numBottles;
            numBottles += leftovers;
            leftovers = numBottles % numExchange;
            numBottles /= numExchange;
        }
        return total;
    }
};