// https://leetcode.com/problems/self-dividing-numbers/

// Simple enough

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; ++i){
            if(i < 10)
                res.emplace_back(i);
            else{
                int n = i; bool valid = true;
                while(n != 0){
                    if(n % 10 == 0 || i % (n % 10) != 0){
                        valid = false;
                        break;
                    }
                    n /= 10;
                }
                if(valid) res.emplace_back(i);
            }
        }
        return res;
    }
};