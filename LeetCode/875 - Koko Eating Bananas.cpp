// https://leetcode.com/problems/koko-eating-bananas/submissions/

// Straight forward binary search for boundary of possible 

class Solution {
public:
    bool possible(vector<int>& piles, int k, int h){
        int taken = 0;
        for(auto &p : piles){
            taken += ceil((double)p / k);
            if(taken > h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = 0;
        for(auto &p : piles)
            hi = max(hi, p);
        
        while(lo < hi){
            int k = (lo + hi)/2;
            if(possible(piles, k, H))
                hi = k;
            else
                lo = k + 1;
        }
        return hi;
    }
};
    