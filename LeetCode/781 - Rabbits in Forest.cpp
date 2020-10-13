// https://leetcode.com/problems/rabbits-in-forest/

// Each answer states how many OTHER rabbits are the same colour.

class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int res = 0;
        unordered_map<int, int> m;
        m.reserve(1000);
        for(auto a: ans)
            ++m[a];
        for(auto pair: m){
            res += pair.first + 1;
            while(pair.first < pair.second - 1){
                res += pair.first + 1;
                pair.second -= pair.first + 1;
            }
        }
        return res;
    }
};