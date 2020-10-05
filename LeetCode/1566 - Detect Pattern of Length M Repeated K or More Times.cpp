// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

// O(n) in time, O(1) in space. Works by comparing indices m apart.

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for(int i = 0; i + m < arr.size(); ++i){
            if(arr[i] == arr[i + m])
                count++;
            else
                count = 0;
            if(count == (k - 1)*m) return true;
        }
        return false;
    }
};