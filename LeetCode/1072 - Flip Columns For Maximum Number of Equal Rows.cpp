// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/submissions/

// Assume the i-th row is an all-0s row after flipping x columns.

//If there are any other all-0s row, say j-th row, then the j-th row before flipping should be the same as the i-th row.
//If there are any other all-1s row, say k-th row, then the k-th row before flipping should be totally different from the i-th row.

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> hmap;
        for(auto x: matrix){
            string s=""; 
            //s keeps track of relative ordering of elements in a row w.r.t the first element
            int top=x[0];
            for(int i=0;i<x.size();i++){
                if(x[i]==top)
                    s+='1';
                else
                    s+='0';
            }
            hmap[s]++; 
        }
        
        int result=0;
        for(auto &[key,val]:hmap)
            result=max(result,val); 

        return result;
    }
};